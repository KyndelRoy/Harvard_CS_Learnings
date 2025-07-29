#include <stdio.h>

int calculate_change(int cents);
void greedy_algorithm(void);

int main(void)
{
    greedy_algorithm();
}

void greedy_algorithm(void)
{
    int cents, owed;
    int input_status;

    do
    {
        printf("Enter amount of change owed: ");
        input_status = scanf("%d", &cents);  // check for valid input

        if (input_status != 1 || cents < 0)
        {
            printf("Invalid input. Please enter a non-negative integer.\n");
            while (getchar() != '\n'); // clear the input buffer
        }
    }
    while (input_status != 1 || cents < 0);

    owed = calculate_change(cents);
    printf("Change owed: %d cents\n", owed); 
}

int calculate_change(int cents)
{
    int coins = 0;

    // Calculate the number of quarters
    coins += cents / 25;
    cents %= 25;

    // Calculate the number of dimes
    coins += cents / 10;
    cents %= 10;

    // Calculate the number of nickels
    coins += cents / 5;
    cents %= 5;

    // Remaining cents are pennies
    coins += cents;

    printf("Total coins used: %d\n", coins);
    return coins;
}
