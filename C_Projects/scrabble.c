#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function declarations
int calculate_scores(char *input);
void decide_winner(int player1, int player2);

int main(void)
{
    char input[2][100];  // Array to store words for Player 1 and Player 2
    int score[2];        // Array to store scores for both players

    // Loop to get input and calculate score for each player
    for (int player = 0; player < 2; player++)
    {
        printf("Player %i: ", player + 1);
        fgets(input[player], sizeof(input[player]), stdin);

        // Remove trailing newline from fgets
        input[player][strcspn(input[player], "\n")] = '\0';

        score[player] = calculate_scores(input[player]);
    }

    // Determine and print the winner
    decide_winner(score[0], score[1]);

    return 0;
}

// Function to calculate score of a given word
int calculate_scores(char *input)
{
    int score = 0;

    // Scoring system for each letter A-Z based on Scrabble points
    int letter_scores[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
        5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
        1, 4, 4, 8, 4, 10
    };

    for (int i = 0; input[i] != '\0'; i++)
    {
        char c = toupper(input[i]);
        if (isalpha(c))
        {
            score += letter_scores[c - 'A'];
        }
    }

    return score;
}

// Function to decide and print the winner based on scores
void decide_winner(int player1, int player2)
{
    if (player1 > player2)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1 < player2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
