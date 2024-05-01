#ifndef DB_SYSTEM_H_INCLUDED
#define DB_SYSTEM_H_INCLUDED

enum Tables {
    BookT,
    BookRST,
    ReviewT,
    RentalT,
    UserT
};


typedef struct book
{
    char ISBN[10];
    int deleted;
} Book;

typedef struct book_rs
{
    char ISBN[10];
    int deleted;
} BookRS;

typedef struct review
{
    char reviewID[10];
    int deleted;
} Review;

typedef struct rental
{
    char rentalID[10];
    int deleted;
} Rental;

typedef struct user
{
    char userID[10];
    char name[10];
    int deleted;
} User;



typedef int (*ComparisonCallback)(void* record, char* key);

typedef struct {
    ComparisonCallback compare_func;
    char* key;
} ComparisonPair;


void DB_insert(enum Tables table, void* ptr);
void DB_update(char* key, enum Tables table, void* ptr);
void DB_delete(char* key, enum Tables table);
void* DB_select(enum Tables table, ComparisonPair* compare_pairs, int comp_pair_size, int* num_found);



#endif /* DB_SYSTEM_H_INCLUDED */