#include <stdio.h>
#include <stdlib.h> // used to access atoi()
#include <cs50.h> // used to access get_string
#include <string.h> // used to access strlen()
#include <ctype.h> // used to access isdigit
#include <stdbool.h> // used to access true and false

void encryptStr(string message,string key);
bool checkArgAmt(int argAmt);
bool checkArgLen(string argStr);
bool checkForAlpha(string input);
int checkRepeats(string argStr);

int main(int argc,string argv[])
{
    if (checkArgAmt(argc))
    {
        if (checkArgLen(argv[1]))
        {
            if (checkForAlpha(argv[1]) && checkRepeats(argv[1]) == 26)
            {
                string message = get_string("plaintext: ");

                printf("ciphertext: ");
                encryptStr(message,argv[1]);
            }
            else
            {
                printf("Usage: ./substitution key\n");
            }
        }
    }
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
        printf("Key must contain 26 characters.\n");
        return false;
    }
    else
    {
        return true;
    }
}

bool checkArgLen(string argStr)
{
    if(strlen(argStr) == 0)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
    else if(strlen(argStr) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    else
    {
        return true;
    }
}

//Ensures the value entered is an letter
bool checkForAlpha(string input)
{
    bool check = true;
    //checks entire string for non alpha characters, if any found the whole input returns false.
    for (int i = 0;i < strlen(input);i++)
    {
        if (!isalpha(input[i]))
        {
            check = false;
        }
    }
    return check;
}

// Checks for repeated characters
int checkRepeats(string argStr)
{
    int cntAlp = 0; // Keeps track of total characters, if > 26, something was repeated
    int cntInst = 0; // Keeps track of the instances of each character
    for (int i = 0; i < strlen(argStr);i++)
    {
        for (int j = 0; j < strlen(argStr);j++)
        {
            if(argStr[i] == argStr[j])
            {
                cntInst++;
            }
        }
        cntAlp+=cntInst;
        cntInst = 0;
    }
    return cntAlp;
}

//
void encryptStr(string message,string key)
{
    for (int i = 0;i < strlen(message);i++)
    {
        //Encrypts common letters
        if (message[i] >= 97 && message[i] <= 122)
        {
            printf("%c",tolower(key[message[i] - 97]));
        }
        //Encrypts capital letters
        else if (message[i] >= 65 && message[i] <= 90)
        {
            printf("%c",toupper(key[message[i] - 65]));
        }
        //prints everything else normally
        else
        {
            printf("%c",message[i]);
        }

    }
    printf("\n");
}

















