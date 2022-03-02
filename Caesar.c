// Author: Austin Crossman

// Included libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Prompt user
    string user_prompt = get_string("Text: ");
    int letters = 0;
    int words = 0;
    int sentences = 0;



    //String length analysis
    for (int i = 0; i < strlen(user_prompt); i++)
    {
        if ((user_prompt[i] >= 'a' && user_prompt[i] <= 'z') || (user_prompt[i] >= 'A' && user_prompt[i] <= 'Z'))
        {
            // Count letters
            letters++;
        }

        else if (user_prompt[i] == ' ')
        {
            // Count words
            words++;
        }
        else if (user_prompt[i] == '.' || user_prompt[i] == '!' || user_prompt[i] == '?')
        {
            // Count sentences
            sentences++;
        }

    }

    // To account for last word in string
    words = words + 1;

    // Calculation
    float L = ((float) letters / (float)words) * 100;
    float S = ((float) sentences / (float)words) * 100;
    float subindex = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(subindex);
    if (index > 16)

    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}