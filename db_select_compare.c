#include <string.h>
#include <stdlib.h>
#include "db_system.h"
#include "utilities.h"

// Return 0 if a match, 1 if not


int compareByUserID(void* record, char* key) {
    User* user = (User*)record;
    return strcmp(user->userID, key);
}
int compareByRentalUserID(void* record, char* key)
{
    Rental* rental = (Rental*)record;
    return strcmp(rental->UserId, key);
}


int compareByBookISBN(void* record, char* key)
{
    Book* book = (Book*)record;
    return strcmp(book->ISBN, key);
}

int compareByUsername(void* record, char* key) {
    User* user = (User*)record;
    return strcmp(user->Username, key);
}

int compareByPassword(void* record, char* key) {
    User* user = (User*)record;
    return strcmp(user->Password, key);
}

int compareSelectEverything(void* record, char* key){
    return 0;
}

int compareByReviewBookISBN(void* record, char* key){
    Review* review = (Review*)record;
    return strcmp(review->BookISBN, key);
}

int compareByRentalBookISBN(void* record, char* key){
    Rental* rental = (Rental*)record;
    return strcmp(rental->BookISBN, key);
}

int compareByRentalReturnYearEqZero(void* record, char* key){
    Rental* rental = (Rental*)record;
    return rental->RentDate.year != 0;
}

int compareByReviewUserID(void* record, char* key){
    Review* review = (Review*)record;
    return strcmp(review->UserId, key);
}

int compareByReviewUserIDEqActiveUserID_AND_ReviewBookISBN(void* record, char* key) {
    Review* review = (Review*)record;
    return !((!strcmp(review->UserId, activeUser.userID)) && (!strcmp(review->BookISBN, key)));
}
int compareByRentalUserIdEqActiveUserId_AND_ReturnYearEqZero(void* record, char* key)
{
    Rental* rental = (Rental*)record;
    return!((!strcmp(rental->UserId, activeUser.userID)) && !(rental->ReturnDate.year != 0));
}

int compareByRentalBookISBN_AND_ReturnYearEqZero(void* record, char* key){
    Rental* rental = (Rental*)record;    
    return !(!(strcmp(rental->BookISBN, key)) && rental->ReturnDate.year == 0);
}

int compareByBookTitle(void* record, char* key){
    Book* book = (Book*)record;

    char* record_lower = toLowercaseCopy(book->Title);
    char* key_lower = toLowercaseCopy(key);
    
    if(strstr(record_lower, key_lower) != NULL){
        free(record_lower);
        free(key_lower);
        return 0;
    }
    free(record_lower);
    free(key_lower);
    return 1;
}

int compareByBookAuthor(void* record, char* key){
    Book* book = (Book*)record;
    
    char* record_lower = toLowercaseCopy(book->Author);
    char* key_lower = toLowercaseCopy(key);
    
    if(strstr(record_lower, key_lower) != NULL){
        free(record_lower);
        free(key_lower);
        return 0;
    }
    free(record_lower);
    free(key_lower);
    return 1;
}

int compareByBookTag(void* record, char* key){
    Book* book = (Book*)record;
    char* key_lower = toLowercaseCopy(key);
    
    for(int i = 0; i < 10; i++){    
        char* record_lower = toLowercaseCopy(book->Tags[i]);
        if(strstr(record_lower, key_lower) != NULL){
            free(record_lower);
            free(key_lower);
            return 0;
        }
        free(record_lower);

        
    }
    
    free(key_lower);
    return 1;
}