#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"db_system.h"
#include"book_funcs.h"
#include"translation_table.h"
#include"db_select_compare.h"
#include"inesrt_funcs.h"
#include"page_menus.h"

void createBook(int language)
{
    Book k;

    printf("-------%s-------\n", getTranslation("nw_book", language));
    
    

    fflush(stdin);

    printf("ISBN: ");
    gets(k.ISBN);

    if (checkValidId(k.ISBN) == 1)
    {
         insertBookInfo(&k, language);
        k.deleted = 0;

        DB_insert(BookT, &k);
        DB_insert(BookRST, &k);
    }
    else
    {
        printf("%s: ", getTranslation("inval_isbn", activeUser.language));

        char op;

        scanf("%c", &op);

        if (toupper(op) == 'Y' || toupper(op) == 'D')
        {
            int num_copies, n;

            printf("%s : ", getTranslation("hwmncp", activeUser.language));
            scanf("%d", &num_copies);

            ComparisonPair cp[] = {{compareByBookISBN, k.ISBN}};

             Book* b = (Book*)DB_select(BookT, cp, sizeof(cp), &n);
             b->numberOfCopies+=num_copies;

             mainPaige();
        }
        else
        {
            mainPaige();
        }
    }

    fflush(stdin);

}

void updateBook(Book* k, int langugage)
{
    printf("-------%s-------\n", getTranslation("upd_bk", langugage));

    insertBookInfo(k, langugage);

    DB_update(k->ISBN, BookT, k);
    DB_update(k->ISBN, BookRST, k);
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