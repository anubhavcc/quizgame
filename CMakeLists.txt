cmake_minimum_required (VERSION 2.8.11)
project(quiz)

set(CURSES_USE_NCURSES TRUE)
set(ADDITIONAL_LIBRARIES menu)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

#How is this working? the file name doesn't seem to have changed
add_executable(play Quiz_main.c  func.c )
add_executable(question enter_question.c)
target_link_libraries(play curses)
target_link_libraries(play menu)
#SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ~/proj/quiz)
#file(MAKE_DIRECTORY ${directory})

# Do the following:
# Create a Makefile
# Have the following targets: 
# make (Compiles your code)
# make install (Installs your binary in /usr/local/bin
# make clean (Cleans up the binaries)
# Use cmake inside makefile. Check csperf Makefile on how to do this. Replicate it like that
