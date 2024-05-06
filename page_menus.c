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
#include "book_funcs.h"

Book* active_book;

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

void currentRentals()
{
    ComparisonPair cp[] = {{compareByRentalUserIdEqActiveUserId_AND_ReturnYearEqZero, activeUser.userID}};

    int numSelected;

    Rental *rentals = DB_select(RentalT, cp, sizeof(cp), &numSelected);

    browseInitiate(printRentalsItem, printRentalsItemSelected, rentals, sizeof(Rental), numSelected, rentalEnterFunc, 40, 4 , myRentalsArt, wrapperEmpty);
}

void allTimeRentals()
{
    ComparisonPair cp[] = {{compareByRentalUserID, activeUser.userID}};

    int numSelected;

    Rental *rentals = DB_select(RentalT, cp, sizeof(cp), &numSelected);

    browseInitiate(printRentalsItem, printRentalsItemSelected, rentals, sizeof(Rental), numSelected, rentalAllEnterFunc, 40, 4 , myRentalsArt, wrapperEmpty);
}

void myRentals()
{
    if (activeUser.Privilege == 0)
    {
        printf("%s", getTranslation("rnt_err", activeUser.language));
    }

    else
    {
        clearScreen();

        int width = 30;

        char* buttons[] = {"Current Rentals", "All Time Rentals"};
        int selection = inlineOneButtonSelect(width, buttons, 2, (windowWidth()-2*width)/2, 3, 1, (windowHeight()-3)/2, wrapperEmpty, wrapperEmpty);

        switch (selection)
        {
        case 0:  
        {
            currentRentals();
        }
        case 1:
        {
            allTimeRentals();
        }
        default:
            break;
        }
    }
}

void mainPaigeUser()
{
    clearScreen();

    char options[5][35] = {"BROWSE", "SEARCH", "MY RENTAL", "EDIT PROFILE", "LOG OUT"};

    browseInitiate(printMainMenuItem, printMainMenuItemSelected, options, 35 * sizeof(char), 5, mainMenuEnterFunc, 40, 5, welcomeArt, returnRentalsMessage);
}
void mainPaigeAdmin()
{
    clearScreen();

    char options[6][35] = {"BROWSE", "SEARCH", "LOG", "EDIT PROFILE", "ADD BOOK", "LOG OUT"};

     browseInitiate(printMainMenuItem, printMainMenuItemSelected, options, 35 * sizeof(char), 6, mainMenuEnterFunc, 40, 5, welcomeArt, wrapperEmpty);
}
void mainPaige()
{
    if (activeUser.Privilege == 0)
        mainPaigeAdmin();
    else if (activeUser.Privilege == 1)
        mainPaigeUser();
    else{
        printf("%s\n", getTranslation("error", activeUser.language));
        landingPage();
    }

}

void delete(Book* k)
{
    clearScreen();

    int width = 30;

    printf("%s", getTranslation("del_conf", activeUser.language));    

    char *buttons[] = {"YES", "NO"};
    int selection = inlineOneButtonSelect(width, buttons, 2, (windowWidth()-2*width)/2, 3, 1, (windowHeight()-3)/2, wrapperEmpty, wrapperEmpty);

    switch (selection)
    {
    case 0:
    {
        DB_delete(k->ISBN, BookT);
        DB_delete(k->ISBN, BookRST);

        clearScreen();
        printf("%s", getTranslation("del_suc", activeUser.language));
        pressEnter();

        clearScreen();
        mainPaige();

        break;
    }
    case 1:
    {
        clearScreen();
        browse();

        break;

    }
    
    default:
        break;
    }    

}

void currentRentals()
{
    ComparisonPair cp[] = {{compareByRentalUserIdEqActiveUserId_AND_ReturnYearEqZero, activeUser.userID}};

    int numSelected;

    Rental *rentals = DB_select(RentalT, cp, sizeof(cp), &numSelected);

    browseInitiate(printRentalsItem, printRentalsItemSelected, rentals, sizeof(Rental), numSelected, rentalEnterFunc, 40, 4 , myRentalsArt, wrapperEmpty);
}

