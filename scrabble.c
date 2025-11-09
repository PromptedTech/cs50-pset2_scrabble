#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points for each letter (A-Z)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Ask both players for their words
    string word1 = get_string("Word for Player 1: ");
    string word2 = get_string("Word for Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print who won, or if it's a tie
    if (score1 > score2)
    {
        printf("Player 1 wins.\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins.\n");
    }
    else
    {
        printf("It's a tie.\n");
    }
}

int compute_score(string word)
{
    int total = 0;
    int n = strlen(word);

    // Go through each character in the word
    for (int idx = 0; idx < n; idx++)
    {
        char ch = word[idx];
        if (isupper(ch))
        {
            int pos = ch - 'A';
            total += POINTS[pos];
        }
        else if (islower(ch))
        {
            int pos = ch - 'a';
            total += POINTS[pos];
        }
        // Ignore anything that's not a letter
    }
    return total;
}