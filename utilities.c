#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#include "db_system.h"
#include "utilities.h"
#include "menu_utils.h"

int getKeyPressed(){
    int ch, n;
    ch = _getch();

    if (ch == 0 || ch == 224)
        ch = _getch ();

    return ch;
}


void clearScreen(){
    system("cls");
}

void pressEnter(){
    char str_ex[100];
    printf("\n\n\nPress Enter to continue");

    fflush(stdin);
    scanf("%[^\n]", str_ex);
}


const char* fillTimesN(char character, int len) {
    char* result = (char*)malloc(len + 1);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < len; ++i){
        result[i] = character; // Fill with spaces
    }

    result[i] = '\0';


    return result;
}


int windowHeight(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;
    ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
    if(!ret) return 0;

    return csbi.dwSize.Y;
}

int windowWidth(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;
    ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
    if(!ret) return 0;

    return csbi.dwSize.X;
}

int compareByRentalID(void* record, char* key){
    Rental* rental = (Rental*)record;
    return strcmp(rental->rentalID, key);
}




void rentBook(Book* book){
    Rental temp;
    strcpy(temp.BookISBN, book->ISBN);

    temp.deleted = 0;
    strcpy(temp.rentalID, randomID(9));
    temp.RentDate = current_date;
    temp.ReturnDate = null_date;
    strcpy(temp.UserId, activeUser.userID);

    DB_insert(RentalT, &temp);
}


int returnBook(char* rentalID){

    ComparisonPair compare_pairs[] = {
        { compareByRentalID, rentalID }, 
    };

    int num_found;
    Rental* rentals = DB_select(RentalT, compare_pairs, sizeof(compare_pairs), &num_found);

    if(rentals == NULL){
        return 0;
    }

    rentals[0].ReturnDate = current_date;
    DB_update(rentalID, RentalT, &rentals[0]);


    return 1;
}