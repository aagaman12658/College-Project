#fndef __attendance
#define __attendance



#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct date
{
	int day[31];
	int month[12];
	int year[100];
};

void attendance()
{
    printf("aagaman");
    int studentcount=0, daycount=0;
	static int n=0;
	n+=1;
	float attendpercent=0;
	char ch='0';
	system("cls");
	system("color f0");
	struct date d[100];
	printf("Enter year: ");
	scanf("%d",d[n].year);
	printf("Enter month: ");
	scanf("%d",&d[n].month);
	printf("Enter day: ");
	scanf("%d",&d[n].day);
	if (((d[n].day)-(d[n-1].day))==1)
		daycount++;
	fflush(stdin);
	printf("Is student present?\nPress P for present.\nPress A for absent.\n>");
	scanf("%c",&ch);
	if (ch=='P')
		studentcount++;
	attendpercent=((studentcount)/(daycount))*100;
	printf("The attendance percentage of student is: %f%c.",attendpercent,37);
}

#endif

