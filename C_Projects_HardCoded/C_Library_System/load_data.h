#ifndef LOAD_DATA_H
#define LOAD_DATA_H
#include "types.h"

void load_users(user users[], int *user_count, int *next_user, const char *filename);
void load_books(book books[], int *book_count, int *next_book, const char *filename);
#endif