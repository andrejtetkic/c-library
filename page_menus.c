#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utilities.h"
#include "menu_utils.h"
#include "db_system.h"
#include "db_select_compare.h"
#include "translation_table.h"
#include "arg_functions.h"

Book* active_book;

void logIn();
void browse();

void landingPage(){
    clearScreen();

    int width = 30;

    char *buttons[] = {"Log In", "Sign Up"};
    int selection = inlineOneButtonSelect(width, buttons, 2, (windowWidth()-2*width)/2, 3, 1, (windowHeight()-3)/2, wrapperEmpty, wrapperEmpty);

    switch (selection)
    {
    case 0:
        // TODO
        logIn();
        break;
    
    case 1:
        // TODO
        printf("SignIn Screen");
        break;
    
    default:
        break;
    }
    
}


void logIn(){
    //
    // Moras centrirati ovaj input i ASCII art. Imas slicno uradjeno u landingPage func


    // Enter Username

    clearScreen();
    logInArt();
    
    int username_len = 34;
    printf("\t\t\t| " ANSI_COLOR_GRAY "Username%s" ANSI_COLOR_RESET "|%s", 
        fillTimesN(' ', username_len - 9), fillTimesN('\b', username_len) );
    
    char username[200] = {0};
    fillInForm(username);

    // Enter Password

    clearScreen();
    logInArt();

    printf("\t\t\t| %s%s|\n", username,
        fillTimesN(' ', username_len - strlen(username) - 1));

    printf("\t\t\t| " ANSI_COLOR_GRAY "Password%s" ANSI_COLOR_RESET "|%s", 
        fillTimesN(' ', username_len - 9), fillTimesN('\b', username_len) );

    char password[200] = {0};
    fillInForm(password);

    // set active user
    User temp;
    strcpy(temp.userID, "3574");
    strcpy(temp.FirstName, "Dimitrije");
    strcpy(temp.LastName, "Sakan");

    temp.language = EN_LANG;
    temp.Privilege = 1;
    activeUser = temp;

    // this will later call mainmenu function
    //for testing purpuses calling browse
    browse();
}

int bookViewInformation(){

    clearScreen();

    printf("%s: %s\n", getTranslation("title", activeUser.language), active_book->Title);
    printf("%s: %s\n", getTranslation("author", activeUser.language), active_book->Author);
    if(strcmp(active_book->SerialName, "") != 0)
        printf("%s: %s, %s %d\n", getTranslation("series", activeUser.language), active_book->SerialName, getTranslation("book_num", activeUser.language), active_book->SerialNumber);
    
    if(active_book->NumberOfPages != 0)
        printf("%s: %d\n", getTranslation("pages", activeUser.language), active_book->NumberOfPages);

    if(strcmp(active_book->Genre[0], "") != 0) printf("%s: ", getTranslation("genre", activeUser.language));
    for(int i = 0; i < 10; i++){
        if(strcmp(active_book->Genre[i], "") == 0) break;

        printf("%s, ", active_book->Genre[i]);
    }
    printf("\n");

    if(strcmp(active_book->Tags[0], "") != 0) printf("%s: ", getTranslation("tags", activeUser.language));
    for(int i = 0; i < 10; i++){
        if(strcmp(active_book->Tags[i], "") == 0) break;

        printf("%s, ", active_book->Tags[i]);
    }
    printf("\n");

    printf("%s %s %s %d\n", getTranslation("published", activeUser.language), active_book->Publisher, getTranslation("in", activeUser.language), active_book->PublicationYear);
    printf("ISBN: %s\n", active_book->ISBN);

    printf("\n\n");

    ComparisonPair compare_pairs[] = {
                { compareByRentalBookISBN, active_book->ISBN}, 
                { compareByRentalReturnYearEqZero, active_book->ISBN}, 
            };

    int num_found = 0;
    Rental* rentals =  DB_select(RentalT, compare_pairs, sizeof(compare_pairs), &num_found);
    if (rentals == NULL)
        num_found = 0; // to make sure it didnt change anything

    free(rentals);

    if(active_book->numberOfCopies > num_found){
        printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, getTranslation("in_stock", activeUser.language));
    } else
        printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, getTranslation("out_stock", activeUser.language));

    printf("\n\n");
}

