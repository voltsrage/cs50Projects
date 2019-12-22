#include <stdio.h>
#include <stdlib.h> // used to access atoi()
#include <cs50.h> // used to access get_string
#include <string.h> // used to access strlen()
#include <ctype.h> // used to access isdigit
#include <stdbool.h> // used to access true and false

bool checkArgAmt(int argAmt);
bool checkForDigit(string input);
void encrpytMsg(string message, int key);

int main(int argc,string argv[])
{
    if (checkArgAmt(argc))
    {
        if (!checkForDigit(argv[1]))
        {
            string message = get_string("plaintext: ");

            printf("ciphertext: ");
            int key = atoi(argv[1]);

            encrpytMsg(message, key);
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }
    }
    //
    return 0;
}

//Ensures user only enters a single command line value
bool checkArgAmt(int argAmt)
{
    if (argAmt < 2)
    {
        printf("missing command-line argument\n");
        return false;
    }
    else if (argAmt > 2)
    {
        printf("Usage: ./caesar key\n");
        return false;
    }
    else
    {
        return true;
    }
}

//Ensures the value entered is an integer
bool checkForDigit(string input)
{
    bool check = false;
    //checks entire string for non digits, if any found the whole input returns false.
    for (int i = 0;i < strlen(input);i++)
    {
        if (!isdigit(input[i]))
        {
            check = true;
        }
    }
    return check;
}

//Encrypy input
void encrpytMsg(string message, int key)
{
    for (int i = 0;i < strlen(message);i++)
    {
        //Encrypts common letters
        if (message[i] >= 97 && message[i] <= 122)
        {
            printf("%c",(char)(((int)(message[i]) - 97 + key)%26) + 97);
        }
        //Encrypts capital letters
        else if (message[i] >= 65 && message[i] <= 90)
        {
            printf("%c",(char)(((int)(message[i]) - 65 + key)%26) + 65);
        }
        //prints everything else normally
        else
        {
            printf("%c",message[i]);
        }

    }
    printf("\n");
}
