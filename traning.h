#ifndef TRANING_H
#define TRANING_H
#define NANO_SEC 100000000

void change_str_to_morse(char *word, char *morse);
int input_function_wrapper(char*input);
void new_terminal_setting();
void normal_terminal();

int traning_mode();
void press_etr_to_continue();

void easy_mode();
void medium_mode();
void hard_mode();

#endif