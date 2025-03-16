// Abstraction is the process of hiding the implementation details and showing only the functionality to the user. Basically only essential information is displayed and details are hided.

#include <iostream>
using namespace std;

class Customer {
    string name;
    int balance;

    public:
    Customer(string a, int b) {
        name = a;
        balance = b;
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << balance << endl;
        }
        else {
            cout << "Invalid amount";
        }
    }
};

int main() {
    Customer A1("Sarthak", 500);
    // This itself is an example of Abstraction. We are just giving user a function to deposit money, but the actual logic is hidden in our Class.
    A1.deposit(500);
}