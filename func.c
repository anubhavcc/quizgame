/*
#include <stdio.h>
#include <menu.h>
#include "func.h"
#include <curses.h>

int display_question(WINDOW *question_window,int  count,struct quiz_format detail) {
    mvwprintw(question_window, 1, 1, "%d.", count);
    mvwprintw(question_window, 1, 3, "%s", detail.question);
    box(question_window, 0, 0);
    wrefresh(question_window);
    return 0;
}

int display_options(WINDOW *option_window, struct quiz_format detail) {
    mvwprintw(option_window, 2, 5, "%s", detail.option_1);
    mvwprintw(option_window, 3, 5, "%s", detail.option_2);
    mvwprintw(option_window, 4, 5, "%s", detail.option_3);
    mvwprintw(option_window, 5, 5, "%s", detail.option_4);
    box(option_window, 0, 0);
    wrefresh(option_window);
    return 0;
}
*/

