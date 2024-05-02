#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#include "utilities.h"
#include "menu_utils.h"

#include "db_system.h"

void contorlSelectedIndex(int ch, int* selected_index, int columns){
    switch (ch)
    {
    case UP_ARROW:
        (*selected_index) -= columns;
        break;
    case DOWN_ARROW:
        (*selected_index) += columns;
        break; 
    case LEFT_ARROW:
        (*selected_index)--;
        break;
    case RIGHT_ARROW:
        (*selected_index)++;
        break;
    case TAB:
        (*selected_index)++;
        break;
    
    default:
        break;
    }
    printf("%d", *selected_index);
}

int inlineOneButtonSelect(int button_width, char *buttons[], int numButtons, int left_spacing, int button_spacing, int is_3_line, int top_offset) {
    int ch = 0;
    int selected_index = 0;


    while (ch != ENTER) {
        printf("%s", fillTimesN('\n', top_offset));


        if(is_3_line==1){
            for (int i = 0; i < numButtons; i++) {
                int factor = 1  ? (i == 0) : 0;
                if(i == selected_index){
                    printf("%s" ANSI_B_COLOR_GREEN "%s" ANSI_COLOR_RESET "%s", 
                        fillTimesN(' ', left_spacing*factor), fillTimesN(' ', button_width), fillTimesN(' ', button_spacing));
                } else {
                    printf("%s" ANSI_B_COLOR_GRAY "%s" ANSI_COLOR_RESET "%s", 
                        fillTimesN(' ', left_spacing*factor), fillTimesN(' ', button_width), fillTimesN(' ', button_spacing));
                }
                
            }
            printf("\n");
        }

        

        for (int i = 0; i < numButtons; i++) {
            int factor = 1  ? (i == 0) : 0;
            if(i == selected_index){
                printf("%s" ANSI_B_COLOR_GREEN "%s%s%s" ANSI_COLOR_RESET "%s",
                    fillTimesN(' ', left_spacing*factor), fillTimesN(' ', (button_width - strlen(buttons[i])) / 2), buttons[i],
                    fillTimesN(' ', button_width - (button_width - strlen(buttons[i]))/2 - strlen(buttons[i])), fillTimesN(' ', button_spacing));
            } else{
                printf("%s" ANSI_B_COLOR_GRAY "%s%s%s" ANSI_COLOR_RESET "%s",
                    fillTimesN(' ', left_spacing*factor), fillTimesN(' ', (button_width - strlen(buttons[i])) / 2), buttons[i],
                    fillTimesN(' ', button_width - (button_width - strlen(buttons[i]))/2 - strlen(buttons[i])), fillTimesN(' ', button_spacing));
            }
        }

        
        
        if(is_3_line==1){
            printf("\n");
            for (int i = 0; i < numButtons; i++) {
                int factor = 1  ? (i == 0) : 0;
                if(i == selected_index){
                    printf("%s" ANSI_B_COLOR_GREEN "%s" ANSI_COLOR_RESET "%s", 
                        fillTimesN(' ', left_spacing*factor), fillTimesN(' ', button_width), fillTimesN(' ', button_spacing));
                } else {
                    printf("%s" ANSI_B_COLOR_GRAY "%s" ANSI_COLOR_RESET "%s", 
                        fillTimesN(' ', left_spacing*factor), fillTimesN(' ', button_width), fillTimesN(' ', button_spacing));
                }
                
            }
        }


        ch = getKeyPressed();

        contorlSelectedIndex(ch, &selected_index, numButtons);

        selected_index = fmin(selected_index, numButtons-1);
        selected_index = fmax(0, selected_index);

        clearScreen();


    }

    return selected_index;
}



void clearline() {
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("                            ");
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
}

void fillInForm(char* buf){
    int index = 0;
    int ch;

    while((ch = getchar()) != EOF && ch != '\n') {

        if(ch == '\b' && index != 0) buf[--index] = 0;
        
        buf[index++] = ch;
        
        clearline();
        fflush(stdout);
    }
}

void logInArt(){
    printf("\n\n\n");
    printf("\t\t\t" ANSI_COLOR_BRIGHT_BLUE " _      ___    ___        ___  _  _ \n");
    printf("\t\t\t" "| |    / _ \\  / __|      |_ _|| \\| |\n");
    printf("\t\t\t" "| |__ | (_) || (_ |       | | | .  |\n");
    printf("\t\t\t" "|____| \\___/  \\___|      |___||_|\\_|\n\n" ANSI_COLOR_RESET);


    
}



void BrowseDisplay(int selected_index, ObjectDisplayTemplate printOne, ObjectDisplayTemplate printOneSelected, void* items, int size_of_item, int num_items, int column_width, int row_height){

    int books_per_row = windowWidth()/(column_width + 4);

    int max_books_to_show = books_per_row * (windowHeight()/row_height);
    int start_from_index = max_books_to_show/books_per_row*(selected_index/max_books_to_show);

    // printf("execvuting");
    // printf("%s", ((Book**)items)[0]->ISBN);
    char* temp_text[35];
    int break_point = -1;
    for(int j = start_from_index; j < start_from_index + max_books_to_show / (books_per_row) ; j++){
        for(int k = 0; k < 5; k++){
            for(int i = 0; i < books_per_row; i++){
                if(books_per_row*j + i == num_items) break_point = i;
                
                if(i != break_point){
                    if(books_per_row*j + i == selected_index){
                        printOneSelected(items + (books_per_row*j + i)*size_of_item, k, column_width);
                    } else if(books_per_row*j + i <= num_items){
                        printOne(items + (books_per_row*j + i)*size_of_item, k, column_width);
                    }
                }
            }
            printf("\n");
        }
        if(break_point >= 0 || j == start_from_index + max_books_to_show / (books_per_row)) return;
        printf("\n\n");
    }
}


// Keep in mind that row height includes seperators, so it will be larger by 2 if row ends with \n\n
void browseInitiate(ObjectDisplayTemplate printOne, ObjectDisplayTemplate printOneSelected, void* items, int size_of_item, int num_items, ObjectEnterMenu enter_function, int column_width, int row_height){
    char ch;
    int selected_index = 0;


    int columns;

    while (ch != ESC)
    {
        columns = windowWidth()/(column_width + 4);

        
        BrowseDisplay(selected_index, printOne, printOneSelected, items, size_of_item, num_items, column_width, row_height);

        ch = getKeyPressed();
        contorlSelectedIndex(ch, &selected_index, columns);

        selected_index = min(selected_index, num_items-1);
        selected_index = max(selected_index, 0);

        clearScreen();

        if(ch == ENTER) enter_function(items + selected_index*size_of_item);
    }
}