// Let's say you have an array of size n = 5. This will be the size of our Stack, so we can store 5 elements at max.
// Now, we have elements :- 2, 3, 1, 5 and 6 to push into this Stack i.e. array. So, first we push 2 into this array which will come at index 0. Then 3 will be pushed to index 1 and so on... Let's say we store 4 elements i.e. till 5.
// We want to pop an element from the Stack i.e. array. Stack follows LIFO and hence, we pop 5 from the array which is the last element that we have filled in our array.
// We can pop this element using the help of a pointer to keep track of the last element. Then after popping, we can decrease the pointer by one to point to the new Last element.
// Intitally, when there are no elements filled in the array this pointer will be at -1, when we want to push an element to the array, we can first increase the pointer and using that add the element to the array.
// For the first element, pointer will be increased from -1 to 0 and then the first element will be inserted at index 0 position.
// If pointer points to the last element in the array, it means that the last position of the array is already filled. So we can't push more elements in the array. If we try to, it will be the condition of Stack Overflow.
// Similarly, if pointer is -1, it means that there are no elements in the array. So we can't pop any element from the array. If we try to, it will be the condition of Stack Underflow.
// The top/peek operation will just return the element pointed to by our pointer, becuase our pointer points to the last element in the array which is our top element in stack.
// Size operation we can also find easily using pointer, as we already know the index of last element using pointer, using it we can find the size of stack. Note that this size is not the size of array which actually represents the total memory space or size avaliable in the stack.
// If pointer = -1, then only Stack is empty.

#include <bits/stdc++.h>
using namespace std;

class Stack {
    int *arr; // Pointer to dynamically allocate array for stack
    // The reason for using int *arr instead of int arr[] in the stack implementation is related to dynamic memory allocation versus static memory allocation.
    // When you declare an array as int arr[size];, the array size must be known at compile time. This means you need to specify the size of the array when you write the code. The array is allocated memory on the stack (memory stack, not the data structure). The size of the array cannot be changed once it's declared. 
    // When you declare int *arr;, you are defining a pointer to an integer, in this case the first element of an array of integers, but not allocating memory for the array itself. You can then allocate memory dynamically using new (or malloc in C). This allows you to determine the size of the array at runtime, making your code more flexible. You can allocate as much memory as you need when the program runs. The array is allocated memory on the heap, which is a larger pool of memory and can grow and shrink as needed, unlike the stack.

    int size; // To store the maximum size of the stack
    int top; // To keep track of the current top index in the stack

    public:

    bool flag; // This we have used to check whether the stack is empty or not. If stack is empty flag will be 1 otherwise it'll be 0.

    // Constructor to initialize the stack with a given size
    Stack(int size) {
        this->size = size;
        arr = new int[size]; // Dynamically allocate memory for the stack
        // When you allocate memory dynamically using new int[size], arr points to the first element of the newly allocated array in memory.
        top = -1; // Initialize top to -1 indicating the stack is empty
        flag = 1; // This means that Stack is emoty at it's creation.
    }

    // Function to push an element onto the stack
    void push(int data) {
        if (top == size - 1) {  // Check if the stack is full (Stack Overflow condition)
            cout << "Stack Overflow" << endl;
            return;
        }
        else {
            top++; // Increment top to point to the next empty position
            arr[top] = data; // Insert the new element at the top position
            // You can replace both of these statements with this :- arr[++top] = data;

            // Now that you know arr is a pointer to first element of the array. And we also know that array name is pointer to first element of the array. And we can use arrayname[index] to access and change array elements. hence, we can also do arr[top] here to access and change the last element, because top is index of the last element.
            // NOTE :- In C++ (and C), the expression arr[index] is a shorthand for pointer arithmetic. The expression arr[index] is equivalent to *(arr + index). arr + index moves the pointer arr forward by index positions, each position corresponding to the size of an int (in this case). *(arr + index) dereferences the pointer at the new location, giving you the value stored at that position.


            cout << "Pushed " << data << " into the Stack" << endl;
            flag = 0; // As we have pushed an element which means Stack is not empty anymore.
        }
    }

    // Function to pop the top element from the stack
    void pop() {
        if (top == -1) { // Check if the stack is empty (Stack Underflow condition)
            cout << "Stack Underflow" << endl;
        }
        else {
            top--; // Decrement top to remove the top element from the stack
            cout << "Popped " << arr[top + 1] << " from the Stack" << endl;
            // You can replace both of these statements with this :- cout << "Popped " << arr[top--] << " from the Stack" << endl;
            
            // You can observe that we have not removed the element from the array but just simply moved the pointer.
            // This is because in this context it doesn't matter whether there is an element in that position or not. 
            // For us, it is not the topmost element any more. When we want to push an element to the stack, we are simply replacing it whether the element that comes after the topmost element.
            // Also because we can't even delete that element, the best thing that we can do is make it zero or empty.

            if (top == -1) { // If after popping, top is -1, then stack is empty.
                flag = 1;
            }
        }
    }

    // Function to return the top element of the stack without removing it
    int peek() {
        if (top == -1) { // If the stack is empty, we cannot return the top element
            cout << "Stack is Empty." << endl;
            return -1; // Assuming our Stack only stores positive values, so we can return -1 in this case. But this becomes a bit problematic. If we have pushed negative numbers and specifically -1 to our Stack, then it will be confusing to know which -1 indicates what.
            // So to get around this we are using the bool flag to check whether the stack is empty or not.
        }
        else {
            return arr[top]; // Return the top element
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        if (top == -1) {
            cout << "Stack is Empty." << endl;
            return true;
        }
        else {
            return false;
        }
        
        // Instead of these if else statements, we could have just written this :-
        // return top == -1;
    }

    int IsSize() {
        return top + 1; // We need to return top + 1 because top is pointing to the last element in the array and array are indexed starting from zero.
    }

     // Function to check if the elements in the stack form a palindrome
    bool isPalindrome() {
        if (top == -1) return true; // An empty stack is considered a palindrome

        int start = 0;
        int end = top;

        while (start < end) {
            if (arr[start] != arr[end]) {
                return false; // If any mismatch found, it's not a palindrome
            }
            start++;
            end--;
        }
        return true; // If no mismatches found, it's a palindrome
    }


    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr; // Free dynamically allocated memory
    }
};

int main() {
    Stack S(5);

    // S.push(5);
    // S.push(4);
    // S.push(3);

    // S.pop();
    // S.pop();
    // S.pop();
    // S.pop(); // Now this will give Underflow.


    // S.push(5);
    // S.push(4);
    // S.push(3);
    // S.push(2);
    // S.push(1);
    // S.push(0); // This will give Overflow.


    // S.push(5);
    // S.push(4);
    // S.push(3);

    // cout << S.peek() << endl;
    // cout << S.isEmpty() << endl;
    // cout << S.IsSize() << endl;


    // With the flag variable now, we won't directly use peek function to check whether the stack is empty or not. We will wrap it inside a condition.
    S.push(-1);
    int value = S.peek();

    if (S.flag == 0) {
        cout << value << endl;
    }

    // Check if the stack is a palindrome
    if (S.isPalindrome()) {
        cout << "The stack elements form a palindrome." << endl;
    } else {
        cout << "The stack elements do not form a palindrome." << endl;
    }

    // Instead of using the flag variable, you could have also used the IsSize and IsEmpty function to check whether Stack is empty or not and then use peek fucntion.
}
