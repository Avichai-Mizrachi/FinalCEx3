// Description: This program gets a string and print all the lines that contain the string

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Max characters per line. */
#define MAX_LINE_LENGTH 256

/* Max characters per word. */
#define MAX_WORD_LENGTH 30

int get_line(char s[]); // gets a string (char after char) from thestandart input
// and save it in s,return the number of characters in s

int getword(char w[]); // gets a string and save it in w,return the number of characters in w

int substring(char *str1, char *str2); // gets two strings and check if str2 is a substring of str1

int similar(char *s, char *t, int n); // gets two strings and n number ,check if s and t are similar until n changes

void print_lines(char *str); // gets a string and print all the lines that contain the string

void print_similar_words(char *str); // gets a string and print all the words
// that are similar to the string by similar function

int main()
{
    char choice;                     // char to get the choice from the user
    char word[MAX_WORD_LENGTH];      // char to get the word from the user
    scanf("%s %c\n", word, &choice); // get the word and the choice from the user
    switch (choice)
    {
    case 'a':
        print_lines(word);
        break;
    case 'b':
        print_similar_words(word);
        break;
    default: // if the user enter a char that is not a or b , scan again
        printf("Invalid choice, please try again");
        break;
    }

    return 0;
}

// /**
//  * Reads a line of input from the standard input (keyboard) and saves it in the
//  * provided array. The line is terminated with a null character.
//  *
//  * @param s Array to store the input line. The array must be large enough to
//  *          hold the line and the terminating null character.
//  * @return The number of characters in the input line (not including the null
//  *         character).
//  */

int get_line(char s[])
{
    int c = 0;
    int i = 0;
    for (i = 0; (c != '\n') && (c != '\r') && (i < MAX_LINE_LENGTH - 1); ++i)
    {
        if (EOF != (c = getchar()))
            if (c != '\r')
                s[i] = c;
            else
                s[i] = '\n';
        else
            return 0;
    }
    if (i == 0)
    {
        return 1;
    }
    s[i] = '\0';
    return i;
}

// /**
//  * Reads a word of input from the standard input  and saves it in the
//  * provided array. The word is terminated with a null character.
//  *
//  * @param w Array to store the input word. The array must be large enough to
//  *          hold the word and the terminating null character.
//  * @return The number of characters in the input word (not including the null
//  *         character).
//  */

int getword(char w[]) // gets a string and save it in w,return the number of characters in w
{
    int c, i = 0;

    while (isspace(c = getchar()))
        ; // skip leading whitespace

    while (c != EOF && !isspace(c) && i < MAX_WORD_LENGTH - 1)
    {
        w[i++] = c;
        c = getchar();
    }

    w[i] = '\0';

    return i;
}

// /**
//  * Determines whether a string is a substring of another string.
//  *
//  * @param str1 The string to search in.
//  * @param str2 The string to search for.
//  * @return 1 if str2 is a substring of str1, 0 otherwise.
//  */

int substring(char *str1, char *str2)
{
    int l2 = strlen(str2);
    int l1 = strlen(str1);

    for (int i = 0; i < l2 + 1 - l1; i++)
    {
        if (strncmp(str1, str2 + i, l1) == 0)
            return 1;
    }
    return 0;
}

// /**
//  * Determines whether two strings are similar.
//  *
//  * @param s The first string.
//  * @param t The second string.
//  * @param n The maximum number of changes allowed.
//  * @return 1 if s and t are similar, 0 otherwise.
//  */

int similar(char *s, char *t, int n)
{
    int lt = strlen(t);
    int ls = strlen(s);

    if (lt + n < ls || ls < lt)
        return 0;

    int j, i;
    for (i = 0, j = 0; j < lt && i < ls; i++)
    {
        if (s[i] == t[j])
            j++;
    }
    if (lt == j)
        return 1;
    else
        return 0;
}

// /**
//  * Reads lines from the standard input and prints any lines that contain the
//  * specified string.
//  *
//  * @param str The string to search for in the input lines.
//  */

void print_lines(char *str)
{
    char myline[MAX_LINE_LENGTH];
    while (get_line(myline) > 0)
    {
        if (substring(str, myline))
        {
            printf("%s", myline);
        }
    }
}

// /**
//  * Reads words from the standard input and prints any words that are similar to
//  * the specified string.
//  *
//  * @param str The string to search for in the input words.
//  */

void print_similar_words(char *str)
{
    char myline[MAX_LINE_LENGTH];
    while (fgets(myline, MAX_LINE_LENGTH, stdin) != NULL)
    {
        char *myword = strtok(myline, " \t\n"); // split the line to words

        while (myword != NULL)
        {
            if (similar(myword, str, 1)) // check if the word is similar to str using "similar function"
            {
                printf("%s\n", myword);
            }
            myword = strtok(NULL, " \t\n"); // get the next word
        }
    }
}