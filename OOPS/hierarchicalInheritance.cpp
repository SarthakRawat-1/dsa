// In hierarchical inheritance, multiple derived classes inherit from a single base class.
// Think you have a Human class which is the base class. Student class, Teacher class, Staff class can all inherit from Human class. So there are multiple child classes for a single base class.

#include <iostream>
using namespace std;

class Human {
    protected :
    string name;
    int age;

    public :

    Human() { // Unlike in Student, when we defined Constructor for Teacher class, we didn't called Human Constructor explicitly.
    // In C++, when you create an object of a derived class, the constructor of the base class is called first, before the derived class's constructor.
    // If the base class does not have a default constructor and you do not explicitly call a specific base class constructor, the program will raise an error.

    // This is why adding this default constructor in base class is important.

    }

    Human(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void work() {
        cout << "I am Working \n";
    }
    void display() {
        cout << "Name :- " << name << " Age :- " << age << endl;
    }

    ~Human() {
        cout << "I am dying \n";
    }
};

class Student : public Human {
    int roll_number, fees;

    public :

    Student(string name, int age, int roll_number, int fees) : Human(name, age) { 
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void display() {
        cout << "Name :- " << name << " Age :- " << age << " Roll No :- " << roll_number << " Fees :- " << fees << endl;
    }

    ~Student() {
        cout << "I am leaving \n";
    }
};

class Teacher : public Human {
    int salary;

    public :
    Teacher(int salary, string name, int age) {
        this->salary = salary;
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << "Name :- " << name << " Age :- " << age << " Salary :- " << salary << endl;
    }

    ~Teacher() {
        cout << "I am resigning \n";
    }
};

int main() {
    Student A1("Sarthak", 19, 62, 2540000);  
    A1.display(); 
    
    Teacher A2(100000, "Shogun", 22);
    A2.display();
}