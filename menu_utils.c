#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

#include "utilities.h"
#include "menu_utils.h"
#include "translation_table.h"

#include "db_system.h"
#include "db_select_compare.h"
#include "page_menus.h"
#include "book_funcs.h"
#include "arg_functions.h"

void contorlSelectedIndex(int ch, int* selected_index, int columns){
    switch (ch)
    {
    case UP_ARROW:
        (*selected_index) -= columns;
        break;
    case DOWN_ARROW:
        (*selected_index) += columns;
        break; 
    case LEFT_ARROW:
        (*selected_index)--;
        break;
    case RIGHT_ARROW:
        (*selected_index)++;
        break;
    case TAB:
        (*selected_index)++;
        break;
    
    default:
        break;
    }
}

int inlineOneButtonSelect(int button_width, char *buttons[], int numButtons, int left_spacing, int button_spacing, int is_3_line, int top_offset, PrintWrapper preWrapper, PrintWrapper postWrapper) {
    int ch = 0;
    int selected_index = 0;


    while (ch != ENTER) {
        printf("%s", fillTimesN('\n', top_offset));

        preWrapper();
        printf("\n");

        if(is_3_line==1){
            for (int i = 0; i < numButtons; i++) {
                int factor = 1  ? (i == 0) : 0;
                if(i == selected_index){
                    printf("%s" ANSI_B_COLOR_GREEN "%s" ANSI_COLOR_RESET "%s", 
                        fillTimesN(' ', left_spacing*factor), fillTimesN(' ', button_width), fillTimesN(' ', button_spacing));
                } else {
                    printf("%s" ANSI_B_COLOR_GRAY "%s" ANSI_COLOR_RESET "%s", 
                        fillTimesN(' ', left_spacing*factor), fillTimesN(' ', button_width), fillTimesN(' ', button_spacing));
                }
                
            }
            printf("\n");
        }

        

        for (int i = 0; i < numButtons; i++) {
            int factor = 1  ? (i == 0) : 0;
            if(i == selected_index){
                printf("%s" ANSI_B_COLOR_GREEN "%s%s%s" ANSI_COLOR_RESET "%s",
                    fillTimesN(' ', left_spacing*factor), fillTimesN(' ', (button_width - strlen(buttons[i])) / 2), buttons[i],
                    fillTimesN(' ', button_width - (button_width - strlen(buttons[i]))/2 - strlen(buttons[i])), fillTimesN(' ', button_spacing));
            } else{
                printf("%s" ANSI_B_COLOR_GRAY "%s%s%s" ANSI_COLOR_RESET "%s",
                    fillTimesN(' ', left_spacing*factor), fillTimesN(' ', (button_width - strlen(buttons[i])) / 2), buttons[i],
                    fillTimesN(' ', button_width - (button_width - strlen(buttons[i]))/2 - strlen(buttons[i])), fillTimesN(' ', button_spacing));
            }
        }

        
        
        if(is_3_line==1){
            printf("\n");
            for (int i = 0; i < numButtons; i++) {
                int factor = 1  ? (i == 0) : 0;
                if(i == selected_index){
                    printf("%s" ANSI_B_COLOR_GREEN "%s" ANSI_COLOR_RESET "%s", 
                        fillTimesN(' ', left_spacing*factor), fillTimesN(' ', button_width), fillTimesN(' ', button_spacing));
                } else {
                    printf("%s" ANSI_B_COLOR_GRAY "%s" ANSI_COLOR_RESET "%s", 
                        fillTimesN(' ', left_spacing*factor), fillTimesN(' ', button_width), fillTimesN(' ', button_spacing));
                }
                
            }
        }

        printf("\n");
        postWrapper();

        ch = getKeyPressed();

        contorlSelectedIndex(ch, &selected_index, numButtons);

        selected_index = fmin(selected_index, numButtons-1);
        selected_index = fmax(0, selected_index);

        clearScreen();


    }

    return selected_index;
}



void clearline() {
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("                            ");
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
}

void fillInForm(char* buf){
    int index = 0;
    int ch;

    while((ch = getchar()) != EOF && ch != '\n') {

        if(ch == '\b' && index != 0) buf[--index] = 0;
        
        buf[index++] = ch;
        
        clearline();
        fflush(stdout);
    }
}

void logInArt(){
    printf("\n\n\n");
    printf("\t\t\t" ANSI_COLOR_BRIGHT_BLUE " _      ___    ___        ___  _  _ \n");
    printf("\t\t\t" "| |    / _ \\  / __|      |_ _|| \\| |\n");
    printf("\t\t\t" "| |__ | (_) || (_ |       | | | .  |\n");
    printf("\t\t\t" "|____| \\___/  \\___|      |___||_|\\_|\n\n" ANSI_COLOR_RESET);

}

