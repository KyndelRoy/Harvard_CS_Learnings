#include <stdio.h>
#include <stdbool.h>

// Function prototypes
long get_credit_card_number(void);
int calculate_luhn_checksum(long number);
void identify_card_type(long number, int checksum);

int main(void)
{
    long credit_card = get_credit_card_number();
    int checksum = calculate_luhn_checksum(credit_card);
    identify_card_type(credit_card, checksum);
    return 0;
}

// Handles validated input
long get_credit_card_number(void)
{
    long number;
    int input_status;

    do 
    {
        printf("Enter your credit card number: ");
        input_status = scanf("%ld", &number);

        if (input_status != 1 || number <= 0)
        {
            printf("Invalid input. Please enter a positive number.\n");
            while (getchar() != '\n'); // clear buffer
        }
    }
    while (input_status != 1 || number <= 0);

    return number;
}

// Implements Luhn’s Algorithm and returns the checksum
int calculate_luhn_checksum(long number)
{
    int sum = 0;
    bool is_even = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (is_even)
        {
            int doubled = digit * 2;
            sum += (doubled / 10) + (doubled % 10);
        }
        else
        {
            sum += digit;
        }

        number /= 10;
        is_even = !is_even;
    }

    return sum;
}

// Determines and prints the card type
void identify_card_type(long number, int checksum)
{
    int digit_count = 0;
    long copy = number;

    while (copy > 0)
    {
        copy /= 10;
        digit_count++;
    }

    // Get first two digits
    long first_two = number;
    while (first_two >= 100)
    {
        first_two /= 10;
    }

    int first_digit = first_two / 10;

    if (checksum % 10 == 0)
    {
        if (first_digit == 4 && (digit_count == 13 || digit_count == 16))
        {
            printf("VISA\n");
        }
        else if ((first_two == 34 || first_two == 37) && digit_count == 15)
        {
            printf("AMEX\n");
        }
        else if ((first_two >= 51 && first_two <= 55) && digit_count == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
