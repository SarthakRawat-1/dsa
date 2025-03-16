// Hybrid inheritance is a combination of two or more types of inheritance. It often includes scenarios where the derived class may inherit from multiple classes, potentially causing ambiguity if the same base class is inherited more than once. This issue is resolved using virtual inheritance.
// Check out multipathInheritance.cpp for an example.

// Here we are combining Hybrid Inheritance and Multiple Inheritance.
// In this example, we have child classes Boy and Girl. Both inherit from Student class. In addition to this, Boy class also inherits from the Male class and Girl class also inherit from the Female class.

#include <iostream>
using namespace std;

class Student {
    public :
    void print() {
        cout << "I am a Student" << endl;
    }
};

class Male {
    public :

    void MalePrint() {
        cout << "I am a Male" << endl;
    }
};

class Female {
    public :

    void MalePrint() {
        cout << "I am a Female" << endl;
    }
};

class Boy : public Student, public Male {
    public :
    void BoyPrint() {
        cout << "I am a Boy" << endl;
    }
};

class Girl : public Student, public Female {
    public :
    void GirlPrint() {
        cout << "I am a Girl" << endl;
    }
};

int main() {
    Girl G1;
    G1.GirlPrint();
    G1.print();

    Boy B1;
    B1.BoyPrint();
    B1.print();
}