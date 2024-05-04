#ifndef DB_SELECT_COMPARE_H_INCLUDED
#define DB_SELECT_COMPARE_H_INCLUDED

int compareByUserID(void* record, char* key);
int compareSelectEverything(void* record, char* key);
int compareByReviewBookISBN(void* record, char* key);
int compareByRentalBookISBN(void* record, char* key);
int compareByRentalReturnYearEqZero(void* record, char* key);
int compareByReviewUserID(void* record, char* key);

#endif /* DB_SELECT_COMPARE_H_INCLUDED */