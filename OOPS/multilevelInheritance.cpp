// In multilevel inheritance, a class is derived from a class which is also derived from another class.

#include <iostream>
using namespace std;

class Person {
    protected :
    string name;

    public :

    void Introduce() {
        cout << "Hello my name is " << name << endl;
    }
};

class Employee : public Person {
    protected :
    int salary;

    public :
    void monthly_salary() {
        cout << "My monthly salary is " << salary << endl;
    }
};

class Manager : public Employee { // This Manager class will inherit from both Person class even though we have only specified Employee here, because Employee itself inherits from Person class.
    public :
    string department;
    
    Manager(string name, int salary, string department) {
        this->name = name;
        this->salary = salary;
        this->department = department;
    }

    void work() {
        cout << "I am Leading the department of " << department << endl;
    }
}; 

int main() {
    Manager A1("Sarthak", 9999999, "History");
    A1.Introduce();
    A1.work();
    A1.monthly_salary();
}