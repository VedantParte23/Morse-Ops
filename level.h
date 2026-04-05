#ifndef LEVEL_H
#define LEVEL_H
#define NANO_SEC 100000000

void change_str_to_morse(char *word, char *morse);
int input_function_wrapper(char *input, time_t timer);
void new_terminal_setting();
void normal_terminal();

void press_etr_to_continue();

int traning_mode();
void easy_mode();
void medium_mode();
void hard_mode();
void reverse_mode();
void practice_mode();

int audio_init();
void audio_cleanup();

#endif