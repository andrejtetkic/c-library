#include <stdio.h>
#include <stdlib.h>

#include "translation_table.h"
#include "page_menus.h"
#include "utilities.h"


int main(){
    initializeTranslationTable();

    landingPage();

    pressEnter();
    return 0;
}