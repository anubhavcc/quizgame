/*


This file contains the definition of two functions display_question and display_option.

display_question : This function prints the question and question number to the question window
display_options  : This function prints the options  to the menu window

*/


#include <stdio.h>
#include <menu.h>
#include <curses.h>

#include "display_quiz.h"


void 
display_question(WINDOW *question_window, int  count, struct quiz_format detail) 
{
    mvwprintw(question_window, 1, 1, "%d.", count);
    mvwprintw(question_window, 1, 3, "%s", detail.question);
    
    box(question_window, 0, 0);
    wrefresh(question_window);
    
}

void
display_options(WINDOW *option_window, struct quiz_format detail) 
{
    mvwprintw(option_window, 2, 5, "%s", detail.option_1);
    mvwprintw(option_window, 3, 5, "%s", detail.option_2);
    mvwprintw(option_window, 4, 5, "%s", detail.option_3);
    mvwprintw(option_window, 5, 5, "%s", detail.option_4);
    
    box(option_window, 0, 0);
    wrefresh(option_window);
   
}


