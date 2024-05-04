#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"db_system.h"
#include"book_funcs.h"
#include"translation_table.h"
#include"db_select_compare.h"
#include"inesrt_funcs.h"

void createBook(int language)
{
   Book k;

    printf("-------%s-------\n", getTranslation("nw_book", language));
    
    do{

        fflush(stdin);

        printf("ISBN: ");
        gets(k.ISBN);

    }  while(checkValidId(k.ISBN) == 0); 

    insertBookInfo(&k, language);

    DB_insert(BookT, k.ISBN);
    DB_insert(BookRST, k.ISBN);

}


void insertBookInfo(Book* k, int language)
{
    insertTitle(k, language);
    insertAuthor(k, language);
    insertGenre(k, language);
    insertTags(k, language);
    insertPublisher(k, language);
    insertPublicationYear(k, language);
    insertNumberOfCopies(k, language);
    insertSerialName(k, language);
    insertSerialNumber(k, language);
    insertNumberOfPages(k, language);
} /// inserts all info except for id, can be used for updating also

int checkValidId(char ID[10])
{
    ComparisonPair cp[] = {{compareByBookISBN, ID}};

    int numFound;
    Book* booksFound;

    booksFound = DB_select(BookT, cp, sizeof(cp), &numFound);

    if (numFound == 0)
        return 1;

    return 0;
}