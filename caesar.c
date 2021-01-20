#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    bool success = false;
    int key = 0;
    int input_len = 0;
    string text = "";

    do
    {
        if (argc != 2)
        {
            printf("Usage: You must provide key\n");
            return 1;
        }
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (! isdigit(argv[1][i]))
            {
                printf("Usage: key must be a digit\n");
                return 1;
            }
        }
        key = atoi(argv[1]);

        if (key < 0)
        {
            printf("Usage: key must be positive");
            return 1;
        }
        else
        {
            success = true;
            printf("plaintext: ");
        }
    }
    while (!success);

    text = get_string("");
    printf("ciphertext: ");
    input_len = strlen(text);

    for (int i = 0; i < input_len; i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                printf("%c", ((((text[i] - 97) + key) % 26) + 97));
            }
            else
            {
                printf("%c", ((((text[i] - 65) + key) % 26) + 65));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}