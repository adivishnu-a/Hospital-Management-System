#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct record
{
    char name[30];
    char disease[30];
    char address[50];
    char gender;
    int room, phone, age;
} x[100];

struct staffinfo
{
    char name[25];
    char spec[25];
    int exp;
} info[5];

int n, i, j = 0, a = 0, sum = 0, g, flag, num;
int read();
void add();
void view();
void search();
void edit();
void del();
void show();
int write();
void staff();
void expense();

int main()
{
    read();
    int c, i, q;
    int m, n;
    char pw[25];
    system("cls");
    printf("--------------------------------------------\n");
    printf("-------- Hospital Management System --------\n");
    printf("--------------------------------------------\n");
    printf("\nWelcome to Admin Dashboard\nEnter your Password : ");
    gets(pw);
    int res=strcmp(pw,"admin");
    while(res != 0)
    {
        system("cls");
        printf("--------------------------------------------\n");
        printf("-------- Hospital Management System --------\n");
        printf("--------------------------------------------\n");
        printf("\n Wrong Password, Try again : ");
        gets(pw);
        res=strcmp(pw,"admin");
    }

    //Successful Login
    system("cls");
    printf("--------------------------------------------\n");
    printf("-------- Hospital Management System --------\n");
    printf("-----Successfully Entered the main menu-----\n");
    while (c != 8)
    {

        printf("Enter your choice \n\n1. Add Information\n2. View Information\n3. Search\n4. Edit Information\n5. Delete Information\n6. Staff Information\n7. Expense Calculation\n8. Save & Exit\n\nOption : ");
        scanf("%d", &c); //choice for option
        fflush(stdin);   //making it clear
        if (c == 1)      //add
        {
            system("cls");
            add();
        }
        else if (c == 2) //view
        {
            system("cls");
            view();
        }
        else if (c == 3) //search
        {
            system("cls");
            search();
        }
        else if (c == 4) //edit
        {
            system("cls");
            edit();
        }
        else if (c == 5) //delete
        {
            system("cls");
            del();
        }
        else if (c == 6) //staff
        {
            system("cls");
            staff();
        }
        else if (c == 7) //expense
        {
            system("cls");
            expense();
        }
        else if (c == 8)
        {
            write();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}
void add()
{
    printf("\n\n");
    printf("Already data inputed on the database : %d\n", num); //how many inputs
    printf("How many entry do you want to add : ");
    scanf("%d", &n);
    sum = n + num;

    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's Name : ");
        gets(x[i].name);
        fflush(stdin);
        printf("Enter disease : ");
        gets(x[i].disease);
        fflush(stdin);
        printf("Enter the age : ");
        scanf("%d", &x[i].age);
        fflush(stdin);
        printf("Enter the gender (M/F/N) : ");
        scanf("%c", &x[i].gender);
        fflush(stdin);
        printf("Enter patient's Address : ");
        gets(x[i].address);
        fflush(stdin);
        printf("Enter Room No. : ");
        scanf("%d", &x[i].room);
        fflush(stdin);
        printf("Enter phone number : ");
        scanf("%d", &x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}

void view()
{
    for (i = 0; i < num; i++)
    {
        printf("\n");
        printf("Serial Number : %d\n", i);
        printf("Name : ");
        puts(x[i].name);
        printf("Disease : ");
        puts(x[i].disease);
        printf("Room no : %d\nPhone number : %d\nAge : %d\nGender : %c", x[i].room, x[i].phone, x[i].age, x[i].gender);
        printf("Patient Address : ");
        puts(x[i].address);
        printf("--------------------------------------------\n");
    }
}
void edit()
{
    int q, p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1. Name\n2. Disease\n3. Age\n4. Room No.\n5. Phone no.\n6. Gender\n7. Address\n");
    printf("Option=");
    scanf("%d", &q); //option
    if (q <= 7)
    {
        printf("Enter the serial no of that patient (0 - %d) : ", num - 1);
        scanf("%d", &p); //serial number
        if (p < num)
        {
            if (q == 1)
            {
                fflush(stdin);
                printf("Enter the new Name : ");
                gets(x[p].name);
            }
            else if (q == 2)
            {
                fflush(stdin);
                printf("Enter the new Disease : ");
                gets(x[p].disease);
            }
            else if (q == 3)
            {
                fflush(stdin);
                printf("Enter the new Age : ");
                scanf("%d", &x[p].age);
            }

            else if (q == 4)
            {
                fflush(stdin);
                printf("Enter the new Room no : ");
                scanf("%d", &x[p].room);
            }

            else if (q == 5)
            {
                fflush(stdin);
                printf("Enter the new Phone no : ");
                scanf("%d", &x[p].phone);
            }
            else if (q == 6)
            {
                fflush(stdin);
                printf("Enter the new Gender : ");
                scanf("%c", &x[p].gender);
            }
            else if (q == 7)
            {
                fflush(stdin);
                printf("Enter the new Address : ");
                gets(x[p].address);
            }
        }
        else
        {
            printf("\n\nInvalid Option \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void search()
{
    int s, h, f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1. Serial no.\n2. Name\n3. Disease\n4. Room no.\n5. Phone no.\n6. Age\n7. Gender\n8. Address\n\nOption : ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("Enter Serial number of the patient : ");
        scanf("%d", &s);
        if (s < num)
        {
            printf("\n");
            printf("Serial Number : %d\n", s);
            printf("Name : ");
            puts(x[s].name);
            printf("Disease : ");
            puts(x[s].disease);
            printf("Room no : %d\nPhone number : %d\nAge : %d\nGender : %c", x[s].room, x[s].phone, x[s].age, x[s].gender);
            printf("Address : ");
            puts(x[s].address);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if (h == 2)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter your name : ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].name) == 0)
            {
                printf("\n");
                printf("Serial Number : %d\n", g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Room no : %d\nPhone number : %d\nAge : %d\nGender : %c", x[g].room, x[g].phone, x[g].age, x[g].gender);
                printf("Address : ");
                puts(x[g].address);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 3)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter Disease : ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].disease) == 0)
            {
                printf("\n");
                printf("Serial Number : %d\n", g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Room no : %d\nPhone number : %d\nAge : %d\nGender : %c", x[g].room, x[g].phone, x[g].age, x[g].gender);
                printf("Address : ");
                puts(x[g].address);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 4)
    {
        int f = 1;
        printf("Enter Room number : ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].room)
            {
                printf("\n");
                printf("Serial Number : %d\n", g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Room no : %d\nPhone number : %d\nAge : %d\nGender : %c", x[g].room, x[g].phone, x[g].age, x[g].gender);
                printf("Address : ");
                puts(x[g].address);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else if (h == 5)
    {
        int f = 1;
        printf("Enter Phone number : ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].phone)
            {
                printf("\n");
                printf("Serial Number : %d\n", g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Room no : %d\nPhone number : %d\nAge : %d\nGender : %c", x[g].room, x[g].phone, x[g].age, x[g].gender);
                printf("Address : ");
                puts(x[g].address);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found");
    }
    else if (h == 6)
    {
        int f = 0;
        printf("Enter Age : ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].age)
            {
                printf("\n");
                printf("Serial Number : %d\n", g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Room no : %d\nPhone number : %d\nAge : %d\nGender : %c", x[g].room, x[g].phone, x[g].age, x[g].gender);
                printf("Address : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("Not Found\n\n");
    }
    else if (h == 7)
    {
        int f = 0;
        char gen;
        printf("Enter Gender : ");
        scanf("%c", &gen);
        for (g = 0; g < num; g++)
        {
            if (gen == x[g].gender)
            {
                printf("\n");
                printf("Serial Number : %d\n", g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Room no : %d\nPhone number : %d\nAge : %d\nGender : %c", x[g].room, x[g].phone, x[g].age, x[g].gender);
                printf("Address : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("Not Found\n\n");
    }
    else if (h == 7)
    {
        int f = 0;
        fflush(stdin);
        printf("Enter Address : ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].address) == 0)
            {
                printf("\n");
                printf("Serial Number : %d\n", g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Room no : %d\nPhone number : 0%d\nAge : %d\nGender : %c", x[g].room, x[g].phone, x[g].age, x[g].gender);
                printf("Address : ");
                puts(x[g].address);
                printf("\n\n");
                f = 1;
            }
        }
        if (f == 0)
            printf("\nNot Found\n");
    }
    else
        printf("\n\nInvalid input\n\n");
}
void del()
{
    int f, h;
    printf("Enter the serial number of the patient that you want to delete : ");
    scanf("%d", &f);
    if (f < num)
    {
        printf("What do you want ?\n");
        printf("1. Remove the whole record\n2. Remove Name\n3. Remove Disease\n4. Remove age\n5. Remove Room No.\n6. Remove phone number\n7. Remove Gender\n8. Remove Address\nOption : ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(x[f].name, x[f + 1].name);
                strcpy(x[f].disease, x[f + 1].disease);
                strcpy(x[f].address, x[f + 1].address);
                x[f].age = x[f + 1].age;
                x[f].gender = x[f + 1].gender;
                x[f].room = x[f + 1].room;
                x[f].phone = x[f + 1].phone;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(x[f].name, "Cleared");
        }
        else if (h == 3)
        {
            strcpy(x[f].disease, "Cleared");
        }
        else if (h == 4)
        {
            x[f].age = 0;
        }
        else if (h == 5)
        {
            x[f].room = 0;
        }
        else if (h == 6)
        {
            x[f].phone = 0;
        }
        else if (h == 7)
        {
            x[f].gender = 'O';
        }
        else if (h == 8)
        {
            strcpy(x[f].address, "Cleared");
        }
    }
    else
        printf("\n\nInvalid Serial number\n");
}
void staff()
{
    strcpy(info[0].name, "Dr. Naresh Trehan");
    strcpy(info[0].spec, "Cardiology");
    info[0].exp = 15;

    strcpy(info[1].name, "Dr. Myles Abbott");
    strcpy(info[1].spec, "Pediatrician");
    info[1].exp = 22;

    strcpy(info[2].name, "Dr. Fouad Abbas");
    strcpy(info[2].spec, "Oncology");
    info[2].exp = 12;

    strcpy(info[3].name, "Dr. Reese Anderson");
    strcpy(info[3].spec, "Psychiatry");
    info[3].exp = 10;

    strcpy(info[4].name, "Dr. Sudhansh Datta");
    strcpy(info[4].spec, "Neurosurgery");
    info[4].exp = 14;

    for (int i = 0; i < 5; i++)
    {
        printf("Doctor Name    : %s\n", info[i].name);
        printf("Specialization : %s\n", info[i].spec);
        printf("Experience     : %d Years\n", info[i].exp);
        printf("---------------------------------------------\n")
    }
}
void expense()
{
    int days;
    float rent, medi, lab, trent, total, tax, final;
    printf("Enter the number of days : ");
    scanf("%d", &days);
    printf("Enter the rent of room per day : ");
    scanf("%f", &rent);
    printf("Enter the total cost of medicines : ");
    scanf("%f", &medi);
    printf("Enter the total laboratory expenses : ");
    scanf("%f", &lab);
    trent = days * rent;
    total = trent + medi + lab;
    tax = 0.15 * total;
    final = total + tax;
    printf("------------------------------------------------------\n");
    printf("Total Rent                  = %.2f\n", trent);
    printf("Total Cost of all expenses  = %.2f\n", total);
    printf("Tax on total                = %.2f\n", tax);
    printf("------------------------------------------------------\n");
    printf("Final Total incl. tax       = %.2f\n", final);
    printf("------------------------------------------------------\n");
}
int read()
{
    FILE *fp = fopen("records.txt", "r");
    if (fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("records.txt", "w");
        fclose(fp);
        printf("File does not exist, creating now...\n\n");
        return 0;
    }

    num = fread(x, sizeof(struct record), 100, fp);
    fclose(fp);
}
int write()
{
    FILE *fp = fopen("records.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct record), num, fp);

    fclose(fp);
}
