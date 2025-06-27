// Array‐based heaps are overwhelmingly preferred in practice over pointer-based (linked‐node) implementations.

// With an array, you can compute the indices of a node’s parent or children in constant time :-
// parent(i) = (i-1)/2
// left_child(i) = 2*i + 1  
// right_child(i) = 2*i + 2  

// To insert a new element into an array-based (binary) heap, you follow two main steps:
// Append the element at the end (to preserve the complete-tree shape).
// “Sift-up” (heapify-up) to restore the heap-order property.

// So first place the new value at the next free slot in the array (i.e. at index size, where size is the current number of elements).
// Compare it with its parent (parent = ⌊(i−1)/2⌋) 
// If it violates the heap-order (e.g. new value > parent in a max-heap), swap them.
// Update your index to the parent’s index.

#include <iostream>
using namespace std;

class MaxHeap{
    int *arr;
    int size;
    int total_size;

    public:
    MaxHeap(int total_size){
        this->total_size = total_size;
        arr = new int[total_size];
        size = 0;
    }

    void insert(int value) {
        if (size == total_size) {
            cout << "Heap is full" << endl;
            return;
        }

        arr[size] = value;
        int index = size;
        size++;
        
        while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " inserted" << endl;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};

int main() {
    MaxHeap maxheap(6);
    maxheap.insert(4);
    maxheap.insert(14);
    maxheap.insert(20);

    maxheap.print();
}