void allTimeRentals()
{
    ComparisonPair cp[] = {{compareByRentalUserID, activeUser.userID}};

    int numSelected;

    Rental *rentals = DB_select(RentalT, cp, sizeof(cp), &numSelected);

    browseInitiate(printRentalsItem, printRentalsItemSelected, rentals, sizeof(Rental), numSelected, rentalAllEnterFunc, 40, 4 , myRentalsArt, wrapperEmpty);
}

void myRentals()
{
    if (activeUser.Privilege == 0)
    {
        printf("%s", getTranslation("rnt_err", activeUser.language));
    }

    else
    {
        clearScreen();

        int width = 30;

        char* buttons[] = {"Current Rentals", "All Time Rentals"};
        int selection = inlineOneButtonSelect(width, buttons, 2, (windowWidth()-2*width)/2, 3, 1, (windowHeight()-3)/2, wrapperEmpty, wrapperEmpty);

        switch (selection)
        {
        case 0:  
        {
            currentRentals();
        }
        case 1:
        {
            allTimeRentals();
        }
        default:
            break;
        }
    }
}

void mainPaigeUser()
{
    clearScreen();

    char options[5][35] = {"BROWSE", "SEARCH", "MY RENTAL", "EDIT PROFILE", "LOG OUT"};

    browseInitiate(printMainMenuItem, printMainMenuItemSelected, options, 35 * sizeof(char), 5, mainMenuEnterFunc, 40, 5, welcomeArt, returnRentalsMessage);
}
void mainPaigeAdmin()
{
    clearScreen();

    char options[6][35] = {"BROWSE", "SEARCH", "LOG", "EDIT PROFILE", "ADD BOOK", "LOG OUT"};

     browseInitiate(printMainMenuItem, printMainMenuItemSelected, options, 35 * sizeof(char), 6, mainMenuEnterFunc, 40, 5, welcomeArt, wrapperEmpty);
}
void mainPaige()
{
    if (activeUser.Privilege == 0)
        mainPaigeAdmin();
    else if (activeUser.Privilege == 1)
        mainPaigeUser();
    else{
        printf("%s\n", getTranslation("error", activeUser.language));
        landingPage();
    }

}

void delete(Book* k)
{
    clearScreen();

    int width = 30;

    printf("%s", getTranslation("del_conf", activeUser.language));    

    char *buttons[] = {"YES", "NO"};
    int selection = inlineOneButtonSelect(width, buttons, 2, (windowWidth()-2*width)/2, 3, 1, (windowHeight()-3)/2, wrapperEmpty, wrapperEmpty);

    switch (selection)
    {
    case 0:
    {
        DB_delete(k->ISBN, BookT);
        DB_delete(k->ISBN, BookRST);

        clearScreen();
        printf("%s", getTranslation("del_suc", activeUser.language));
        pressEnter();

        clearScreen();
        mainPaige();

        break;
    }
    case 1:
    {
        clearScreen();
        browse();

        break;

    }
    
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

    mainPaige();
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
                { compareByRentalBookISBN_AND_ReturnYearEqZero, active_book->ISBN},
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
        case 1:{
            
            ComparisonPair compare_pairs[] = {
                { compareByRentalBookISBN_AND_ReturnYearEqZero, active_book->ISBN}, 
            };

            int num_found = 0;
            Rental* rentals =  DB_select(RentalT, compare_pairs, sizeof(compare_pairs), &num_found);
            if (rentals == NULL)
                num_found = 0; // to make sure it didnt change anything

            free(rentals);

            if(active_book->numberOfCopies > num_found){
                rentBook(item);
            } else{
                printf("%s", getTranslation("out_stock", activeUser.language));
                pressEnter();
            }
            break;
            }
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
                { compareByReviewUserIDEqActiveUserID_AND_ReviewBookISBN, active_book->ISBN}, 
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
            updateBook(active_book, activeUser.language);
            pressEnter();
            break;
        case 2:
            delete(active_book);
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



