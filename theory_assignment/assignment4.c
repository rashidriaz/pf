/*
 *   Copyright (c) 2019 
 *   All rights reserved.
 */

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */

/*
 *   Copyright (c) 2019 
 *   All rights reserved.
 */

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */

/**
 * ------------------------
 * 
 * INCLUDING LIBRARIES
 * 
 * ------------------------
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * ------------------------
 * 
 * END INCLUDING LIBRARIES
 * 
 * ------------------------
 */

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */

/**
 * -----------------------------
 * 
 * INITIALIZING CUSTOM FUNCTION
 * 
 * -----------------------------
 */
void menu();
void create_new_file(char *file_name);
void initialize_record();
void add_tool();
void remove_tool();
void update_tool();
int file_is_empty();
int record_number_exist(int);
void list_one_record();
void list_all_records();
/**
 * ---------------------------------
 * 
 * END INITIALIZING CUSTOM FUNCTIONS
 * 
 * ----------------------------------
 */

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */

/**
 * ------------------------------
 * 
 * DEFINITION OF STRUCTS
 * 
 * ------------------------------
 */
typedef struct
{
    int record;
    char name[100];
    int quantity;
    double cost;
} tool;
/**
 * ------------------------------
 * 
 * END DEFINITION OF STRUCTS
 * 
 * ------------------------------
 */

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */

/**
 * -----------------------------
 * 
 * MAIN FUNCTION
 * 
 * -----------------------------
 */

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */

int main()
{
    printf("\n\t\t\t\t Welcome To XYZ Hardware store\n\n\t\t\t\t\t Welcome Admin\n\n");
    printf("\n\t\t\t\t\tWhat Would You like to do?");
    menu();
    return 0;
}

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */

/**
 * ------------------------------
 * 
 * END MAIN FUNCTION
 * 
 * ------------------------------
 */

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */

/**
 * -------------------------------
 * 
 * DEFINITION OF CUSTOM FUNCTIONS
 * 
 * -------------------------------
 */

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */

/**
 * @function: menu();
 * This function prints the menu on
 * the screen and ask user to select
 * any operation he/she wants to perform.
 * @param: NULL
 * @return: NULL
 */
void menu()
{
    int choice = 0;

    printf("\nPress \"1\" to add a new tool!");
    printf("\nPress \"2\" to remove an existing tool!");
    printf("\nPress \"3\" to update an existing tool!");
    printf("\nPress \"4\" to see Information about specific tool from inventory!");
    printf("\nPress \"5\" to See a list of tools in inventory!");
    printf("\nPress \"6\" Exit!");
    printf("\n\t\t\tEnter your choice Here:\t");
    scanf("%d", &choice);

    if (choice == 1)
    {
        add_tool();
    }
    else if (choice == 2)
    {
        remove_tool();
    }
    else if (choice == 3)
    {
        update_tool();
    }
    else if (choice == 4)
    {
        list_one_record();
    }
    else if (choice == 5)
    {
        list_all_records();
    }
    else
    {
        printf("\nProgram Terminated Successfully!!\n\t\t\t\t\tGood BYE!!\n\n");
    }
}

/**
 * ----------------------------------------------------------------------------------------------------------------------
 * ----------------------------------------------------------------------------------------------------------------------
 */

/**
 * @function: initialize_record();
 * This function adds a new record
 * in FILE: tools.dat.
 * @param: NULL
 * @return: Null
 */
void add_tool()
{
    FILE *toolptr;
    tool new_tool, existing = {0, "", 0, 0};
    int last_record_number = 0;
    if ((toolptr = fopen("tool.dat", "rb+")) == NULL)
    {
        printf("\nCannot Open File: Tool.dat\n");
        printf("\n\t\t\t Creating a new file: tool.dat\n");
        create_new_file("tool.dat");
    }
    else
    {
        if (file_is_empty() == 1)
        {
            initialize_record();
        }

    /* Getting data about new record from user */
    enter_record:
        printf("\n\t\t\t\tEnter Tool Information Here!!\n\n");
        printf("\nEnter tool ID:\t");
        scanf("%d", &new_tool.record);
        if (record_number_exist(new_tool.record) == 1)
        {
            printf("\n\t\t\t\t\tERROR!!\n\n\t\t\t This tool ID is already assigned to another tool\n\t\t\t\t\t\n\nTry Again!\n");
            goto enter_record;
        }
        printf("\nEnter Tool Name:\t");
        scanf(" %[^\n]%*c", new_tool.name);
        printf("\nEnter Quantity:\t");
        scanf("%d", &new_tool.quantity);
        printf("\nEnter Cost of This Tool:\t");
        scanf("%lf", &new_tool.cost);
        /* getting record number of last record from file: tool.dat */
        fread(&existing, sizeof(tool), 1, toolptr);
        while (!feof(toolptr))
        {
            if (existing.record == 0)
            {
                break;
            }
            last_record_number++;
            fread(&existing, sizeof(tool), 1, toolptr);
        }
        fseek(toolptr, (last_record_number * sizeof(tool)), SEEK_SET);
        fwrite(&new_tool, sizeof(tool), 1, toolptr);
        printf("\n\n\t\t\t Record Entered Successfully!!\n");
        fclose(toolptr);
    }
    menu();
}

