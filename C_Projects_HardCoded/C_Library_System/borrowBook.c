#include <stdio.h>
#include <string.h>
#include "borrowBook.h"
#include "utils.h"

void borrowBook(book *library_books, user *library_users, borrowed_record *library_borrowed_records, 
                int *book_count, int *user_count, int *borrowed_count)
{
    if (*borrowed_count >= MAX_BORROWED_RECORDS)
    {        printf("Borrowed records limit reached, cannot borrow more books.\n");
        return;
    }

    int user_id;
    int book_id;
    char borrow_date[MAX_DATE_LENGTH];
    char return_date[MAX_DATE_LENGTH];

    printf("Enter user ID: ");
    scanf("%d", &user_id);
    while(getchar() != '\n'); // Clear the input buffer

    // Validate user ID
    int user_found = 0;
    for (int i = 0; i < *user_count; i++)
    {
        if (library_users[i].id == user_id && !library_users[i].is_deleted)
        {
            user_found = 1;
            break;
        }
    }

    if (!user_found)
    {
        printf("User not found or deleted. Cannot borrow book.\n");
        return;
    }
    printf("User found: %s (ID: %d)\n", library_users[user_id - 1].name, user_id);

    // Input book ID
    printf("Enter book ID: ");
    scanf("%d", &book_id);
    while(getchar() != '\n'); // Clear the input buffer

    // Validate book ID
    int book_found = 0;
    for (int i = 0; i < *book_count; i++)
    {
        if (library_books[i].id == book_id && library_books[i].available_copies > 0)
        {
            book_found = 1;
            break;
        }
    }
    if (!book_found)
    {
        printf("Book not found or no available copies. Cannot borrow book.\n");
        return;
    }
    // Check if the user has already borrowed the book
    printf("Enter borrow date (YYYY-MM-DD): ");
    fgets(borrow_date, sizeof(borrow_date), stdin);
    trim_newline(borrow_date);

    // Validate borrow date format
    if (strlen(borrow_date) != 10 || borrow_date[4] != '-' || borrow_date[7] != '-')
    {
        printf("Invalid date format. Please use YYYY-MM-DD.\n");
        return;
    }
}