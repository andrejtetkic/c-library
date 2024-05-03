#ifndef DB_SYSTEM_H_INCLUDED
#define DB_SYSTEM_H_INCLUDED

enum Tables {
    BookT,
    BookRST,
    ReviewT,
    RentalT,
    UserT
};

typedef struct 
{
    int day;
    int mounth;
    int year;
}Date;



typedef struct book
{
    char ISBN[10];
    char Title[100];
    char Author[100];
    char Genre[10][100];
    char Tags[10][100];
    char Publisher[100];
    int PublicationYear;
    int numberOfCopies;
    int deleted;
    char SerialName[100];
    int SerialNumber;
    int NumberOfPages;
} Book;

typedef struct book_rs
{
    char ISBN[10];
    char Title[100];
    int deleted;
} BookRS;

typedef struct review
{
    char reviewID[10];
    char BookISBN[10];
    char UserId[10];
    char ReviewText[500];
    int Rating;
    int deleted;
} Review;

typedef struct rental
{
    char rentalID[10];
    char BookISBN[10];
    char UserId[10];
    Date RentDate;
    Date ReturnDate;
    int deleted;
} Rental;

typedef struct user
{
    char userID[10];
    char FirstName[100];
    char LastName[100];
    int language;
    char Email[100];
    char Username[100];
    char Password[100];
    int Privilege;
    int deleted;
} User;

User activeUser;

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