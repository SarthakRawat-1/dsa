// The capability of a class to derive property and characteristics from another class.
// We have a Parent class and there can be lot of Child classes deriving from that Parent class.
// Let's say we have a Human class whcih is our Parent class and it has it's class members :- string name, int age, int weight
// We have two Child classes, Student and Teacher class, now instead of redefining the name, age and weight in Child classes, we can derive those from Human class. Ofc the members should be declared in public or protected.

#include <iostream>
using namespace std;

class Human {
    // Now, Religion and color won't be inherited by Student class.
    string Religion, color;
    public:
    string name;
    int age, weight;
};

// In creating a Derived class we have used an access modifier before the Parent class name. This access modifier determines the access modifier of the inherited members, inside the derived class.
// So, when you have a Parent Class, form that Class both public and protected data members can be inherited. But after they are inherited in the Child class, what will be their access modifier inside the Child class is determined by this access modifier. So obv, it can be public/private/protected.
// When the access modifier in the Parent Class is public, then access modifier before the Parent class name will be the access modifier of the inherited Public members inside the Child class.
// When the access modifier in the Parent Class is protected and the access modifier before the Parent class name is public or protected then the access modifier of the inherited protected members will be protected inside the Child class but if it is private then the access modifier of the inherited protected members will be private inside the Child class.
// When the access modifier in the Parent Class is private, the members inside that cannot be inherited by Child classes.
class Student : private Human {
    int roll_number, fees;

    public:

    Student(string name, int age, int weight, int roll_number, int fees) {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_number = roll_number;
        this->fees = fees;
    }

    // void fun(string n, int a, int w) {
    //     // This is allowed obviously
    //     name = n;
    //     age = a;
    //     weight = w;
    // }

    void display() {
        cout << "Name :- " << name << " Age :- " << age << " Weight :- " << weight << " Roll No :- " << roll_number << " Fees :- " << fees << endl;
    }
};

class Teacher: public Human {
    int salary, id;
};

int main() {
    Student A("Sarthak", 19, 57, 62, 2540000);

    // This is valid, if both states are public.
    // A.name = "Sarthak"; 

    // This can run for pretty much every case as the function is public so it can be accessed. Only time this will fail, is when name, age, weight are private in the Parent Class as then they cannot be inherited.
    // A.fun("Sarthak", 19, 57); 
    A.display();

    Teacher B;
    B.name = "Shogun"; // This will work and we can see that instance of Teacher class is able to access the inherited member name from Parent Class.
}