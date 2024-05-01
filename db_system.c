#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db_system.h"

FILE* Open_File(enum Tables table, char type[10]){
    FILE *fp;

    char path[30];

    switch (table) {
        case BookT:
            strcpy(path, "database/book.tb");
            break;

        case BookRST:
            strcpy(path, "database/book_rs.tb");
            break;
        
        case ReviewT:
            strcpy(path, "database/review.tb");
            break;

        case RentalT:
            strcpy(path, "database/rental.tb");
            break;

        case UserT:
            strcpy(path, "database/user.tb");
            break;
        
        default:
            printf("Invalid table type\n");
            return NULL;
    }

    if((fp = fopen(path, type)) == NULL){
        printf("Error opening file!\n");
        return NULL;
    }
    return fp;
}



// int DB_select(char JMBG_Q[20], char name_Q[100], char surname_Q[100], Patient out[100]){
//     FILE *fp = Open_File("rb");
//     Patient temp;


//     int n = 0;
//     while(fread(&temp, sizeof(Patient), 1, fp))
//     {
//         if((strcmp(JMBG_Q, temp.JMBG)==0 ||strcmp(JMBG_Q, "")==0)  &&
//         (strcmp(name_Q, temp.Ime)==0 || strcmp(name_Q, "")==0) && 
//         (strcmp(surname_Q, temp.Prezime)==0 || strcmp(surname_Q, "")==0) &&
//         temp.deleted == 0){
//             out[n] = temp;
//             n++;
//         }
//     }

//     fclose(fp);

//     return n;
// }

void DB_insert(enum Tables table, void* ptr){
    FILE* fp = Open_File(table, "ab");

    void* a_ptr;
    switch (table) {
        case BookT:
            a_ptr = (Book*)ptr;
            fwrite(ptr, sizeof(Book), 1, fp);
            break;

        case BookRST:
            a_ptr = (BookRS*)ptr;
            fwrite(a_ptr, sizeof(BookRS), 1, fp);
            break;
        
        case ReviewT:
            a_ptr = (Review*)ptr;
            fwrite(a_ptr, sizeof(Review), 1, fp);
            break;

        case RentalT:
            a_ptr = (Rental*)ptr;
            fwrite(a_ptr, sizeof(Rental), 1, fp);
            break;

        case UserT:
            a_ptr = (User*)ptr;
            fwrite(a_ptr, sizeof(User), 1, fp);
            break;
        
        default:
            printf("Invalid table type\n");
            return;
    }

    fclose(fp);

}



// void DB_update(char jmbg[20], Patient *new_patient){
//     FILE *fp = Open_File("rb+");
//     if(strcmp(new_patient->JMBG, jmbg) != 0){
//         printf("JMBGs don't match!\n");
//         fclose(fp);
//         return;
//     }




//     Patient temp;

//     while(fread(&temp, sizeof(Patient), 1, fp))
//     {
//         if(strcmp(temp.JMBG, jmbg)==0){
//             fseek(fp, -sizeof(Patient), SEEK_CUR);
//             fwrite(new_patient, sizeof(Patient), 1, fp);
//             break;
//         }
//     }
    
//     fclose(fp);
// }


// void DB_delete(char jmbg[20]){
//     FILE *fp = Open_File("rb+");


//     Patient temp;
//     strcpy(temp.JMBG, jmbg);
//     temp.deleted = 1;

//     DB_update(jmbg, &temp);

// }