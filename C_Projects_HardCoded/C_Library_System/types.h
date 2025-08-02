#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_USERS 100
#define MAX_BORROWED_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 11
#define MAX_TITLE_LENGTH 60
#define MAX_AUTHOR_LENGTH 60
#define MAX_DATE_LENGTH 11

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
    bool is_deleted;
} user;

typedef struct
{
    int user_id;
    int book_id;
    char borrow_date[MAX_DATE_LENGTH];
    char return_date[MAX_DATE_LENGTH];
} borrowed_record;



#endif
