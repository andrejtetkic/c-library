#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utilities.h"
#include "menu_utils.h"
#include "db_system.h"
#include "db_select_compare.h"
#include "translation_table.h"

void printBookItem(void* item, int k, int column_width){
    printf(ANSI_B_COLOR_GRAY " %s%s" ANSI_COLOR_RESET "%s", getBookInformation((Book*)item, k), 
            fillTimesN(' ', column_width - strlen(getBookInformation((Book*)item, k))), fillTimesN(' ', 3));
}

void printBookItemSelected(void* item, int k, int column_width){
    printf(ANSI_B_COLOR_RED " %s%s" ANSI_COLOR_RESET "%s", getBookInformation((Book*)item, k), 
            fillTimesN(' ', column_width - strlen(getBookInformation((Book*)item, k))), fillTimesN(' ', 3));
}



void tempEnterFunc(void* item){
    printf("selected item ISBN = %s", ((Book*)item)->ISBN);
    pressEnter();
}

int wrapperEmpty(){
    return 0;
}
