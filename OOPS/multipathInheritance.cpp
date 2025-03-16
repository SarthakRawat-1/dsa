// In multipath inheritance, a class can inherit from more than one class, and those parent classes themselves share a common ancestor. This leads to the same base class being inherited more than once. In such cases, without careful management, you'll have multiple copies of the base class's data members, which can lead to inconsistencies.
// Let's say we have a Human class. Then we have two classes Youtuber and Engineer, both inheriting from Human. And finally we have a CodeTeacher class, inheriting from both Youtuber and Engineer class. There is a problem now, data members of Human class will be inherited by both Youtuber and Engineer class, and as CodeTeacher class is inheriting from both Youtuber and Engineer, it means that CodeTeacher now have multiple instances (here, 2) of the data members of Human class. Now how will it know which of the instance to use? This is solved using Virtual Inheritance.

#include <iostream>
using namespace std;

class Human {
    public :
    string name;

    void display() {
        cout << "My name is " << name << endl;
    }
};

class Engineer : public virtual Human {
    public :
    string specialization;

    void work() {
        cout << "I have specialization in " << specialization << endl;
    }
};

class Youtuber : public virtual Human {
    public : 
    int subscribers;

    void contentCreator() {
        cout << "I have " << subscribers << " subscribers" << endl;
    }
};

// The name variable and display function from Human class has come here from both Engineer and Youtuber class, which leads to confusion.
// Solve this using Virtual Inheritance. Use virtual keyword when inheriting from Human class.
// In this way there is only one shared copy of the Human class in both Engineer and Youtuber class.
class CodeTeacher : public Engineer, public Youtuber { 
    public :
    int salary;

    CodeTeacher() {}

    CodeTeacher(string name, string specialization, int subscribers, int salary) {
        this->name = name;
        this->specialization = specialization;
        this->subscribers = subscribers;
        this->salary = salary;
    }


    void showcase() {
        work(); 
        contentCreator(); 
    }
};

int main() {
    CodeTeacher A1("Sarthak", "C++", 1000, 99999);
    A1.display();
}