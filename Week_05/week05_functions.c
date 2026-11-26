// Week 5 C companion: functions use pointers to modify caller data.
#include <stdio.h>

int globalValue = 100;
void swap_by_value(int a, int b) { int t=a; a=b; b=t; printf("Inside pass-by-value: %d %d\n",a,b); }
void swap_by_pointer(int *a, int *b) { int t=*a; *a=*b; *b=t; }
unsigned long long factorial(int n) { return n <= 1 ? 1ULL : (unsigned long long)n * factorial(n-1); }
unsigned long long factorial_tail(int n, unsigned long long result) { return n <= 1 ? result : factorial_tail(n-1,result*(unsigned long long)n); }
double area_circle(double r) { return 3.141592653589793*r*r; }
double area_rectangle(double l,double w) { return l*w; }
double area_triangle(double b,double h) { return b*h/2.0; }
double area_square(double s) { return s*s; }
double perimeter_rectangle(double l,double w) { return 2*(l+w); }

int main(void) {
    int x=5,y=10;
    puts("ACTIVITY 1 - Pass by value vs pointer swap");
    swap_by_value(x,y); printf("Originals after value call: %d %d\n",x,y);
    swap_by_pointer(&x,&y); printf("After pointer fix: %d %d\n\n",x,y);
    puts("ACTIVITY 2 - Scope");
    printf("Global value: %d\n",globalValue);
    { int localValue=25; printf("Block-local value: %d (scope ends with this block)\n\n",localValue); }
    puts("ACTIVITY 3 - Factorials for n=5");
    printf("Simple recursion: %llu\nTail recursion: %llu\n\n",factorial(5),factorial_tail(5,1));
    puts("ACTIVITY 4 - Geometry library");
    printf("Circle area r=2: %.2f\nRectangle area 4x3: %.2f\nTriangle area b=6 h=4: %.2f\nSquare area side=3: %.2f\nRectangle perimeter 4x3: %.2f\n",
           area_circle(2),area_rectangle(4,3),area_triangle(6,4),area_square(3),perimeter_rectangle(4,3));
    return 0;
}
