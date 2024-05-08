#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db_system.h"
#include "db_select_compare.h"

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


void* DB_select(enum Tables table, ComparisonPair* compare_pairs, int comp_pair_size, int* num_found) {
    // Example Usage:
    // ComparisonPair compare_pairs[] = {
    //     { compareByUserID, "123" }, 
    //    // { compareByUserID, "12345" },
    //     // { compareBySomeField, "some_value" }
    // };

    // int num_found;
    // User* found_users = DB_select(UserT, compare_pairs, sizeof(compare_pairs), &num_found);

    // if (found_users != NULL) {
    //     printf("Found %d user(s):\n", num_found);
    //     for (int i = 0; i < num_found; i++) {
    //         printf("User ID: %s\n", found_users[i].userID);
    //     }
    //     free(found_users);
    // } else {
    //     printf("No matching records found.\n");
    // }

    FILE* fp = Open_File(table, "rb");
    int num_pairs = comp_pair_size / sizeof(ComparisonPair);

    void* found_records = NULL;
    int found_count = 0;

    switch (table) {
        case BookT: {
            Book tempBook;
            while (fread(&tempBook, sizeof(Book), 1, fp) == 1) {
                for (int i = 0; i < num_pairs; i++) {
                    if (compare_pairs[i].compare_func(&tempBook, compare_pairs[i].key) == 0 
                                                        && tempBook.deleted != 1) {

                        found_records = realloc(found_records, (found_count + 1) * sizeof(Book));
                        if (found_records == NULL) {
                            printf("Failed to allocate memory");
                            fclose(fp);
                            return NULL;
                        }
                        // Copy the found record to the array
                        memcpy((Book*)found_records + found_count, &tempBook, sizeof(Book));
                        found_count++;
                        break;
                        
                    }
                }
            }
            break;
        }

        case BookRST: {
            BookRS tempBookRS;
            while (fread(&tempBookRS, sizeof(BookRS), 1, fp) == 1) {
                for (int i = 0; i < num_pairs; i++) {
                    if (compare_pairs[i].compare_func(&tempBookRS, compare_pairs[i].key) == 0 
                                                        && tempBookRS.deleted != 1) {

                        found_records = realloc(found_records, (found_count + 1) * sizeof(BookRS));
                        if (found_records == NULL) {
                            printf("Failed to allocate memory");
                            fclose(fp);
                            return NULL;
                        }
                        // Copy the found record to the array
                        memcpy((BookRS*)found_records + found_count, &tempBookRS, sizeof(BookRS));
                        found_count++;
                        
                        break;
                    }
                }
            }
            break;
        }
        
        case ReviewT:{
            Review tempReview;
            while (fread(&tempReview, sizeof(Review), 1, fp) == 1) {
                for (int i = 0; i < num_pairs; i++) {
                    if (compare_pairs[i].compare_func(&tempReview, compare_pairs[i].key) == 0 
                                                        && tempReview.deleted != 1) {

                        found_records = realloc(found_records, (found_count + 1) * sizeof(Review));
                        if (found_records == NULL) {
                            printf("Failed to allocate memory");
                            fclose(fp);
                            return NULL;
                        }
                        // Copy the found record to the array
                        memcpy((Review*)found_records + found_count, &tempReview, sizeof(Review));
                        found_count++;
                        
                        break;
                    }
                }
            }
            break;
        }

        case RentalT: {
            Rental tempRental;
            while (fread(&tempRental, sizeof(Rental), 1, fp) == 1) {
                for (int i = 0; i < num_pairs; i++) {
                    if (compare_pairs[i].compare_func(&tempRental, compare_pairs[i].key) == 0 
                                                        && tempRental.deleted != 1) {

                        found_records = realloc(found_records, (found_count + 1) * sizeof(Rental));
                        if (found_records == NULL) {
                            printf("Failed to allocate memory");
                            fclose(fp);
                            return NULL;
                        }
                        // Copy the found record to the array
                        memcpy((Rental*)found_records + found_count, &tempRental, sizeof(Rental));
                        found_count++;
                        
                        break;
                    }
                }
            }
            break;
        }

        case UserT: {
            User tempUser;
            while (fread(&tempUser, sizeof(User), 1, fp) == 1) {
                for (int i = 0; i < num_pairs; i++) {
                    if (compare_pairs[i].compare_func(&tempUser, compare_pairs[i].key) == 0 
                                                        && tempUser.deleted != 1) {

                        found_records = realloc(found_records, (found_count + 1) * sizeof(User));
                        if (found_records == NULL) {
                            printf("Failed to allocate memory");
                            fclose(fp);
                            return NULL;
                        }
                        // Copy the found record to the array
                        memcpy((User*)found_records + found_count, &tempUser, sizeof(User));
                        found_count++;
                        
                        break;
                    }
                }
            }
            break;
        }

        default:
            printf("Invalid table type\n");
            break;
    }


    fclose(fp);

    *num_found = found_count;

    return found_records;
}


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

    Book tempBook;            
    BookRS tempBookRS;
    Review tempReview;
    Rental tempRental;
    User tempUser;



    switch (table) {
        case BookT:

            strcpy(tempBook.ISBN, key);
            tempBook.deleted = 1;

            DB_update(key, table, &tempBook);
            break;

        case BookRST:

            strcpy(tempBookRS.ISBN, key);
            tempBookRS.deleted = 1;

            DB_update(key, table, &tempBookRS);
            break;
        
        case ReviewT:

            strcpy(tempReview.reviewID, key);
            tempReview.deleted = 1;

            DB_update(key, table, &tempReview);
            break;

        case RentalT:

            strcpy(tempRental.rentalID, key);
            tempRental.deleted = 1;

            DB_update(key, table, &tempRental);
            break;

        case UserT:

            strcpy(tempUser.userID, key);
            tempUser.deleted = 1;

            DB_update(key, table, &tempUser);
            break;
        
        default:
            printf("Invalid table type\n");
            return;
    }

}