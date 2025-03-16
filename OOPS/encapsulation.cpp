// Encapsulation refers to the wrapping of data and information like functions in a single unit, while controlling access to them.
#include <iostream>
using namespace std;

class Customer {
    // We have made the data members private, so that User can't directly access them and provide wrong data. Logic for checking data we can write in functions, which we can make public.
    string name;
    int balance;
    int age;

    public:

    Customer(string a, int b, int c) {
        name = a;
        balance = b;
        int age = c;
    }

    void deposit(int amount) {
        // Logic we have written here
        if (amount > 0) {
            balance += amount;
            cout << balance << endl;
        }
        else {
            cout << "Invalid amount";
        }
    }

    void withdraw(int amount) {
        // Logic we have written here
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << balance << endl;
        }
        else {
            cout << "Invalid amount";
        }
    }

    void updateAge(int age) {
        if (age > 0 && age < 100) {
            this->age = age;
        }
        else {
            cout << "Invalid age";
        }
    }

};

int main() {
    Customer A1("Sarthak", 2304, 18);
    A1.deposit(100);
    A1.withdraw(2000);
    A1.updateAge(19);
}