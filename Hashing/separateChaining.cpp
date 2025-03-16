// Separate Chaining is a Collision Handling technique.

// In this when multiple elements are hashed into the same slot index, then these elements are inserted into a singly-linked list which is known as a chain. 

// In separate chaining, multiple elements with the same hash value are stored in a linked list at the corresponding index.
// To search for a key K, traverse the linked list at the hashed index.
// If a matching key is found, the entry exists; otherwise, reaching the end of the list means the entry is absent.

// Key Point :- Separate chaining handles collisions by grouping elements with the same hash value into a linked list, allowing multiple entries at a single index.

// The hash table stores the address (reference or pointer) of the first node of the linked list at each index, not the first element itself.

// Example :- 
// Index | Linked List (Chain)
// -----------------------------------
//   0   |  NULL
//   1   |  NULL
//   2   |  NULL
//   3   |  NULL
//   4   |  NULL
//   5   |  [15] --> [25] --> NULL
//   6   |  NULL
//   7   |  NULL
//   8   |  NULL
//   9   |  NULL

#include <iostream>
#include <list>
#include <algorithm>  

using namespace std;

class HashTable {
private:
    int BUCKET;               // Number of buckets in the hash table
    list<int>* table;         // Pointer to an array of lists (for chains)

public:
    // Constructor to initialize hash table with the given number of buckets
    HashTable(int b) {
        BUCKET = b;
        table = new list<int>[BUCKET];  // Create an array of lists (chains)
    }

    // Hash function to compute the index for each key
    int hashFunction(int key) {
        return key % BUCKET;  // Simple modulo operation to map key to index
    }

    // Function to insert a key into the hash table
    void insertItem(int key) {
        int index = hashFunction(key);     // Find index using hash function
        table[index].push_back(key);       // Insert key into the linked list at that index
    }

    // Function to delete a key from the hash table
    void deleteItem(int key) {
        int index = hashFunction(key);  // Find the index for the key
        list<int>::iterator it = find(table[index].begin(), table[index].end(), key);
        if (it != table[index].end()) {  // If key is found
            table[index].erase(it);      // Remove the key from the linked list
            cout << "Key " << key << " deleted from hash table." << endl;
        } else {
            cout << "Key " << key << " not found in hash table." << endl;
        }
    }

    // Function to display the hash table
    void displayTable() {
        for (int i = 0; i < BUCKET; i++) {
            cout << "Bucket " << i << ": ";
            for (int x : table[i]) {
                cout << x << " --> ";  // Print all elements in the chain
            }
            cout << "NULL" << endl;
        }
    }

    // Destructor to free allocated memory
    ~HashTable() {
        delete[] table;  // Clean up dynamically allocated memory
    }
};

// Driver function to test the hash table
int main() {
    HashTable h(7);  // Create a hash table with 7 buckets

    // Insert keys into the hash table
    h.insertItem(15);
    h.insertItem(11);
    h.insertItem(27);
    h.insertItem(8);
    h.insertItem(12);

    // Display the hash table
    cout << "Hash Table after insertion:" << endl;
    h.displayTable();

    // Delete a key from the hash table
    h.deleteItem(12);

    // Display the hash table after deletion
    cout << "\nHash Table after deletion:" << endl;
    h.displayTable();

    return 0;
}

// Advanatges :- Handles Collisions Efficiently, Dynamic Size, Simple Deletion, No Wastage of Space, Better Performance for Large Datasets and Supports Complex Data Types.
// Disadvantages :- Extra Memory Overhead, Cache Inefficiency, Performance Degradation with High Collisions, Not Suitable for Small Hash Tables and Pointer Overhead.

// The std::unordered_map in C++ is implemented using a Hash Table with Separate Chaining to handle collisions.