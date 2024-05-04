#ifndef DB_SELECT_COMPARE_H_INCLUDED
#define DB_SELECT_COMPARE_H_INCLUDED

int compareByUserID(void* record, char* key);
int compareByUsername(void* record, char* key);
int compareByPassword(void* record, char* key);
int compareSelectEverything(void* record, char* key);

#endif /* DB_SELECT_COMPARE_H_INCLUDED */