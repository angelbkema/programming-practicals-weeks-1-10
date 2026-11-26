// Week 9: inheritance, virtual dispatch, abstract classes, polymorphism.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shape {
protected: string color;
public:
    explicit Shape(string c):color(c){}
    virtual ~Shape()=default;
    void displayColor()const{cout<<"Color: "<<color<<'\n';}
    virtual double area()const=0;
    virtual void draw()const=0;
};
class Circle:public Shape {
    double radius;
public:
    Circle(string c,double r):Shape(c),radius(r){}
    double area()const override{return 3.141592653589793*radius*radius;}
    void draw()const override{cout<<"Drawing "<<color<<" circle (area "<<area()<<")\n";}
};
class Rectangle:public Shape {
    double width,height;
public:
    Rectangle(string c,double w,double h):Shape(c),width(w),height(h){}
    double area()const override{return width*height;}
    void draw()const override{cout<<"Drawing "<<color<<" rectangle (area "<<area()<<")\n";}
};
class Triangle:public Shape {
    double base,height;
public:
    Triangle(string c,double b,double h):Shape(c),base(b),height(h){}
    double area()const override{return base*height/2.0;}
    void draw()const override{cout<<"Drawing "<<color<<" triangle (area "<<area()<<")\n";}
};
class Animal {public: void speak()const{cout<<"Animal sound\n";} virtual void virtualSpeak()const{cout<<"Animal sound\n";} virtual ~Animal()=default;};
class Dog:public Animal {public: void speak()const{cout<<"Dog sound (non-virtual call through base uses Animal)\n";} void virtualSpeak()const override{cout<<"Woof (virtual dispatch)\n";}};

int main(){
    cout<<"ACTIVITY 1 - Inheritance hierarchy\n";Circle circle("red",2);Rectangle rectangle("blue",4,3);circle.displayColor();rectangle.displayColor();cout<<"Circle area "<<circle.area()<<", rectangle area "<<rectangle.area()<<"\n\n";
    cout<<"ACTIVITY 2 - Virtual function mystery\n";Dog dog;Animal* animal=&dog;animal->speak();animal->virtualSpeak();cout<<"\n";
    cout<<"ACTIVITY 3 - Abstract class\n";cout<<"Shape is abstract because area() and draw() are pure virtual; instantiate Circle or Rectangle instead.\n";cout<<"A concrete circle has area "<<circle.area()<<"\n\n";
    cout<<"ACTIVITY 4 - Polymorphic drawing\n";Triangle triangle("green",6,4);vector<Shape*> canvas={&circle,&rectangle,&triangle};for(const Shape* shape:canvas)shape->draw();
    return 0;
}