/**
 * ----------------------------------------------------------------------------------------------------------------------
 * ----------------------------------------------------------------------------------------------------------------------
 */
/**
 * @function: remove_tool();
 * This Function Removes an existing 
 * Tool record from the @file: tool.dat.
 * @param: Null
 * @return: Null
 */
void remove_tool()
{
    int record_number, count = 0;
    FILE *toolptr;
    tool existing;

    if ((toolptr = fopen("tool.dat", "rb+")) == NULL)
    {
        printf("\nCannot Open File: Tool.dat\n");
    }
    else
    {
        printf("\nEnter tool ID you want to remove:\t");
        scanf(" %d", &record_number);
        fread(&existing, sizeof(tool), 1, toolptr);
        while (!feof(toolptr))
        {
            if (existing.record == record_number)
            {
                break;
            }
            count++;
            fread(&existing, sizeof(tool), 1, toolptr);
        }
        if (existing.record != record_number)
        {
            printf("\n Tool with this ID doesn't Exist\n");
            remove_tool();
        }
        tool existing = {0, "", 0, 0};
        fseek(toolptr, (count * sizeof(tool)), SEEK_SET);
        fwrite(&existing, sizeof(tool), 1, toolptr);
        fclose(toolptr);
    }
    menu();
}

/**
 * ----------------------------------------------------------------------------------------------------------------------
 * ----------------------------------------------------------------------------------------------------------------------
 */
/**
 * @function: update_tool();
 * This Function Edits an existing 
 * Tool record from the @file: tool.dat.
 * @param: Null
 * @return: Null
 */
void update_tool()
{
    int record_number, count = 0;
    FILE *toolptr;
    tool existing;

    if ((toolptr = fopen("tool.dat", "rb+")) == NULL)
    {
        printf("\nCannot Open File: Tool.dat\n");
    }
    else
    {
        printf("\nEnter tool ID you want to Update:\t");
        scanf(" %d", &record_number);
        fread(&existing, sizeof(tool), 1, toolptr);
        while (!feof(toolptr))
        {
            if (existing.record == record_number)
            {
                break;
            }
            count++;
            fread(&existing, sizeof(tool), 1, toolptr);
        }
        if (existing.record != record_number)
        {
            printf("\n Tool with this ID doesn't Exist\n");
            remove_tool();
        }
        /* Getting Tool's Updated Information form user */
        printf("\n\t\t\t\tEnter Updated Information\n");
    enter_record:
        printf("\nEnter tool ID:\t");
        scanf("%d", &existing.record);
        if (record_number_exist(existing.record) == 1 && existing.record != record_number)
        {
            printf("\n\t\t\t\t\tERROR!!\n\n\t\t\t This tool ID is already assigned to another tool\n\t\t\t\t\t\n\nTry Again!\n");
            goto enter_record;
        }
        printf("\nEnter Tool Name:\t");
        scanf(" %[^\n]%*c", existing.name);
        printf("\nEnter Quantity:\t");
        scanf("%d", &existing.quantity);
        printf("\nEnter Cost of This Tool:\t");
        scanf("%lf", &existing.cost);
        fseek(toolptr, (count * sizeof(tool)), SEEK_SET);
        fwrite(&existing, sizeof(tool), 1, toolptr);
        fclose(toolptr);
    }
    menu();
}

/**
 * ----------------------------------------------------------------------------------------------------------------------
 * ----------------------------------------------------------------------------------------------------------------------
 */
/**
 * @function: list_one_record()
 * This function shows Only One record
 * of user's choice from @file: tool.dat
 * on the screen!
 * @param: Null
 * @return: Null
 */
