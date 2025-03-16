// In Single Inheritance, a derived class inherits from a single base class.

#include <iostream>
using namespace std;

class Human {
    protected :
    string name;
    int age;

    public :

    // Constructor for Human class.
    Human(string name, int age) {
        this->name = name;
        this->age = age;
        cout << "Human" << endl ; // Wrote this to test which constructor will be called first, Human or Student.
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

    // Student(string name, int age, int roll_number, int fees) {
    //     this->name = name;
    //     this->age = age;
    //     this->roll_number = roll_number;
    //     this->fees = fees;
    //     cout << "Student" << endl; // Wrote this to test which constructor will be called first, Human or Student.
    // }

    // In this constructor, we are not writing age and name by ourselves here. We will inherit them from the parent class
    Student(string name, int age, int roll_number, int fees) : Human(name, age) { // Now call the Human constructor here and send necessary parameters.
        this->roll_number = roll_number;
        this->fees = fees;
        cout << "Student" << endl; // Wrote this to test which constructor will be called first, Human or Student.
    }

    void display() {
        cout << "Name :- " << name << " Age :- " << age << " Roll No :- " << roll_number << " Fees :- " << fees << endl;
    }

    ~Student() {
        cout << "I am leaving \n";
    }
};

// First the constructor of parent class will be called, then the constructor of base class will be called.
// This would be the same even if we had used default constructor for Student class.
// First the destructor of base class will be called, then the destructor of parent class will be called.


int main() {
    Student A1("Sarthak", 19, 62, 2540000);
    A1.work(); // This will work because the work() function is public in Human class and we have also used public access modifier.
    // But what if we don't want to send the values of name and age in the constructor of Student class. We want to inherit them from the parent class.
    // For this, we need to call the parent class constructor in base class constructor and pass values to that.

    A1.display(); // As you can observe from above, that for both Human class and Student class we have made a display function. But Human class display function only displays name and age because it only has access to them. Also, display function in Human class is public which means it is inherited by Student class.
    // This display function will display the Student class member display function.
    // This is because A1 is an object of Student class. And when you call a fucntion on an object, it first tries to see if that function is avaliable in that class or not. If it's not present, then it'll go to check it in parent class.
    // This is Method Overriding. 
}