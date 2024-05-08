#ifndef DB_SELECT_COMPARE_H_INCLUDED
#define DB_SELECT_COMPARE_H_INCLUDED

int compareByUserID(void* record, char* key);
int compareByRentalUserID(void* record, char* key);
int compareByBookISBN(void* record, char* key);
int compareByUsername(void* record, char* key);
int compareByPassword(void* record, char* key);
int compareSelectEverything(void* record, char* key);
int compareByReviewBookISBN(void* record, char* key);
int compareByRentalBookISBN(void* record, char* key);
int compareByRentalReturnYearEqZero(void* record, char* key);
int compareByReviewUserID(void* record, char* key);
int compareByReviewUserIDEqActiveUserID_AND_ReviewBookISBN(void* record, char* key);
int compareByRentalUserIdEqActiveUserId_AND_ReturnYearEqZero(void* record, char* key);
int compareByRentalBookISBN_AND_ReturnYearEqZero(void* record, char* key);
int compareByBookTitle(void* record, char* key);
int compareByBookAuthor(void* record, char* key);
int compareByBookTag(void* record, char* key);

#endif /* DB_SELECT_COMPARE_H_INCLUDED */