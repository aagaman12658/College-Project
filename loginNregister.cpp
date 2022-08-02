#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <graphics.h>
#include "attendanceprog.h"
#include "studentdatabase.h"
#define TAB 9
#define ENTER 13
#define BCKSPC 8



struct login                           // before the first use of `l`.
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};

void login (void);
void registration (void);

void takepassword(char pwd[50])
{
    int i=0;
    char ch='0';
    while (1)
    {
        ch = _getch();
        if (ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == BCKSPC)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i] = ch;
            printf("* \b");
            i++;
        }
    }
}


void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int main (void)
{
    system("color f0");
    int option;
    gotoxy(55,20);
    printf("%c Attendance Register",254);
    delay(4);
    system("cls");
    gotoxy(55,01);
    printf("%c Attendance Register",254);
    gotoxy(55,18);
    printf("> Press '1' to Register");
    gotoxy(55,20);
    printf("> Press '2' to Login");
    gotoxy(55,22);
    printf("%c  ",175);
    scanf("%d",&option);

    getchar();           // catching newline.

    if(option == 1)
        {
            system("CLS");
            system("color f0");
            registration();
        }

    else if(option == 2)
        {
            system("CLS");
            system("color 0f");
            login();
        }
}

void login (void)
{
    char username[30];
    char password[20];

    FILE *log;

    log = fopen("login.txt","r");
    if (log == NULL)
    {
        fputs("FIle cannot be opened!", stderr);
        exit(1);
    }

    struct login l;


    Login:

    printf("\nPlease Enter your login credentials below\n\n");
    fflush(stdin);
    printf("Username: ");
    scanf("%s",username);
    fflush(stdin);
    printf("\nPassword: ");
    takepassword(password);


    while(fread(&l,sizeof(l),1,log))
        {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
            {
                printf("\nSuccessful Login\n");
                entryORattendance();
            }
        else
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
                goto Login;
            }
        }

    fclose(log);

    return;
}




void registration(void)
{
    int i,k=0;
    char firstname[15];
    char ab, choice, cd;
    FILE *log;
    FILE *fp;
    log=fopen("login.txt","w");
    if (log == NULL)
    {
        fputs("File cannot be opened!", stderr);
        exit(1);
    }


    struct login l,l1;
    gotoxy(25,01);
    printf("Welcome to your registration portal. We need to enter some details for registration.");
    gotoxy(55,04);
    printf("Enter First Name:");
    scanf("%s",l.fname);
    fflush(stdin);
    gotoxy(55,07);
    printf("Enter Surname:");
    scanf("%s",l.lname);
    fflush(stdin);
    gotoxy(55,10);
    printf("Thank you.");
    gotoxy(5,12);
    printf("i) Now please choose a username and password as credentials for system login.");
    gotoxy(5,14);
    printf("ii)Ensure the username is no more than 30 characters long.");
    gotoxy(5,16);
    printf("iii)Ensure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n");
    gotoxy(55,20);
    printf("Enter Username:");
    scanf("%s",l.username);
    fflush(stdin);

    AGAIN:
        if (k==0)
        {
            gotoxy(55,23);
            printf("Enter your password:        ");
        }
        if (k==1)
        {
            gotoxy(55,20);
            printf("Enter your password:        ");
        }

        takepassword(l.password);
        printf("\n");
        if (k==0)
        {
            gotoxy(55,24);
            printf("Confirm your password:      ");
        }
         if (k==1)
        {
            gotoxy(55,21);
            printf("Confirm your password:      ");
        }
        takepassword(l1.password);

      if (strcmp(l.password,l1.password)!=0)
        {
            gotoxy(55,25);
            printf("Passwords do not match. Please try again!");
            delay(3);
            k=1;
            system("cls");
            goto AGAIN;
        }

    fwrite(&l,sizeof(l),1,log);
    fclose(log);
    gotoxy(35,26);
    printf("Confirming details.");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    printf("Welcome, ");
    for (i=0;i<strlen(l.fname);i++)
    {
        printf("%c",l.fname[i]);
    }
    delay(2);
    gotoxy(35,28);
    printf("Registration Successful!");
    fflush(stdin);
    delay(2);
    gotoxy(35,30);
    printf("Press any key to continue...");
        getchar();
    system("CLS");
    login();
}
