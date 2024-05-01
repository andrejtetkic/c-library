#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

int getKeyPressed(){
    int ch, n;
    ch = _getch();

    if (ch == 0 || ch == 224)
        ch = _getch ();

    return ch;
}


void clearScreen(){
    system("cls");
}

void pressEnter(){
    char str_ex[100];
    printf("\n\n\nPress Enter to continue");

    fflush(stdin);
    scanf("%[^\n]", str_ex);
}


const char* fillTimesN(char character, int len) {
    char* result = (char*)malloc(len + 1);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < len; ++i){
        result[i] = character; // Fill with spaces
    }

    result[i] = '\0';


    return result;
}


int windowHeight(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;
    ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
    if(!ret) return 0;

    return csbi.dwSize.Y;
}

int windowWidth(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;
    ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);
    if(!ret) return 0;

    return csbi.dwSize.X;
}