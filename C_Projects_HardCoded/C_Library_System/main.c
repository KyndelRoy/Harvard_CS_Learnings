#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "types.h"
#include "addBooks.h"
#include "addUser.h"

int main(void)
{
    book library_books[MAX_BOOKS];
    user library_users[MAX_USERS];
    borrowed_record library_borrowed_records[MAX_BORROWED_RECORDS];

    int book_count = 0;
    int next_book = 1;
    int user_count = 0;
    int next_user = 1;
    int borrowed_count = 0;
    
    int choice;
    do {
        printf("Library System Menu:\n");
        printf("1. Add Book\n");
        printf("2. Add User\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. View Books\n");
        printf("6. View Users\n");
        printf("7. View Borrowed Records\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // Clear the input buffer 
        
        switch (choice) {
        case 1:
            addBook(library_books, &book_count, &next_book);
            break;
        case 2:
            addUser(library_users, &user_count, &next_user);
            break;
        case 8:
            printf("Exiting the library system. Goodbye!\n");
            return 0;   
        default:
            printf("Invalid choice. Please try again.\n\n");
            break;
        }    
    } while (choice != 8);    
}