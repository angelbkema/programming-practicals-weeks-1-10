// Week 10 C companion: checked file I/O, return codes, and robust CSV parsing.
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int read_status(const char *path){FILE *f=fopen(path,"r");if(!f)return 1;fclose(f);return 0;}
static int parse_score(const char *text,int *score){char *end;long n;errno=0;n=strtol(text,&end,10);if(errno||end==text||*end!='\0'||n<0||n>100)return 0;*score=(int)n;return 1;}
static void sum_numbers(void){
    FILE *in=fopen("numbers.txt","r");if(!in){fprintf(stderr,"Activity 1: cannot open numbers.txt: %s\n",strerror(errno));return;}
    int value,sum=0;while(fscanf(in,"%d",&value)==1)sum+=value;fclose(in);
    FILE *out=fopen("sum.txt","w");if(!out){fprintf(stderr,"Cannot create sum.txt.\n");return;}
    fprintf(out,"The total sum is: %d\n",sum);fclose(out);printf("ACTIVITY 1 - Sum of numbers: %d (written to sum.txt)\n",sum);
}
static void missing_file_demo(void){
    FILE *f=fopen("missing_data.txt","r");
    if(!f){printf("ACTIVITY 2 - fopen returned NULL. Using it with fscanf would be invalid and could crash; check for NULL first.\n");return;}
    fclose(f);
}
static void return_code_demo(void){
    printf("\nACTIVITY 3 - Return-code strategy: ");
    if(read_status("missing_data.txt"))fprintf(stderr,"open failed: %s\n",strerror(errno));
    else puts("success");
    puts("The caller checks the return value; C has no try/catch exceptions.");
}
static void parse_csv(void){
    FILE *file=fopen("students.csv","r");if(!file){fprintf(stderr,"Cannot open students.csv: %s\n",strerror(errno));return;}
    char line[256];puts("\nACTIVITY 4 - Robust CSV parsing");
    while(fgets(line,sizeof(line),file)){
        char *fields[4],*token;int count=0,s1,s2,s3;
        line[strcspn(line,"\r\n")]='\0';if(line[0]=='\0')continue;
        token=strtok(line,",");while(token&&count<4){fields[count++]=token;token=strtok(NULL,",");}
        if(count!=4||token){puts("WARNING: malformed CSV row skipped.");continue;}
        if(!parse_score(fields[1],&s1)||!parse_score(fields[2],&s2)||!parse_score(fields[3],&s3)){
            fprintf(stderr,"WARNING: Skipping malformed record for %s (invalid score data).\n",fields[0]);continue;
        }
        printf("%s -> GPA/average: %.2f\n",fields[0],(s1+s2+s3)/3.0);
    }
    fclose(file);
}
int main(void){puts("WEEK 10 - FILE I/O AND ERROR HANDLING (C)");sum_numbers();missing_file_demo();return_code_demo();parse_csv();return 0;}
