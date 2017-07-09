add_executable(play Quiz_main.c  func.c func.h)
add_executable(question enter_question.c)
target_link_libraries(play curses)
target_link_libraries(play menu)
