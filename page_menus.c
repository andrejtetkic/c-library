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

void logIn();
void browse();

void landingPage(){
    clearScreen();

    int width = 30;

    char *buttons[] = {"Log In", "Sign Up"};
    int selection = inlineOneButtonSelect(width, buttons, 2, (windowWidth()-2*width)/2, 3, 1, (windowHeight()-3)/2);

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
    strcpy(temp.userID, "123456");
    strcpy(temp.name, "N123456");
    temp.language = 1;

    activeUser = temp;

    // this will later call mainmenu function
    //for testing purpuses calling browse
    browse();
}






char* getBookInformation(Book* item, int k){

    char* naziv[35];
    char* autor[35];
    char* dostupnost[35];

    *naziv = "Naziv Knjige i biblioteka";
    *autor = "R. R. Martin";
    *dostupnost = "Na Stanju";


    switch (k)
    {
    case 0:
        return item->ISBN;
    
    case 1:
        return "";
    
    case 2:
        return *autor;
    
    case 3:
        return "4.32* (7)";
    case 4:
        return *dostupnost;
    }

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