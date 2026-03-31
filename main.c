#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void typewriter(char *text ,time_t seconds, long milliseconds);
void wait(time_t seconds, long milliseconds);


int main(){


    int option;
    char title[] = "|==MORSE OPS==|";
    typewriter(title,0, 350);
    wait(2,0);
    printf("\nOfficer we NEED YOU!!\n");
    wait(2,0);
    
    
    
    while (option != 5)
    {
         printf("\n︻デ═一");
         printf("\n1.TRANING");
         printf("\n2.EASY LEVEL");
         printf("\n3.MEDIUM LEVEL");
         printf("\n4.HARD LEVEL");
         printf("\n5.EXIT GAME");

         printf("\n\nEnter your level: ");
         if(scanf("%d",&option) != 1){
            printf("Please enter a valid character");
         }
        if (option < 0 || option > 5)
        {
            printf("Please Enter a valid level");
        }
        
    }
    
    
    
    

    return 0;
}



void typewriter(char *text, time_t seconds, long milliseconds){
    
    long nano_secods = milliseconds * 1000000;
    
    struct timespec time;
    
    time.tv_sec = seconds;
    time.tv_nsec = nano_secods;
    
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        nanosleep(&time,NULL);
    }
    
}


void wait(time_t seconds,long milliseconds){
    
    long nano_secods = milliseconds * 1000000;

    struct timespec time;

    time.tv_sec = seconds;
    time.tv_nsec = nano_secods;


    nanosleep(&time,NULL);

}

void clear_buffer(){
    char c;
   while ((c = getchar()) != '\n' && c != EOF);
}