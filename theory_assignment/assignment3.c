/*
 *   Copyright (c) 2019 
 *   All rights reserved.
 */
#include <stdbool.h>
#include <stdio.h>

/* Initializing Custom Functions */
void get_string(char array[]);
int get_n();
int string_length(char array[]);
char *string_copy(char array1[], char array2[]);
char *strncopy(char array1[], char array2[], int);
char to_A_lower(char);
int is_A_lower(char);
char to_AN_upper(char);
int is_AN_upper(char);
int is_AN_alpha(char);
int is_A_digit(char);
int is_AN_alnum(char);
char *string_HAS_str(char *array1, char *array2);
int string_comp(char array[], char array2[]);
int str_ncmp(char array[], char array2[], int);
char *string_HAS_char(char *array, char chr);
char *str_REV_chr(char *array, char chr);
char *string_concat(char array[], char array2[]);
char *str_ncat(char array[], char array2[], int);
bool is_eos(char value) { return value == '\0'; }
/* END Initializing Custom Function */

/* Main Function */
void main()
{
  // Variable Declaration
  int i = 0, number = 0, alphabet = 0, alnum = 0, uppercase = 0, lowercase = 0;
  char array[100], array2[100], *chrptr;
  // END Variable Declaration
  get_string(array);
  // For string_length FUNCTION
  printf("\n Total Number of characters Entered are:\t %d\n", string_length(array));
  // FOR islower and isupper FUNCTION
  while (!is_eos(array[i]))
  {
    if (is_A_lower(array[i]) != 0)
    {
      lowercase++;
    }
    else if (is_AN_upper(array[i]) != 0)
    {
      uppercase++;
    }
    i++;
  }
  i = 0;
  printf("\n Total Uppercase characters:\t%d\n", uppercase);
  printf("\n Total lowercase characters:\t%d\n", lowercase);
  // FOR string_copy and strncopy FUNCTION
  printf("\n%s\n", string_copy(array2, array));
  printf("\n%s\n", strncopy(array2, array, get_n()));
  // FOR to_A_lower FUNCTION
  while (!is_eos(array[i]))
  {
    printf("\n%c in LowerCase is :\t %c\n", array[i], to_A_lower(array[i]));
    i++;
  }
  i = 0;
  // FOR toupper FUNCTION
  while (!is_eos(array[i]))
  {
    printf("\n%c in UpperCase is :\t %c\n", array[i], to_AN_upper(array[i]));
    i++;
  }
  i = 0;
  // FOR is_AN_alpha, is_A_digit and is_AN_alnum FUNCTION
  while (!is_eos(array[i]))
  {
    if (is_AN_alpha(array[i]) != 0)
    {
      alphabet++;
    }
    if (is_A_digit(array[i]) != 0)
    {
      number++;
    }
    if (is_AN_alnum(array[i]) != 0)
    {
      alnum++;
    }
    i++;
  }
  i = 0;
  printf("\n Total number of alphabets are:\t %d\n", alphabet);
  printf("\n Total number of digits are:\t %d\n", number);
  printf("\n Total number of alphanumerics are:\t %d\n", alnum);

  // FOR string_HAS_str
  printf("\n\t\t\t FOR strstr()");
  get_string(array);
  get_string(array2);
  printf("\n Result From strstr() function IS:\t %s\n", string_HAS_str(array, array2));
  
  // FOR strcmp FUNCTION
  printf("\n\t\t\tFOR strcmp Functions\n");
  get_string(array2);
  if (string_comp(array, array2) != 0)
  {
    printf("\nStrings are unequal\n");
  }
  else
  {
    printf("\nStrings are equal\n");
  }
  // FOR string_HAS_char FUNCTION
  printf("\n\t\t\t FOR strchr\n");
  char chr = 's';
  chrptr = string_HAS_char(array, chr);
  if (chrptr != NULL)
  {
    printf("\nString starting from %c is: %s\n", chr, chrptr);
  }
  else
  {
    printf("\n |%c| does not exist in String\n", chr);
  }

  // FOR str_REV_chr FUNCTION
  printf("\n\t\t\t FOR strrchr\n");
  char rchr = 's';
  chrptr = str_REV_chr(array, rchr);
  if (chrptr != NULL)
  {
    printf("\nString starting from last occurrance of%c is: %s\n", rchr, chrptr);
  }
  else
  {
    printf("\n |%c| does not exist in String\n", rchr);
  }

  // FOR strcat and strncat FUNCTION
  printf("\n\t\t\tFOR strcat and stncat Functions\n");
  get_string(array2);
  printf("\n concatenation function returns (with n = 5):\t%s\n", str_ncat(array, array2, 5));
  printf("\n concatenation function returns:\t%s\n", string_concat(array, array2));
}
/* END Main Function */

