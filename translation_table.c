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
    insert("in_stock", "In Stock", "Na Stanju");
    insert("out_stock", "Out of Stock", "Nije na Stanju");
    insert("title", "Title", "Naziv");
    insert("author", "Author", "Autor");
    insert("series", "Series", "Serijal");
    insert("book_num", "book number", "knjiga broj");
    insert("pages", "Number of Pages", "Broj Stranica");
    insert("genre", "Genre", "Zanr");
    insert("tags", "Tags", "Tagovi");
    insert("published", "Published by", "Objavio");
    insert("in", "in", "");
    insert("back_br", "Back to Browsing", "Nazad na Pregledanje");
    insert("rentT", "Rent This", "Iznajmi");
    insert("rev", "Reviews", "Recenzije");
    insert("lev_rev", "Leave a Review", "Postavite Recenziju");
    insert("edit", "Edit", "Izmeni");
    insert("delete", "Delete", "Izbrisi");
    insert("review", "Review", "Oceni");
    insert("rating", "Rating", "Ocena");
    insert("detiles", "Share Details", "Podelite Detalje");
    insert("alr_rev", "You have Already left a Review on this Book", "Vec ste Ocenili ovu Knjigu");



    return 0;
}
