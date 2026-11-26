// Week 9 C companion: embedded structs and function pointers simulate OOP.
#include <stdio.h>
#include <string.h>

typedef struct { char color[20]; } Shape;
typedef struct { Shape base; double radius; } Circle;
typedef struct { Shape base; double width,height; } Rectangle;
typedef struct Drawable Drawable;
struct Drawable { char label[20]; void (*draw)(const Drawable *); double (*area)(const Drawable *); double a,b; };
static void draw_circle(const Drawable*d){printf("Drawing %s circle (area %.2f)\n",d->label,d->area(d));}
static void draw_rectangle(const Drawable*d){printf("Drawing %s rectangle (area %.2f)\n",d->label,d->area(d));}
static void draw_triangle(const Drawable*d){printf("Drawing %s triangle (area %.2f)\n",d->label,d->area(d));}
static double circle_area(const Drawable*d){return 3.141592653589793*d->a*d->a;}
static double rectangle_area(const Drawable*d){return d->a*d->b;}
static double triangle_area(const Drawable*d){return d->a*d->b/2.0;}
static void animal_sound(void){puts("Animal sound");}
static void dog_sound(void){puts("Woof (function pointer dispatch)");}

int main(void){
    printf("ACTIVITY 1 - Struct embedding simulates inheritance\n");Circle c;strcpy(c.base.color,"red");c.radius=2;Rectangle r;strcpy(r.base.color,"blue");r.width=4;r.height=3;
    printf("Circle base color=%s radius=%.1f; Rectangle base color=%s size=%.1fx%.1f\n\n",c.base.color,c.radius,r.base.color,r.width,r.height);
    printf("ACTIVITY 2 - Function pointers simulate virtual dispatch\n");void(*speak)(void)=animal_sound;speak();speak=dog_sound;speak();printf("\n");
    printf("ACTIVITY 3 - Abstract interface convention\n");printf("A null draw callback represents an incomplete shape; do not call it. Concrete shapes provide a callback.\n\n");
    printf("ACTIVITY 4 - Polymorphic drawing\n");Drawable circle={"red",draw_circle,circle_area,2,0};Drawable rect={"blue",draw_rectangle,rectangle_area,4,3};Drawable tri={"green",draw_triangle,triangle_area,6,4};
    const Drawable*canvas[]={&circle,&rect,&tri};for(int i=0;i<3;++i)canvas[i]->draw(canvas[i]);
    return 0;
}
