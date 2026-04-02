#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <termios.h>
#include <ctype.h>
#include "supporting.h"
#include "traning.h"

const char *morse_alphabet[] = {
    ".-", "-...", "-.-.", "-..", ".",
    "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---",
    ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--",
    "--.."};

int traning_mode()
{

    // printf("\n\nCAPTAIN: \n");
    // print_captain("WELCOME TO THE TRAINING OFFICER\n");
    // wait(0,500);
    // printf("\n\n\nPress enter to continue: ");
    // getchar();
    // system("clear");

    // print_soldier("YES SIR!");
    // printf("\n\n\nPress enter to continue: ");
    // getchar();
    // system("clear");

    // printf("\n\nCAPTAIN: \n");
    // print_captain("YOUR COMMIONED HERE FOR LEARNING MORSE CODE COMMUNICATION");
    // wait(0,500);
    // printf("\n\n\nPress enter to continue: ");
    // getchar();
    // system("clear");

    // print_soldier("YES SIR");
    // printf("\n\n\nPress enter to continue: ");
    // getchar();
    // system("clear");

    // print_captain("YOU'LL LEARN HERE HOW TO SEND MORSE CODE TO OUR POSITIONS IN FRONT LINE TO ALRET THEN\nARE YOU READY?");
    // wait(0,500);
    // printf("\n\n\nPress enter to continue");
    // getchar();
    // system("clear");

    // print_soldier("YES SIR! I'M READY TO SERVE MY COUNTRY");
    // printf("\n\n\nPress enter to continue: ");
    // getchar();
    // system("clear");

    // print_captain("NICE TO SEE YOUR ATTITUCE SOLDIER\nHERE IS NOW YOUR FIRST PART\n");
    // wait(0,500);
    // printf("\n\n\nPress enter to continue: ");
    // getchar();
    // system("clear");

    print_captain("\n\nSEND 'ATTACK' TO THE FORWARD. USE 'J' FOR '.' AND K FOR '-'\n");
    wait(0, 500);
    printf("Press enter to continue: ");
    getchar();
    system("clear");


    char *attack = "ATTACK";
    char print_morse[strlen(attack) * 6];
    change_str_to_morse(attack, print_morse);

    new_terminal_setting();

    char ch,  answer[strlen(attack) * 6];
    int i = 0;

    clear_buffer();
    while (1)
    {
        ch = getchar();
        if(ch == 'J' || ch == 'j'){
            printf(".");
            fflush(stdout);

            answer[i++] = '.';
        }
        else if(ch == 'K' || ch == 'k'){
            printf("-");
            fflush(stdout);

            answer[i++] = '-';
        }
        else if(ch == 'q'){
            exit(EXIT_SUCCESS);
        }
        else if (ch == '\b' || ch == 127)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        
        answer[i] = '\0';

        printf("\n INput: %s",answer);
        
    }
    

    exit(EXIT_SUCCESS);

    return 0;
}

void change_str_to_morse(char *word, char *morse)
{

    morse[0] = '\0';

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == ' ')
        {
            strcat(morse, " / ");
        }
        else
        {
            char upper_case = toupper(word[i]);
            if (upper_case >= 'A' && upper_case <= 'Z')
            {
                int index = upper_case - 'A';
                strcat(morse, morse_alphabet[index]);
                strcat(morse, " ");
            }
        }
    }

    int length = strlen(morse);
    if (length > 0)
    {
        morse[length - 1] = '\0';
    }

    printf("The word is: %s \n\n", word);
    printf("The morse is : %s", morse);
    printf("\n\n");
}

void new_terminal_setting()
{
    printf("New terminal settings \n");

    struct termios new_terminal, old_terminal;
    tcgetattr(STDIN_FILENO, &old_terminal);
    new_terminal = old_terminal;
    new_terminal.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal);
}

// void normal_terminal(void (*new_terminal_setting)()){
//     tcsetattr(STDIN_FILENO, TCSANOW, &oldterminal);
// }

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