/* Definition of custom function */

/**
 * FUNCTION: get_string(array[]);
 * This Function Takes a string
 * from user and stores it in a
 * character array.
 * @param: array[];
 * @return: void
 */
void get_string(char array[])
{
  printf("\n Enter a string:\t");
  scanf("%s", array);
}

/**
 * FUNCTION: string_length(array[]);
 * This Function Takes a string
 * and count the total number
 * of character in that string.
 * @param: array[];
 * @return: int
 */

int string_length(char array[])
{
  int i = 0, count = 0;
  while (array[i] != '\0')
  {
    count++;
    i++;
  }
  return count;
}

/**
 * FUNCTION: get_n();
 * This Function gives the number
 * of characters of array1 user
 * wants to copy in array2.
 * @param: NILL;
 * @return: int;
 */

int get_n()
{
  int n = 0;
  printf("\n how many characters of array 1 you want in array2:\t");
  scanf("%d", &n);
  return n;
}

/**
 * FUNCTION: string_copy(array1[], array2[]);
 * This Function Takes Two Character
 * arrays as parameters and copies
 * all characters of array2 in array1.
 * @param: array1[], array2[];
 * @return: char*
 */

char *string_copy(char array1[], char array2[])
{
  int i = 0;
  while (!is_eos(array2[i]))
  {
    array1[i] = array2[i];
    i++;
  }
  array1[i] = '\0';
  return array1;
}

/**
 * FUNCTION: strncopy(array1[], array2[], n);
 * This Function Takes Two Character
 * arrays and an integer as parameters and copies
 * n characters of array2 in array1.
 * @param: array1[], array2[];
 * @return: char*
 */

char *strncopy(char array1[], char array2[], int n)
{
  int i = 0;
  while (i < n)
  {
    array1[i] = array2[i];
    i++;
  }
  array1[i] = '\0';
  return array1;
}

/**
 * FUNCTION: to_A_lower(alpha);
 * This Function takes a character
 * and converts it into lowercase
 * if its uppercase.
 * @param: char alpha;
 * @return: char
 */
char to_A_lower(char alpha)
{
  int ascii = 0;
  ascii = alpha;
  bool uppercase = ascii >= 65 && ascii <= 90;
  if (uppercase)
  {
    ascii += 32;
    alpha = ascii;
  }
  return alpha;
}
/**
 * FUNCTION: is_A_lower(alpha);
 * This Function takes a character
 * and check whether the character
 * is lowercase or not.
 * @param: char alpha;
 * @return: int
 */
