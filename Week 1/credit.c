#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long number = get_long("Card Number: ");
    
    int length = trunc(log10(number)) + 1;   
    
    //Checks validity of card by length  
    long long num_array[length];
    
    //makes an array of numbers
    int i=length-1;
    while(number!=0)
    {             
        num_array[i] = number%10;        
        number = trunc(number/10);         
        i--;
    }    
    
    //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those             products’ digits together.
    int sum = 0;
    for(int j = length-2;j>=0;j-=2)
    {        
        int pro = num_array[j]*2;
        if(pro != 0)
        {
            int length_pro = trunc(log10(pro)) + 1; 
            if (length_pro == 1)
            {
                sum = sum + pro;
            }
            else
            {
                while(pro!=0)
                {
                    sum = sum + pro%10;
                    pro = trunc(pro/10);
                }
            }
        }       
    }
    //---------------End Sum of Every other Digit
    int sum2 = 0;
    
    //Get some of remaining digits
    for(int j = length-1;j>=0;j-=2)
    {
        sum2 = sum2 + num_array[j];
    }
    
    //Check overall validity
    if((sum2 + sum)%10 != 0)
    {
        printf("Invalid Card!\n");
    }
    else
    {
        if((length == 13 || length == 16) && num_array[0] == 4)
        {
            printf("VISA\n");
        }
        else if(length == 15 && num_array[0] == 3 && (num_array[1] == 4 || num_array[1] == 7))
        {
            printf("American Express\n");
        }      
        else if(length == 16 && num_array[0] == 5 && (num_array[1] >=1 && num_array[1] <= 5))
        {
            printf("MasterCard\n");
        }  
        else
        {
            printf("Company Unknown!\n");
        }
        
    }
    
}
