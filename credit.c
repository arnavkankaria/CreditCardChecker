//Author: Arnav Kankaria
//This program validates if the credit number is valid, and detects the credit card type
#include <stdio.h>
#include <cs50.h>

//Functions
int card_length(long n);
void checksum(long a, int b);
void find_card(long cn, int l);

int main(void)
{
    long num;
    int length;
    //Ask for number
    do
    {
        num = get_long("Number: ");
        length = card_length(num);
    }
    while (length < 1);
    if (length < 13 || length > 16 || length == 14)
    {
        printf("INVALID\n");
    }
    else
    {
    checksum(num, length);
    }
}

//Finding card length
int card_length(long n)
{
    int i = 10;
    int len = 0;
    while (n > 0)
    {
        n = n / 10;
        len ++;
    }
    return len;
}

void checksum(long a, int b)
{
    //variables
    long card_number = a;
    int slsum = 0;
    int digits = 0;
    int lsum = 0;
    //Going digit by digit over the card number
    for (int j = 0; j < b; j++)
    {
        //Alternating from last number
        if (j % 2 == 0)
        {
            lsum = lsum + (a % 10);
        }
        //Alternating from second last number
        else
        {
            //if the value doubled is above 10 then break it down into two digits
            if (((a % 10) * 2) >= 10)
            {
                digits = 0;
                digits = ((a % 10) * 2);
                digits = (digits % 10) + (digits / 10);
            }
            //Take the value doubled
            else
            {
                digits = 0;
                digits = ((a % 10) * 2);
            }
            //Add the sum
            slsum = slsum + digits;
        }
        //reduce one digit from the number
        a = a / 10;
    }
    //Adding the two sums
    int sum = slsum + lsum;
    if (sum % 10 == 0)
    {
        find_card(card_number, b);
    }
    else
    {
        printf("INVALID\n");
    }
}

void find_card(long cn, int l)
{
    for (int i = 0; i < l - 2; i++)
    {
        cn = cn / 10;
    }
    if (cn == 34 || cn == 37)
    {
        printf("AMEX\n");
    }
    else if (cn / 10 == 4)
    {
        printf("VISA\n");
    }
    else if (cn <= 55 && cn >= 51)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

