// A Segment Tree is a versatile binary tree data structure designed for storing information about intervals (or segments) of an array.
// It excels at handling range queries and dynamic updates efficiently, making it ideal for problems such as range sum queries, range minimum/maximum queries etc.

// A segment tree is a binary tree where each leaf represents a single element of the original array, and each internal node represents a segment (or interval) that is the union of its child segments.
// The root covers the entire array, and each level of the tree represents a further partitioning of the array into smaller segments.

// For eg :- Let's say we have an array {3, 6, 4, 25, 5, 13, 8}
// If we are asked for sum of all elements from index 2 to 5, we can do it normally but it will take O(n) complexity in worst case (if indexes cover whole array).
// But with Segment Tree we can do it in O(log n) complexity.
// But we can also make an array for Prefix sums to calculate that!
// However this will not be efficient if we want to change one particular element in the array, as then quite a lot of elements in prefix sum array will have to be updated.
// However, to update Segment Tree, it will still only take O(log n) complexity.
// Similarly, we can find maximum element in a range in O(log n) complexity using Segment Tree.

// We want to build a Segment Tree for {3, 6, 4, 25, 5, 13, 8}
// The root node will store answer for index 0 to 6 i.e. whole array. In our case, we want sum of elements, so we will store sum of all elements in root node.
// Then we will divide the array into 2 parts, 0 to 3 index and 4 to 6 index.
// In that store sum of elements of 0 to 3 index in left child and sum of elements of 4 to 6 index in right child.
// Similarly, keep dividing till we get to a single element (index) only, which will store just that element at index. These will be our leaf nodes.
// Calculating the sum part might take more time, so we will avoid taht at first, only divide the nodes first. Then we will start filling out leaf nodes first and parent nodes will be filled from the sum of values of their child nodes.
// Ensuring the tree is created in O(n) complexity.

// The height of the Segment Tree will be log n and total number of nodes will be 2n - 1. This is if n is a power of 2.
// When the input array’s length isn’t a power of 2, the segment tree is built on the next power of 2, say m=2⌈log⁡2n⌉. 
// In that case, the complete tree would have up to 2×m−1 nodes, and since m can be almost 2n in the worst case, this value is less than 4n. 
// Allocating an array of size 4n is a safe upper bound that works for any n without having to calculate the exact size.

// Another way to think about this is that, if tree has 2n - 1 nodes, then on the last level there are n nodes, before that there are n - 1 nodes and finally if one more level comes below n, then it will require 2n nodes, hence, 2n - 1 + 2n = 4n - 1 = 4n.

// Now if we are asked to find the sum of all elements from index 2 to 5.
// From Segment Tree, we can find it using follows :-
// We start with root, it holds sum of 0 to 6 index. Let's say 2 is left and 5 is right and 0 is start and 6 is end.
// We have three cases :- Fully out of range, Fully in range, Partially in range.

// We want answer from 2 to 5 and we are given 0 to 6. Let's say while traversing we get to node which has value of index 6. In this case, the answer is Fully out of range. We won't take answer from this.
// But if we are at node with answer for range 2, 3. In this case, the answer is Fully in range, so we will take answer from here. 
// Let's say we have 0 to 6 range node. In this case, the answer is Partially in range (as we only want from 2 to 5 but it also has 0 and 6). In this case, go to both child nodes, and take answer from both of them and add them.
                                                                                                                                            