int is_A_lower(char alpha)
{
  int ascii = 0;
  ascii = alpha;
  bool lowercase = ascii >= 97 && ascii <= 122;
  if (lowercase)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
/**
 * FUNCTION: to_AN_upper(alpha);
 * This Function takes a character
 * and converts it into uppercase
 * if its lowercase.
 * @param: char alpha;
 * @return: char
 */
char to_AN_upper(char alpha)
{
  int ascii = 0;
  ascii = alpha;
  bool lowercase = ascii >= 97 && ascii <= 122;
  if (lowercase)
  {
    ascii -= 32;
    alpha = ascii;
  }
  return alpha;
}
/**
 * FUNCTION: is_AN_upper(alpha);
 * This Function takes a character
 * and check whether the character
 * is uppercase or not.
 * @param: char alpha;
 * @return: int
 */
int is_AN_upper(char alpha)
{
  int ascii = 0;
  ascii = alpha;
  bool uppercase = ascii >= 65 && ascii <= 90;
  if (uppercase)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
/**
 * FUNCTION: isalpha(alpha);
 * This Function takes a character
 * and check whether the character
 * is alphabet or not.
 * @param: char alpha;
 * @return: int;
 */
int is_AN_alpha(char alpha)
{
  int ascii = 0;
  ascii = alpha;
  bool lowercase = ascii >= 97 && ascii <= 122;
  bool uppercase = ascii >= 65 && ascii <= 90;
  if (lowercase || uppercase)
  {
    return 1;
  }
  return 0;
}

/**
 * FUNCTION: isdigit(alpha);
 * This Function takes a character
 * and check whether the character
 * is digit or not.
 * @param: char alpha;
 * @return: int;
 */
int is_A_digit(char alpha)
{
  int ascii = 0;
  ascii = alpha;
  bool digit = ascii >= 48 && ascii <= 57;
  if ((digit))
  {
    return 1;
  }
  return 0;
}

/**
 * FUNCTION: isalnum(alpha);
 * This Function takes a character
 * and check whether the character
 * is alphanumeric or not.
 * @param: char alpha;
 * @return: int;
 */
int is_AN_alnum(char alpha)
{
  int ascii = 0;
  ascii = alpha;
  bool digit = ascii >= 48 && ascii <= 57;
  bool lowercase = ascii >= 97 && ascii <= 122;
  bool uppercase = ascii >= 65 && ascii <= 90;
  if (digit || lowercase || uppercase)
  {
    return 1;
  }
  return 0;
}

/**
 * FUNCTION: string_HAS_str(*array1, *array2);
 * This function searches for the substring
 * array2 in the string array1, not including
 * the terminating null characters.
 * @param: *array1, *array2;
 * @return: char*
 */
char *string_HAS_str(char *array1, char *array2)
{
  char *ptr = array1;
  int len = string_length(array2);
  for (; (ptr = str_REV_chr(ptr, *array2)) != 0; ptr++)
  {
    if (str_ncmp(ptr, array2, len) == 0)
    {
      return (char *)ptr;
    }
    return 0;
  }
}

/**
 * FUNCTION: string_comp(array1[], array2[]);
 * This Function Takes Two Character
 * arrays and compares them lexicographically.
 * @param: array[], array2[];
 * @return: int
 */
int string_comp(char array[], char array2[])
{
  int ascii1 = 0, ascii2 = 0, i = 0, j = 0;
  while (array[i] != '\0' && array2[j] != '\0')
  {
    ascii1 = array[i];
    ascii2 = array2[i];
    if (ascii1 != ascii2)
    {
      return 1;
    }
    i++;
    j++;
  }
  if (i != j)
  {
    return 1;
  }

  return 0;
}

/**
 * FUNCTION: str_ncmp(array1[], array2[]);
 * This Function Takes Two Character
 * arrays and an integer compares them
 * lexicographically.
 * @param: array[], array2[];
 * @return: int
 */
int str_ncmp(char array[], char array2[], int n)
{
  int ascii1 = 0, ascii2 = 0, i = 0;
  while (n != i)
  {
    ascii1 = array[i];
    ascii2 = array2[i];
    if (ascii1 != ascii2)
    {
      return 1;
    }
    i++;
  }

  return 0;
}
/**
 * FUNCTION: string_HAS_char(array1[], chr);
 * The function searches the occurrence
 * of a specified character in the given
 * string and returns the pointer to it.
 * @param: array[], chr;
 * @return: char*
 */
char *string_HAS_char(char *array, char chr)
{
  int i = 0, j = 0;
  while (*array)
  {
    if (*array == chr)
    {
      return (char *)array;
    }
    *array++;
  }
  return 0;
}

/**
 * FUNCTION: str_REV_chr(array1[], chr);
 * The function searches the last occurrence
 * of a specified character in the given
 * string and returns the pointer to it.
 * @param: array[], chr;
 * @return: char*
 */
char *str_REV_chr(char *array, char chr)
{
  int i = 0, j = 0;
  char *ptr = 0;
  while (*array)
  {
    if (*array == chr)
    {
      ptr = (char *)array;
    }
    *array++;
  }
  return ptr;
}

/**
 * FUNCTION: str_ncat(array1[], array2[], n);
 * This Function Takes Two Character
 * arrays and an integer and perform concatenation.
 * @param: array[], array2[];
 * @return: char*
 */
char *str_ncat(char array[], char array2[], int n)
{
  int i = 0, j = 0;
  while (array[i] != '\0')
  {
    i++;
  }
  while (j != n)
  {
    array[i] = array2[j];
    i++;
    j++;
  }
  array[i] = '\0';
  return array;
}

/**
 * FUNCTION: string_concat(array1[], array2[], n);
 * This Function Takes Two Character
 * arrays and perform concatenation.
 * @param: array[], array2[];
 * @return: char*
 */
char *string_concat(char array[], char array2[])
{
  int i = 0, j = 0;
  while (array[i] != '\0')
  {
    i++;
  }
  while (array2[j] != '\0')
  {
    array[i] = array2[j];
    i++;
    j++;
  }
  array[i] = '\0';
  return array;
}

/* END Definition of Custom Function */