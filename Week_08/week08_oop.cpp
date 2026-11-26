// Week 8: encapsulation, stack/heap objects, and a validated bank account.
#include <iostream>
#include <string>
using namespace std;

class Student {
    string name; int age;
public:
    Student(string n,int a):name(n),age(0){setAge(a);}
    string getName()const{return name;}
    int getAge()const{return age;}
    void setAge(int a){if(a>0&&a<120)age=a;else cout<<"Rejected invalid student age.\n";}
};
class Car { string model; public: explicit Car(string m):model(m){} void show()const{cout<<model;} };
class BadRecord { public: int age; };
class SafeRecord { int age; public: explicit SafeRecord(int a):age(0){setAge(a);} int getAge()const{return age;} void setAge(int a){if(a>0&&a<120)age=a;} };
class BankAccount {
    string owner; double balance;
public:
    BankAccount(string n,double opening):owner(n),balance(opening>=0?opening:0){}
    bool deposit(double amount){if(amount<=0)return false;balance+=amount;return true;}
    bool withdraw(double amount){if(amount<=0||amount>balance)return false;balance-=amount;return true;}
    double getBalance()const{return balance;}
    string getOwner()const{return owner;}
};

int main(){
    cout<<"ACTIVITY 1 - Encapsulated Student\n";Student student("Alice",20);cout<<student.getName()<<", age "<<student.getAge()<<'\n';student.setAge(-5);cout<<"Age remains "<<student.getAge()<<"\n\n";
    cout<<"ACTIVITY 2 - Stack and heap objects\n";Car stackCar("Stack Car");Car* heapCar=new Car("Heap Car");stackCar.show();cout<<" is automatic; ";heapCar->show();cout<<" is explicitly deleted.\n";delete heapCar;heapCar=nullptr;
    cout<<"\nACTIVITY 3 - Encapsulation review\n";BadRecord bad;bad.age=-50;cout<<"Bad public design accepts age "<<bad.age<<". ";SafeRecord safe(20);safe.setAge(-50);cout<<"Validated class keeps age "<<safe.getAge()<<".\n\n";
    cout<<"ACTIVITY 4 - Bank account\n";BankAccount account("Alex",100.00);cout<<account.getOwner()<<" starts with $"<<account.getBalance()<<'\n';
    cout<<"Deposit $50: "<<(account.deposit(50)?"accepted":"rejected")<<"\nWithdraw $200: "<<(account.withdraw(200)?"accepted":"rejected")<<"\nWithdraw $30: "<<(account.withdraw(30)?"accepted":"rejected")<<"\nBalance: $"<<account.getBalance()<<'\n';
    return 0;
}
