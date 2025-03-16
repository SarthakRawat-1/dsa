// When multiple keys hash to the same index (collision), linear probing handles it by searching for the next available empty slot in the hash table. It does this in a linear fashion, checking the next slot, then the next, and so on, wrapping around to the beginning of the table if necessary.

// So for eg, the Hash function can look something like :- H(k) = (k + i) % 10 where i is the number of collisions
// Consider data :- (22, 34, 98, 54, 64, 74)
// For 22 :- (22 + 0) % 10 = 2, so 22 is stored at index 2, Similarly 34 at index 4, 98 at index 8
// For 54 :- (54 + 0) % 10 = 4, but 4 already stores 34, so there is one collision. Again, (54 + 1) % 10 = 5, so 54 is stored at index 5.
// For 64 :- (64 + 0) % 10 = 4, but 4 already stores 34, so there is one collision. Again, (64 + 1) % 10 = 5, but 5 already stores 54, so there are two collisions. Again, (64 + 2) % 10 = 6, so 64 is stored at index 6.
// Similarly, 74 is stored at index 7.
// Index | Data
// -----------------------------------
//   0   |  NULL
//   1   |  NULL
//   2   |  22
//   3   |  NULL
//   4   |  34
//   5   |  54
//   6   |  64
//   7   |  74
//   8   |  98
//   9   |  NULL

// Primary Clustering is a phenomenon that occurs in Open Addressing (specifically in Linear Probing) in Hash Tables, where keys tend to form clusters (groups) within the table.
// These clusters increase the probability of collisions and slow down search, insertion, and deletion operations.

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

    // Insert key using linear probing
    void insert(int key) {
        int index = hashFunction(key);
        while (table[index] != -1) {  // If the slot is occupied
            index = (index + 1) % TABLE_SIZE;  // Linear probing
        }
        table[index] = key;  // Insert the key at the found position
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

// Advantages :- Simple and Easy to Implement, No Extra Memory Overhead, Cache-Friendly, Supports Dynamic Resizing and Efficient for Low Load Factors 
// Disadvantages :- Primary Clustering, Performance Degrades at High Load Factors, Deletion Complexity, Poor Handling of Large Datasets and Table Resizing Overhead 