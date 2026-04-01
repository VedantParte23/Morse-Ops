#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include "supporting.h"
#include "traning.h"



const char *morse_alphabet[] = {
    ".-", "-...", "-.-.", "-..", ".",
    "..-.", "--.", ".....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---",
    ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--",
    "--.."};











int traning_mode()
{

    printf("\n\nCAPTAIN: \n");
    print_captain("WELCOME TO THE TRAINING OFFICER\n");
    wait(0,500);
    printf("\n\n\nPress enter to continue");
    getchar();
    system("clear");

    print_soldier("YES DARLING");
    wait(0,500);
    printf("\n\n\nPress enter to continue");
    getchar();
    system("clear");

    printf("\n\nCAPTAIN: \n");
    print_captain("YOUR COMMIONED HERE FOR LEARNING MORSE CODE");
    wait(0,500);
    printf("\n\n\nPress enter to continue");
    getchar();
    system("clear");
    

    return 0;
}













void change_str_to_morse(char *word, char *change_buffer)
{

    change_buffer[0] = '\0';

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == ' ')
        {
            strcat(change_buffer, " / ");
        }
        else
        {
            char upper_case = toupper(word[i]);
            if (upper_case >= 'A' && upper_case <= 'Z')
            {
                int index = upper_case - 'A';
                strcat(change_buffer, morse_alphabet[index]);
                strcat(change_buffer, " ");
            }
        }
    }

    int length = strlen(change_buffer);
    if (length > 0)
    {
        change_buffer[length - 1] = '\0';
    }
}

void easy_mode()
{
    printf("this is easy mode");
}
void medium_mode()
{
    printf("This is medicum mode");
}
void hard_mode()
{
    printf("This is hard mode");
}