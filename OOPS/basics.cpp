#include <iostream>
using namespace std;

// This is how we have defined our class.
class Student {
    
// The public keyword, which is an access modifier is necessary so that we can access the members of the class from outside the class.
// By default, the access modifier is private. Other options are public and protected.

// public means that the code can be accessed within the class, external code i.e. outside the class and also derived class.
// private means that the code can only be accessed within the class.
// protected means that the code can be accessed within the class and derived class but not outside the class.

// public:
 string name;
 int age, roll_number;
 string grade;

 // It's not a good idea to public the data members of the class. We use setters and getters for that. Another good thing about these functions is that we can use additional logic inside them to check for certain conditions. All this is called Data Hiding.

 public: 
 void setName(string s) {
    if (s.size() == 0) {
        cout << "Invalid name" << endl;
        return;
    }
     name = s;
 }
 void setAge(int a) {
    if (a < 0 || a > 100) {
        cout << "Invalid age" << endl;
        return;
    }
     age = a;
 }
 void setRollNumber(int r) {
     roll_number = r;
 }
 void setGrade(string g) {
     grade = g;
 }
 void getName() {
     cout << name << " ";
 }
 void getAge() {
     cout << age << " ";
 }
 int getRollNumber() {
    // This is also valid 
     return roll_number;
 }
 string getGrade(int pin) {
    if (pin == 1234) {
     return grade;
    }
    return "";
 }
};

int main() {
    Student S1;
    // This is how we can assign values to the data members of the class. But using setters is better.
    // S1.name = "Sarthak";
    // S1.age = 19;
    // S1.roll_number = 62;
    // S1.grade = "A";

    // This is how we can get the values of the data members of the class. But using getters is better.
    // cout << S1.age << " ";

    S1.setName("Sarthak");
    S1.setAge(19);
    S1.setRollNumber(62);
    S1.setGrade("A");
    S1.getName();
    S1.getAge();
    cout << S1.getGrade(1234) << " ";
    cout << S1.getRollNumber();

}