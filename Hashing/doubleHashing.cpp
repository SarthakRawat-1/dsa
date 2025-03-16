// In double hashing, if a collision occurs at an index calculated by the primary hash function, a secondary hash function is used to calculate a fixed interval (step size) to probe for the next slot.
// It minimizes clustering—both primary and secondary clustering—that can occur with linear probing and quadratic probing.

// So for eg, the Hash function can look something like :- H(k) = (H1(k) + i * H2(k)) % 10 where i is the number of collisions
// Let's say :- H1(k) = k % 5 and H2(k) = k % 6
// Consider data :- (32, 47, 52, 87, 2)
// For 32 :- (32 % 5 + 0 * 32 % 6) % 10 = 2, so 32 is stored at index 2.
// For 47 :- (47 % 5 + 0 * 47 % 6) % 10 = 2, but 2 already stores 32, so there is one collision. Again, (47 % 5 + 1 * 47 % 6) % 10 = 7, so 47 is stored at index 7.
// For 52 :- (52 % 5 + 0 * 52 % 6) % 10 = 2, but 2 already stores 32, so there is one collision. Again, (52 % 5 + 1 * 52 % 6) % 10 = 6, so 52 is stored at index 6.
// Simiarly, 87 will be stored at index 5, and 2 will be stored at index 0.
// Index | Data
// -----------------------------------
//   0   |  2
//   1   |  NULL
//   2   |  32
//   3   |  NULL
//   4   |  NULL
//   5   |  87
//   6   |  52
//   7   |  47
//   8   |  NULL
//   9   |  NULL

#include <iostream>
#include <vector>
using namespace std;

// Define table size
#define TABLE_SIZE 7

// Hash table class
class HashTable {
private:
    vector<int> table;  // Hash table storage

public:
    // Constructor to initialize table with -1
    HashTable() {
        table.resize(TABLE_SIZE, -1);
    }

    // Primary hash function
    int h1(int key) {
        return key % TABLE_SIZE;
    }

    // Secondary hash function
    int h2(int key) {
        return 1 + (key % (TABLE_SIZE - 1)); // Must be co-prime to TABLE_SIZE
    }

    // Insert key into the hash table
    void insert(int key) {
        int index = h1(key);
        int step = h2(key);
        int i = 0;

        // Probing sequence
        while (table[(index + i * step) % TABLE_SIZE] != -1) {
            i++;
            if (i == TABLE_SIZE) { // Full table
                cout << "Table is full, cannot insert " << key << endl;
                return;
            }
        }
        table[(index + i * step) % TABLE_SIZE] = key;
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] == -1)
                cout << "Index " << i << ": empty" << endl;
            else
                cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

// Driver code
int main() {
    HashTable ht;

    // Insert keys
    ht.insert(49);
    ht.insert(63);
    ht.insert(56);
    ht.insert(52);

    // Display hash table
    ht.display();

    return 0;
}

// Advantages :- Eliminates Primary and Secondary Clustering, Better Distribution of Keys, No Extra Memory Overhead, Cache-Friendly and Supports Dynamic Resizing  
// Disadvantages :- Higher Computational Cost, Complex Implementation, Deletion Complexity, Performance Degrades at High Load Factors and Table Resizing Overhead  
