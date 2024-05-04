#ifndef INSERT_FUNCS_H_INCLUDED
#define INSERT_FUNCS_H_INCLUDED

#include"db_system.h"
#include"translation_table.h"

void insertTitle(Book* k, int language);
void insertAuthor(Book* k, int language);
void insertGenre(Book* k, int language);
void insertTags(Book* k, int language);
void insertPublisher(Book* k, int language);
void insertPublicationYear(Book* k, int language);
void insertNumberOfCopies(Book* k, int language);
void insertSerialName(Book* k, int language);
void insertSerialNumber(Book* k, int language);
void insertNumberOfPages(Book* k, int language);

#endif