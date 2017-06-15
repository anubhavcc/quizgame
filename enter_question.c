/*This program is written to insert quiz questions into a binary file*/

#include <stdio.h>
#include<stdio.h>
#include "func.h"

int 
main()
{
    int counter=0,noOfQuestions;size_t len;
    FILE *ptr;
    struct quiz_format record;
    ptr=fopen("test.bin", "wb");
    
    if (!ptr) {
        printf("Unable to open file\n");
        return 1;
    }
	printf("Enter the number of questions\n");
	scanf("%d",&noOfQuestions);

    while(counter != noOfQuestions) {
        printf("Enter the question no\n");
        scanf("%d", &record.question_no);
		getchar();
        printf("Enter the question\n");
		fgets(record.question,sizeof(record.question),stdin);
        printf("Enter the option 1\n");
		fgets(record.option_1,sizeof(record.option_1),stdin);
        printf("Enter the option 2\n");
		fgets(record.option_2,sizeof(record.option_2),stdin);
        printf("Enter the option 3\n");
		fgets(record.option_3,sizeof(record.option_3),stdin);
        printf("Enter the option 4\n");
		fgets(record.option_4,sizeof(record.option_4),stdin);
        printf("Enter the question answer\n");
		scanf("%s",&record.question_answer);
        fwrite(&record, sizeof(struct quiz_format), 1, ptr);
		counter++;
    }
    fclose(ptr);
    return 0;
}




