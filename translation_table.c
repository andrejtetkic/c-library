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
    insert("login", "Log In", "Uloguj se");
    insert("password", "Password", "Lozinka");
    insert("signup", "Sign Up", "Registruj se");
    insert("search", "Search", "Pretraga");

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
    insert("rntT", "Rent This", "Iznajmi");
    insert("rev", "Reviews", "Recenzije");
    insert("lev_rev", "Leave a Review", "Postavite Recenziju");
    insert("edit", "Edit", "Izmeni");
    insert("delete", "Delete", "Izbrisi");
    insert("review", "Review", "Oceni");
    insert("rating", "Rating", "Ocena");
    insert("detiles", "Share Details", "Podelite Detalje");
    insert("alr_rev", "You have Already left a Review on this Book", "Vec ste Ocenili ovu Knjigu");
    insert("error", "ERORR", "GRESKA");
    insert("del_conf", "ARE YOU SURE YOU WANT TO DELETE THIS BOOK", "DA LI STE SIGURNI DA ZELITE DA OBRISETE OVU KNJIGU");
    insert("del_suc", "BOOK DELETED SUCSECFULLY", "KNJIGA USPESNO OBRISANA");
    insert("upd_bk", "UPDATE BOOK", "AZURIRAJ KNJIGU");

    insert("genres", "Gneres", "Zanrovi");
    insert("tags", "Tags", "Tagovi");
    insert("tag", "Tag", "Tag");
    insert("publ", "Publisher", "Izdavac");
    insert("pub_yr", "Publication Year", "Godina Izdavanja");
    insert("num_cop", "Number Of Copies", "Broj Kopija");
    insert("ser_nam", "Serial Name", "Ime Serijala");
    insert("ser_num", "Serial Number", "Broj Knjige Serijala");
    insert("num_pag", "Number Of Pages", "Broj Stranica");
    insert("nw_book", "INSERT NEW BOOK", "UNOS NOVE KNJIGE");
    insert("rnt_err", "ERROR! CANNOT ACSEES RENTALS AS ADMIN", "GRESKA! NE MOZETE PRISTUPITI IZNAJMLJENIM KNJIGAMA KAO ADMIN");
    insert("rtnt_on", "Rented On", "Iznajmljeno");
    insert("rnt_untl", "Rented Until", "Iznajmljeno do");
    insert("rnt_msg", "REMINDER: You have rentals due in 4 days or less", "PODSETNIK: Imate iznajmljenja ciji rokovi isticu za 4 dana ili manje");
    insert("rnt_ms1", "WARNING: You have overdue rentals", "UPOZORENJE: Imate iznajmljivanja ciji je rok istekao");

    insert("edt_pr", "EDIT PROFILE", "IZMENITE PROFIL");
    insert("frs_nm", "First Name", "Prvo Ime");
    insert("language", "Language", "Jezik");
    insert("email", "Email", "Email");
    insert("usr_nm", "Username", "Korisnicko Ime");
    insert("psw", "Password", "Lozinka");
    insert("inval_isbn", "Book with this ISBN already exists, do you want to increase the number of copies in stock?(Y\\N)",
    "Knjiga sa ovim ISBN vec postoji, da li zelite da povecate broj dostupnih primeraka?(D\\N)");
    insert("hwmncp", "How many copies do you want to add", "Koliko primeraka zelite da dodate");
    insert("cnt_dl", "Cannot delete this book because it is currently rented by someone",
    "Ne mozete obrisati ovu knjigu jer je neko ternutno iznajmljuje");
    insert("acc", "Ascending", "Rastuci");
    insert("dec", "Descending", "Opadajuci");
    insert("ordby", "Order By", "Poredjaj Po");
    insert("ord", "Order", "Redosled");



    return 0;
}
