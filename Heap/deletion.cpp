// Deletion happens at the root (top) of the heap always, which is either the maximmum or the minimum element, depending on max heap or min heap
// The last node of the heap will replace the top of the heap. This is because even if we remove the last node of heap, the structure remains a complete bianry tree.
// But this may disturb heap in a second manner. The parent being lesser or greater than it's children depending on the type of heap.
// So, this new root node is now swapped and sent to it's correct position. It is compared with it's children. For max heap, we will select the greatest children and swap it with that.
// Then again, it will happen with it's new children. When no more further swaps happen or there is no children, we stop and find correct position.

#include <iostream>
using namespace std;

class MaxHeap {
    int *arr;          // Pointer to the array that holds heap elements
    int size;          // Current number of elements in heap
    int total_size;    // Maximum capacity of the heap array

public:
    // Constructor: allocate array and initialize sizes
    MaxHeap(int total_size) {
        this->total_size = total_size;
        arr = new int[total_size];  // allocate array on heap
        size = 0;                    // start with empty heap
    }

    // Destructor: free allocated memory
    ~MaxHeap() {
        delete[] arr;
    }

    // Insert a new value into the heap
    void insert(int value) {
        // Check for overflow (heap full)
        if (size == total_size) {
            cout << "Heap is full" << endl;
            return;
        }

        // Place the new element at the end (next free slot)
        arr[size] = value;
        int index = size;
        size++;

        // Sift-up: restore heap-order by swapping with parent while larger
        while (index > 0) {
            int parent = (index - 1) / 2;
            // If current node is greater than parent, swap
            if (arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;  // move up to parent's index
            } else {
                break;  // heap property satisfied
            }
        }

        cout << arr[index] << " inserted" << endl;
    }

    // Heapify (sift-down) starting from index to restore heap-order
    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;   // left child index
        int right = 2 * index + 2;  // right child index

        // Find largest among current node and its children
        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        // If a child is larger, swap and continue heapifying
        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);  // recursive call on child index
        }
    }

    // Remove the root (max element) from the heap
    void delete_node() {
        // Underflow check
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        // Output the maximum value
        cout << arr[0] << " deleted" << endl;

        // Move the last element to root position
        arr[0] = arr[size - 1];
        size--;  // reduce heap size (removes last element logically)

        // If heap is not empty, restore heap-order from root
        if (size > 0) {
            heapify(0);
        }
    }

    // Print all elements in the heap (array order)
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create a MaxHeap with capacity 6
    MaxHeap maxheap(6);

    // Insert some elements
    maxheap.insert(4);
    maxheap.insert(14);
    maxheap.insert(20);
    maxheap.insert(11);

    // Delete (extract) the maximum element
    maxheap.delete_node();

    // Continue inserting
    maxheap.insert(15);
    maxheap.insert(25);

    // Print current heap array
    maxheap.print();

    return 0;
}


// A Min-Heap implementation using an array (complete binary tree)
// Supports insert, extract-min (delete_node), and print operations.

#include <iostream>
using namespace std;

class MinHeap {
    int *arr;          // Pointer to array holding heap elements
    int size;          // Current number of elements in heap
    int capacity;      // Maximum capacity of the heap array

public:
    // Constructor: allocate array and initialize sizes
    MinHeap(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];  // allocate underlying array
        size = 0;                 // start with an empty heap
    }

    // Destructor: free allocated memory
    ~MinHeap() {
        delete[] arr;
    }

    // Insert a new value into the heap
    void insert(int value) {
        // Check for overflow (heap full)
        if (size == capacity) {
            cout << "Heap is full" << endl;
            return;
        }

        // Place the new element at the end (next free slot)
        arr[size] = value;
        int index = size;
        size++;

        // Sift-up: restore heap-order by swapping with parent while smaller
        while (index > 0) {
            int parent = (index - 1) / 2;
            // If current node is smaller than parent, swap
            if (arr[index] < arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;  // move up to parent's index
            } else {
                break;  // heap property satisfied
            }
        }

        cout << arr[index] << " inserted" << endl;
    }

    // Heapify (sift-down) starting from index to restore heap-order
    void heapify(int index) {
        int smallest = index;
        int left = 2 * index + 1;   // left child index
        int right = 2 * index + 2;  // right child index

        // Find smallest among current node and its children
        if (left < size && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest]) {
            smallest = right;
        }

        // If a child is smaller, swap and continue heapifying
        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            heapify(smallest);  // recursive call on child index
        }
    }

    // Remove the root (minimum element) from the heap
    void delete_node() {
        // Underflow check
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        // Output the minimum value
        cout << arr[0] << " deleted" << endl;

        // Move the last element to root position
        arr[0] = arr[size - 1];
        size--;  // reduce heap size (removes last element logically)

        // If heap is not empty, restore heap-order from root
        if (size > 0) {
            heapify(0);
        }
    }

    // Print all elements in the heap (array order)
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create a MinHeap with capacity 6
    MinHeap minheap(6);

    // Insert some elements
    minheap.insert(20);
    minheap.insert(15);
    minheap.insert(30);
    minheap.insert(10);

    // Delete (extract) the minimum element
    minheap.delete_node();

    // Continue inserting
    minheap.insert(12);
    minheap.insert(8);

    // Print current heap array
    minheap.print();

    return 0;
}
