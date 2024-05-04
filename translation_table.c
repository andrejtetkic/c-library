#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "translation_table.h"

Entry *hashTable[SIZE];

unsigned int hash(const char *key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }

    return value % SIZE;
}

void insert(char *key, ...) {
    unsigned int slot = hash(key);

    Entry *entry = hashTable[slot];

    if (entry == NULL) {
        entry = malloc(sizeof(Entry));
        entry->key = malloc(strlen(key) + 1);

        // Copy the key
        strcpy(entry->key, key);

        va_list args;
        va_start(args, key);

        // Copy translations for each language
        for (int i = 0; i < NUM_LANGUAGES; ++i) {
            char *translation = va_arg(args, char *);
            entry->translations[i] = malloc(strlen(translation) + 1);
            strcpy(entry->translations[i], translation);
        }

        va_end(args);

        hashTable[slot] = entry;
    }
}

char* getTranslation(char *key, int langIndex) {
    unsigned int slot = hash(key);

    Entry *entry = hashTable[slot];

    if (entry == NULL) {
        return NULL;
    }

    if (strcmp(entry->key, key) == 0) {
        return entry->translations[langIndex];
    }

    return NULL;
}

int initializeTranslationTable() {
    //      key    1st lan   2nd lan   ...
    insert("name", "First Name", "Ime");
    insert("lastname", "Last Name", "Prezime");
    insert("username", "Username", "Korisnicko Ime");
    insert("no_results", "No Results Found", "Nista nije pronadjeno :(");
    insert("title", "Naziv", "Title");
    insert("author", "Autor", "Author");
    insert("genre", "Zanr", "Genre");
    insert("genres", "Zanrovi", "Gneres");
    insert("tags", "Oznake", "Tags");
    insert("tag", "Oznaka", "Tag");
    insert("publ", "Izdavac", "Publisher");
    insert("publication_year", "Godina Izdavanja", "Publication Year");
    insert("number_of_copies", "Broj Izdanja", "Number Of Copies");
    insert("serial_name", "Serijsko Ime", "Serial Name");
    insert("serial_number", "Serijski Broj", "Serial Number");
    insert("num_pg", "Broj Stranica", "Number Of Pages");
    insert("new_book", "UNOS NOVE KNJIGE", "INSERT NEW BOOK");

    return 0;
}
