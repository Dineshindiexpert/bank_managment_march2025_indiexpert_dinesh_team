#include <stdio.h>
#include <string.h>
#include<ctype.h>
char account_no[1000][12];
char account_holder[1000][25];
int balance[1000];
void choice();
void createaccount();
void deposite();
void withdraw();
void checkbalance();
void menu();

int main() 
{
    menu();
    choice();
    return 0;
}
void choice ()
{
    char choice[10];

    while (1) 
    {
        printf("\tEnter your choice: ");
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
void menu()
{
    printf("\t......WELCOME.......\n");
    printf("\tBANK MANAGEMENT SYSTEM.\n");
    printf("\tMenu given below.\n");
    printf("\tPress 1. to Create Account.\n");
    printf("\tPress 2. to Withdraw Money.\n");
    printf("\tPress 4. to Deposit Money.\n");
    printf("\tPress 5. to Check Balance.\n");
    printf("\tPress 6. to Exit.\n");
}
void createaccount()
{
    int i = 0;
    while (1)
    {
        char accountnumber[12];
        int len;
        int check = 1;
        printf("\tEnter 11 digit account number: ");
        scanf("%s", accountnumber);
        len = strlen(accountnumber);
        if (len != 11)
        {
            printf("\tInvalid! Enter exactly 11 digits.\n");
            continue;
        }
        for (int j = 0; j < len; j++)
        {
            if (!isdigit(accountnumber[j]))
            {
                check = 0;
                break;
            }
        }
        if (!check)
        {
            printf("\tInvalid! Use digits only.\n");
            continue;
        }
        int duplicate = 0;
        for (int j = 0; j<i; j++)
        {
            if (strcmp(account_no[j], accountnumber)==0)
            {
                duplicate =1;
                break;
            }
        }
        if (duplicate)
        {
        printf("\tAccount number already exists.\n");
        continue;
        }
        if(strcmp(accountnumber,"00000000000")==0)
        {
            printf("\tenter the valid digit !\n");
            continue;
        }
        strcpy(account_no[i], accountnumber);
        getchar();
    
        char holdername[25]; 
        while (1)
        {
            printf("\tEnter account holder name: ");
            scanf(" %[^\n]", holdername);  

            int checkname = 1;
            for (int j = 0; j < strlen(holdername); j++)
            {
                if (isdigit(holdername[j]))
                {
                    checkname = 0;
                    break;
                }
            }

            if (!checkname)
            {
                printf("\tInvalid name! It should not contain digits.\n");
                while (getchar() != '\n');
                continue;
            }
            strcpy(account_holder[i], holdername);
            break;
        }

        int deposit;
        while (1)
        {
            printf("\tEnter amount: ");
            if (scanf("%d", &deposit) != 1)
            {
                printf("\tInvalid input! Please enter numbers only.\n");
                while (getchar() != '\n');
                continue;
            }
            if (deposit < 500 || deposit > 100000)
            {
                printf("\tAmount must be between 500 and 100000.\n");
                continue;
            }
            balance[i]=deposit;
            printf("\ttransaction sucessfully..\n");
            break; 
        }
        printf("\taccount Created Successfully!\n");
        printf("\taccount Number : %s\n", account_no[i]);
        printf("\tHolder Name    : %s\n", account_holder[i]);
        printf("\tCurrent Balance: Rs.%d\n", balance[i]);
        i++; 
        break;
    
    }
    
}
void deposite()
{
    char accountnumber[12];
    while (1)
    {
        printf("\tEnter 11 digit account number: ");
        scanf("%s", accountnumber);

        if (strlen(accountnumber) != 11)
        {
            printf("\tInvalid! Enter exactly 11 digits.\n");
            continue;
        }

        int check = 1;
        for (int j = 0; j < 11; j++)
        {
            if (!isdigit(accountnumber[j]))
            {
                check  = 0;
                break;
            }
        }
        if (!check)
        {
            printf("\tInvalid! Use digits only.\n");
            continue;
        }
        if (strcmp(accountnumber,"0000000000")==0)
        {
            printf("\tinvalid digit !\n");
            continue;
        }

        int checkaccount = 0;
        for (int i = 0; i < 1000; i++)
        {
            if (account_no[i][0] != '\0' && strcmp(account_no[i], accountnumber) == 0)
            {
                printf("\t\t Note : please ensure user have right details.\n");
                printf("\n\n");
                printf("\tyour account details :%s\n",&account_no[i]);
                printf("\tholder name :%s\n",&account_holder[i]);
                printf("\tyour balance :%d\n",balance[i]);
                printf("\tplease wait......");
                printf("\n\n");
                
                int deposit;
                while (1)
                {
                    printf("\tEnter amount to deposite : ");
                    if (scanf("%d", &deposit) != 1)
                    {
                        printf("\tInvalid input! Please enter numbers only.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (deposit < 500 || deposit > 100000)
                    {
                        printf("\tAmount must be between 500 and 100000.\n");
                        continue;
                    }
                    balance[i] += deposit;
                    printf("\tTransaction successful.\n");
                    printf("\tAccount Number : %s\n", account_no[i]);
                    printf("\tHolder Name    : %s\n", account_holder[i]);
                    printf("\tCurrent Balance: Rs.%d\n", balance[i]);
                    break;
                }
                checkaccount = 1;
                break;
            }
        }

        if (!checkaccount)
        {
            printf("\tAccount number does not exist.\n");
            continue;
        }

        break;
    }
}
void withdraw()
{
    char accountnumber[12];
    while (1)
    {
        printf("\tEnter 11 digit account number: ");
        scanf("%s", accountnumber);

        if (strlen(accountnumber) != 11)
        {
            printf("\tInvalid! Enter exactly 11 digits.\n");
            continue;
        }

        int check = 1;
        for (int j = 0; j < 11; j++)
        {
            if (!isdigit(accountnumber[j]))
            {
                check  = 0;
                break;
            }
        }
        if (!check)
        {
            printf("\tInvalid! Use digits only.\n");
            continue;
        }
        if (strcmp(accountnumber,"0000000000")==0)
        {
            printf("\t invalid account number !\n");
            continue;
        }

        int checkaccount = 0;
        for (int i = 0; i < 1000; i++)
        {
            if (account_no[i][0] != '\0' && strcmp(account_no[i], accountnumber) == 0)
            {
                printf("\t\t Note : please ensure user have right details.\n");
                printf("\n\n");
                printf("\tyour account details :%s\n",&account_no[i]);
                printf("\tholder name :%s\n",&account_holder[i]);
                printf("\tyour balance :%d\n",balance[i]);
                printf("\tplease wait......");
                printf("\n\n");
                
                int deposit;
                while (1)
                {
                    printf("\tEnter amount to withdraw : ");
                    if (scanf("%d", &deposit) != 1)
                    {
                        printf("\tInvalid input! Please enter numbers only.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (deposit < 500 || deposit > 100000)
                    {
                        printf("\tAmount must be between 500 and 100000.\n");
                        continue;
                    }
                    if (balance[i]==500)
                    {
                        printf("\tyou have only Rs. 500 hundred rupees.\n");
                        printf("\t To you dont withdraw the money according to bank system.\n");
                        break;
                    }
                    if (balance[i]-deposit <500)
                    {
                        printf("\tmin amount in the bank account will be 500 Rs.\n");
                        continue;

                    }
                    else
                    {
                        balance[i] -= deposit;
                    }
                    
                    printf("\tTransaction successful.\n");
                    printf("\tAccount Number : %s\n", account_no[i]);
                    printf("\tHolder Name    : %s\n", account_holder[i]);
                    printf("\tCurrent Balance: Rs.%d\n", balance[i]);
                    break;
                }
                checkaccount = 1;
                break;
            }
        }

        if (!checkaccount)
        {
            printf("\tAccount number does not exist.\n");
            continue;
        }

        break;
    }
}
void checkbalance()
{
    char accountnumber[12];
    while (1)
    {
        printf("\tEnter 11 digit account number: ");
        scanf("%s", accountnumber);

        if (strlen(accountnumber) != 11)
        {
            printf("\tInvalid! Enter exactly 11 digits.\n");
            continue;
        }

        int check = 1;
        for (int j = 0; j < 11; j++)
        {
            if (!isdigit(accountnumber[j]))
            {
                check = 0;
                break;
            }
        }

        if (!check)
        {
            printf("\tInvalid! Use digits only.\n");
            continue;
        }
        if(strcmp(accountnumber,"0000000000")==0)
        {
            printf("\t invalid digit.!\n");
            continue;

        }

        int checkaccount = 0;
        for (int i = 0; i < 1000; i++)
        {
            if (account_no[i][0] != '\0' && strcmp(account_no[i], accountnumber) == 0)
            {
                printf("\n\t\tNote: Please ensure user has correct details.\n\n");
                printf("\tAccount Number : %s\n", account_no[i]);
                printf("\tHolder Name    : %s\n", account_holder[i]);
                printf("\tCurrent Balance: Rs.%d\n", balance[i]);
                printf("thanks to visit again.\n");
                checkaccount = 1;
                break;
            }
        }

        if (!checkaccount)
        {
            printf("\tAccount number does not exist.\n");
            continue;
        }

        break;
    }
}


