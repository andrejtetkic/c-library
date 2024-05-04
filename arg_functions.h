#ifndef PAGE_MENUS_H_INCLUDED
#define PAGE_MENUS_H_INCLUDED

void printBookItem(void* item, int k, int column_width);
void printBookItemSelected(void* item, int k, int column_width);
void tempMainScreenButtonSellectEnterFunc(void* item);
int wrapperEmpty();
void printRentedItem(void* item, int k, int column_width);
void printRentedItemSelected(void* item, int k, int column_width);
void getFullReview(void* item);

#endif /* PAGE_MENUS_H_INCLUDED */