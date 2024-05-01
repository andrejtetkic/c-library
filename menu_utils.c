#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#include "utilities.h"

void contorlSelectedIndex(int ch, int* selected_index){
    switch (ch)
        {
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

        contorlSelectedIndex(ch, &selected_index);

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