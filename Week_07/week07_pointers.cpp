// Week 7: pointer arithmetic, references, cleanup, and a resizing array.
#include <iostream>
using namespace std;

class DynamicArray {
    int* data; int size; int capacity;
public:
    DynamicArray():data(new int[2]),size(0),capacity(2){}
    ~DynamicArray(){delete[] data;}
    void push_back(int value){
        if(size==capacity){int newCapacity=capacity*2;int* bigger=new int[newCapacity];for(int i=0;i<size;++i)bigger[i]=data[i];delete[] data;data=bigger;capacity=newCapacity;}
        data[size++]=value;
    }
    int get(int i)const{return (i>=0&&i<size)?data[i]:0;}
    int length()const{return size;}
    int getCapacity()const{return capacity;}
};

int main(){
    int numbers[5]={10,20,30,40,50}; int* ptr=numbers;
    cout<<"ACTIVITY 1 - Pointer traversal (no indexing in the read loop): ";
    for(int i=0;i<5;++i){cout<<*ptr<<' ';++ptr;} cout<<"\nOffset traversal: ";ptr=numbers;
    for(int i=0;i<5;++i)cout<<*(ptr+i)<<' ';
    int value=10; int& ref=value; int* p=&value;
    cout<<"\n\nACTIVITY 2 - value/reference/pointer\n"; ref=20; *p+=5; cout<<"value="<<value<<", ref="<<ref<<", *p="<<*p<<"\n";
    cout<<"A reference remains bound to its original object; a pointer can be reassigned.\n\n";
    cout<<"ACTIVITY 3 - Dynamic memory ownership\n";
    int* safe=new int[3]{4,5,6};cout<<"Allocated values: "<<safe[0]<<' '<<safe[1]<<' '<<safe[2]<<"\n";delete[] safe;safe=nullptr;
    cout<<"The allocation is released with delete[]. Omitting delete[] would leak the array.\n\n";
    cout<<"ACTIVITY 4 - Dynamic array wrapper\n";DynamicArray items;int sample[]={10,20,30,40,50};for(int n:sample){items.push_back(n);cout<<"Added "<<n<<", size="<<items.length()<<", capacity="<<items.getCapacity()<<'\n';}
    cout<<"Stored values: ";for(int i=0;i<items.length();++i)cout<<items.get(i)<<' ';cout<<'\n';
    return 0;
}
