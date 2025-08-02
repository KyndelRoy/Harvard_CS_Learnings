#include <stdio.h>
#include <string.h>

void trim_newline(char *str);

int main(void)
{
    char name[50] = "";
    
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    trim_newline(name); // Remove the newline character from fgets
    printf("Hello, %s!\n", name); // %s is used to print strings
    return 0;
}

void trim_newline(char *str) 
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0'; // Remove the newline character
    }
}