void bookView(void* item){
    active_book = item;

    int width = 24;
    int selection;

    char *buttonsUser[] = {getTranslation("back_br", activeUser.language), getTranslation("rentT", activeUser.language), getTranslation("rev", activeUser.language), getTranslation("lev_rev", activeUser.language)};
    char *buttonsAdmin[] = {getTranslation("back_br", activeUser.language), getTranslation("edit", activeUser.language), getTranslation("delete", activeUser.language)};


    if(activeUser.Privilege == 1){
        selection = inlineOneButtonSelect(width, buttonsUser, 4, (windowWidth()-4*width - 4*3)/2, 3, 1, (windowHeight()-3)/2, bookViewInformation, wrapperEmpty);

        switch (selection)
        {
        case 0:
            break;
        case 1:
            clearScreen();
            printf("Renting This");
            pressEnter();
            break;
        case 2: {
            clearScreen();
            

            ComparisonPair compare_pairs[] = {
                { compareByReviewBookISBN, active_book->ISBN }, 
            };
                    
            int num_found;
            Review* found_reviews = DB_select(ReviewT, compare_pairs, sizeof(compare_pairs), &num_found);


            if (found_reviews != NULL) {
                browseInitiate(printRentedItem, printRentedItemSelected, found_reviews, sizeof(Review), num_found, getFullReview, 50, 6, wrapperEmpty, wrapperEmpty);
            } else {
                printf("%s\n", getTranslation("no_results", activeUser.language));
                pressEnter();
            }

            break;
        }
        case 3:
            clearScreen();

            ComparisonPair compare_pairs[] = {
                { compareByReviewUserID, activeUser.userID}, 
            };
                    
            int num_found;
            Review* found_reviews = DB_select(ReviewT, compare_pairs, sizeof(compare_pairs), &num_found);

            if(num_found > 0){
                printf("%s", getTranslation("alr_rev", activeUser.language));
                pressEnter();
                break;
            }

            printf("-------- %s %s --------\n\n", getTranslation("review", activeUser.language), active_book->Title);

            char temp_str[50];
            Review temp;
            temp.Rating = 0;
            do
            {
                fflush(stdin);
                printf("%s:  *\b\b", getTranslation("rating", activeUser.language));
                scanf("%[0-9]", &temp_str);
                temp.Rating = atoi(temp_str);
            } while (temp.Rating < 1 || temp.Rating > 5);

            fflush(stdin);
            printf("\n%s: \n", getTranslation("detiles", activeUser.language));
            scanf("%[^\n]", &temp.ReviewText);

            strcpy(temp.BookISBN, active_book->ISBN);
            temp.deleted = 0;
            strcpy(temp.UserId, activeUser.userID);

            char* ran_id = randomID(9);
            strcpy(temp.reviewID, ran_id);

            DB_insert(ReviewT, &temp);
            
            free(ran_id);
            pressEnter();
            break;
        default:
            break;
        }

    } else if (activeUser.Privilege == 0)
    {
        selection = inlineOneButtonSelect(width, buttonsAdmin, 3, (windowWidth()-3*width - 3*3)/2, 3, 1, (windowHeight()-3)/2, bookViewInformation, wrapperEmpty);

        switch (selection)
        {
        case 0:
            break;
        case 1:
            clearScreen();
            printf("Editing");
            pressEnter();
            break;
        case 2:
            clearScreen();
            printf("Deleting");
            pressEnter();
            break;
        default:
            break;
        }

    }
    

}

void browse(){

    ComparisonPair compare_pairs[] = {
        { compareSelectEverything, "" }, 
    };

    int num_found;
    Book* found_books = DB_select(BookT, compare_pairs, sizeof(compare_pairs), &num_found);

    if (found_books != NULL) {
        browseInitiate(printBookItem, printBookItemSelected, found_books, sizeof(Book), num_found, bookView, 35, 7, wrapperEmpty, wrapperEmpty);
    } else {
        printf("%s\n", getTranslation("no_results", activeUser.language));
    }

    free(found_books);

}

void mainPaigeUser()
{

   /* char *buttons[] = {"Browse", "Search", "MyRental", "Profile"};

    // problem with browse intiate

    browseInitiate(printButton, printButtonSelected, buttons, sizeof(char) * 10, 4, tempMainScreenButtonSellectEnterFunc, 35, 7, wrapperEmpty, wrapperEmpty);

    */
}


