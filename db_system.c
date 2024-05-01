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



void DB_update(char* key, enum Tables table, void* ptr){
    FILE* fp = Open_File(table, "rb+");
    
    

    void* a_ptr;
    switch (table) {
        case BookT:
            a_ptr = (Book*)ptr;
            if(strcmp(((Book*)a_ptr)->ISBN, key) != 0){
                printf("Keys don't match!\n");
                fclose(fp);
                return;
            }

            Book tempBook;

            while(fread(&tempBook, sizeof(Book), 1, fp))
            {
                if(strcmp(tempBook.ISBN, key)==0){
                    fseek(fp, -sizeof(Book), SEEK_CUR);
                    fwrite(a_ptr, sizeof(Book), 1, fp);
                    break;
                }
            }

            break;

        case BookRST:
            a_ptr = (BookRS*)ptr;
            if(strcmp(((BookRS*)a_ptr)->ISBN, key) != 0){
                printf("Keys don't match!\n");
                fclose(fp);
                return;
            }

            BookRS tempBookRS;

            while(fread(&tempBookRS, sizeof(BookRS), 1, fp))
            {
                if(strcmp(tempBookRS.ISBN, key)==0){
                    fseek(fp, -sizeof(BookRS), SEEK_CUR);
                    fwrite(a_ptr, sizeof(BookRS), 1, fp);
                    break;
                }
            }

            break;
        
        case ReviewT:
            a_ptr = (Review*)ptr;
            if(strcmp(((Review*)a_ptr)->reviewID, key) != 0){
                printf("Keys don't match!\n");
                fclose(fp);
                return;
            }

            Review tempRoview;

            while(fread(&tempRoview, sizeof(Review), 1, fp))
            {
                if(strcmp(tempRoview.reviewID, key)==0){
                    fseek(fp, -sizeof(Review), SEEK_CUR);
                    fwrite(a_ptr, sizeof(Review), 1, fp);
                    break;
                }
            }

            break;

        case RentalT:
            a_ptr = (Rental*)ptr;
            if(strcmp(((Rental*)a_ptr)->rentalID, key) != 0){
                printf("Keys don't match!\n");
                fclose(fp);
                return;
            }

            Rental tempRental;

            while(fread(&tempRental, sizeof(Rental), 1, fp))
            {
                if(strcmp(tempRental.rentalID, key)==0){
                    fseek(fp, -sizeof(Rental), SEEK_CUR);
                    fwrite(a_ptr, sizeof(Rental), 1, fp);
                    break;
                }
            }

            break;

        case UserT:
            a_ptr = (User*)ptr;
            if(strcmp(((User*)a_ptr)->userID, key) != 0){
                printf("Keys don't match!\n");
                fclose(fp);
                return;
            }

            User tempUser;

            while(fread(&tempUser, sizeof(User), 1, fp))
            {
                if(strcmp(tempUser.userID, key)==0){
                    fseek(fp, -sizeof(User), SEEK_CUR);
                    fwrite(a_ptr, sizeof(User), 1, fp);
                    break;
                }
            }

            break;
        
        default:
            printf("Invalid table type\n");
            return;
    }

    fclose(fp);
}




void DB_delete(char* key, enum Tables table){
    FILE *fp = Open_File(table, "rb+");

    switch (table) {
        case BookT:
            Book tempBook;

            strcpy(tempBook.ISBN, key);
            tempBook.deleted = 1;

            DB_update(key, table, &tempBook);
            break;

        case BookRST:
            BookRS tempBookRS;

            strcpy(tempBookRS.ISBN, key);
            tempBookRS.deleted = 1;

            DB_update(key, table, &tempBookRS);
            break;
        
        case ReviewT:
            Review tempReview;

            strcpy(tempReview.reviewID, key);
            tempReview.deleted = 1;

            DB_update(key, table, &tempReview);
            break;

        case RentalT:
            Rental tempRental;

            strcpy(tempRental.rentalID, key);
            tempRental.deleted = 1;

            DB_update(key, table, &tempRental);
            break;

        case UserT:
            User tempUser;

            strcpy(tempUser.userID, key);
            tempUser.deleted = 1;

            DB_update(key, table, &tempUser);
            break;
        
        default:
            printf("Invalid table type\n");
            return;
    }

}