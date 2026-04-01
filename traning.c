#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "supporting.h"
#include "traning.h"


const char* morse_alphabet[] = {
    ".-", "-...", "-.-.", "-..", ".", 
    "..-.", "--.", ".....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---",
    ".--.","--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--",
    "--.."              
};

void traning_mode(){

    printf("");



}

void change_str_to_morse(char* word, char* change_buffer){

    change_buffer[0] = '\0';
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'A';
        strcat(change_buffer, morse_alphabet[index]);
        strcat(change_buffer, " ");
    }

    int lenght = strlen(change_buffer);
    if (lenght > 0)
    {
        change_buffer[lenght -1] = '\0';
    }
}


