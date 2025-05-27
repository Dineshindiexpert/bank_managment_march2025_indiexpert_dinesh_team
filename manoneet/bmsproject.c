#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    int len, flag, m;

    while (1)
    {
        printf("Enter Your 11 digit Account Number: ");
        scanf("%s", number);
        len = strlen(number);

        if (len == 11)
        {
            flag = 1;

            for (m = 0; m < len; m++)
            {
                if (!isdigit(number[m]))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                printf("Your Account Number is Valid. \n");
                strcpy(account_number[i], number);

                balance[i] = 1000;
                printf("Your Current Balance is: %d\n", balance[i]);
                i++;
                break;
            }
            else
            {
                printf("Invalid Account Number. \n");
            }
            printf("Try Again. \n");
        }
    }
}