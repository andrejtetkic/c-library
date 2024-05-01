#ifndef TRANSLATION_TABLE_H_INCLUDED
#define TRANSLATION_TABLE_H_INCLUDED

#define SIZE 100
#define NUM_LANGUAGES 2 // Define the number of supported languages
#define RS_LANG 1
#define EN_LANG 0

typedef struct {
    char *key;
    char *translations[NUM_LANGUAGES]; // Store translations for multiple languages
} Entry;

int initializeTranslationTable();
char* getTranslation(char *key, int langIndex);

#endif /* TRANSLATION_TABLE_H_INCLUDED */