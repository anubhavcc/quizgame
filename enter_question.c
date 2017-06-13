/*This program is written to insert quiz questions into a binary file*/

#include <stdio.>
#include "func.h"

int 
main()
{
    int counter;
    FILE *ptr;
    struct quiz_format record;
    ptr=fopen("test.bin","wb");
    
    if (!ptr) {
        printf("Unable to open file\n");
        return 1;
    }
    for(counter=1; counter<=20;counter++) {
        printf("Enter the question no\n");
        scanf("%d",record.question_no);
        printf("Enter the question\n");
        scanf("%s",record.question);
        printf("Enter the option 1\n");
        scanf("%s",record.option_1);
        printf("Enter the option 2\n");
        scanf("%s",record.option_2);
        printf("Enter the option 3\n");
        scanf("%s",record.option_3);
        printf("Enter the option 4\n");
        scanf("%s",record.option_4);
        printf("Enter the question answer\n)";
        scanf("%s",record.question_answer);
        fwrite(&record,sizeof(struct quiz_format),1,ptr);
    }
    fclose(ptr);
    return 0;
}




