#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "translation_table.h"
#include "page_menus.h"
#include "utilities.h"
#include "db_system.h"


int main(){
    // initializeTranslationTable();

    // landingPage();

    User temp;

    strcpy(temp.userID, "123545");
    strcpy(temp.name, "Name 123");

    //DB_insert(UserT, &temp);

    DB_update("123545", UserT, &temp);

    pressEnter();
    return 0;
}