#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <ctype.h>
#include <time.h>
#include "supporting.h"
#include "level.h"

static struct termios old_terminal;

const char *morse_alphabet[] = {
    ".-", "-...", "-.-.", "-..", ".",
    "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---",
    ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--",
    "--.."};

int input_function_wrapper(char *input, time_t timer)
{

    if (timer == 0)
    {
        printf("have todo something for traning");

    }
    time_t start = time(NULL);
    

    char *attack = input;
    char print_morse[strlen(attack) * 6];
    change_str_to_morse(attack, print_morse);

    char ch, answer[strlen(attack) * 6]; // thought 4 adding exta 2 for safty
    answer[0] = '\0';

    printf("The word is: %s \n\n", attack);
    printf("The morse is : %s", print_morse);
    printf("\nEnter to start");
    printf("\n");

    clear_buffer();
    new_terminal_setting();
    int i = 0;
    while (1)
    {

        ch = getchar();

        if (ch == '\n' || ch == '\r')
        {
            break;
        }
        else if (ch == '/')
        {
            printf("/");
            fflush(stdout);
            answer[i++] = '/';
        }
        else if (ch == 'J' || ch == 'j')
        {
            printf(".");
            fflush(stdout);

            answer[i++] = '.';
        }
        else if (ch == 'K' || ch == 'k')
        {
            printf("-");
            fflush(stdout);

            answer[i++] = '-';
        }
        else if (ch == 'q' || ch == 'Q')
        {
            exit(EXIT_SUCCESS);
        }
        else if (ch == '\b' || ch == 127)
        {
            if (i > 0)
            {

                i--;
                answer[i] = '\0';
                printf("\b \b");
                fflush(stdout);
            }
        }
        else if (ch == ' ')
        {
            printf(" ");
            fflush(stdout);
            answer[i++] = ' ';
        }

        answer[i] = '\0';
    }

    atexit(normal_terminal);

    time_t end = time(NULL);

    double time_diff = difftime(end ,start);

    if (timer == 0 && strcmp(answer, print_morse) == 0 )
    {
        printf("\n CAPTAIN: Correct!\n");
        return 1;
    }
    else if (timer == 0 && strcmp(answer, print_morse) != 0)
    {
        printf("\nWrong\n CAPTAIN: this was expected: %s", print_morse);
        return 0;
    }
    
    else if (strcmp(answer, print_morse) == 0 && time_diff < timer)
    {
        printf("\n CAPTAIN: Correct!\n");
        return 1;
    }
    else if (time_diff > timer)
    {
        printf("\nCAPTAIN: YOU FAILED ON TIME");
        return 0;
    }
    else
    {
        printf("\nWrong\n CAPTAIN: this was expected: %s", print_morse);
        return 0;
    }

    
    

}

int traning_mode()
{
    system("clear");
    clear_buffer();
    int catch = 0, lev_sum = 0;
    printf("\n\nCAPTAIN: \n");
    print_captain("WELCOME TO THE TRANING OFFICER\n");
    wait(0, 500);
    press_etr_to_continue();

    print_soldier("YES SIR!");
    press_etr_to_continue();

    printf("\n\nCAPTAIN: \n");
    print_captain("YOUR COMMIONED HERE FOR LEARNING MORSE CODE COMMUNICATION");
    wait(0, 500);
    press_etr_to_continue();

    print_soldier("YES SIR");
    press_etr_to_continue();

    print_captain("YOU'LL LEARN HERE HOW TO SEND MORSE CODE TO OUR POSITIONS IN FRONT LINE\n TO ALRET YOUR FORCES\nARE YOU READY?");
    wait(0, 500);
    press_etr_to_continue();

    print_soldier("YES SIR! I'M READY TO SERVE MY COUNTRY");
    press_etr_to_continue();

    print_captain("NICE TO SEE YOUR ATTITUCE SOLDIER\nHERE IS NOW YOUR FIRST PART\n");
    wait(0, 500);
    press_etr_to_continue();

    // A
    print_captain("\n\nSEND 'A' TO THE FORWARD. USE 'J' FOR '.' AND K FOR '-'\n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("A", 0) == 1)
    {
        lev_sum++;
    }

    // ATTACK
    print_captain("\n\nSEND 'ATTACK'\n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("ATTACK", 0) == 1)
    {
        lev_sum++;
    }

    // BRAVO
    print_captain("\n\nSEND 'BRAVO'\n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("BRAVO", 0) == 1)
    {
        lev_sum++;
    }

    // COPY THAT
    print_captain("\n\nSEND 'COPY THAT'\n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("COPY THAT", 0) == 1)
    {
        lev_sum++;
    }

    // CHARLIE TANGO
    print_captain("\n\nSEND 'CHARLIE TANGO'\n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("CHARLIE TANGO", 0) == 1)
    {
        lev_sum++;
    }
    press_etr_to_continue();
    if (lev_sum >= 4)
    {
        print_captain("GOOD JOB SOLDIER YOU SCORED GOOD\n YOU'RE READY FOR FRONTLINE");
        press_etr_to_continue();
        print_soldier("THANK YOU SIR! IT IS MY HONOR TO SERVE MY COUNTRY!");
        press_etr_to_continue();
    }
    else if (lev_sum <= 3)
    {
        print_captain("SOLDIER YOU NEED IMPROVEMENTS\nBUT DUE TO LACK OF MEN WE'RE SENDING YOU TO FRONTLINE");
        press_etr_to_continue();
        print_soldier("THANKYOU SIR! I WILL WORK HARDER TO IMPROVE MYSELF");
        press_etr_to_continue();
    }

    return 1;
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
}

void new_terminal_setting()
{
    struct termios new_terminal;
    tcgetattr(STDIN_FILENO, &old_terminal);

    new_terminal = old_terminal;

    new_terminal.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal);
}

void normal_terminal()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
}



void easy_mode()
{
    print_captain("WELCOME TO EASY MODE SOLDIER YOU'LL GET JUST 10 SECONDS TO PASS EVERY MESSAGE");
    
}
void medium_mode()
{
    printf("This is medicum mode");
}
void hard_mode()
{
    printf("This is hard mode");
}

void press_etr_to_continue()
{
    printf("\n\nPress enter to continue: ");
    getchar();
    system("clear");
}
