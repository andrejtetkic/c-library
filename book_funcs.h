#ifndef BOOK_FUNCS_H_INCLUDED
#define BOOK_FUNCS_H_INCLUDED

#include "db_system.h"
#include "translation_table.h"
#include "db_select_compare.h"
#include "inesrt_funcs.h"

void createBook(int language);
void insertBookInfo(Book* k, int langugae);
int checkValidId(char ID[10]);
void updateBook(Book* k, int language);

#endif 