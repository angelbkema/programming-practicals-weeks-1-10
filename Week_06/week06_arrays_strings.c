// Week 6 C companion: array search, 2D layout, C strings, and score analysis.
#include <stdio.h>
#include <string.h>

int main(void) {
    int values[8]={12,45,67,89,23,56,78,90},target,found=-1;
    printf("ACTIVITY 1 - Search target in 12 45 67 89 23 56 78 90: ");
    if(scanf("%d",&target)!=1)return 1;
    for(int i=0;i<8;++i)if(values[i]==target){found=i;break;}
    if(found>=0)printf("%d found at index %d (position %d)\n",target,found,found+1);else puts("Value was not found.");

    int matrix[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    puts("\nACTIVITY 2 - Row-major traversal with addresses");
    for(int r=0;r<3;++r)for(int c=0;c<4;++c)printf("matrix[%d][%d]=%d @ %p\n",r,c,matrix[r][c],(void*)&matrix[r][c]);
    printf("Column-major traversal values: ");
    for(int c=0;c<4;++c)for(int r=0;r<3;++r)printf("%d ",matrix[r][c]);

    char name[100];
    printf("\n\nACTIVITY 3 - C-string input\nEnter a name: ");
    if(scanf(" %99[^\n]",name)!=1)return 1;
    printf("C-string length=%zu, first character=%c\n",strlen(name),name[0]);
    printf("In C, fixed char arrays require a size limit and null terminator.\n\n");

    int scores[10],high,low,above=0; double total=0;
    printf("ACTIVITY 4 - Enter 10 scores (0-100): ");
    for(int i=0;i<10;++i){if(scanf("%d",&scores[i])!=1||scores[i]<0||scores[i]>100){puts("Invalid score.");return 1;}total+=scores[i];}
    double average=total/10.0; high=low=scores[0];
    printf("Average: %.2f\nScores above average: ",average);
    for(int i=0;i<10;++i){if(scores[i]>average){printf("%d (position %d) ",scores[i],i+1);++above;}if(scores[i]>high)high=scores[i];if(scores[i]<low)low=scores[i];}
    printf("\nHighest: %d; lowest: %d; count above average: %d\n",high,low,above);
    return 0;
}