int welcomeArt()
{
    printf("\n\n\n");
    printf("\t\t\t\t\t  __        __   _                          \n");
    printf("\t\t\t\t\t  \\ \\      / /__| | ___ ___  _ __ ___   ___ \n");
    printf("\t\t\t\t\t   \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ \n");
    printf("\t\t\t\t\t    \\ V  V /  __/ | (_| (_) | | | | | |  __/\n");
    printf("\t\t\t\t\t     \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|\n");
    printf("\n\n\n");

    return 11;
}

int myRentalsArt()
{
    printf("\n\n\n");
    printf("\t\t\t\t\t  __  __       _____            _        _     \n");
    printf("\t\t\t\t\t |  \\/  |     |  __ \\          | |      | |    \n");
    printf("\t\t\t\t\t | \\  / |_   _| |__) |___ _ __ | |_ __ _| |___ \n");
    printf("\t\t\t\t\t | |\\/| | | | |  _  // _ \\ '_ \\| __/ _` | / __|\n");
    printf("\t\t\t\t\t | |  | | |_| | | \\ \\  __/ | | | || (_| | \\__ \\ \n");
    printf("\t\t\t\t\t |_|  |_|\\__, |_|  \\_\\___|_| |_|\\__\\__,_|_|___/ \n");
    printf("\t\t\t\t\t          __/ |                                \n");
    printf("\t\t\t\t\t         |___/                                 \n");
    printf("\n\n\n");

    return 14;
}


char* getReviewInformation(Review* item, int k){
    switch (k)
    {
        case 0:{
            ComparisonPair compare_pairs[] = {
                { compareByUserID, item->UserId }, 
            };

            int num_found = 0;
            User* user =  DB_select(UserT, compare_pairs, sizeof(compare_pairs), &num_found);
            char* formatted_str_user_name = (char*)malloc(50 * sizeof(char));


            if (user == NULL) {
                snprintf(formatted_str_user_name, 100, "Deleted User");
                return formatted_str_user_name;
            }

            snprintf(formatted_str_user_name, 100, "%s %s", user[0].FirstName, user[0].LastName);
            
            return formatted_str_user_name;
        }
        case 1:{
            char* formatted_str_rating = (char*)malloc(50 * sizeof(char));
            snprintf(formatted_str_rating, 50, "%d*", item->Rating);
            return formatted_str_rating;
        }
        
        case 2:
            return "";
        
        case 3:{
            char* target = (char*)malloc(50 * sizeof(char));

            if(strcmp(item->ReviewText, "") != 0){
                *target = '\0';
                strncat(target, item->ReviewText, 45);
                if(strlen(item->ReviewText) > 45) strcat(target, "...");
                return target;
            }
            snprintf(target, 100, "");
            return target;

        }
    }
}

char* getBookInformation(Book* item, int k){


    switch (k)
    {
        case 0:
            return item->Title;
        
        case 1:
            return "";
        
        case 2:
            return item->Author;
        
        case 3:{
            ComparisonPair compare_pairs[] = {
                { compareByReviewBookISBN, item->ISBN }, 
            };

            char* formatted_str = (char*)malloc(50 * sizeof(char));
            int num_found = 0;
            float avg_rating = 0;
            Review* reviews =  DB_select(ReviewT, compare_pairs, sizeof(compare_pairs), &num_found);

            if (reviews != NULL) {
                for (int i = 0; i < num_found; i++) {
                    avg_rating += (float)reviews[i].Rating / num_found;
                }
            } else {
                snprintf(formatted_str, 100, "");
                free(reviews);
                return formatted_str;
            }

            
            snprintf(formatted_str, 50, "%.2f* (%d)", avg_rating, num_found);

            free(reviews);
            return formatted_str;

        }
            
        case 4:{

            ComparisonPair compare_pairs[] = {
                { compareByRentalBookISBN_AND_ReturnYearEqZero, item->ISBN},
            };

            int num_found = 0;
            Rental* rentals =  DB_select(RentalT, compare_pairs, sizeof(compare_pairs), &num_found);
            if (rentals == NULL)
                num_found = 0;

            free(rentals);

            if(item->numberOfCopies > num_found){
                return getTranslation("in_stock", activeUser.language);
            }


            return getTranslation("out_stock", activeUser.language);
              
        }
       
    }

}

