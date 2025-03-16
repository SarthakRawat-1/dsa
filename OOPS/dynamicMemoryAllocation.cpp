#include <iostream>
using namespace std;

class Student {
    public:
    string name;
    int age, roll_number;
    string grade;
};


// This is how we can do Dynamic memory allocation using pointers.
int main() {
    // The Student before *S is there because datatype of pointer is same as the object it is pointing to.
    Student *S = new Student;
    (*S).name = "Sarthak";
    (*S).age = 10;
    (*S).roll_number = 21;
    (*S).grade = "A";

    // You can also use this notation, i.e. S->name instead of (*S).name
    cout << S->name << endl;
    cout << S->age << endl;
    cout << S->roll_number << endl;
    cout << S->grade << endl;

}