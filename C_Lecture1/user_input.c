#include <stdio.h>
#include <string.h>

int main(void)
{
    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    char name[30] = "";
    printf("Input your age: ");
    scanf("%d", &grade); // scanf("datatype", &variable) reads input from the user

    printf("Input your GPA: ");
    scanf("%f", &gpa); // scanf("datatype", &variable) reads input from the user

    printf("Enter your grade: ");
    scanf(" %c", &grade); // Note the space before %c to skip any whitespace

    getchar(); // Clear the newline character left in the input buffer
    // This is necessary to avoid issues with fgets after scanf

    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin); // fgets(variable, size, stdin) reads a line of text from the user
    // sizeof() is a function to ensure to get the size of the array 
    name[strlen(name) - 1] = '\0'; // Remove the newline character from fgets
    
    printf("Your age: %d\n", age);
    printf("Your GPA: %.2f\n", gpa);
    printf("Your grade: %c\n", grade);
    printf("Your name: %s\n", name); // %s is used to print strings
}
