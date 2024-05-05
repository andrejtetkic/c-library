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
void SignUp();
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
        SignUp();
        break;
    
    default:
        break;
    }
    
}

 void SignUp(){
    // Enter first name
    clearScreen();
    SignUpArt();
    
    int firstName_len = 34;
    printf("\t\t\t| " ANSI_COLOR_GRAY "First name%s" ANSI_COLOR_RESET "|%s", 
        fillTimesN(' ', firstName_len - 9), fillTimesN('\b', firstName_len) );
    
    char firstName[200] = {0};
    fillInForm(firstName);
    DB_insert(UserT, &firstName);

    // Enter last name
    clearScreen();
    SignUpArt();
    
    int lastName_len = 34;
    printf("\t\t\t| " ANSI_COLOR_GRAY "Last name%s" ANSI_COLOR_RESET "|%s", 
        fillTimesN(' ', lastName_len - 9), fillTimesN('\b', lastName_len) );
    
    char lastName[200] = {0};
    fillInForm(lastName);

    // Enter Username

    clearScreen();
    SignUpArt();
    
    int username_len = 34;
    printf("\t\t\t| " ANSI_COLOR_GRAY "Username%s" ANSI_COLOR_RESET "|%s", 
        fillTimesN(' ', username_len - 9), fillTimesN('\b', username_len) );
    
    char username[200] = {0};
    fillInForm(username);

    // Enter Password

    clearScreen();
    SignUpArt();

    printf("\t\t\t| %s%s|\n", username,
        fillTimesN(' ', username_len - strlen(username) - 1));
    printf("\t\t\t| " ANSI_COLOR_GRAY "Password%s" ANSI_COLOR_RESET "|%s",
        fillTimesN(' ', username_len - 9), fillTimesN('\b', username_len) );

    char password[200] = {0};
    fillInForm(password);

    // Enter Password Again

    clearScreen();
    SignUpArt();

    printf("\t\t\t| %s%s|\n", username,
        fillTimesN(' ', username_len - strlen(username) - 1));

    printf("\t\t\t| %s%s|\n", password,
        fillTimesN(' ', username_len - strlen(password) - 1));

    printf("\t\t\t| " ANSI_COLOR_GRAY "Password%s" ANSI_COLOR_RESET "|%s", 
        fillTimesN(' ', username_len - 9), fillTimesN('\b', username_len) );

    char password2[200] = {0};
    fillInForm(password2);

    // Check if passwords match

    if(strcmp(password, password2) != 0){
        clearScreen();
        SignUpArt();
        printf("\t\t\t| %s%s|\n", username,
            fillTimesN(' ', username_len - strlen(username) - 1));
        printf("\t\t\t| %s%s|\n", password,
            fillTimesN(' ', username_len - strlen(password) - 1));
        printf("\t\t\t| %s%s|\n", password2,
            fillTimesN(' ', username_len - strlen(password2) - 1));
        printf("\t\t\t| " ANSI_COLOR_RED "Passwords do not match%s" ANSI_COLOR_RESET "|%s", 
            fillTimesN(' ', username_len - 20), fillTimesN('\b', username_len) );
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
    strcpy(temp.userID, "123456");
    strcpy(temp.Username, "N123456");
    temp.language = 1;

    ComparisonPair compare_pairs[] = {
         { compareByUsername, "123456" }, 
         { compareByPassword, "N123456" },
         /* { compareBySomeField, "some_value" } */
     };

     int num_found;
     User* found_users = DB_select(UserT, compare_pairs, sizeof(compare_pairs), &num_found);
     if (found_users != NULL) {
         printf("Found %d user(s):\n", num_found);
         for (int i = 0; i < num_found; i++) {
             printf("User ID: %s\n", found_users[i].userID);
         }
         free(found_users);
     } else {
         printf("No matching records found.\n");
     }


    activeUser = temp;

    // this will later call mainmenu function
    //for testing purpuses calling browse
     browse(); 
}





void browse(){

    ComparisonPair compare_pairs[] = {
        { compareSelectEverything, "" }, 
    };

    int num_found;
    Book* found_books = DB_select(BookT, compare_pairs, sizeof(compare_pairs), &num_found);

    if (found_books != NULL) {
        browseInitiate(printBookItem, printBookItemSelected, found_books, sizeof(Book), num_found, tempEnterFunc, 35, 7, wrapperEmpty, wrapperEmpty);
    } else {
        printf("%s\n", getTranslation("no_results", activeUser.language));
    }

    free(found_books);

}