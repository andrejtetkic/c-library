#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"inesrt_funcs.h"
#include"db_system.h"
#include"translation_table.h"

void insertTitle(Book* k, int language)
{
    fflush(stdin);

   do{
        printf("%s: ", getTranslation("title", language));
        gets(k->Title);
   }while(strcmp(k->Title, "") == 0);

    fflush(stdin);
}

void insertAuthor(Book* k, int language)
{
    fflush(stdin);

    do{
        printf("%s: ", getTranslation("author", language));
        gets(k->Author);
    }while(strcmp(k->Author, "") == 0);

    fflush(stdin);

}

void insertGenre(Book* k, int language)
{
    fflush(stdin);

    printf("%s: \n", getTranslation("genres", language));

   int userFinishedInput = 0;

   for (int i = 0; i < 10; i ++)
   {

        if (userFinishedInput == 0)
        {
            printf(" %s %d: ", getTranslation("genre", language), i + 1);
            gets(k->Genre[i]);
        }

        if (strcmp(k->Genre[i], "") == 0)
            userFinishedInput = 1;

        if (userFinishedInput == 1)
            strcpy(k->Genre[i], "");

        fflush(stdin);
   }

    fflush(stdin);
}

void insertTags(Book* k, int language)
{
    fflush(stdin);

   printf("%s: \n", getTranslation("tags", language));

   int userFinishedInput = 0;

   for (int i = 0; i < 10; i ++)
   {

        if (userFinishedInput == 0)
        {
            printf("%s %d: ", getTranslation("tag", language), i + 1);
            gets(k->Tags[i]);
        }

        if (strcmp(k->Tags[i], "") == 0)
            userFinishedInput = 1;

        if (userFinishedInput == 1)
            strcpy(k->Tags[i], "");

        fflush(stdin);
   }

   fflush(stdin);
}

void insertPublisher(Book* k, int language)
{
    fflush(stdin);

    do{
        printf("%s: ", getTranslation("publ", language));
        gets(k->Publisher);
    }while(strcmp(k->Publisher, "") == 0);

    fflush(stdin);
}


void insertPublicationYear(Book* k, int language)
{
    fflush(stdin);

    char temp_str[100];

    do
    {
        k->PublicationYear = 0;
        printf("%s: ", getTranslation("publication_year", language));
        fflush(stdin);
        scanf("%[0-9]", &temp_str);

        k->PublicationYear = atoi(temp_str);

    } while (k->PublicationYear < 0 || k->PublicationYear > 2024);

    fflush(stdin);
}

void insertNumberOfCopies(Book* k, int language)
{
    fflush(stdin);

    char temp_str[100];

    do
    {
        k->numberOfCopies = 0;
        printf("%s: ", getTranslation("num_copies", language));
        fflush(stdin);
        scanf("%[0-9]", &temp_str);

        k->numberOfCopies = atoi(temp_str);

    } while (k->numberOfCopies < 0);
    
    fflush(stdin);
}

void insertSerialName(Book* k, int language)
{
    fflush(stdin);

    printf("%s: ", getTranslation("ser_name", language));
    gets(k->SerialName);

    fflush(stdin);
}

void insertSerialNumber(Book* k, int language)
{
    if (strcmp(k->SerialName, "") == 0)
    {
        return;
    }
    else
    {
    fflush(stdin);

    char temp_str[10];

    do
    {
        k->SerialNumber = 0;
        printf("%s: ", getTranslation("serial_number", language));
        fflush(stdin);
        scanf("%[0-9]", &temp_str);

        k->SerialNumber = atoi(temp_str);

    } while (k->SerialNumber < 0);

    fflush(stdin);
    }
}

void insertNumberOfPages(Book* k, int language)
{
    fflush(stdin);

    char temp_str[100];

    do
    {
        k->NumberOfPages = 0;
        printf("%s: ", getTranslation("num_pg", language));
        fflush(stdin);
        scanf("%[0-9]", &temp_str);

        k->NumberOfPages = atoi(temp_str);

    } while (k->NumberOfPages < 0);
    
    fflush(stdin);
}
