// An Exception is an unexpected problem that arises during the execution of the program and our program terminates with some error.
// We have try block which represents a block of code which can throw an exception, catch block which is executed when exception is thrown and throw keyword which can be used to throw the Exception.

// 

#include <iostream>
using namespace std;

// You can make your own exception class which inherits from exception class or it's subclasses.
class InvalidAmountError : public runtime_error {
    public:
    // Constructor that takes an error message and passes it to the base class runtime_error
    InvalidAmountError(const string &msg): runtime_error(msg) {};
};

class Customer {
    string name;
    int balance, account_number;

    public:

    Customer(string name, int balance, int account_number) {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }

    void deposit(int amount) {
        if (amount <= 0) {
            // You can also use this to throw an exception. runtime_error is a subclass of exception.
            throw runtime_error("Amount should be greater than Zero.");
        }

        // This logic will work perfectly because these statements won't be executed if the amount is less than or equal to zero as it throws an exception.
        balance += amount;
        cout << amount << " is credited successfully." << endl;

        
    }

    void withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << " is debited successfully." << endl;
        }
        else if (amount < 0) {
            throw InvalidAmountError("Amount should be greater than Zero.");
        }
        else {
            throw "Insufficient Balance.";
        }
    }
};

int main() {
    Customer C1("Sarthak", 5000, 10);

    try {
        C1.deposit(200);
        C1.withdraw(-2);
        C1.deposit(100); // This statement won't run as the statement before it will throw an exception.
    } catch (const char *e) {
        // This can be used to catch exceptions that are thrown as C-style string literals or const char*
        cout << "Exception Occured String:- " << e << endl;
    }
    catch (const InvalidAmountError &e) {
        // This can be used to catch InvalidAmountError exceptions
        cout << "Exception Occured InvalidAmountError:- " << e.what() << endl;
    }
    catch (const runtime_error &e) {
        // This can be used to catch runtime_error exceptions
        cout << "Exception Occured Runtime:- " << e.what() << endl;
    } 
    // This is a catch-all block. It catches any type of exception, including non-standard exceptions, exceptions that don't inherit from std::exception, and even primitive types like integers, strings, etc.
    catch (...) {
        cout << "Exception Occured Catch-All:- " << endl;
    }

}