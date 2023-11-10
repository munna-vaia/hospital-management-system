#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct patient
{
    int age;
    char gender[1];
    char name[30];
    char contactnumber[15];
    char doctor[20];
    char problem[20];
};
struct patient p, temp char ans = 0;
int ok = 0;
int b, valid = 0;
int main()
{ //    char ans;
     FILE *ek;
    ek = fopen("record2.txt", "a");
    printf("\n\n Add record \n");
    do
    {
    A:
        printf("\nname:");
        // scanf("%s",p.name);
        gets(p.name);
        if (strlen(p.name) > 30 || strlen(p.name) < 5)
        {
            printf("invalid name");
            goto A;
        }
        else
        {
            valid = 1;
            // for (b = 0; b < strlen(p.name); b++)
            // {
            //     if (isalpha(p.name[b]))
            //         valid = 1;
            //     else
            //     {
            //         valid = 0;
            //         break;
            //     }
            // }
            // if (!valid)
            //     goto A;
        }
    } while (!valid);

    printf("\n gender[M/F]:");
    scanf("%c", &p.gender);

    // age
    printf("\nAge:");
    scanf("%d", &p.age);
    // Address
    do
    {
    C:
        printf("\ncontact number");
        scanf("%s", p.contactnumber);
        for (b = 0; b < strlen(p.contactnumber); b++)
        {
            if (!(isalpha(p.contactnumber[b])))
                valid = 1;
            else
                valid = 0;
        }
        if (!valid)
            goto C;
    } while (!valid);
    // problem
    do
    {
    D:
        printf("\nproblem");
        scanf("%s", p.problem);
        if (strlen(p.problem) > 15 || strlen(p.problem) < 4)
        {
            printf("invalid problem");
            goto D;
        }
    } while (!valid);
    // doctor name
E:
    printf("\ndoctor:");
    scanf("%s", p.doctor);

    for (b = 0; b < strlen(p.doctor); b++)
    {
        if (isalpha(p.doctor[b]))
            valid = 1;
        else
        {
            valid = 0;
            break;
        }
    }
    if (!valid)
    {
        printf("valid character name");
        goto E;
    }
    fprintf(ek, "%s%s%d%s%s%s\n", p.name, p.gender, p.age, p.contactnumber, p.problem, p.doctor);
    fclose(ek);
    return 0;
}
