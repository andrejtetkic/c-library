#ifndef MENU_UTILS_H_INCLUDED
#define MENU_UTILS_H_INCLUDED

typedef void (*ObjectDisplayTemplate)(void* item, int k, int column_width);
typedef void (*ObjectEnterMenu)(void* item);
typedef int (*PrintWrapper)(); // returns number of lines printed

#include "db_system.h"

int inlineOneButtonSelect(int button_width, char *buttons[], int numButtons, int left_spacing, int button_spacing, int is_3_line, int top_offset, PrintWrapper preWrapper, PrintWrapper postWrapper);
void fillInForm(char* buf);
void logInArt();
void welcomeArt();
char* getBookInformation(Book* item, int k);
char* getReviewInformation(Review* item, int k);
void browseInitiate(ObjectDisplayTemplate printOne, ObjectDisplayTemplate printOneSelected, void* items, int size_of_item, int num_items, ObjectEnterMenu enter_function, int column_width, int row_height, PrintWrapper preWrapper, PrintWrapper postWrapper);
char* randomID();

#endif /* MENU_UTILS_H_INCLUDED */