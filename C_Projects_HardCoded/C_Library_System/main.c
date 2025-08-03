#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "addBooks.h"
#include "addUser.h"
#include "borrowBook.h"
#include "display_users.h"
#include "load_data.h"
#include "types.h"

int main(void)
{
    book library_books[MAX_BOOKS];
    user library_users[MAX_USERS];
    borrowed_record library_borrowed_records[MAX_BORROWED_RECORDS];

    int book_count = 0, next_book = 1;
    int user_count = 0, next_user = 1;
    int borrowed_count = 0;
    
    load_users(library_users, &user_count, &next_user, "data_users.txt");
    load_books(library_books, &book_count, &next_book, "data_books.txt");
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
        case 3:
            borrowBook(library_books, library_users, library_borrowed_records, &book_count, &user_count, &borrowed_count);
            break;  
        case 4:
            //
            break;
        case 5:
            //
            break;
        case 6:
            displayUsers(library_users, &user_count);
            break;
        case 7:
            //
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