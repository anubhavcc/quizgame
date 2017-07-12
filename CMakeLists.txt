cmake_minimum_required (VERSION 2.8.11)
project(quiz)

set(CURSES_USE_NCURSES TRUE)
set(ADDITIONAL_LIBRARIES menu)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(play quiz_main.c  display_quiz.c )
add_executable(question enter_question.c)
target_link_libraries(play curses)
target_link_libraries(play menu)


