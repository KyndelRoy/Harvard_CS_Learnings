#include <stdio.h>
#include <string.h>
#include "addUser.h"   
#include "utils.h"

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

    // Validate contact length
    if (strlen(name) == 0 || strlen(contact) != 10)
    {
        printf("Invalid input. User not added.\n");
        return;
    }

    // Check if name or contact exceeds maximum length
    if (strlen(name) >= MAX_NAME_LENGTH || strlen(contact) >= MAX_CONTACT_LENGTH)
    {
        printf("Name or contact too long. Please limit to 50 characters for name and 10 digits for contact.\n");
        return;
    }

    // Check if user with the same contact already exists
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