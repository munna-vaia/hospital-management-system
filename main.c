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
    char name[60];
    char contactnumber[15];
    char doctor[20];
    char problem[20];
};
struct patient p, temp;
void add_rec();
void func_list();
void del_rec();
void seach_rec();
void ex_it();
void Main_menu()
{
    int chose;
    while (1)
    {
        printf("\n\nchoese form 1 to 4:\n");
        printf("add the record press 1:\n");
        printf("function list press 2:\n");
        printf("delete record press 3:\n");
        printf("seach the record press 4:\n");
        printf("exit record press 5:\n");
        scanf("%d", &chose);
        fflush(stdin);
        switch (chose)
        {
        case 1:
            add_rec();
            break;
        case 2:
            func_list();
            break;
        case 3:
            del_rec();
            break;
        case 4:
            seach_rec();
            break;
        case 5:
            ex_it();
            return;
        default:
            printf("please enter your right option");
            break;
        }
    }
}
char ans = 0;
int b, valid = 0;
void add_rec()
{
    fflush(stdin);
    FILE *ek = NULL;
    ek = fopen("record2.txt", "ab");
    printf("\n\n\t\t\t\t\t\t Add patient record \n");
    do
    {
    A:
        printf("\nname:");
        fflush(stdin);
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
    fflush(stdin);
    scanf("%c", &p.gender);

    // age
    printf("\nAge:");
    fflush(stdin);
    scanf("%d", &p.age);
    // contact number
    do
    {
    C:
        printf("\ncontact number:");
        fflush(stdin);
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
        printf("\nproblem:");
        fflush(stdin);
        gets(p.problem);
        if (strlen(p.problem) > 15 || strlen(p.problem) < 4)
        {
            printf("invalid problem");
            goto D;
        }
    } while (!valid);
    // doctor name
    do
    {
    E:
        printf("\ndoctor:");
        fflush(stdin);
        gets(p.doctor);
        if (strlen(p.doctor) > 20 || strlen(p.doctor) < 5)
        {
            printf("invalid name");
            goto E;
        }
        else
        {
            valid = 1;
        }
    } while (!valid);
    fwrite(&p, sizeof(p), 1, ek);
    fclose(ek);
}
void func_list()
{
    FILE *ek;
    ek = fopen("record2.txt", "rb");
    printf("\n\n\t\t\t\t\t\t list of patient\n");
    fflush(stdin);
    printf("%-20s", "Full name");
    printf("%-20s", "gender");
    printf("%-20s", "Age");
    printf("%-20s", "Contact number");
    printf("%-20s", "problem");
    printf("%-20s", "doctor");
    puts("");
    puts("");
    // system("cls");
    while (fread(&p, sizeof(p), 1, ek) == 1)
    {
        printf("%-20s", p.name);
        printf("%-20c", p.gender);
        printf("%-20d", p.age);
        printf("%-20s", p.contactnumber);
        printf("%-20s", p.problem);
        printf("%-20s", p.doctor);
        puts("");
    }
    fclose(ek);
}
void del_rec()
{
    char name[20];
    int found = 0;
    FILE *ek, *ft;
    ft = fopen("temp.txt", "wb");
    ek = fopen("record2.txt", "rb");
    printf("\n\n\t\t\t\t\t\tdelete patient record");
    printf("\nenter patient name:");
    fflush(stdin);
    gets(name);
    while (fread(&p, sizeof(p), 1, ek) == 1)
    {
        if (strcmp(p.name, name) != 0)
        {
            fwrite(&p, sizeof(p), 1, ft);
            // fprintf(ft, "%s%c%d%s%s%s", p.name, p.gender, p.age, p.contactnumber, p.problem, p.doctor);
        }
        else
        {
            printf("\t\t\t\t\t\tDelete successfully\n");
            // printf("%s%c%d%s%s%s", p.name, p.gender, p.age, p.contactnumber, p.problem, p.doctor);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("\n\nrecord not found");
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("record2.txt");
        rename("temp.txt", "record2.txt");
        getch();
    }
}
void seach_rec()
{
    char name[20];
    int found=0;
    FILE *ek;
    ek=fopen("record2.txt","rb");
     printf("\nenter patient name:");
    fflush(stdin);
    gets(name);
    while (fread(&p, sizeof(p), 1, ek) == 1)
    {    if (strcmp(p.name, name) == 0)
            { printf("%s  %c  %d  %s  %s   %s", p.name, p.gender, p.age, p.contactnumber, p.problem, p.doctor);
            found = 1;
            }
    }
       if (found == 0)
            {
            printf("\n\nrecord not found");
            }
      else
          {
        fclose(ek);
        getch();
           }
}
void ex_it()
{
    system("cls");
    // title();
    printf("\n\n\n\n\t\t\t\t\t\tTHANK YOU FOR VISITING");
    getch();
}

void wellcomescreen()
{
    printf("\n\n\n\n\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$");
    printf("\n\t\t\t\t\t\t\twellcome ");
    printf("\n\t\t\t\t\t\t  HOSPTAL MANAGEMENT");
    printf("\n\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$");
    printf("\n\n\n\n\nPress to key continue ");
    getch();
    system("cls");
}
void title()
{
    printf("\n\n\t\t\t\t\t\t***************************");
    printf("\n\t\t\t\t\t\t     LIFE CARE HOSPITAL");
    printf("\n\t\t\t\t\t\t***************************");
    getch();
}
void loginscreen()
{
    char username[15];
    char password[15];
    char original_name[] = "munna";
    char original_password[] = "munna";
    int e = 0;
    do
    {
        fflush(stdin);
        printf("\n\n\n\nenter your username and password");
        printf("\n\n\nusername=");
        scanf("%s", &username);
        printf("\n\n\npassword=");
        scanf("%s", &password);
        if ((strcmp(username, original_name) == 0) && (strcmp(password, original_password) == 0))
        {
            printf("\n\n\nlogin successful");
            getch();
            Main_menu();
            break;
        }
        else
        {
            printf("password incorrect try again");
            e++;
            getch();
        }

    } while (e <= 2);
}
int main()
{
    wellcomescreen();
    title();
    loginscreen();
    return 0;
}