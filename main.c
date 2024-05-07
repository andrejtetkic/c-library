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

    current_date.day = 14;
    current_date.mounth = 4;
    current_date.year = 2023;
    null_date.day = 0;
    null_date.mounth = 0;
    null_date.year = 0;


    activeUser.Privilege = 1;

    landingPage();

    return 0;
}