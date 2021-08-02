/*
 *   Copyright (c) 2019 
 *   All rights reserved.
 */

/**
 * ______________________________________________________________________________________________________
 * ______________________________________________________________________________________________________
 */
/**
 * ___________________________
 * 
 * INCLUDING LIBRARIES
 * 
 * ___________________________
 */
#include <stdio.h>

/**
 * ____________________________
 * 
 * END INCLUDING LIBRARIES
 * 
 * ____________________________
 */

/**
 * _________________________________________________________________________________________________________
 * _________________________________________________________________________________________________________
 */
/**
 * _____________________________________
 * 
 * INITIALIZATION OF CUSTOM FUNCTION
 * 
 * _____________________________________
 */
void get_marks(float subject[][4], int rows);
void evaluate_total(float subject[][4], int rows);
float get_maximum_marks(float subject[][4], int rows);
float get_minimum_marks(float subject[][4], int rows);
float get_average_marks(float subject[][4], int rows);
void show_results(float subject[][4], int rows, float maximum, float minimum, float average);
/**
 * ______________________________________
 * 
 * END INITIALIZATION OF CUSTOM FUNCTION
 * 
 * _______________________________________
 */

/**
 * _______________________________________________________________________________________________________________
 * _______________________________________________________________________________________________________________
 */

/**
 * _____________________
 * 
 * MAIN FUNCTION
 * 
 * _____________________
 */
int main()
{
    float subject[10][4], maximum, minimum, average;
    get_marks(subject, 10);
    evaluate_total(subject, 10);
    maximum = get_maximum_marks(subject, 10);
    minimum = get_minimum_marks(subject, 10);
    average = get_average_marks(subject, 10);
    show_results(subject, 10, maximum, minimum, average);
    return 0;
}
/**
 * ______________________
 * 
 * END MAIN FUNCTION
 * 
 * ______________________
 */
/**
 * ________________________________________________________________________________________________________________
 * ________________________________________________________________________________________________________________
 */
/**
 * ____________________________________
 * 
 * DEFINITION OF CUSTOM FUNCTION
 * 
 * ____________________________________
 */
/**
 * _________________________________________________________________________________________________________________
 * _________________________________________________________________________________________________________________
 */
/**
 * @function: get_marks();
 * This function takes a two dimensional 
 * array as an argument and get values
 * from user.
 * @param: array[][], rows
 * @return: Null;
 */
void get_marks(float subject[][4], int rows){
for (int i = 0; i < rows; i++)
{
    printf("\n\n\t\t\t\t\t Enter Marks For Subject %d\n\n", (i + 1));
    /* For Sessional 1 */
        s1:
        printf("\nEnter S1 Marks:\t");
        scanf("%f", &subject[i][1]);
        if (subject[i][1] < 0 || subject[i][1] > 100)
        {
            printf("\n Entered Marks are out of range, TRY AGAIN!:\n");
            goto s1;
        }
        /* For Sessional 2 */
        s2:
        printf("\nEnter S2 Marks:\t");
        scanf("%f", &subject[i][2]);
        if (subject[i][2] < 0 || subject[i][2] > 100)
        {
            printf("\n Entered Marks are out of range, TRY AGAIN!:\n");
            goto s2;
        }
        /* For Terminal */
        terminal:
        printf("\nEnter Terminal Marks:\t");
        scanf("%f", &subject[i][3]);
        if (subject[i][3] < 0 || subject[i][3] > 100)
        {
            printf("\n Entered Marks are out of range, TRY AGAIN!:\n");
            goto terminal;
        }
}
}

/**
 * ____________________________________________________________________________________________________
 * ____________________________________________________________________________________________________
 */
/**
 * @function: evaluate_total();
 * This function takes a two dimensional 
 * array as an argument and evaluates 
 * total marks!
 * @param: array[][], rows
 * @return: Null;
 */
void evaluate_total(float subject[][4], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        subject[i][4] = (subject[i][1] / 4) + (subject[i][2] / 4) + (subject[i][3] / 2);
    }
}
/**
 * ____________________________________________________________________________________________________
 * ____________________________________________________________________________________________________
 */
/**
 * @function: get_maximum_marks();
 * This function takes a two dimensional 
 * array as an argument and returns maximum
 * marks.
 * @param: array[][], rows
 * @return: float;
 */
float get_maximum_marks(float subject[][4], int rows)
{
    float max = 0;
    for (int i = 0; i < rows; i++)
    {
        if (subject[i][4] > max)
        {
            max = subject[i][4];
        }
        }
        return max;
}
/**
 * ____________________________________________________________________________________________________
 * ____________________________________________________________________________________________________
 */
/**
 * @function: get_minimum_marks();
 * This function takes a two dimensional 
 * array as an argument and returns minimum
 * marks.
 * @param: array[][], rows
 * @return: float;
 */
float get_minimum_marks(float subject[][4], int rows)
{
    float max = 100;
    for (int i = 0; i < rows; i++)
    {
        if (subject[i][4] < max)
        {
            max = subject[i][4];
        }
    }
    return max;
}
/**
 * ____________________________________________________________________________________________________
 * ____________________________________________________________________________________________________
 */
/**
 * @function: get_average_marks();
 * This function takes a two dimensional 
 * array as an argument and returns average
 * of total marks.
 * @param: array[][], rows
 * @return: float;
 */
float get_average_marks(float subject[][4], int rows)
{
    float average = 0;
    for (int i = 0; i < rows; i++)
    {
        average += subject[i][4];
    }
    return (average / 10);
}

/**
 * ____________________________________________________________________________________________________
 * ____________________________________________________________________________________________________
 */
void show_results(float subject[][4], int rows, float maximum, float minimum, float average){
    printf("\n\n%10s\t%10s\t%10s\t%10s\t%10s\n\n", "Subjects","S1(25%)","S2(25%)","Terminal(50%)","Total(100%)");
    printf("\n_________________________________________________________________________________");
    for (int i = 0; i < rows; i++)
    {
        printf("\n\n%8s%2d\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n", "Subject", (i + 1), subject[i][1], subject[i][2], subject[i][3],subject[i][4]);
    }
    printf("\n_________________________________________________________________________________");

    printf("\n\n\t\t\t\t Maximum Marks:\t%.2f\n", maximum);
    printf("\n\n\t\t\t\t Minimum Marks:\t%.2f\n", minimum);
    printf("\n\n\t\t\t\t Average Marks:\t%.2f\n", average);
}
/**
 * ____________________________________
 * 
 * END DEFINITION OF CUSTOM FUNCTION
 * 
 * ____________________________________
 */