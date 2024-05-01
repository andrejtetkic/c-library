#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "translation_table.h"
#include "page_menus.h"
#include "utilities.h"
#include "db_system.h"
#include "db_select_compare.h"


int main(){
    // initializeTranslationTable();

    // landingPage();

//    User temp;

//     strcpy(temp.userID, "12345");
//    strcpy(temp.name, "Name123");

//     DB_insert(UserT, &temp);

   // DB_update("123545", UserT, &temp);

    ComparisonPair compare_pairs[] = {
        { compareByUserID, "123" }, 
       // { compareByUserID, "12345" },
        // { compareBySomeField, "some_value" }
    };

    int num_found;
    User* found_users = DB_select(UserT, compare_pairs, sizeof(compare_pairs), &num_found);

    if (found_users != NULL) {
        printf("Found %d user(s):\n", num_found);
        for (int i = 0; i < num_found; i++) {
            printf("User ID: %s\n", found_users[i].userID);
        }
        free(found_users);
    } else {
        printf("No matching records found.\n");
    }

    pressEnter();
    return 0;
}