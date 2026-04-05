#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "supporting.h"

void typewriter(char *text, time_t seconds, long milliseconds)
{

    long nano_secods = milliseconds * 1000000;

    struct timespec time;

    time.tv_sec = seconds;
    time.tv_nsec = nano_secods;

    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        system("aplay assests/type.wav > /dev/null 2>&1");
        nanosleep(&time, NULL);
    }
}

void typewriter_fast(char *text, time_t nano_seconds)
{

    struct timespec time;

    time.tv_sec = 0;
    time.tv_nsec = nano_seconds;

    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);

        nanosleep(&time, NULL);
    }
}

void wait(time_t seconds, long milliseconds)
{

    long nano_secods = milliseconds * 1000000;

    struct timespec time;

    time.tv_sec = seconds;
    time.tv_nsec = nano_secods;

    nanosleep(&time, NULL);
}

void clear_buffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void print_soldier(char* reply)
{

    printf("\n\n");
    printf("         .---.\n");
    printf("    ___ /_____\\\n");
    printf("   /\\.-`( '.' )\t %s!\n", reply);
    printf("  / /    \\_-_/_\n");
    printf("  \\ `-.-\"`'V'//-.\n");
    printf("   `.__,   |// , \\\n");
    printf("       |Ll //Ll|\\ \\\n");
    printf("       |__//   | \\_\\\n");
    printf("      /---|[]==| / /\n");
    printf("      \\__/ |   \\/\\/\n");
    printf("      /_   | Ll_\\|\n");
    printf("       |`^\"\"\"^`|\n");
    printf("       |   |   |\n");
    printf("       |   |   |\n");
    printf("       |   |   |\n");
    printf("       |   |   |\n");
    printf("       L___l___J\n");
    printf("        |_ | _|\n");
    printf("       (___|___)\n");
    printf("        ^^^ ^^^\n");
}

void print_captain(char* order)
{
    printf("\t\t\t                 _,..---''-.,\n");
    printf("\t\t\t              ,-`,-.         `,\n");
    printf("\t\t\t             /  / _/           \\\n");
    printf("\t\t\t            /___//_____,--.     ,\n");
    printf("\t\t\t           /     __,..--'||     |\n");
    printf("\t\t\t           `T`7 //,-',  //      |\n");
    printf("\t\t\t            )/_//  `'  //       |\n");
    printf("\t\t\t            |`-`      <<,       /\n");
    printf("\t\t\t            \\ _        `,\\     /\n");
    printf("\t\t\t             |)`',       \\\\___/\n");
    printf("\t\t\t             \\`~~       , `--'\n");
    printf("\t\t\t              |     ,.-'     |\n");
    printf("\t\t\t               `--,`         \\  _\n");
    printf("\t\t\t           ,-'`)T(            >` `--..,\n");
    printf("\t\t\t        ,'`   //\\_\\        ,/`         `-,\n");
    printf("\t\t\t       (  ___/   /`-....--<               `,\n");
    printf("\t\t\t        /`  /\\__/\\__,/     >._              )\n");
    printf("\t\t\t       /   |__/\\__/  \\____/\\  `-,-.____,.--'\\\n");

    char* pass_by = order;
    typewriter_fast(pass_by, NANO_SEC);
}


void printarmy()
{
    printf("    |\\                |\\                |\\                |\\\n");
    printf("    || .---.          || .---.          || .---.          || .---.\n");
    printf("    ||/_____\\         ||/_____\\         ||/_____\\         ||/_____\\\n");
    printf("    ||( '.' )         ||( '.' )         ||( '.' )         ||( '.' )\n");
    printf("    || \\_-_/_         || \\_-_/_         || \\_-_/_         || \\_-_/_\n");
    printf("    :-\"`'V'//-.       :-\"`'V'//-.       :-\"`'V'//-.       :-\"`'V'//-.\n");
    printf("   / ,   |// , `\\    / ,   |// , `\\    / ,   |// , `\\    / ,   |// , `\\\n");
    printf("  / /|Ll //Ll|| |   / /|Ll //Ll|| |   / /|Ll //Ll|| |   / /|Ll //Ll|| |\n");
    printf(" /_/||__//   || |  /_/||__//   || |  /_/||__//   || |  /_/||__//   || |\n");
    printf(" \\ \\/---|[]==|| |  \\ \\/---|[]==|| |  \\ \\/---|[]==|| |  \\ \\/---|[]==|| |\n");
    printf("  \\/\\__/ |   \\| |   \\/\\__/ |   \\| |   \\/\\__/ |   \\| |   \\/\\__/ |   \\| |\n");
    printf("  /\\|_   | Ll_\\ |   /\\|_   | Ll_\\ |   /\\|_   | Ll_\\ |   /\\|_   | Ll_\\ |\n");
    printf("  `--|`^\"\"\"^`||_|   `--|`^\"\"\"^`||_|   `--|`^\"\"\"^`||_|   `--|`^\"\"\"^`||_|\n");
    printf("     |   |   ||/       |   |   ||/       |   |   ||/       |   |   ||/\n");
    printf("     |   |   |         |   |   |         |   |   |         |   |   |\n");
    printf("     |   |   |         |   |   |         |   |   |         |   |   |\n");
    printf("     |   |   |         |   |   |         |   |   |         |   |   |\n");
    printf("     L___l___J         L___l___J         L___l___J         L___l___J\n");
    printf("      |_ | _|           |_ | _|           |_ | _|           |_ | _|\n");
    printf("      (___|___)         (___|___)         (___|___)         (___|___)\n");
}




void shoot_tank() {
    printf("            _\n");
    printf("    ______,' `._______                   _______\n");
    printf("   (______(   }___,,__) .';-.;',`.;';.`=|_______)\n");
    printf("         .'  ,'  //\n");
    printf("        '    \\  //\n");
    printf("       '      `'/\n");
    printf("   ----`-------~-------------------\n");
}




void destroyed_tank() {
    printf("                 \\o/\n");
    printf("           __/    (/     o/        \n");
    printf("             )     \\    / )\n");
    printf("            /o\\          //        \n");
    printf("              .   |   .            \n");
    printf("       __j7    \\  :  /    .L_\n");
    printf("      (_(,F.    ` ' '    , z_)===::\n");
    printf("        '' _ __:.   .:__ _'                         __.--\n");
    printf("       '          .        `                  ::===(___ _\n");
    printf("         .---_ /` : '\\     \\o/o/ o  _o              .--\"-\n");
    printf("       _/__=_='   |   `_    //)</\\   |\\           _/_/_\n");
    printf("      (_(--(_(__  '   __)  /\\/ >/\\   / \\          (_(--(_(_\n");
    printf("    .'.'.' '.'.' '.'.' '.'.' '.'.' '.'.' '.'.' '.'.' '.'.' '.'.' '.\n");
    printf("    .  '  .  '  .  '  .  '  .  '  .  '  .  '  .  '  .  '  .  '  .  '\n");
    printf("  .   '  .  '  .  '  .  '  .  '  .  '  .  '  .  '  .  '  .  '  .  '  .\n");
}






