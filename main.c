#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "level.h"
#include "supporting.h"

int main()
{

    int option = 0;
    char title[] = "MORSE OPS";
    typewriter(title, 0, 250);
    printf("\n");
    wait(2, 0);
    char officer[] = "OFFICER WE NEED YOU!";
    typewriter_fast(officer, 100000000);
    printf("\n");
    wait(2, 0);
    printf("Select level. (enter a number to select)\n");

    audio_init();
    atexit(audio_cleanup);
    while (option != 5)
    {
        printf("\n︻デ═一");
        printf("\n1.TRAINING MODE");
        printf("\n2.EASY LEVEL");
        printf("\n3.MEDIUM LEVEL");
        printf("\n4.HARD LEVEL");
        printf("\n5.EXIT GAME");

        printf("\n\nEnter your level: ");
        if (scanf("%d", &option) != 1)
        {
            clear_buffer();
            printf("Please enter a valid character");
        }
        if (option < 0 || option > 5)
        {
            clear_buffer();
            printf("Please Enter a valid level");
        }
        switch (option)
        {
        case 1:

            if (traning_mode() != 1)
            {
                perror("Something went wrong");
                atexit(normal_terminal);
            }
            break;
        case 2:
            easy_mode();
            atexit(normal_terminal);
            break;

        case 3:
            medium_mode();
            atexit(normal_terminal);
            break;

        case 4:
            hard_mode();
            atexit(normal_terminal);
            break;
        case 5:
            printf("SUCCESSFULLY Exited the GAME");
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("This is impossible to print, IDK how you done this?");
            break;
        }
    }

    return 0;
}
