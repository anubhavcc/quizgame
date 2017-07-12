/*

This file is used to enter the questions and options for the quiz and also take the input for the correct answer.
The questions and options are then written to a binary file.

*/ 

#include <stdio.h>

#include "display_quiz.h"

int 
main()
 {

     int counter=0,noOfQuestions;
     size_t len;
     FILE *ptr;
     
     
     struct quiz_format record;
     ptr=fopen("tes.bin", "wb");
     
     
     if (!ptr) {
         printf("Unable to open file\n");
         return 1;
     }
     
     
     printf("Enter the number of questions\n");
     scanf("%d", &noOfQuestions);
     
     while(counter != noOfQuestions) {
     getchar();
     
     printf("Enter the question\n");
     fgets(record.question, 100, stdin);
     
     
     printf("Enter the option blank\n");
     fgets(record.option_blank, 100, stdin);
     
     
     printf("Enter option 1\n");
     fgets(record.option_1, 100, stdin);
     
     
     printf("Enter the option 2\n");
     fgets(record.option_2, 100, stdin);
     
     
     printf("Enter the option 3\n");
     fgets(record.option_3, 100, stdin);
     
     
     printf("Enter the option 4\n");
     fgets(record.option_4, 100, stdin);
     
     
     printf("Enter the question answer\n");
     scanf("%s", record.question_answer);
     
     
     fwrite(&record, sizeof(struct quiz_format), 1, ptr);
     counter++;
     }
     
     
     fclose(ptr);
     return 0;
}     
