#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#include "db_system.h"
#include "utilities.h"
#include "menu_utils.h"
#include "translation_table.h"
#include "inesrt_funcs.h"
#include "db_select_compare.h"

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

void editUser()
{
    printf("------%s-----\n", getTranslation("edt_pr", activeUser.language));

    insertUserInfo(&activeUser, activeUser.language);
}

void insertUserInfo(User* u, int language)
{
    insertUserUsername(u, language);
    insertUserPassword(u, language);
    insertUserFirstName(u, language);
    insertUserLastName(u, language);
    insertUserEmail(u, language);
    insertUserLanguga(u, language);
}

float getAverageRating(char* ISBN){
    ComparisonPair compare_pairs[] = {
        { compareByReviewBookISBN, ISBN }, 
    };

    int num_found = 0;
    float average_rating = 0;
    Review* reviews =  DB_select(ReviewT, compare_pairs, sizeof(compare_pairs), &num_found);

    if (reviews != NULL) {
        for (int i = 0; i < num_found; i++) {
            average_rating += (float)reviews[i].Rating / num_found;
        }
    } else {
        return 0;
    }
}

char* toLowercaseCopy(const char *str) {
    if (str == NULL) {
        return NULL; // Handle null input string
    }

    // Allocate memory for the new lowercase string
    char *lowercaseStr = malloc(strlen(str) + 1); // +1 for the null terminator
    if (lowercaseStr == NULL) {
        return NULL; // Handle memory allocation failure
    }

    // Convert the string to lowercase
    const char *originalStr = str;
    char *lowercasePtr = lowercaseStr;
    while (*originalStr) {
        *lowercasePtr++ = tolower((unsigned char) *originalStr++);
    }
    *lowercasePtr = '\0'; // Null-terminate the new string

    return lowercaseStr; // Return the new lowercase string
}

int floatcmp(float f1, float f2) {
    float precision = 0.000001; // Precision of comparison
    if (fabs(f1 - f2) < precision) return 0; // Numbers are equal
    else if (f1 > f2) return 1; // First number is greater
    else return -1; // Second number is greater
}

int sortComparatorForSearch(const void* p1, const void* p2){
    Book* book1 = (Book*)p1;
    Book* book2 = (Book*)p2;

    int scalar = 1;
    if(order_selection == 1)
        scalar = -1;

    switch (order_by_selection)
    {
    case 0:{
        return strcmp(book1->Title, book2->Title) * scalar;
        break;
    }
    case 1:{
        return strcmp(book1->Author, book2->Author) * scalar;
        break;
    }
    case 2:{
        
        float avg1 = getAverageRating(book1->ISBN);
        float avg2 = getAverageRating(book2->ISBN);

        return floatcmp(avg1, avg2) * scalar;
        break;
    }
    case 3:{
        return floatcmp((float)(book1->NumberOfPages), (float)(book2->NumberOfPages)) * scalar;
        break;
    }
    case 4:{
        return floatcmp((float)(book1->PublicationYear), (float)(book2->PublicationYear)) * scalar;
        break;
    }
    
    default:
        break;
    }
}