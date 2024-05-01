#include <stdio.h>
#include <stdlib.h>

#include "translation_table.h"
#include "page_menus.h"
#include "utilities.h"
#include "db_system.h"


int main(){
    // initializeTranslationTable();

    // landingPage();

    User temp;

    temp.t = 5;
    DB_insert(UserT, &temp);

    pressEnter();
    return 0;
}