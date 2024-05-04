#include <string.h>

#include "db_system.h"

// Return 0 if a match, 1 if not


int compareByUserID(void* record, char* key) {
    User* user = (User*)record;
    return strcmp(user->userID, key);
}

int compareByBookISBN(void* record, char* key)
{
    Book* book = (Book*)record;
    return strcmp(book->ISBN, key);
}

int compareSelectEverything(void* record, char* key){
    return 0;
}