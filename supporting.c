#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "supporting.h"

void typewriter(char *text, time_t seconds, long milliseconds){
    
    long nano_secods = milliseconds * 1000000;
    
    struct timespec time;
    
    time.tv_sec = seconds;
    time.tv_nsec = nano_secods;
    
    for (int i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        fflush(stdout);
        system("aplay assests/type.wav > /dev/null 2>&1");
        nanosleep(&time,NULL);
    }
    
}

void typewriter_fast(char *text, time_t nano_seconds){
    
    
    
    struct timespec time;
    
    time.tv_sec = 0;
    time.tv_nsec = nano_seconds;
    
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