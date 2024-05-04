#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

#include "utilities.h"
#include "menu_utils.h"
#include "translation_table.h"

#include "db_system.h"
#include "db_select_compare.h"

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
}

int inlineOneButtonSelect(int button_width, char *buttons[], int numButtons, int left_spacing, int button_spacing, int is_3_line, int top_offset, PrintWrapper preWrapper, PrintWrapper postWrapper) {
    int ch = 0;
    int selected_index = 0;


    while (ch != ENTER) {
        printf("%s", fillTimesN('\n', top_offset));

        preWrapper();
        printf("\n");

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

        printf("\n");
        postWrapper();

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

void welcomeArt()
{
    printf("\t\t\t" "__          __   ______    _         _______   _______    _    _    ______\n");
    printf("\t\t\t" "\\ \\        / /  |  ____|  | |        | _____| | _____ |  | \\  / |  |  ____|\n");
    printf("\t\t\t" " \\ \\  /\\  / /   | |____   | |        | |      | |   | |  |  \\/  |  | |____\n");
    printf("\t\t\t" "  \\ \\/  \\/ /    |  ____|  | |        | |      | |   | |  | |\\/| |  |  ____|\n");
    printf("\t\t\t" "   \\  /\\  /     | |____   | |_____   | |____  | |___| |  | |  | |  | | ___\n");
    printf("\t\t\t" "    \\/  \\/      |______|  |_______|  |______| |_______|  |_|  |_|  |______|\n");
}


char* getReviewInformation(Review* item, int k){
    switch (k)
    {
        case 0:{
            ComparisonPair compare_pairs[] = {
                { compareByUserID, item->UserId }, 
            };

            int num_found = 0;
            User* user =  DB_select(UserT, compare_pairs, sizeof(compare_pairs), &num_found);
            char* formatted_str_user_name = (char*)malloc(50 * sizeof(char));


            if (user == NULL) {
                snprintf(formatted_str_user_name, 100, "Deleted User");
                return formatted_str_user_name;
            }

            snprintf(formatted_str_user_name, 100, "%s %s", user[0].FirstName, user[0].LastName);
            
            return formatted_str_user_name;
        }
        case 1:{
            char* formatted_str_rating = (char*)malloc(50 * sizeof(char));
            snprintf(formatted_str_rating, 50, "%d*", item->Rating);
            return formatted_str_rating;
        }
        
        case 2:
            return "";
        
        case 3:{
            char* target = (char*)malloc(50 * sizeof(char));

            if(strcmp(item->ReviewText, "") != 0){
                *target = '\0';
                strncat(target, item->ReviewText, 45);
                if(strlen(item->ReviewText) > 45) strcat(target, "...");
                return target;
            }
            snprintf(target, 100, "");
            return target;

        }
    }
}

char* getBookInformation(Book* item, int k){


    switch (k)
    {
        case 0:
            return item->Title;
        
        case 1:
            return "";
        
        case 2:
            return item->Author;
        
        case 3:{
            ComparisonPair compare_pairs[] = {
                { compareByReviewBookISBN, item->ISBN }, 
            };

            char* formatted_str = (char*)malloc(50 * sizeof(char));
            int num_found = 0;
            float avg_rating = 0;
            Review* reviews =  DB_select(ReviewT, compare_pairs, sizeof(compare_pairs), &num_found);

            if (reviews != NULL) {
                for (int i = 0; i < num_found; i++) {
                    avg_rating += (float)reviews[i].Rating / num_found;
                }
            } else {
                snprintf(formatted_str, 100, "");
                free(reviews);
                return formatted_str;
            }

            
            snprintf(formatted_str, 50, "%.2f* (%d)", avg_rating, num_found);

            free(reviews);
            return formatted_str;

        }
            
        case 4:{

            ComparisonPair compare_pairs[] = {
                { compareByRentalBookISBN, item->ISBN}, 
                { compareByRentalReturnYearEqZero, item->ISBN}, 
            };

            int num_found = 0;
            Rental* rentals =  DB_select(RentalT, compare_pairs, sizeof(compare_pairs), &num_found);
            if (rentals == NULL)
                num_found = 0;

            free(rentals);

            if(item->numberOfCopies > num_found){
                return getTranslation("in_stock", activeUser.language);
            }


            return getTranslation("out_stock", activeUser.language);
              
        }
       
    }

}



void BrowseDisplay(int selected_index, ObjectDisplayTemplate printOne, ObjectDisplayTemplate printOneSelected, void* items, int size_of_item, int num_items, int column_width, int row_height, int wrappers_size){

    int books_per_row = windowWidth()/(column_width + 4);

    int max_books_to_show = books_per_row * ((windowHeight() - wrappers_size)/row_height);
    int start_from_index = max_books_to_show/books_per_row*(selected_index/max_books_to_show);

    // printf("execvuting");
    // printf("%s", ((Book**)items)[0]->ISBN);
    char* temp_text[35];
    int break_point = -1;
    for(int j = start_from_index; j < start_from_index + max_books_to_show / (books_per_row) ; j++){
        for(int k = 0; k < row_height-2; k++){
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
void browseInitiate(ObjectDisplayTemplate printOne, ObjectDisplayTemplate printOneSelected, void* items, int size_of_item, int num_items, ObjectEnterMenu enter_function, int column_width, int row_height, PrintWrapper preWrapper, PrintWrapper postWrapper){
    char ch;
    int selected_index = 0;


    int columns;

    int wrappers_size = postWrapper() + preWrapper();

    while (ch != ESC)
    {
        clearScreen();

        columns = windowWidth()/(column_width + 4);

        preWrapper();
        printf("\n");

        BrowseDisplay(selected_index, printOne, printOneSelected, items, size_of_item, num_items, column_width, row_height, wrappers_size);

        postWrapper();

        ch = getKeyPressed();
        contorlSelectedIndex(ch, &selected_index, columns);

        selected_index = min(selected_index, num_items-1);
        selected_index = max(selected_index, 0);


        if(ch == ENTER) enter_function(items + selected_index*size_of_item);
    }
}

char* randomID(int len) {
    srand(time(NULL));
    const char ALLOWED[] = "abcdefghijklmnopqrstuvwxyz1234567890";
    char* random = (char*)malloc((len+1) * sizeof(char)); // Allocate memory for the string
    int i, c, nbAllowed = sizeof(ALLOWED) - 1;
    for (i = 0; i < len; i++) {
        c = rand() % nbAllowed;
        random[i] = ALLOWED[c];
    }
    random[len] = '\0';
    return random;
}