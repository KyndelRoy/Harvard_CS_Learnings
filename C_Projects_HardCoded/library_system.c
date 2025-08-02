#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_USERS 100
#define MAX_BORROWED_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 11
#define MAX_TITLE_LENGTH 60
#define MAX_AUTHOR_LENGTH 60
#define MAX_DATE_LENGTH 11
 
// structs
typedef struct 
{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int id;
    int available_copies;
} book;

typedef struct 
{
    int id;
    char name[MAX_NAME_LENGTH];
    char contact[MAX_CONTACT_LENGTH];
    bool is_deleted; // Indicates if the user is active
} user;

typedef struct
{
    int user_id;
    int book_id;
    char borrow_date[MAX_DATE_LENGTH]; // Format: YYYY-MM-DD
    char return_date[MAX_DATE_LENGTH]; // Format: YYYY-MM-DD
} borrowed_record;

// Function prototypes
void trim_newline(char *str);
void addBook(book *library_books, int *book_count, int *next_book);
void addUser(user *library_users, int *user_count, int *next_user);

// main function
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

void trim_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove the newline character
    }   
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

    if (strlen(title) >= MAX_TITLE_LENGTH || strlen(author) >= MAX_AUTHOR_LENGTH)
    {
        printf("Title or author name too long. Please limit to 60 characters.\n");
        return;
    }

    for (int i = 0; i < *book_count; i++)
    {
        if (strcmp(library_books[i].title, title) == 0 && strcmp(library_books[i].author, author) == 0)
        {
            library_books[i].available_copies += copies;
            printf("Book already exists. Updated available copies to %d.\n", library_books[i].available_copies);
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

void addUser(user *library_users, int *user_count, int *next_user)
{
    if (*user_count >= MAX_USERS)
    {
        printf("User limit reached, cannot add more users.\n");
        return;
    }

    char name[50];
    char contact[11];

    printf("Enter user name: ");
    fgets(name, sizeof(name), stdin);
    trim_newline(name);

    printf("Enter user contact (10 digits): ");
    fgets(contact, sizeof(contact), stdin);
    trim_newline(contact);

    if (strlen(name) == 0 || strlen(contact) != 10)
    {
        printf("Invalid input. User not added.\n");
        return;
    }

    if (strlen(name) >= MAX_NAME_LENGTH || strlen(contact) >= MAX_CONTACT_LENGTH)
    {
        printf("Name or contact too long. Please limit to 50 characters for name and 10 digits for contact.\n");
        return;
    }

    for (int i = 0; i < *user_count; i++)
    {
        if (strcmp(library_users[i].contact, contact) == 0)
        {
            printf("Contact number already exists. User not added.\n");
            return;
        }
    }

    strcpy(library_users[*user_count].name, name);
    strcpy(library_users[*user_count].contact, contact);
    library_users[*user_count].id = *next_user; // Assign ID based on current count
    library_users[*user_count].is_deleted = false; // Set user as active
    printf("User added successfully with ID: %d\n", library_users[*user_count].id);
    (*user_count)++; // Increment the user count
    (*next_user)++; // Increment the next user ID for future additions
}