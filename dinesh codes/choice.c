#include <stdio.h>
#include <string.h>
void choice();
void creataccount();
void deposite();
void withdraw();
void checkbalancce();

int main() 
{
    choice();
    return 0;
}
void choice ()
{
    char choice[10];

    while (1) 
    {
        printf("Enter your choice (1 to 5): ");
        scanf("%s", choice);
        if (strcmp(choice, "1") == 0) 
        {
            createaccount(); // put createaccount fun
            continue;       
        }
        if (strcmp(choice, "2") == 0) 
        {
            deposite(); // put deposite fun
            continue;
        }
        if (strcmp(choice, "3") == 0) 
        {
            withdraw(); // put withdraw fun
            continue;
        }

        if (strcmp(choice, "4") == 0) 
        {
            checkbalance(); // put balance fun
            continue;
        }
        if (strcmp(choice, "5") == 0) 
        {
            printf("Exiting program.\n"); // no need change here.
            break;          
        }
        printf("\tInvalid input!\n");
        printf("\tPlease enter a number from 1 to 5.\n");
        
    }

}

