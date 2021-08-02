/*
 *   Copyright (c) 2019 
 *   All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define File "data.dat"

typedef struct car
{
    int id;
    char company[20];
    int name;
    int model;
    int price;
    char status[20];

} cars;

void menu(const char status[20]);
void add(const char status[20]);
void del(const char status[20]);
void sales_record(const char status[20]);
void quantity(const char status[20]);
void main_menu();

cars b[100];
int count = 0;
FILE *file;
int main()
{
    if ((file = fopen(File, "rb")) == NULL)
    {
        fclose(file);
        file = fopen(File, "wb");
        fclose(file);
    }
    fclose(file);
    main_menu();
}
void main_menu()
{
    int type;
    char status[20];
    printf("\n_______________________________________________________________________________________________________________\n\n");
    printf("\n---------------------------->>WELCOME TO Thadd &  Son's AUTOSHOP<<-------------------------------------------------\n");
    printf("\n\n_______________________________________________________________________________________________________________\n");
    do
    {
        printf("Enter\n1) For Dealing with Record of New Cars \n2) For Dealing with Record of 2nd Hand Cars\n ");
        scanf("%d", &type);
        if (type == 1 || type == 2)
        {
            menu((type == 1 ? "New Cars" : "2nd Hand Cars"));
        }
        else
        {
            printf("Invalid Choice\n");
        }

    } while (type == 1 || type == 2);
}
void menu(const char status[20])
{
    int i;
    do
    {
        printf("\n_______________________________________________________________________\n");
        printf("Enter \n1) Add\n2) Delete\n3) Search Sales Record\n4) Quantity Of Cars\n5) Exit\nEnter Your Choice:\n");
        printf("\n_______________________________________________________________________\n");
        scanf("%d", &i);
        if (i < 1 || i > 5)
        {
            printf("\nInvalid Choice\nExiting........\n");
            break;
        }
        else
        {
            switch (i)
            {
            case 1:
                add(status);
                break;
            case 2:
                del(status);
                break;
            case 3:
                sales_record(status);
                break;
            case 4:
                quantity(status);
                break;
            case 5:
                printf("\n_______________________________________________________________________\n");
                printf("----------------------------------------->>Thank You For Your Time!!!<<-----------------------------------------\n");
                printf("\n_______________________________________________________________________\n");
                break;
            default:
                break;
            }
        }
    } while (i >= 1 && i <= 4);
    return;
}

void add(const char status[20])
{
    fflush(stdin);
    FILE *write_file;
    cars b, retrieved;
    if ((write_file = fopen(File, "rb")) == NULL)
    {
        printf("Failed to Open File\n");
        exit(1);
    }
    else
    {

        char temp[20];
    id:
        printf("\nEnter ID : ");
        scanf(" %d", &b.id);
        fread(&retrieved, sizeof(cars), 1, write_file);
        while (!feof(write_file))
        {
            if (b.id == retrieved.id)
            {
                printf("\n ID is already assigned to another product\n");
                goto id;
            }
            fread(&retrieved, sizeof(cars), 1, write_file);
        }
        fclose(write_file);
        write_file = fopen(File, "ab");
        printf("\nEnter Company:\t");
        scanf("%s", temp);
        printf("\nEnter Engine Power:\t");
        scanf("%d", &b.name);
        printf("\nEnter Model:\t");
        scanf("%d", &b.model);
        printf("\nEnter Price:\tRs. ");
        scanf("%d", &b.price);
        strcpy(b.status, status);
        strcpy(b.company, temp);
        fwrite(&b, sizeof(cars), 1, write_file);
        fclose(write_file);
    }
}

void sales_record(const char status[20])
{
    int i, count = 0;
    cars b;
    FILE *file_read;
    printf("\nEnter ID of the Car to be Searched:\t");
    scanf("%d", &i);
    printf("\n_______________________________________________________________________\n");
    printf("\n\n%7s%25s%7s%7s%7s\n\n", "ID", "Company", "Name", "Model", "Price");
    if ((file_read = fopen(File, "rb")) == NULL)
    {
        printf("Failed to Open File\n");
        exit(1);
    }
    else
    {
        fread(&b, sizeof(cars), 1, file_read);
        while (!feof(file_read))
        {
            if (b.id == i && strcmp(b.status, status) == 0)
            {
                printf("\n_______________________________________________________________________\n");
                printf("\n%7d%25s%7d%7d%7d\n", b.id, b.company, b.name, b.model, b.price);

                count++;
            }
            fread(&b, sizeof(cars), 1, file_read);
        }
        fclose(file_read);
    }
    if (count > 0)
    {
        printf("\n%d Entries Found in File\n", count);
    }
    else
    {
        printf("\nNo Entries Found\n");
    }
}

void del(const char status[20])
{
    int id, count = 0;
    cars b;
    FILE *file_read;
    cars empty = {0, " ", 0, 0, 0, " "};
    printf("\nEnter ID of the Car to be Deleted:\t");
    scanf("%d", &id);
    if ((file_read = fopen(File, "rb+")) == NULL)
    {
        printf("Failed to Open File\n");
        exit(1);
    }
    else
    {
        fread(&b, sizeof(cars), 1, file_read);
        while (!feof(file_read))
        {
            if ((b.id == id) && (strcmp(b.status, status) == 0))
            {
                fseek(file_read, (count * sizeof(cars)), SEEK_SET);
                fwrite(&empty, sizeof(cars), 1, file_read);
                printf("\nRecord Successfully Deleted!!\n\n");
                break;
            }
            fread(&b, sizeof(cars), 1, file_read);
            count++;
        }
        fclose(file_read);
    }
}
void quantity(const char status[20])
{
    int i, count = 0;
    cars b;
    FILE *file_read;
    if ((file_read = fopen(File, "rb")) == NULL)
    {
        printf("Failed to Open File\n");
        exit(1);
    }
    else
    {
        while (!feof(file_read))
        {
            fread(&b, sizeof(cars), 1, file_read);
            if (strcmp(b.status, status) == 0)
            {
                count++;
            }
        }
        fclose(file_read);
    }
    printf("\n_______________________________________________________________________\n");
    printf("\n\n%d %s Found in File\n\n", count, status);
    printf("\n_______________________________________________________________________\n");
}
