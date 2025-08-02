#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_USERS 100
#define MAX_BORROWED_RECORDS 100
 
// structs
typedef struct 
{
    char title[50];
    char author[50];
    int id;
    int available_copies;
} book;

typedef struct 
{
    int id;
    char name[50];
    char contact[11];
} user;

typedef struct
{
    int user_id;
    int book_id;
    char borrow_date[11]; // Format: YYYY-MM-DD
    char return_date[11]; // Format: YYYY-MM-DD
} borrowed_record;

// Function prototypes
void trim_newline(char *str);
void addBook(book *library_books, int *book_count, int *next_book);

// main function
int main(void)
{
    book library_books[MAX_BOOKS];
    user library_users[MAX_USERS];
    borrowed_record library_borrowed_records[MAX_BORROWED_RECORDS];

    int book_count = 0;
    int next_book = 1;
    int user_count = 0;
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
        case 8:
            printf("Exiting the library system. Goodbye!\n");
            return 0;   
        default:
            printf("Invalid choice. Please try again.\n\n");
            break;
        }    
    } while (choice != 8);    
}

void addBook(book *library_books, int *book_count, int *next_book)
{
    if (*book_count >= MAX_BOOKS) 
    {
        printf("Library is full, cannot add more books.\n");
        return;
    }

    char title[50];
    char author[50];
    int copies;

    printf("Enter book title: ");
    fgets(title, sizeof(title), stdin);
    trim_newline(title);

    printf("Enter book author: ");
    fgets(author, sizeof(author), stdin);
    trim_newline(author);   

    printf("Enter number of copies: ");
    scanf("%d", &copies);
    while(getchar() != '\n'); // Clear the input buffer

    if (strlen(title) == 0 || strlen(author) == 0 || copies <= 0) 
    {
        printf("Invalid input. Book not added.\n");
        return;
    }

    if (strlen(title) >= 60 || strlen(author) >= 60)
    {
        printf("Title or author name too long. Please limit to 60 characters.\n");
        return;
    }

    for (int i = 0; i < *book_count; i++)
    {
        if (strcmp(library_books[i].title, title) == 0 
        && strcmp(library_books[i].author, author) == 0)
        {
            library_books[i].available_copies += copies;
            printf("Book already exists. Updated available copies to %d.\n", 
            library_books[i].available_copies);
            return;
        }
    }
    
    strcpy(library_books[*book_count].title, title);
    strcpy(library_books[*book_count].author, author);
    library_books[*book_count].id = *next_book;
    library_books[*book_count].available_copies = copies;

    printf("Book added successfully with ID: %d\n", library_books[*book_count].id);
    (*book_count)++; // this is necessary to increment the value count not the pointer
    (*next_book)++; // Increment the next book ID for future additions
}

void trim_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove the newline character
    }   
}
