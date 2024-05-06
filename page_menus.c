#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "utilities.h"
#include "menu_utils.h"
#include "db_system.h"
#include "db_select_compare.h"
#include "translation_table.h"
#include "arg_functions.h"

#define HASH_SIZE 65
#define HASH_SIZE 65 // SHA-256 produces a 64-character hash plus '\0'
#define SALT_SIZE 16 // Size of the salt (in bytes)

void logIn();
void browse();
void SignUp();
void postWrap();

/* void generate_salt(char *salt) {
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = 0; i < SALT_SIZE; i++) {
        salt[i] = rand() % 256; // Generate a random byte
    }
} */

void hash_password(const char *password, char *hashed_password) {
    // Concatenate password and salt
    char hashed[HASH_SIZE];
    strcpy(hashed, password);


    // Simple hash function (example only, not cryptographically secure)
    unsigned long hash = 5381;
    int c;

    char *ptr = hashed;
    while ((c = *ptr++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    // Convert the hash to a hexadecimal string
    sprintf(hashed_password, "%lx", hash);
}
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
    int num_found;
    char salt[4] = {0};
    char password[200] = {0};
    char password2[200] = {0};
    char firstName[200] = {0};
    char lastName[200] = {0};
    char email[200] = {0};
    char username[200] = {0};
    int language;
    do{
    clearScreen();
    SignUpArt();
    
    int firstName_len = 34;
    printf("\t\t\t| " ANSI_COLOR_GRAY "First name%s" ANSI_COLOR_RESET "|%s", 
    fillTimesN(' ', firstName_len - 11), fillTimesN('\b', firstName_len) );
    
    
    fillInForm(firstName);
    

    // Enter last name
    clearScreen();
    SignUpArt();
    
    int lastName_len = 34;
    printf("\t\t\t| %s%s|\n", firstName,
        fillTimesN(' ', firstName_len - strlen(firstName) - 1));
    printf("\t\t\t| " ANSI_COLOR_GRAY "Last name%s" ANSI_COLOR_RESET "|%s", 
        fillTimesN(' ', lastName_len - 10), fillTimesN('\b', lastName_len) );
    
    
    fillInForm(lastName);

    // Enter email
    clearScreen();
    SignUpArt();
    
    int email_len = 34;
    printf("\t\t\t| %s%s|\n", firstName,
        fillTimesN(' ', firstName_len - strlen(firstName) - 1));
    printf("\t\t\t| %s%s|\n", lastName,
        fillTimesN(' ', lastName_len - strlen(lastName) - 1));
    printf("\t\t\t| " ANSI_COLOR_GRAY "Email%s" ANSI_COLOR_RESET "|%s", 
        fillTimesN(' ', email_len - 7), fillTimesN('\b', email_len) );
    fillInForm(email);

    //Enter language
    
    int width = 10;
    printf("\t\t\t| %s%s|\n", firstName,
        fillTimesN(' ', firstName_len - strlen(firstName) - 1));
    printf("\t\t\t| %s%s|\n", lastName,
        fillTimesN(' ', lastName_len - strlen(lastName) - 1));
    printf("\t\t\t| %s%s|\n", email,
        fillTimesN(' ', email_len - strlen(email) - 1));
    char *buttons[] = {"English", "Srpski"};
    int selection = inlineOneButtonSelect(width, buttons, 2, (windowWidth()-2*width)/2, 3, 1, (windowHeight()-3)/2, wrapperEmpty, wrapperEmpty);
    language = selection;
    // Enter Username

    clearScreen();
    SignUpArt();
    
    int username_len = 34;
    printf("\t\t\t| %s%s|\n", firstName,
        fillTimesN(' ', firstName_len - strlen(firstName) - 1));
    printf("\t\t\t| %s%s|\n", lastName,
        fillTimesN(' ', lastName_len - strlen(lastName) - 1));
    printf("\t\t\t| %s%s|\n", email,
        fillTimesN(' ', email_len - strlen(email) - 1));
    printf("\t\t\t| %s%s|\n", buttons[language],
        fillTimesN(' ', firstName_len - strlen(buttons[language]) - 1));
    printf("\t\t\t| " ANSI_COLOR_GRAY "Username%s" ANSI_COLOR_RESET "|%s", 
        fillTimesN(' ', username_len - 9), fillTimesN('\b', username_len) );
    
    fillInForm(username);

    // Enter Password

    clearScreen();
    SignUpArt();

    printf("\t\t\t| %s%s|\n", firstName,
        fillTimesN(' ', firstName_len - strlen(firstName) - 1));
    printf("\t\t\t| %s%s|\n", lastName,
        fillTimesN(' ', lastName_len - strlen(lastName) - 1));
    printf("\t\t\t| %s%s|\n", email,
        fillTimesN(' ', email_len - strlen(email) - 1));
    printf("\t\t\t| %s%s|\n", buttons[language],
        fillTimesN(' ', firstName_len - strlen(buttons[language]) - 1));
    printf("\t\t\t| %s%s|\n", username,
        fillTimesN(' ', username_len - strlen(username) - 1));
    printf("\t\t\t| " ANSI_COLOR_GRAY "Password%s" ANSI_COLOR_RESET "|%s",
        fillTimesN(' ', username_len - 9), fillTimesN('\b', username_len) );

    fillInForm(password);
    

    // Check if passwords match
    

    do{
        clearScreen();
        SignUpArt();
        
        printf("\t\t\t| %s%s|\n", firstName,
        fillTimesN(' ', firstName_len - strlen(firstName) - 1));
        printf("\t\t\t| %s%s|\n", lastName,
            fillTimesN(' ', lastName_len - strlen(lastName) - 1));
        printf("\t\t\t| %s%s|\n", email,
            fillTimesN(' ', email_len - strlen(email) - 1));
        printf("\t\t\t| %s%s|\n", buttons[language],
            fillTimesN(' ', firstName_len - strlen(buttons[language]) - 1));
        printf("\t\t\t| %s%s|\n", username,
            fillTimesN(' ', username_len - strlen(username) - 1));
        printf("\t\t\t| %s%s|\n", password,
            fillTimesN(' ', username_len - strlen(password) - 1));
        printf("\t\t\t| " ANSI_COLOR_GRAY "Password again%s" ANSI_COLOR_RESET "|%s",
            fillTimesN(' ', username_len - 15), fillTimesN('\b', username_len));
        fillInForm(password2);
    }while (strcmp(password, password2) != 0);

    memset(password2, 0, strlen(password2));
    hash_password(password, password);
    
    ComparisonPair compare_pairs[] = {
         { compareByUsername, username }, 
         /* { compareBySomeField, "some_value" } */
     };

     
     User* found_users = DB_select(UserT, compare_pairs, sizeof(compare_pairs), &num_found);
     if (found_users != NULL) {
             printf("Username already taken\n");
         free(found_users);
     }
    }while(num_found > 0);
    User signedUser;
    strcpy(signedUser.Email, email);
    strcpy(signedUser.FirstName, firstName);
    strcpy(signedUser.LastName, lastName);
    strcpy(signedUser.Username, username);
    strcpy(signedUser.Password, password);
    signedUser.language = language;
    signedUser.Privilege = 0;
    DB_insert(UserT, &signedUser);
    
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

    ComparisonPair compare_pairs[] = {
         { compareByUsername, username }, 
         { compareByPassword, password },
         /* { compareBySomeField, "some_value" } */
     };

     int num_found;
     User* found_users = DB_select(UserT, compare_pairs, sizeof(compare_pairs), &num_found);
     if (found_users != NULL) {
         activeUser = found_users[0];
         free(found_users);
     } else {
         printf("No matching records found.\n");
     }

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