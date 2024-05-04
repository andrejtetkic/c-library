#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "translation_table.h"
#include "page_menus.h"
#include "utilities.h"
#include "db_system.h"
#include "db_select_compare.h" 
#include "book_funcs.h"


int main(){

   initializeTranslationTable();

    // Book temp;

    // char buffer[20];

    // for(int i = 0; i<15; i++){
    //     itoa(i,buffer,10);

    //     strcpy(temp.ISBN, buffer);
    //     temp.deleted = 0;

    //     DB_insert(BookT, &temp);

     // }


   // pressEnter(); 

    int a = 1;
   
    createBook(a);

    return 0;
}