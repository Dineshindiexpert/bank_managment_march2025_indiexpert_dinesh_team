#include <stdio.h>
#include <string.h>

void checkbalance();

char account_number[10000][12];
char holder_name[10000][25];
int balance[10000];
int i = 0;

int main()
{
    checkbalance();
    return 0;
}

void checkbalance()
{
    char number[12];
    int len;

    printf("Enter Your 11 digit Account Number: ");
    scanf("%s", number);
    len = strlen(number);

    if (len == 11)
    {
        printf("Your Account Number is Valid. \n");
        strcpy(account_number[i], number);

        balance[i] = 1000;
        printf("Your Current Balance is: %d\n", balance[i]);
        i++;
    }
    else
    {
        printf("Invalid Account Number. \n");
    }
}