#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[1000];
    int input_length = 0;
    int result = 0;
    float letters = 0, words = 1, sentence = 0;

    // Input loop until non-empty
    do
    {
        printf("Text: ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';
        input_length = strlen(input);
    }
    while (input_length < 1);

    // Reject if starts or ends with a space
    if (isspace(input[0]) || isspace(input[input_length - 1]))
    {
        return 1;
    }

    // Count letters, words, sentences
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalpha(input[i]))
        {
            letters++;
        }
        else if (i > 0 && isspace(input[i]) && isspace(input[i - 1]))
        {
            return 1; // Reject double spaces
        }
        else if (isspace(input[i]))
        {
            words++;
        }
        else if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentence++;
        }
    }

    // Coleman-Liau formula
    float L = (letters / words) * 100;
    float S = (sentence / words) * 100;
    result = round(0.0588 * L - 0.296 * S - 15.8);

    // Output grade level
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }

    return 0;
}
