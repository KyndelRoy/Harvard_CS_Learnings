#ifndef BORROW_BOOK_H
#define BORROW_BOOK_H

#include "types.h"

void borrowBook(book *library_books, user *library_users, borrowed_record *library_borrowed_records,
     int *book_count, int *user_count, int *borrowed_count);

#endif