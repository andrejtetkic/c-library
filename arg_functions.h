#ifndef PAGE_MENUS_H_INCLUDED
#define PAGE_MENUS_H_INCLUDED

void printBookItem(void* item, int k, int column_width);
void printBookItemSelected(void* item, int k, int column_width);
void printButton(void* item, int k, int column_width);
void printButtonSelected(void* item, int k, int column_width);
void tempEnterFunc(void* item);
void tempMainScreenButtonSellectEnterFunc(void* item);
int wrapperEmpty();

#endif /* PAGE_MENUS_H_INCLUDED */