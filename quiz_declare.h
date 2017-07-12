/*

 Rename the file as either display_quiz.h or quiz_main.h. (.c and .h file names should be in sync)
In this file we are declaring the structure for the quiz format  and declaring the two functions.

*/ 

#ifndef FUNC_H
#define FUNC_H
#include <curses.h>
#include <menu.h>

#define QUIZ_MAX_VAR_SIZE 60

struct quiz_format {
    
    /* Replace 60 with QUIZ_MAX_VAR_SIZE so if you want, you can change QUIZ_MAX_VAR_SIZE in
     * 1 place */
    char question[60];
    char option_blank[60];
    char option_1[60];
    char option_2[60];
    char option_3[60];
    char option_4[60];
    char question_answer[2];

};


int display_options(WINDOW *menu_window, struct quiz_format detail);
int display_question(WINDOW *question_window, int count, struct quiz_format detail);

#endif


