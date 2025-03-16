// When a function is marked as virtual in the base class, it can be overridden by derived classes. When you use pointers or references to base class objects, the overridden function in the derived class is called, enabling run-time polymorphism.

#include <iostream>
#include <vector>
using namespace std;

class Animal {
    public :

    // With virtual keyword, this speak() function will be resolved at run time not at compile time.
    // Now we know that at run time, memory is allocated for an object of class Dog. So now the pointer knows that it is pointing to an object of class Dog, so it should invoke speak() from the Dog class.
    virtual void speak() {
        cout << "HuHu" << endl;
    }
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
    // NOTE :- A pointer that we declared of type of a parent class, can hold address of an object of it's child class.
    Animal *p;
    p = new Dog(); // We know that when we use new keyword, the memory allocation happens at run time. 
    p->speak(); // This will output HuHu. As we have seen in single inheritance, that object of a class first try to access methods from their class and if not availiable, they check in their Parent class. In our case, Animal class has no Parent class. 
    // So while we are creating a Dog object and storing it's address in p, we have defined pointer p to be pointing to object of Animal class.
    // This is because the function call is resolved at compile-time based on the type of the pointer, not the actual type of the object it points to. So in compile time itself, it was decided that speak() function to be called will be from Animal class.

    // But what as we have allocated memory for an object of class Dog, we wanted to invoke speak() function of Dog class. We can achieve this using virtual keyword. Insert virtual keyword before speak() in Animal class.
    // But be careful now, if you have a function present just in Dog class and not in parent class, then you won't be able to access that function with the p pointer. That function needs to be present in both classes, and if you want the Dog class one to execute you will have to use virtual keyword in Animal class one jsut like we did with speak.

    // But now the question arises, why did we not just made an object of type Dog and used speak method on that??
    // Let's look at this through an example. For this we will also make a child class called Cat.
    Animal *p;
    vector <Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Animal());
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    // We have to take addresses one by one from the vector and invoke corresponding speak() function.

    // One way to solve this is iterate and then from each of the address, know what's present there, and compare it with Dog, Cat and Animal. and on the basis of that, execute speak fucntion. But this will become complex.
    // A simpler way would be to iterate, then using the Animal *p, store each address from the vector one by one. Then on that p, you can directly invoke speak()

    for (int i = 0; i < animals.size(); i++) {
        p = animals[i];
        p->speak();
    } 
    // We are able to do this because of Runtime polymorphism using virtual keyword.
    // p is an Animal* pointer. The vector animals contains objects of different types (Dog, Cat, and Animal), but all of these objects are stored as pointers of type Animal*. When you assign p = animals[i];, the pointer p points to a specific object (which could be a Dog, Cat, or Animal). The call p->speak() is resolved at runtime, and the correct version of speak() is called based on the actual type of the object that p points to.

    // This becomes even more convient as the number of child classes grow. Because it could be that User gives an input and we don't know which class output it is. So in this case, we can use dynamic polymorphism and pointer to parent class. Store the address of object in that pointer and then using virtual keyword and methods, we can execute the desired method.
}