#ifndef __studentdatabase
#define __studentdatabase




#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include"attendanceprog.h"

void gotoxy(short a, short b) //Custom gotoxy() function
{
    COORD coordinates; //Data type of co-ordinates
    coordinates.X = a; //Assign value to X- Co-ordinate
    coordinates.Y = b; //Assign value to Y Co-ordinate

SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}

struct newstud
{
	int year;
	char department[100];
};

struct studentdata
{
	char name[100];
	char rollno[10];
	char section[5];
};


int newentry()
{
    system("cls");
	char strtmpname[100], strtmproll[10], strtmpsection[5];
	int i=0;
	char choice;
	FILE *NE=0;
	NE = fopen("Studentdata.txt","a+");
	if (NE==NULL)
	{
		printf("File cannot be opened", stderr);
		exit(1);
	}

	struct newstud s;
	struct studentdata s1[200];
	gotoxy(45,5);
	printf("Enter year: ");
	scanf("%d",&s.year);
	fprintf(NE, "%d",s.year);
	gotoxy(45,7);
	printf("Enter department: ");
	scanf("%s",&s.department);
	fprintf(NE, "\n%s",s.department);


	while(choice!='C')
	{
		system("cls");
		gotoxy(45,5);
		printf("Enter name: ");
		scanf("%s",s1[i].name);


		gotoxy(45,7);
		printf("Enter roll number: ");
		scanf("%s",s1[i].rollno);


		gotoxy(45,9);
		printf("Enter section: " );
		scanf("%s",s1[i].section);


		fprintf(NE,"\n\n%s",s1[i].name);
		fprintf(NE,"\n%s",s1[i].rollno);
		fprintf(NE, "\n%s",s1[i].section);
		fflush(stdin);
		i++;
		printf("Press 'C' if data entry is complete else press 'enter' to continue data entry.");
		scanf("%c",&choice);
		fflush(stdin);
	}

	fclose(NE);

	return 0;
}
int entryORattendance()
{
    system("color f0");
	int fate;
	gotoxy(45,18);
	printf("1) Press 1 to enter data of new students: ");
	gotoxy(45,20);
	printf("2) Press 2 to take attendance: ");
	scanf("%d",&fate);

	if (fate==1)
	{
		system("cls");
		system("color f0");
		newentry();
	}

	else
	{
		system("cls");
		system("color f0");
		attendance();
	}
	return 0;
}

#endif

