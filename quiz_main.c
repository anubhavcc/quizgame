/*

This is the file containing the main function.In this file all the windows and menus are created and initialized
 and the questions and options are displayed by calling their respective functions. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <menu.h>
#include <unistd.h>


#include "curses.h"
/* Is this required? */
#include "func.h"

/* Remove additional blank spaces */

/* Use a macro when it is required multiple times */
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

char *option[] =  {
      
                            "1.","2.",
                            "3.","4.",
                             (char *)NULL,
         
                  };


int
main()
{   
    int next_question = 0;
    ITEM **my_items;
    MENU *my_menu;
    WINDOW *my_question_window;
    WINDOW *my_menu_window;
    FILE *ptr_file;
    struct quiz_format  detail;
    int i, n_options, c, count;


    /* Initialize curses */
    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    
    
    /*changes background colour to blue*/
    wbkgd(stdscr, COLOR_PAIR(1));
    refresh();
    
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    /* Create items for the menu */
    n_options = ARRAY_SIZE(option);
    my_items = (ITEM**)calloc(n_options, sizeof(ITEM*));

    attron(COLOR_PAIR(1));
    mvprintw(0, 60, "QUIZ GAME");
    attroff(COLOR_PAIR(1));
    refresh();

    /* creating question window and menu window */ 
    my_question_window = newwin(10, 100, 4, 6);
    my_menu_window = newwin(10, 40, 20, 6);
    box(my_question_window, 0, 0);
    box(my_menu_window, 0, 0);
    keypad(my_menu_window, TRUE);
    wrefresh(my_question_window);
    wrefresh(my_menu_window);

    /*opening file for reading purpose*/
    ptr_file = fopen("tes.bin", "rb");
    
    
    if (!ptr_file) {
         printf("Unable to open file\n");
         return 1;
      }
      
    for( count=1; count<=5; count++) {
     /* Leave a white space in comments */
    	/*changes background colour to blue*/
        wbkgd(stdscr, COLOR_PAIR(1));
        refresh();
        next_question = 0;
        
        fread(&detail, sizeof(struct quiz_format), 1, ptr_file);
        
        display_question(my_question_window, count, detail);
        
        /*Initializing items for the menu*/
        my_items[0] = new_item(option[0], "            ");
        my_items[1] = new_item(option[1], "            ");
        my_items[2] = new_item(option[2], "            ");
        my_items[3] = new_item(option[3], "            ");

        /*creating menu*/
        my_menu = new_menu((ITEM **)my_items);

        /* Set main window and sub window */
        set_menu_win(my_menu, my_menu_window);
        set_menu_sub(my_menu, derwin(my_menu_window, 6, 38, 2, 1));
        set_menu_format(my_menu, 4, 1);
        set_menu_mark(my_menu, "*");
        set_menu_spacing(my_menu, 1, 1, 1);
        menu_opts_on(my_menu, O_SHOWDESC);
        box(my_question_window, 0, 0);
        
        /* post menu */
        post_menu(my_menu);
        wrefresh(my_menu_window);
        wrefresh(my_question_window);
        box(my_menu_window, 0, 0);

        display_options(my_menu_window, detail); 

        while((c = wgetch(my_menu_window)) != 'z' && next_question == 0) {
            switch(c)
            {
                case KEY_DOWN:
                        menu_driver(my_menu, REQ_DOWN_ITEM);
                        break;
                case KEY_UP:
                        menu_driver(my_menu, REQ_UP_ITEM);
                        break;
                case KEY_LEFT:
                        menu_driver(my_menu, REQ_LEFT_ITEM);
                        break;
                case KEY_RIGHT:
                        menu_driver(my_menu, REQ_RIGHT_ITEM);
                        break;
                case 10:
                        if(strcmp((item_name(current_item(my_menu))), detail.question_answer)==0) {
                        
                            /*changes bacground colour to green*/
                            wbkgd(stdscr, COLOR_PAIR(3));
                            
                            refresh();
                            mvwprintw(my_question_window, 5, 2, "correct answer");
                            display_question(my_question_window, count, detail);
                            display_options(my_menu_window, detail);
                            wrefresh(my_question_window);
                            attron(COLOR_PAIR(1));
                            mvprintw(10, 60, "PRESS ANY KEY TO CONTINUE");
                            attroff(COLOR_PAIR(1));
                         /* Fix indentation. Difficult to read */
    			    		refresh();
                        } else {
                        
                            /*changes bacground colour to red*/
                            wbkgd(stdscr, COLOR_PAIR(2));
                            
                            refresh();
                            mvwprintw(my_question_window, 5, 2, "wrong answer");
                            display_question(my_question_window, count, detail);
                            display_options(my_menu_window, detail);
                            wrefresh(my_question_window);
                            attron(COLOR_PAIR(1));
                            mvprintw(10, 60, "PRESS ANY KEY TO CONTINUE");
                            attroff(COLOR_PAIR(1));
    			    		refresh();
                        }
                        
                        
                        /*control of the program goes to the next question*/
                        next_question = 1;
                        break;
            }
            
            display_options(my_menu_window,  detail);
            
        }
        /*Unpost and free all the memory taken up */
        unpost_menu(my_menu);
        for(i=0; i < n_options; ++i){
            free_item(my_items[i]);
        }
        free_menu(my_menu);
        werase(my_menu_window);
        werase(my_question_window);
    }
    endwin();
}
        



    
