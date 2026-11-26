// Week 8 C companion: structs and functions simulate basic OOP patterns.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char name[50]; int age; } Student;
typedef struct { char model[40]; } Car;
typedef struct { char owner[50]; double balance; } BankAccount;
static void set_age(Student *s,int age){if(age>0&&age<120)s->age=age;else puts("Rejected invalid student age.");}
static int deposit(BankAccount *a,double amount){if(amount<=0)return 0;a->balance+=amount;return 1;}
static int withdraw(BankAccount *a,double amount){if(amount<=0||amount>a->balance)return 0;a->balance-=amount;return 1;}

int main(void){
    printf("ACTIVITY 1 - Encapsulation by functions\n");Student student;strcpy(student.name,"Alice");student.age=0;set_age(&student,20);printf("%s, age %d\n",student.name,student.age);set_age(&student,-5);printf("Age remains %d\n\n",student.age);
    printf("ACTIVITY 2 - Stack and heap structs\n");Car stackCar;strcpy(stackCar.model,"Stack Car");Car *heapCar=(Car*)malloc(sizeof(Car));if(!heapCar)return 1;strcpy(heapCar->model,"Heap Car");printf("%s is automatic; %s is explicitly freed.\n",stackCar.model,heapCar->model);free(heapCar);heapCar=NULL;
    printf("\nACTIVITY 3 - Encapsulation review\n");Student publicRecord;strcpy(publicRecord.name,"Public");publicRecord.age=-50;printf("A public struct field accepts invalid age %d. A setter can reject it.\n\n",publicRecord.age);
    printf("ACTIVITY 4 - BankAccount struct\n");BankAccount account;strcpy(account.owner,"Alex");account.balance=100;printf("%s starts with $%.2f\n",account.owner,account.balance);
    printf("Deposit $50: %s\n",deposit(&account,50)?"accepted":"rejected");printf("Withdraw $200: %s\n",withdraw(&account,200)?"accepted":"rejected");printf("Withdraw $30: %s\n",withdraw(&account,30)?"accepted":"rejected");printf("Balance: $%.2f\n",account.balance);
    return 0;
}
