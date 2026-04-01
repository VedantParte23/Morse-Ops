#ifndef SUPPORTING_H
#define SUPPORTING_H
#define NANO_SEC 100000000
#include <time.h>

void typewriter(char *text, time_t seconds, long milliseconds);
void typewriter_fast(char *text, time_t nano_seconds);
void wait(time_t seconds, long milliseconds);
void clear_buffer();
void print_soldier(char* reply);
void print_captain(char* order);

#endif