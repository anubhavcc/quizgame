/*

In this file we are declaring the structure for the quiz format , declaring the options variable and declaring the two functions.

*/ 

#ifndef FUNC_H
#define FUNC_H
#include <curses.h>
#include <menu.h>
struct quiz_format {
    
    char question[60];
    char option_blank[60];
    char option_1[60];
    char option_2[60];
    char option_3[60];
    char option_4[60];
    char question_answer[2];

};

char *option[] =  {

                    "1.","2.",
                    "3.","4.",
                    (char *)NULL,

                   };

int display_options(WINDOW *menu_window, struct quiz_format detail);
int display_question(WINDOW *question_window, int count, struct quiz_format detail);

#endif


