#ifndef MENU_UTILS_H_INCLUDED
#define MENU_UTILS_H_INCLUDED

typedef void (*ObjectDisplayTemplate)(void* item, int k, int column_width);
typedef void (*ObjectEnterMenu)(void* item);
typedef int (*PrintWrapper)(); // returns number of lines printed


int inlineOneButtonSelect(int button_width, char *buttons[], int numButtons, int left_spacing, int button_spacing, int is_3_line, int top_offset);
void fillInForm(char* buf);
void logInArt();
void browseInitiate(ObjectDisplayTemplate printOne, ObjectDisplayTemplate printOneSelected, void* items, int size_of_item, int num_items, ObjectEnterMenu enter_function, int column_width, int row_height, PrintWrapper preWrapper, PrintWrapper postWrapper);


#endif /* MENU_UTILS_H_INCLUDED */