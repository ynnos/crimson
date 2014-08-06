/** 
 * Uses caesar cipher to scramble user input.
 *
 * Just for fun.
 * Do not actually use for sensitive information.
 *
 * Requires some custom header files.
 * ynnos.org
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    bool keyValid = false;
    int key = 0;
    int ilen = 0;
    string text = " ";

    // check input
    do
    {
        // number of cmdline arguments invalid
        if (argc != 2)
        {
            printf("Invalid encryption key.\n");
            printf("Enter a valid key and re-run the program.\n");
            return 1;
        }
        // convert key to int
        else
        {
            key = atoi(argv[1]);
            keyValid = true;
        }
    }
    while (!keyValid);
    
    // read user input
    printf("Enter message you want to encrypt: \n");
    text = GetString();
    ilen = strlen(text);

    for (int i = 0; i < ilen; i++)
    {
        // check each char
        if (isalpha(text[i]))
        {
            // lower case
            if (islower(text[i]))
            {
                printf("%c", ((((text[i] -97) +key) %26) +97));
            }
            //upper case
            else
            {
                printf("%c", ((((text[i] -65) +key) %26) +65));
            }
        }
        // just print out all other chars
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}
