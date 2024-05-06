#ifndef INSERT_FUNCS_H_INCLUDED
#define INSERT_FUNCS_H_INCLUDED

#include"db_system.h"
#include"translation_table.h"

/// for inserting book info
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

///for inserting user info

void insertUserFirstName(User* u, int language);
void insertUserLastName(User* u, int langugage);
void insertUserLanguga(User* u, int language);
void insertUserEmail(User* u, int language);
void insertUserUsername(User* u, int langugage);
void insertUserPassword(User* u, int langugage);

#endif