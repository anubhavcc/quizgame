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
    
    
    char question[QUIZ_MAX_VAR_SIZE];
    char option_blank[QUIZ_MAX_VAR_SIZE];
    char option_1[QUIZ_MAX_VAR_SIZE];
    char option_2[QUIZ_MAX_VAR_SIZE];
    char option_3[QUIZ_MAX_VAR_SIZE];
    char option_4[QUIZ_MAX_VAR_SIZE];
    char question_answer[2];

};


void display_options(WINDOW *menu_window, struct quiz_format detail);
void display_question(WINDOW *question_window, int count, struct quiz_format detail);

#endif


