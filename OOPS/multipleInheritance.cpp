// In multiple inheritance, a derived class inherits from more than one base class.

#include <iostream>
using namespace std;

class Engineer {
    public :
    string specialization;

    Engineer() {
        cout << "I am an Engineer" << endl;
    }

    void work() {
        cout << "I have specialization in " << specialization << endl;
    }
};

class Youtuber {
    public : 
    int subscribers;

    Youtuber() {
        cout << "I am a Youtuber" << endl;
    }

    void contentCreator() {
        cout << "I have " << subscribers << " subscribers" << endl;
    }
};

class CodeTeacher : public Engineer, public Youtuber { // Now this class will inherit from both Engineer and Youtuber class.
    public :
    string name;

    CodeTeacher(string name, string specialization, int subscribers) {
        this->name = name;
        this->specialization = specialization;
        this->subscribers = subscribers;
    }


    void showcase() {
        work(); // This will work because the work() function is public in Engineer class and we have also used public access modifier.
        contentCreator(); // Same goes for this
    }
};

int main() {
    CodeTeacher A1("Sarthak", "C++", 1000);
    A1.showcase();

    // We know that CodeTeacher constructor will be called the last. But now the question arises, which constructor will be called first? Engineer or Youtuber?
    // The constructor of Engineer class will be called first. Because in this statement :- class CodeTeacher : public Engineer, public Youtuber
    // We have inherited Engineer class first, then we have inherited the Youtuber class.
}