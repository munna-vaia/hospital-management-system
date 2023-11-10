#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct patient
{
    int age;
    char gender;
    char name[30];
    char contactnumber[15];
    char doctor[20];
    char problem[20];
};
struct patient p, temp;
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main()
{
    FILE *ek;
    ek = fopen("record2.txt", "r");
    printf("\n\n list of patient\n");
    //fflush(stdin);
    gotoxy(1, 20);
    printf("Full name\t");
    gotoxy(10,20);
    printf("gender\t");
    gotoxy(15,20);
    printf("Age\t");
    gotoxy(30,20);
    printf("contactnumber\t");
    gotoxy(40,20);
    printf("problem\t");
    gotoxy(55,20);
    printf("doctor\t");
    //system("cls");
    int row=22;
    while (fscanf(ek, "%s %c %d %s %s %s\n", p.name, &p.gender, &p.age, p.contactnumber, p.problem, p.doctor) != EOF)
    {
        gotoxy(1,row);
        printf("%s\t", p.name);
        gotoxy(10,row);
        printf("%c\t", p.gender);
        gotoxy(15,row);
         printf("%d\t", p.age);
        gotoxy(30,row);
         printf("%s", p.contactnumber);
        gotoxy(40,row);
         printf("%s", p.problem);
        gotoxy(55,row);
         printf("%s", p.doctor);
         row++;
        /* code */
    }
    fclose(ek);
    // Main_menu();
}
printf("function list");
    FILE *ek;
    ek = fopen("record2.txt", "r");
    printf("\n\n list of patient\n");
    gotoxy(1, 15);
    printf("Full Name");
    gotoxy(20,15);
    printf("gender");
    gotoxy(32,15);
    printf("Age");
    gotoxy(37,15);
    printf("contactnumber");
    gotoxy(49,15);
    printf("problem");
    gotoxy(59,15);
    printf("doctor");
    //system("cls");
    while (fscanf(ek, "%s %s %d %s %s %s\n", p.name, p.gender, &p.age, p.contactnumber, p.problem, p.doctor) != EOF)
    {
        gotoxy(15, 5);
        printf("%s", p.name);
        gotoxy(15, 7);
        printf("%s", p.gender);
        gotoxy(15, 9);
         printf("%d", p.age);
        gotoxy(15, 11);
         printf("%s", p.contactnumber);
        gotoxy(15, 13);
         printf("%s", p.problem);
        gotoxy(15, 15);
         printf("%s", p.doctor);
        /* code */
    }
    fclose(ek);