char* getRentalInformation(Rental* item, int k)
{
    char* returnString = (char*)malloc(50 * sizeof(char));


    switch(k)
    {

        case 0:
        {
            ComparisonPair compare_pairs[] = {
                { compareByBookISBN, item->BookISBN }, 
            };

            int num_found;
            Book* found_books = DB_select(BookT, compare_pairs, sizeof(compare_pairs), &num_found);


            if (found_books != NULL) {
                snprintf(returnString, 50, "%s", found_books[0].Title);
                free(found_books);
                return returnString;
            } else {
                snprintf(returnString, 20, "Deleted Book");
                free(found_books);
                return returnString;
            }

        }
        case 1:
        {
            

            if (item->RentDate.mounth != 12)
                snprintf(returnString, 20, "%d.%d.%d.", item->RentDate.day, item->RentDate.mounth + 1, item->RentDate.year);
            else
                snprintf(returnString, 20, "%d.%d.%d.", item->RentDate.day, 1, item->RentDate.year + 1);

            return returnString;
        }
    }
}



void BrowseDisplay(int selected_index, ObjectDisplayTemplate printOne, ObjectDisplayTemplate printOneSelected, void* items, int size_of_item, int num_items, int column_width, int row_height, int wrappers_size){

    int books_per_row = windowWidth()/(column_width + 4);

    int max_books_to_show = books_per_row * ((windowHeight() - wrappers_size)/row_height);
    int start_from_index = max_books_to_show/books_per_row*(selected_index/max_books_to_show);

    // printf("execvuting");
    // printf("%s", ((Book**)items)[0]->ISBN);
    char* temp_text[35];
    int break_point = -1;
    for(int j = start_from_index; j < start_from_index + max_books_to_show / (books_per_row) ; j++){
        for(int k = 0; k < row_height-2; k++){
            for(int i = 0; i < books_per_row; i++){
                if(books_per_row*j + i == num_items) break_point = i;
                
                if(i != break_point){
                    if(books_per_row*j + i == selected_index){
                        printOneSelected(items + (books_per_row*j + i)*size_of_item, k, column_width);
                    } else if(books_per_row*j + i <= num_items){
                        printOne(items + (books_per_row*j + i)*size_of_item, k, column_width);
                    }
                }
            }
            printf("\n");
        }
        if(break_point >= 0 || j == start_from_index + max_books_to_show / (books_per_row)) return;
        printf("\n\n");
    }
}


// Keep in mind that row height includes seperators, so it will be larger by 2 if row ends with \n\n
void browseInitiate(ObjectDisplayTemplate printOne, ObjectDisplayTemplate printOneSelected, void* items, int size_of_item, int num_items, ObjectEnterMenu enter_function, int column_width, int row_height, PrintWrapper preWrapper, PrintWrapper postWrapper){
    char ch;
    int selected_index = 0;


    int columns;

    int wrappers_size = postWrapper() + preWrapper();

    while (ch != ESC)
    {
        clearScreen();

        columns = windowWidth()/(column_width + 4);

        preWrapper();
        printf("\n");

        BrowseDisplay(selected_index, printOne, printOneSelected, items, size_of_item, num_items, column_width, row_height, wrappers_size);

        postWrapper();

        ch = getKeyPressed();
        contorlSelectedIndex(ch, &selected_index, columns);

        selected_index = min(selected_index, num_items-1);
        selected_index = max(selected_index, 0);


        if(ch == ENTER) enter_function(items + selected_index*size_of_item);
    }
}

char* randomID(int len) {
    srand(time(NULL));
    const char ALLOWED[] = "abcdefghijklmnopqrstuvwxyz1234567890";
    char* random = (char*)malloc((len+1) * sizeof(char)); // Allocate memory for the string
    int i, c, nbAllowed = sizeof(ALLOWED) - 1;
    for (i = 0; i < len; i++) {
        c = rand() % nbAllowed;
        random[i] = ALLOWED[c];
    }
    random[len] = '\0';
    return random;
}
void printMainMenuItem(void* item, int k, int column_width){
    
    if(k == 1){
        printf(ANSI_B_COLOR_GRAY " %s%s%s" ANSI_COLOR_RESET "%s", fillTimesN(' ', (column_width - strlen((char*)item))/2), (char*)item, 
                fillTimesN(' ', column_width - (column_width - strlen((char*)item))/2 - strlen((char*)item)), fillTimesN(' ', 3));
    } else{
        printf(ANSI_B_COLOR_GRAY " %s" ANSI_COLOR_RESET "%s", 
                    fillTimesN(' ', column_width), fillTimesN(' ', 3));
    }
}

void printMainMenuItemSelected(void* item, int k, int column_width){
    
    if(k == 1){
        printf(ANSI_B_COLOR_RED " %s%s%s" ANSI_COLOR_RESET "%s", fillTimesN(' ', (column_width - strlen((char*)item))/2), (char*)item, 
                fillTimesN(' ', column_width - (column_width - strlen((char*)item))/2 - strlen((char*)item)), fillTimesN(' ', 3));
    } else{
        printf(ANSI_B_COLOR_RED " %s" ANSI_COLOR_RESET "%s", 
                    fillTimesN(' ', column_width), fillTimesN(' ', 3));
    }
}

