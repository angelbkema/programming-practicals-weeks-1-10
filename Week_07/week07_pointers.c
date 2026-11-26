// Week 7 C companion: pointer traversal, allocation cleanup, dynamic array.
#include <stdio.h>
#include <stdlib.h>

typedef struct { int *data; int size; int capacity; } DynamicArray;
static int push_back(DynamicArray *a,int value){
    if(a->size==a->capacity){int cap=a->capacity*2;int *bigger=(int*)malloc((size_t)cap*sizeof(int));if(!bigger)return 0;for(int i=0;i<a->size;++i)bigger[i]=a->data[i];free(a->data);a->data=bigger;a->capacity=cap;}
    a->data[a->size++]=value;return 1;
}

int main(void){
    int numbers[5]={10,20,30,40,50},*ptr=numbers;
    printf("ACTIVITY 1 - Pointer traversal: ");for(int i=0;i<5;++i){printf("%d ",*ptr);++ptr;}
    int value=10,*p=&value;int *alias=p;*alias+=15;
    printf("\n\nACTIVITY 2 - pointer alias changes the pointed value: value=%d, *p=%d\n",value,*p);
    printf("C has pointers but no built-in reference variables.\n\n");
    printf("ACTIVITY 3 - Dynamic allocation and cleanup\n");
    int *safe=(int*)malloc(3*sizeof(int));if(!safe){puts("Allocation failed.");return 1;}
    safe[0]=4;safe[1]=5;safe[2]=6;printf("Allocated: %d %d %d\n",safe[0],safe[1],safe[2]);free(safe);safe=NULL;
    puts("free() releases the allocation; omitting it would leak memory.\n");
    printf("ACTIVITY 4 - Dynamic array wrapper\n");
    DynamicArray a; a.data=(int*)malloc(2*sizeof(int));a.size=0;a.capacity=2;if(!a.data)return 1;
    int sample[]={10,20,30,40,50};for(int i=0;i<5;++i){if(!push_back(&a,sample[i])){free(a.data);return 1;}printf("Added %d, size=%d, capacity=%d\n",sample[i],a.size,a.capacity);}
    printf("Stored values: ");for(int i=0;i<a.size;++i)printf("%d ",a.data[i]);putchar('\n');free(a.data);
    return 0;
}
