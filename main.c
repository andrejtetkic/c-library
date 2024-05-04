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
   landingPage();

    return 0;
}