void printRentalsItem(void* item, int k, int column_width){

    char* info = getRentalInformation((Rental*)item, k);
    printf(ANSI_B_COLOR_GRAY " %s%s" ANSI_COLOR_RESET "%s", info, 
            fillTimesN(' ', column_width - strlen(info)), fillTimesN(' ', 3));

    if(k == 1)
        free(info);
}

void printRentalsItemSelected(void* item, int k, int column_width){
    char* info = getRentalInformation((Rental*)item, k);
    printf(ANSI_B_COLOR_RED " %s%s" ANSI_COLOR_RESET "%s", info, 
            fillTimesN(' ', column_width - strlen(info)), fillTimesN(' ', 3));

    if(k == 1)
        free(info);
}

void mainMenuEnterFunc(void* item){
    
    char* op = (char*)item;

    switch(activeUser.Privilege)
    {
        case 0:
        {
            // admin

            if (strcmp(op, "BROWSE") == 0)
            {
                clearScreen();
                browse();
            }
            else if(strcmp(op, "SEARCH") == 0)
            {
                printf("searching...");
                // will call for search func when it is completed               
            }
            else if(strcmp(op, "LOG") == 0)
            {
               printf("loging...");
                // will call for log func when it is completed
            }
            else if (strcmp(op, "EDIT PROFILE") == 0)
            {
                printf("editing profile...");
                //will call for edit profile func for admin when it is completed
            }
            else if (strcmp(op, "ADD BOOK") == 0)
            {
                clearScreen();
                createBook(activeUser.language);
            }
            else if(strcmp(op, "LOG OUT") == 0)
            {
                clearScreen();
                landingPage();
            }
            else
            {
                printf("%s", getTranslation("error", activeUser.language));
            }
            
            break;
        }

        case 1:
        {
            // user

            if (strcmp(op, "BROWSE") == 0)
            {
                clearScreen();
                browse();
            }
            else if(strcmp(op, "SEARCH") == 0)
            {
                printf("searching....");
                //this will call for search fuc when it is completed
            }
            else if(strcmp(op, "MY RENTAL") == 0)
            {
                printf("my rentals....");
                
                myRentals();
            }
            else if(strcmp(op, "EDIT PROFILE") == 0)
            {
                printf("editing profile...");
                //this will call for edit profile func for user when it is completed
            }
            else if(strcmp(op, "LOG OUT") == 0)
            {
                landingPage();
            }
            else
            {
                printf("GRESKA!");
            }

            break;
        }

        default: 
        {
            printf("GRESKA SA KORISNIKOM!");
        }
    }
}

void rentalAllEnterFunc(void* item){
    Rental* r = (Rental*)item;

    ComparisonPair cp[] = {compareByBookISBN, r->BookISBN};
    int num_items;

    Book* results = DB_select(BookT, cp, sizeof(cp), &num_items);

    char* Title = results[0].Title;

    clearScreen();

    printf("%s\n", Title);


    printf("%s %d.%d.%d. \n", getTranslation("rtnt_on", activeUser.language), r->RentDate.day, r->RentDate.mounth, r->RentDate.year);
    printf("%s %d.%d.%d. \n", getTranslation("rnt_untl", activeUser.language), r->ReturnDate.day, r->ReturnDate.mounth, r->ReturnDate.year);
    
    printf("ID: %s\n", r->rentalID);

    pressEnter();
}

void rentalEnterFunc(void* item)
{
    Rental* r = (Rental*)item;

    ComparisonPair cp[] = {compareByBookISBN, r->BookISBN};
    int num_items;

    Book* results = DB_select(BookT, cp, sizeof(cp), &num_items);

    char* Title = results[0].Title;

    clearScreen();

    printf("%s\n", Title);


    printf("%s %d.%d.%d. \n", getTranslation("rtnt_on", activeUser.language), r->RentDate.day, r->RentDate.mounth, r->RentDate.year);
    printf("%s %d.%d.%d. \n", getTranslation("rnt_untl", activeUser.language), r->ReturnDate.day, r->ReturnDate.mounth, r->ReturnDate.year);
    
    printf("ID: %s\n", r->rentalID);

    int width = 30;

    if(activeUser.Privilege == 1){
        char *buttons[] = {"Return Rental", "Exit"};
        int selection = inlineOneButtonSelect(width, buttons, 2, (windowWidth()-2*width)/2, 3, 1, (windowHeight()-3)/2, wrapperEmpty, wrapperEmpty);

        switch(selection)
        {
            case 0:
            {
                returnBook(r->rentalID);
                mainPaige();

                break;

            }
            case 1:
            {
                clearScreen();
                

                myRentals();

                break;
            }
            default:
            {
                break;
            }
        }
    }
}


