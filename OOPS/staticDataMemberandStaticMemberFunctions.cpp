// Static Data Members are attributes of classes or class members. Declared using static keyword. Only one copy of that member is created for the entire class and that is shared by all objects. 
// Static Data Members are initialized before any object of that class is created.
// It belongs to class only, not to objects.

// Static Member Functions are functions that belong to the class rather than any particular instance of the class. This means they can be called without creating an object of the class and do not have access to non-static data members or non-static member functions of the class. They can access static data members and static member functions of the class, even if the declaration of them is done in private instead of public.

#include <iostream>
using namespace std;

class Customer {
    string name;
    int account_number, balance;
    // This is a Static Data Member
    static int total_customers;
    static int total_balance;

    public:

    // If you want to access the Static Data Member without creating an object. Just shift the declaration to public: like :-
    // static int total_customers;
    // Initialization will remain same.

    Customer(string name, int account_number, int balance) {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        total_customers += 1;
        total_balance += balance;
    }

    // This is a Static Member Function. It can only access Static Data Members.
    static void accessStatic() {
        cout << "Total Customers : " << total_customers << endl;
        cout << "Total Balance : " << total_balance << endl;
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            total_balance += amount;
        }
    }

    void withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            total_balance -= amount;
        }
    }

    void display() {
        cout << name << " " << account_number << " " << balance << " " << total_customers << endl;
    }
};

// This is initializing the Static Data Member. 
int Customer::total_customers = 0;
int Customer::total_balance = 0;

int main() {
    Customer A1("Sarthak", 21, 999999);
    Customer A2("Shogun", 22, 9999999);
    A1.display();
    A2.display();
    Customer A3("Kinggun", 24, 99999999);
    A3.display();


    // You can use this statement to access the Static Data Member without creating an object.
    // Customer::total_customers = 5;
    // cout << Customer::total_customers << endl;

    Customer::accessStatic();

    A1.deposit(800);
    A2.withdraw(9999);
    Customer::accessStatic();
}