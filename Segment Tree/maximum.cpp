#include <iostream>
#include <vector>
#include <climits>    // For INT_MIN
#include <algorithm>  // For std::max

using namespace std;

// SegmentTree class for answering range maximum queries and handling point updates.
class SegmentTree {
    vector<int> tree; // The segment tree array that holds the maximum value for each segment.
    vector<int> arr;  // The original input array.
    int n;            // Number of elements in the input array.

public:
    // Constructor: initializes the segment tree using the provided input vector.
    SegmentTree(vector<int> input) {
        n = input.size();
        arr = input;
        tree.resize(4 * n);  // Allocate enough space for the segment tree.
        build(0, 0, n - 1);    // Build the tree starting from the root node.
    }

    // Recursively builds the segment tree.
    // node: current index in the segment tree.
    // start, end: current segment range in the original array that the node represents.
    void build(int node, int start, int end) {
        if (start == end) {
            // Base case: leaf node; directly assign the value from the original array.
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        // Recursively build the left child (segment: start to mid).
        build(2 * node + 1, start, mid);
        // Recursively build the right child (segment: mid+1 to end).
        build(2 * node + 2, mid + 1, end);

        // Internal node stores the maximum of its two children.
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Helper function to perform a range maximum query.
    // node: current index in the segment tree.
    // start, end: current segment range in the original array.
    // left, right: query range.
    int range(int node, int start, int end, int left, int right) {
        // If the current segment is completely outside the query range.
        if (end < left || start > right) {
            return INT_MIN; // Return a very small value.
        }

        // If the current segment is completely inside the query range.
        if (start >= left && end <= right) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;
        // Query both left and right children and return the maximum value.
        return max(range(2 * node + 1, start, mid, left, right),
                   range(2 * node + 2, mid + 1, end, left, right));
    }

    // Public function to return the maximum value in the range [left, right].
    int query(int left, int right) {
        return range(0, 0, n - 1, left, right);
    }

    // Helper function to update the value at a specific index in the array.
    // node: current index in the segment tree.
    // start, end: current segment range in the original array.
    // idx: index in the original array that is being updated.
    // val: new value to be assigned at index idx.
    void updating(int node, int start, int end, int idx, int val) {
        // If the index is outside the current segment, do nothing.
        if (idx < start || idx > end) {
            return;
        }

        // If we are at the leaf node corresponding to idx.
        if (start == end) {
            arr[idx] = val;    // Update the original array.
            tree[node] = val;  // Update the leaf node in the segment tree.
            return;
        }

        int mid = start + (end - start) / 2;
        // Recurse into the left child if idx is in the left segment.
        if (idx <= mid)
            updating(2 * node + 1, start, mid, idx, val);
        else
            // Otherwise, recurse into the right child.
            updating(2 * node + 2, mid + 1, end, idx, val);

        // After updating the child, update the current node's value to maintain the max property.
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Public function to update the value at a given index.
    void update(int index, int val) {
        updating(0, 0, n - 1, index, val);
    }
};

int main() {
    // Define a sample input array.
    vector<int> arr = {3, 6, 4, 25, 5, 13, 18};

    // Create the segment tree from the input array.
    SegmentTree *Tree = new SegmentTree(arr);

    // Update the element at index 2 to 10.
    Tree->update(2, 10);

    // Query the maximum element in the range [1, 5] and print the result.
    cout << Tree->query(1, 5) << endl;

    return 0;
}
