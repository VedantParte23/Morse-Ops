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

    char *attack = input;
    char print_morse[1024];
    change_str_to_morse(attack, print_morse);

    char ch, answer[1024];
    answer[0] = '\0';

    printf("--------------------------------------------\n");
    printf("TARGET WORD : %s\n", attack);
    printf("REQUIRED    : %s\n", print_morse);
    printf("--------------------------------------------\n");
    printf("Controls: J = [.]  K = [-]  SPACE = [/]  BACKSPACE = Undo\n");
    if (timer != 0)
    {
        printf("PRESS ENTER TO START THE CLOCK...\n\n");
    }
    else
    {
        printf("PRESS ENTER TO START: \n\n");
    }

    clear_buffer();
    new_terminal_setting();
    int i = 0;

    time_t start = time(NULL);
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

    time_t end = time(NULL);

    double time_diff = difftime(end, start);

    if (i > 0 && answer[i - 1] == ' ')
    {
        answer[i - 1] = '\0';
    }

    int correct = (strcmp(answer, print_morse) == 0);

    if (correct)
    {
        if (timer == 0 || time_diff <= timer)
        {
            printf("\nCAPTIAN: CORRECT, GOOD JOB SOLDIER\n\n");
            return 1;
        }
        else
        {
            printf("\nCAPTAIN: CORRECT BUT TOOO SLOW SOLDIER\n\n");
        }
    }
    else
    {
        printf("\nCAPTAIN: WRONG,\nTHIS WAS EXPECTED: %s\n\n", print_morse);
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

    if ((catch = input_function_wrapper("A", 0)) == 1)
    {
        lev_sum++;
    }

    // ATTACK
    print_captain("\n\nSEND 'ATTACK'\n");
    wait(0, 500);
    press_etr_to_continue();

    if ((catch = input_function_wrapper("ATTACK", 0)) == 1)
    {
        lev_sum++;
    }

    // BRAVO
    print_captain("\n\nSEND 'BRAVO'\n");
    wait(0, 500);
    press_etr_to_continue();

    if ((catch = input_function_wrapper("BRAVO", 0)) == 1)
    {
        lev_sum++;
    }

    // COPY THAT
    print_captain("\n\nSEND 'COPY THAT'\n");
    wait(0, 500);
    press_etr_to_continue();

    if ((catch = input_function_wrapper("COPY THAT", 0)) == 1)
    {
        lev_sum++;
    }

    // CHARLIE TANGO
    print_captain("\n\nSEND 'CHARLIE TANGO'\n");
    wait(0, 500);
    press_etr_to_continue();

    if ((catch = input_function_wrapper("CHARLIE TANGO", 0)) == 1)
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

void easy_mode()
{
    system("clear");
    clear_buffer();
    int catch = 0, lev_sum = 0;
    printf("\n\nCAPTAIN: \n");
    print_captain("WELCOME EASY MODE OFFICER. HERE YOU'LL HAVE JUST 10 SECONDS TO SEND A MESSAGE\n");
    wait(0, 500);
    press_etr_to_continue();

    print_soldier("YES SIR! I'LL TRY MY HARD");
    press_etr_to_continue();

    print_captain("UNFORTUNATELY THE STUDENT WRITING THIS CODE ISN'T SKILLED ENOUGH TO ADD A CLOCK\nSO YOU'LL GET TO KNOW RESULT AFTER YOU SUBMIT");
    wait(0, 500);
    press_etr_to_continue();

    print_soldier("YES SIR! I'LL TRY MY BEST");
    press_etr_to_continue();

    print_captain("GREAT! LETS START: ");
    wait(0, 500);
    press_etr_to_continue();

    printarmy();
    press_etr_to_continue();

    print_captain("ENEMY ARE APPROACHIN SEND 'ENEMY APPROACHING'");
    wait(0, 500);
    press_etr_to_continue();

    if ((catch = input_function_wrapper("ENEMY APPROACHING", 10)) == 1)
    {
        lev_sum++;
    }

    printf("\n\nCAPTAIN: SEND MESSAGE 'ENEMY WEST' \n");
    wait(0, 500);
    press_etr_to_continue();

    if ((catch = input_function_wrapper("ENEMY WEST", 10)) == 1)
    {
        lev_sum++;
    }

    printf("\n\nCAPTAIN: SEND MESSAGE 'MULTIPLE ENEMY' \n");
    wait(0, 500);
    press_etr_to_continue();

    if ((catch = input_function_wrapper("MULTIPLE ENEMY", 10)) == 1)
    {
        lev_sum++;
    }

    printf("\n\nCAPTAIN: SEND MESSAGE 'SET AMBUSH' \n");
    wait(0, 500);
    press_etr_to_continue();

    if ((catch = input_function_wrapper("SET AMBUSH", 10)) == 1)
    {
        lev_sum++;
    }

    printf("\n\nCAPTAIN: SEND MESSAGE 'OPEN FIRE' \n");
    wait(0, 500);
    press_etr_to_continue();

    if ((catch = input_function_wrapper("OPEN FIRE", 10)) == 1)
    {
        lev_sum++;
    }

    if (lev_sum == 5)
    {
        typewriter_fast("COMMANDING OFFICER: WE WON THE BATTLE!!!\n", NANO_SEC);
        wait(0, 250);
        typewriter_fast("CAPTAIN: GOOD JOB SOLDIER\n", NANO_SEC);
    }
    else if (lev_sum >= 3 && lev_sum < 5)
    {
        typewriter_fast("\nWE WON THE BATTLE BUT THERE ARE MULTIPLE CASULITIES\nSEND MEDICS\n", NANO_SEC);
        wait(0, 250);
        typewriter_fast("\nCAPTAIN: GOOD JOB SOLDIER. BUT YOU NEED LOT BETTERMENT\n", NANO_SEC);
    }
    else if (lev_sum < 3)
    {
        typewriter_fast("\nAMBUSH FAILED BUT WE HOLDING THE LINE\nSEND RENFORCEMENTS AND MEDICS\nWE TOOK A LOT CASULITIES\n", NANO_SEC);
        wait(0, 250);
        typewriter_fast("\nCAPTAIN: SOLDIER YOU NEED YOU LEAVE THIS JOB TBH. SKILLS ISSUES!\n", NANO_SEC);
    }
}
void medium_mode()
{
    system("clear");
    clear_buffer();
    int catch = 0, lev_sum = 0;
    printf("\n\nCAPTAIN: \n");
    print_captain("WELCOME MEDIUM MODE OFFICER. HERE YOU'LL HAVE JUST 7 SECONDS TO SEND A MESSAGE\n");
    wait(0, 500);
    press_etr_to_continue();

    print_soldier("YES SIR!");
    press_etr_to_continue();

    print_captain("THERE IS NOT CLOCK YOU'LL GET TIME UPDATE AFTER YOU SUBMIT");
    wait(0, 500);
    press_etr_to_continue();

    print_soldier("YES SIR! I UNDERSTAND HIS SKILL ISSUES!");
    press_etr_to_continue();

    print_captain("GREAT! LETS START: ");
    wait(0, 500);
    press_etr_to_continue();

    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("ATTACK", 7) == 1)
    {
        lev_sum++;
    }

    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("ATTACK", 7) == 1)
    {
        lev_sum++;
    }
    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("ATTACK", 7) == 1)
    {
        lev_sum++;
    }
    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("ATTACK", 7) == 1)
    {
        lev_sum++;
    }
    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
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
}
void hard_mode()
{
    system("clear");
    clear_buffer();
    int catch = 0, lev_sum = 0;
    printf("\n\nCAPTAIN: \n");
    print_captain("WELCOME HARD MODE OFFICER. HERE YOU'LL HAVE JUST 5 SECONDS TO SEND A MESSAGE\n");
    wait(0, 500);
    press_etr_to_continue();

    print_soldier("YES SIR! I'LL TRY MY HARD");
    press_etr_to_continue();

    print_captain("AS USUAL YOU'LL GET TO KNOW RESULT AFTER YOU INPUT\nGUESS I SHOULD STOP THIS");
    wait(0, 500);
    press_etr_to_continue();

    print_soldier("DEFINETLY SIR!");
    press_etr_to_continue();

    print_captain("GREAT! LETS START: ");
    wait(0, 500);
    press_etr_to_continue();

    // aasci of tank story

    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("ATTACK", 5) == 1)
    {
        lev_sum++;
    }

    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("ATTACK", 5) == 1)
    {
        lev_sum++;
    }
    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("ATTACK", 5) == 1)
    {
        lev_sum++;
    }
    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
    press_etr_to_continue();

    if (catch = input_function_wrapper("ATTACK", 5) == 1)
    {
        lev_sum++;
    }
    print_captain("\n\nCAPTAIN: SEND MESSAGE 'SOME_BULLSHIT' \n");
    wait(0, 500);
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
}

void reverse_mode()
{
    printf("CAPTAIN: THIS IS WHERE WE'LL GIVE YOU RANDOM MORSE CODE AND YOU HAVE TO WRITE THE WORD!\nDUE TO STUDENT'S ONGOING EXAMS HE'S UNABLE TO COMPLETE THIS\nWILL BE ADDED SOON");
}

void practice_mode(){
    print_captain("CAPTAIN: HERE YOU'LL GET RANDOM WORDS AND YOU HAVE TO COMPLETE THEM YOU CAN CHOOSE TIME IN SECONDS\nGOING TODO IT SOON");
}

void press_etr_to_continue()
{
    printf("\n\nPress enter to continue: ");
    getchar();
    system("clear");
}

void change_str_to_morse(char *word, char *morse)
{

    morse[0] = '\0';

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == ' ')
        {
            strcat(morse, "/");
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