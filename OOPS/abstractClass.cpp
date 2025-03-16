// If you want to ensure that a derived class must override a function, you can declare it as a pure virtual function in the base class. A class containing at least one pure virtual function becomes an abstract class, and you cannot instantiate objects of this class.
// The Syntax is pretty much the same as Virtual classes, just the method that you are delcaring virtual in parent class, don't put anything in body (don't even use braces) and after parenthesis use =0
// In this case however, you can't create an object of the parent class if it has a pure virtual function.

// Take the same example as virtualFunction.cpp
// Now we know that no animal does HuHu, each animal will have a particular speak() function. So, in this case, the speak() method of Animal class should never be invoked. Which means that every child class should have this method overwritten inside them.

#include <iostream>
#include <vector>
using namespace std;

class Animal {
    public :

    virtual void speak() = 0; // Pure Virtual Function
};

class Dog : public Animal {
    public : 

    void speak() {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
    public : 

    void speak() {
        cout << "Meow" << endl;
    }
};

int main() {

    Animal *p;
    vector <Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for (int i = 0; i < animals.size(); i++) {
        p = animals[i];
        p->speak();
    } 

}