#include <stdio.h>

int main(void)
{
    int age = 20;

    if (age < 18) 
    {
        printf("You are a minor.\n");
    } 
    else if (age < 65) 
    {
        printf("You are an adult.\n");
    } 
    else 
    {
        printf("You are a senior citizen.\n");
    }

    return 0;
} 