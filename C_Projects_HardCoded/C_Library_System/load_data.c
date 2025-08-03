#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "load_data.h"
#define MAX_LINE 256

void load_users(user users[], int *user_count, int *next_user, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open %s\n", filename);
        *user_count = 0;
        *next_user = 1;
        return;
    }

    char line[MAX_LINE];
    *user_count = 0;
    int max_id = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *name = strtok(line, ",");
        char *contact = strtok(NULL, ",");
        char *is_deleted = strtok(NULL, ",");

        if (name && contact && is_deleted) {
            if (*user_count < MAX_USERS) {
                strcpy(users[*user_count].name, name);
                strcpy(users[*user_count].contact, contact);
                users[*user_count].is_deleted = (strcmp(is_deleted, "1") == 0);
                users[*user_count].id = *user_count + 1;
                if (users[*user_count].id > max_id)
                    max_id = users[*user_count].id;
                (*user_count)++;
            } else {
                printf("User array full, skipping user: %s\n", name);
            }
        } else {
            printf("Invalid user entry skipped.\n");
        }
    }

    *next_user = max_id + 1;
    fclose(file);
}

void load_books(book books[], int *book_count, int *next_book, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open %s\n", filename);
        *book_count = 0;
        *next_book = 1;
        return;
    }
    char line[MAX_LINE];
    *book_count = 0;
    int max_id = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *title = strtok(line, ",");
        char *author = strtok(NULL, ",");
        char *available_copies = strtok(NULL, ",");
        char *is_deleted = strtok(NULL, ",");

        if (title && author && available_copies && is_deleted) {
            if (*book_count < MAX_BOOKS) {
                strcpy(books[*book_count].title, title);
                strcpy(books[*book_count].author, author);
                books[*book_count].available_copies = atoi(available_copies);
                books[*book_count].is_deleted = (strcmp(is_deleted, "1") == 0);
                books[*book_count].id = *book_count + 1;
                if (books[*book_count].id > max_id)
                    max_id = books[*book_count].id;
                (*book_count)++;
            } else {
                printf("Book array full, skipping book: %s\n", title);
            }
        } else {
            printf("Invalid book entry skipped.\n");
        }
    }
    *next_book = max_id + 1;
    fclose(file);
}