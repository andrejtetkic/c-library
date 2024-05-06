#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "db_system.h"

#define UP_ARROW 72 
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define ENTER 13
#define ESC 27
#define TAB 9


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_GRAY    "\x1b[90m"
#define ANSI_COLOR_BRIGHT_BLUE "\x1b[94m"
#define ANSI_COLOR_RESET   "\x1b[0m"


#define ANSI_B_COLOR_RED     "\x1b[41m"
#define ANSI_B_COLOR_GREEN   "\x1b[42m"
#define ANSI_B_COLOR_YELLOW  "\x1b[43m"
#define ANSI_B_COLOR_BLUE    "\x1b[44m"
#define ANSI_B_COLOR_MAGENTA "\x1b[45m"
#define ANSI_B_COLOR_CYAN    "\x1b[46m"
#define ANSI_B_COLOR_GRAY    "\x1b[100m"
#define ANSI_B_COLOR_RESET   "\x1b[0m"

int getKeyPressed();
void clearScreen();
void pressEnter();
const char* fillTimesN(char character, int len);
void fillInForm(char* buf);
int windowHeight();
int windowWidth();
int compareByRentalID(void* record, char* key);
void rentBook(Book* book);
int returnBook(char* rentalID);
void editUser();
void insertUserInfo(User* u, int language);


#endif /* UTILITIES_H_INCLUDED */