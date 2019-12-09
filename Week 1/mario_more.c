#include <cs50.h>
#include <stdio.h>

//Build ladder
void ladder(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j < n - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }            
        }  
        printf("   ");
        for (int j = 0; j <= n; j++)
        {
            if (j < i + 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }            
        }  
        printf("\n");
    }
}

//Request input from user
int main(void)
{
    int number;
    do
    {
        number = get_int("Enter height: ");
        if (number >= 1 && number <= 8)
        {
            ladder(number);
        }        
    }
    while (true && number != 100);
   
}
