#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int getDigitsCount(long number)
{
    int result = 0;
    while (number > 1)
    {
        result++;
        number /= 10;
    }
    return result;
}

int getFirstNDigits(long input, int n)
{
    long result = input;

    while (result >= (int)pow((double)10, n)) 
    {
        result /= 10;
    }

    return result;
}

string getCardType(long number)
{
    int digits = getDigitsCount(number);
    
    if ((digits == 13 || digits == 16) && getFirstNDigits(number, 1) == 4)
    {
        return "VISA";
    }
    else if (digits == 15 && (getFirstNDigits(number, 2) == 34 || getFirstNDigits(number, 2) == 37))
    {
        return "AMEX";
    }
    else if (digits == 16 && (getFirstNDigits(number, 2) >= 51 && getFirstNDigits(number, 2) <= 55))
    {
        return "MASTERCARD";
    }
    else
    {
        return "INVALID";
    }
}

int main(void)
{
    int sum = 0;
    long number = get_long("Number: ");
    string type = getCardType(number);
    
    if (strcmp(type, "INVALID") == 0)
    {
        printf("INVALID\n");
        return 0;
    }

    while (number >= 1)
    {
        sum += number % 10;
        number /= 10;
        int temp = (number % 10) * 2;
        while (temp >= 1)
        {
            sum += temp % 10;
            temp /= 10;
        }
        number /= 10;
    }
    
    if (sum % 10 == 0)
    {
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}
