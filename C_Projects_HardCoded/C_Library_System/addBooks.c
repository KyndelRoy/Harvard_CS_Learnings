#include <stdio.h>
#include <string.h>
#include "types.h"
#include "addBooks.h"
#include "utils.h"

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

