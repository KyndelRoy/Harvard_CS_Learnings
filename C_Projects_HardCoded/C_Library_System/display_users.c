#include <stdio.h>
#include "display_users.h"

void displayUsers(const user *library_users, int *user_count)
{
    int active_users = 0;
    printf("Displaying Active Users:\n");
    printf("ID\tName\t\tContact\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < *user_count; i++)
    {
        if (!library_users[i].is_deleted) // Only display active users
        {
            printf("%d\t%s\t%s\n", library_users[i].id, library_users[i].name, library_users[i].contact);
            active_users++;
        }
    }

    if (active_users == 0)
    {
        printf("No active users found.\n");
    }

    printf("Total Active Users: %d\n", active_users);
    printf("-----------------------------------\n");

    char choice;
    printf("Do you want to display deleted users? (y/n): ");
    scanf(" %c", &choice);
    while(getchar() != '\n'); // Clear the input buffer

    // If user chooses not to display deleted users, exit the function
    if (choice != 'y' && choice != 'Y') {
        printf("Exiting user display.\n");
        return;
    }
    
    // Display deleted users
    int deleted_users = 0;
    printf("Displaying Deleted Users:\n");
    printf("ID\tName\t\tContact\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < *user_count; i++)
    {
        if (library_users[i].is_deleted) // Only display deleted users
        {
            printf("%d\t%s\t%s\n", library_users[i].id, library_users[i].name, library_users[i].contact);
            deleted_users++;
        }
    } 
    if (deleted_users == 0)
    {
        printf("No deleted users found.\n");
    }
    printf("Total Deleted Users: %d\n", deleted_users);
    printf("-----------------------------------\n");  
}