/*
 *   Copyright (c) 2019 
 *   All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int get_number();
int get_initial_value(int);

int main()
{
    int arr[2][2], i, j, x, number, type;

    int difficulty_level;

    printf("Enter dificulty level:\t 1-Easy\t 2-Moderate\t 3-Hard\n");
    scanf("%d", &difficulty_level);

    arr[0][0] = get_initial_value(difficulty_level);
get_second_value:
    arr[1][0] = get_initial_value(difficulty_level);
    if (arr[0][0] == arr[1][0])
    {
        goto get_second_value;
    }
    //----------------------------------------------------------------------------------------------------------------
    srand(time(NULL));
    x = (rand() % 3) + 1;
    switch (x)
    {
    // For Squaring
    case 1:
        for (i = 0; i < 2; i++)
        {
            arr[i][1] = (arr[i][0] * arr[i][0]);
        }
        break;
    case 2:
        //For Increment
        number = get_number();
        for (i = 0; i < 2; i++)
        {
            arr[i][1] = arr[i][0] + number;
        }
        break;
    case 3:
        //For decrement
        number = get_initial_value(difficulty_level);
        for (i = 0; i < 2; i++)
        {
            arr[i][1] = arr[i][0] - number;
        }
        break;
    }
    // ------------------------------------------------------------------------------------------------------------------------------
    //for missing number
    int index1, index2;
    srand(time(NULL));
    index1 = (rand() % 2);
    index2 = (rand() % 2);
    // For Output
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (i == index1 && j == index2)
            {
                printf("?\t");
            }
            else
            {
                printf("%d\t", arr[i][j]);
            }
        }

        printf("\n");
    }
    int entered_number = 0;
    printf("\n_________________________________________________________________________________\n\n");
    printf("\n\t\t\t\t What's the missing number? :\t");
    scanf(" %d", &entered_number);
if (entered_number == arr[index1][index2])
{
    printf("\n \t\t\t\t\t\t\t Correct Answer\n\n");
}else
{
    printf("\n \t\t\t\t\t\t\t Wrong Answer\n\n Original Series is:\n");
for (i = 0; i < 2; i++)
{
    for (j = 0; j < 2; j++)
    {
        printf("%d\t", arr[i][j]);
    }
    printf("\n");
}
}

return 0;
}

int get_initial_value(int x)
{
    int i;

    switch (x)
    {

    case 1:
    {

        srand(time(NULL));
        return (i = (rand() % 10) + 1);
        break;
    }

    case 2:
    {

        srand(time(NULL));
        return (i = (rand() % 20) + 11);
        break;
    }

    case 3:
    {

        srand(time(NULL));
        return (i = (rand() % 30) + 21);
        break;
    }

    default:

        printf("Invalid input\n");
    }
}

int get_number()
{
    srand(time(NULL));
    return ((rand() % 199) + 31);
}