void list_one_record()
{
    int record_number;
    FILE *toolptr;
    tool existing;

    if ((toolptr = fopen("tool.dat", "rb")) == NULL)
    {
        printf("\nCannot Open File: Tool.dat\n");
    }
    else
    {
        printf("\nEnter tool ID:\t");
        scanf(" %d", &record_number);
        fread(&existing, sizeof(tool), 1, toolptr);
        while (!feof(toolptr))
        {
            if (existing.record == record_number)
            {
                break;
            }
            fread(&existing, sizeof(tool), 1, toolptr);
        }
        printf("\n\n%10s\t%20s\t%10s\t%10s\n\n", "Record#", "Tool Name", "Quantity", "Cost");
        printf("_____________________________________________________________________");
        printf("\n\n%10d\t%20s\t%10d\t%10.2f\n\n", existing.record, existing.name, existing.quantity, existing.cost);
    }
    menu();
}

/**
 * ----------------------------------------------------------------------------------------------------------------------
 * ----------------------------------------------------------------------------------------------------------------------
 */
/**
 * @function: list_all_records()
 * This function shows every record
 * from @file: tool.dat on the screen!
 * @param: Null
 * @return: Null
 */
void list_all_records()
{
    int record_number;
    FILE *toolptr;
    tool existing;

    if ((toolptr = fopen("tool.dat", "rb")) == NULL)
    {
        printf("\nCannot Open File: Tool.dat\n");
    }
    else
    {
        fread(&existing, sizeof(tool), 1, toolptr);
        printf("\n\n%10s\t%20s\t%10s\t%10s\n\n", "Record#", "Tool Name", "Quantity", "Cost");
        printf("_____________________________________________________________________");
        while (!feof(toolptr))
        {
            if (existing.record != 0)
            {
                printf("\n\n%10d\t%20s\t%10d\t%10.2f\n\n", existing.record, existing.name, existing.quantity, existing.cost);
            }
            fread(&existing, sizeof(tool), 1, toolptr);
        }
    }
    menu();
}
/**
 * -----------------------------------------------------------------------------------------------------------------------
 * -----------------------------------------------------------------------------------------------------------------------
 */
/**
 * @function: create_new_file()
 * This function, when called,
 * creates new file of name given by user!
 * @param: file_name
 * @return: NULL
 */
void create_new_file(char *file_name){
    FILE *fileptr;

    if ((fileptr = fopen(file_name, "wb")) == NULL)
    {
        printf("An Error Occurred While Creating file: %s\n Unable to create new file!\n", file_name);
    }else
    {
        printf("\nFile Created Successfully!!\n");
    }
}
/**
 * -------------------------------------------------------------------------------------------------------------------------
 * -------------------------------------------------------------------------------------------------------------------------
 */
/**
 * @function: initialize_record();
 * This function creates empty records
 * in FILE: tools.dat.
 * @param: NULL
 * @return: Null
 */
void initialize_record()
{
    FILE *toolptr;
    tool empty = {0, "", 0, 0};
    if ((toolptr = fopen("tool.dat", "ab")) == NULL)
    {
        printf("\nCannot Open File: Tool.dat\n");
    }
    else
    {
        for (int i = 0; i < 100; i++)
        {
            fwrite(&empty, sizeof(tool), 1, toolptr);
        }
        fclose(toolptr);
    }
}

/**
 * ----------------------------------------------------------------------------------------------------
 * ----------------------------------------------------------------------------------------------------
 */

/**
 * @function: file_is_empty()
 * this function checks whether 
 * the file: tool.dat have any
 * record or not!
 * @param: NULL
 * @return: int
 */
int file_is_empty()
{
    FILE *toolptr;
    tool existing;

    if ((toolptr = fopen("tool.dat", "rb+")) == NULL)
    {
        printf("\nCannot Open File: tool.dat\n");
    }
    else
    {
        int count = 0;
        fread(&existing, sizeof(tool), 1, toolptr);
        while (!feof(toolptr))
        {
            count++;
            fread(&existing, sizeof(tool), 1, toolptr);
        }
        if (count == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
/**
 * -----------------------------------------------------------------------------------------------------
 * -----------------------------------------------------------------------------------------------------
 */

/**
 * @function: check_for_duplication()
 * This function compares the entered tool 
 * id with the data from the @file: tool.dat
 * to avoid any duplication.
 * @param: int;
 * @return: int;
 */
int record_number_exist(int current_record_number)
{
    FILE *toolptr;
    tool existing;
    if ((toolptr = fopen("tool.dat", "rb")) == NULL)
    {
        printf("\nCannot open file: Tool.dat\n");
    }
    else
    {
        fread(&existing, sizeof(tool), 1, toolptr);
        while (!feof(toolptr))
        {
            if (existing.record == current_record_number)
            {
                return 1;
                fread(&existing, sizeof(tool), 1, toolptr);
            }
            return 0;
        }
    }
}

/**
 * ------------------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------------------
 */
/**
 * ----------------------------------
 * 
 * END DEFINITION OF CUSTOM FUNCTIONS
 * 
 * ----------------------------------
 */