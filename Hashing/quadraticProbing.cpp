// When a collision occurs (i.e., two keys hash to the same index), quadratic probing searches for the next available slot using a quadratic function, rather than a linear function. The probing sequence is designed to reduce clustering, a problem associated with linear probing, where consecutive keys might hash to consecutive indices and cause "primary clustering".

// So for eg, the Hash function can look something like :- H(k) = (k + i ^ 2) % 10 where i is the number of collisions
// Consider data :- (72, 84, 96, 94, 58)
// For 72 :- (72 + 0 ^ 2) % 10 = 2, so 72 is stored at index 2, Similarly 84 at index 4, 96 at index 8
// For 94 :- (94 + 0 ^ 2) % 10 = 4, but 4 already stores 84, so there is one collision. Again, (94 + 1 ^ 2) % 10 = 5, so 94 is stored at index 5.
// For 58 :- (58 + 0 ^ 2) % 10 = 8, so 58 is stored at index 8.
// Index | Data
// -----------------------------------
//   0   |  NULL
//   1   |  NULL
//   2   |  72
//   3   |  NULL
//   4   |  84
//   5   |  94
//   6   |  96
//   7   |  NULL
//   8   |  58
//   9   |  NULL

// Secondary Clustering is a problem that occurs in Open Addressing techniques like Quadratic Probing and Double Hashing when keys hash to the same initial index and follow the same probe sequence to resolve collisions.

#include <iostream>
using namespace std;

#define TABLE_SIZE 7

class HashTable {
private:
    int table[TABLE_SIZE];  // Array to store the hash table

public:
    HashTable() {
        // Initialize the table with -1 (indicating empty slots)
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    // Hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Insert key using quadratic probing
    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;
        // Quadratic probing
        while (table[(index + i * i) % TABLE_SIZE] != -1) {
            i++;
            if (i == TABLE_SIZE) {
                cout << "Table is full, cannot insert key: " << key << endl;
                return;
            }
        }
        table[(index + i * i) % TABLE_SIZE] = key;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (table[i] != -1)
                cout << table[i];
            else
                cout << "empty";
            cout << endl;
        }
    }
};

int main() {
    HashTable h;
    h.insert(10);
    h.insert(22);
    h.insert(31);
    h.insert(4);
    h.insert(15);
    h.insert(28);
    h.insert(17);

    h.display();  // Display the table
    return 0;
}

// Advantages :- Reduces Primary Clustering, Better Distribution of Keys, No Extra Memory Overhead, Cache-Friendly and Supports Dynamic Resizing  
// Disadvantages :- Secondary Clustering, Higher Computational Cost, Performance Degrades at High Load Factors, Deletion Complexity and Table Resizing Overhead  
