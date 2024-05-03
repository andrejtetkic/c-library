#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "translation_table.h"
#include "page_menus.h"
#include "utilities.h"
#include "db_system.h"
#include "db_select_compare.h"


int main(){
    initializeTranslationTable();

   landingPage();

    // Book temp;
    // Review temp;
    // Rental temp;

    // char buffer[20];

    // for(int i = 0; i<15; i++){
    //     itoa(i,buffer,10);

        // strcpy(temp.ISBN, "74125");
        // // temp.Rating = 3;
        // strcpy(temp.Title, "Ne Karenjina");
        // strcpy(temp.Author, "Lav moj");
        // strcpy(temp.Genre[0], "Zanr1");
        // strcpy(temp.Genre[1], "Zanr2");
        // strcpy(temp.Publisher, "Laguna");
        // strcpy(temp.SerialName, "Template");
        // strcpy(temp.Tags[0], "Tag1");
        // temp.numberOfCopies = 1;
        // temp.deleted = 0;
        // temp.ReturnDate.year = 0;

        // DB_insert(BookT, &temp);
    // }

    pressEnter();
    return 0;
}