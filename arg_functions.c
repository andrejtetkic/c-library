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
    char* info = getBookInformation((Book*)item, k);
    printf(ANSI_B_COLOR_GRAY " %s%s" ANSI_COLOR_RESET "%s", info, 
            fillTimesN(' ', column_width - strlen(info)), fillTimesN(' ', 3));
    if(k == 3) free(info);
}

void printBookItemSelected(void* item, int k, int column_width){
    char* info = getBookInformation((Book*)item, k);
    printf(ANSI_B_COLOR_RED " %s%s" ANSI_COLOR_RESET "%s", info, 
            fillTimesN(' ', column_width - strlen(info)), fillTimesN(' ', 3));

    if(k == 3) free(info);
}

void printRentedItem(void* item, int k, int column_width){
    char* info = getReviewInformation((Review*)item, k);
    printf(ANSI_B_COLOR_GRAY " %s%s" ANSI_COLOR_RESET "%s", info, 
            fillTimesN(' ', column_width - strlen(info)), fillTimesN(' ', 3));
    if(k == 0 || k == 1 || k == 3) free(info);
}

void printRentedItemSelected(void* item, int k, int column_width){
    char* info = getReviewInformation((Review*)item, k);
    printf(ANSI_B_COLOR_RED " %s%s" ANSI_COLOR_RESET "%s", info, 
            fillTimesN(' ', column_width - strlen(info)), fillTimesN(' ', 3));
    if(k == 0 || k == 1 || k == 3) free(info);
}

void getFullReview(void* item){
    Review* review = (Review*)item;

    clearScreen();
    printf("%d*\n", review->Rating);
    printf("%s", review->ReviewText);

    pressEnter();
}

void tempMainScreenButtonSellectEnterFunc(void* item){
    printf("selected button: %s", *(char*)item);
} 

int wrapperEmpty(){
    return 0;
}

int preWrapperOrderBy(){
    char* text = getTranslation("ordby", activeUser.language);
    printf("%s%s%s\n\n", fillTimesN(' ', (windowWidth() - strlen(text))/2), text, fillTimesN(' ', (windowWidth() - strlen(text))/2));
    return 2;
}

int preWrapperOrder(){
    char* text = getTranslation("ord", activeUser.language);
    printf("%s%s%s\n\n", fillTimesN(' ', (windowWidth() - strlen(text))/2), text, fillTimesN(' ', (windowWidth() - strlen(text))/2));
    return 2;
}
