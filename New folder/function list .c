#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
struct patient
{
    int age;
    char gender[1];
    char name[30];
    char contactnumber[15];
    char doctor[20];
    char problem[20];
};
struct patient p,temp;
void gotoxy(short x,short y)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int main()
{
    FILE *ek;
    ek=fopen("record2.txt","r");
    printf("\n\n list of patient\n");
    gotoxy(1,15);
    printf("Full Name");
    gotoxy(20,15);
    printf("gender");
    gotoxy(32,15);
    printf("Age");
    gotoxy(36,15);
    printf("contactnumber");
    gotoxy(50,15);
    printf("problem");
    gotoxy(63,15);
    printf("doctor");
    int row=17;
    while (fscanf(ek,"%s %s %d %s %s %s\n",p.name,p.gender,&p.age,p.contactnumber,p.problem,p.doctor)!=EOF)
    {gotoxy(1,row);
    printf("%s",p.name);
    gotoxy(20,row);
    printf("%s",p.gender);
    gotoxy(32,row);
    printf("%d",p.age);
    gotoxy(36,row);
    printf("%s",p.contactnumber);
    gotoxy(50,row);
    printf("%s",p.problem);
    gotoxy(63,row);
    printf("%s",p.doctor);
    row++;
        /* code */
    }
    fclose(ek);
   // Main_menu();

}
