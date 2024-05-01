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
    int t;
} Book;

typedef struct book_rs
{
    int t;
} BookRS;

typedef struct review
{
    int t;
} Review;

typedef struct rental
{
    int t;
} Rental;

typedef struct user
{
    int t;
} User;



void DB_insert(enum Tables table, void* ptr);



#endif /* DB_SYSTEM_H_INCLUDED */