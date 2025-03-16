#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
    vector<int> tree; // Segment tree array holding the sum of segments.
    vector<int> arr;  // Original input array.
    int n;            // Size of the input array.

public:
    // Constructor: initializes the segment tree from the input array.
    SegmentTree(vector<int> input) {
        n = input.size();
        arr = input;
        tree.resize(4 * n); // Allocate enough space for the segment tree.
        build(0, 0, n - 1);   // Build the tree starting from the root node.
    }

    // Recursively builds the segment tree.
    // node: current index in the segment tree.
    // start, end: segment range in the original array represented by this node.
    void build(int node, int start, int end) {
        // If we are at a leaf node, assign the value from the original array.
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        // Calculate the middle index of the current segment.
        int mid = start + (end - start) / 2;

        // Recursively build the left child (segment: start to mid).
        build(2 * node + 1, start, mid);
        // Recursively build the right child (segment: mid+1 to end).
        build(2 * node + 2, mid + 1, end);

        // Internal node holds the sum of its two children.
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Recursively queries the sum in the range [left, right].
    // node: current index in the segment tree.
    // start, end: current segment range in the original array.
    // left, right: query range.
    int range(int node, int start, int end, int left, int right) {
        // If the current segment is completely outside the query range.
        if (end < left || start > right) {
            return 0;
        }

        // If the current segment is completely inside the query range.
        if (start >= left && end <= right) {
            return tree[node];
        }

        // Calculate the middle index.
        int mid = start + (end - start) / 2;

        // Query the left and right children and combine the results.
        return range(2 * node + 1, start, mid, left, right) +
               range(2 * node + 2, mid + 1, end, left, right);
    }

    // Public function to query the sum in the range [left, right].
    int query(int left, int right) {
        return range(0, 0, n - 1, left, right);
    }

    // Recursively updates the segment tree when an element in the original array is changed.
    // node: current index in the segment tree.
    // start, end: segment range in the original array.
    // idx: index in the original array that is being updated.
    // val: new value for the element at index idx.
    void updating(int node, int start, int end, int idx, int val) {
        // If the index is not within the current segment, do nothing.
        if (idx > end || idx < start) {
            return;
        }

        // If we are at the leaf node corresponding to idx.
        if (start == end) {
            tree[node] = val;   // Update the segment tree leaf.
            arr[idx] = val;     // Update the original array.
            return;
        }

        // Compute the difference between the new value and the old value.
        int diff = val - arr[idx];

        // Update the current node's sum using the difference.
        tree[node] += diff;

        int mid = start + (end - start) / 2;

        // Recursively update the left and right children.
        updating(2 * node + 1, start, mid, idx, val);
        updating(2 * node + 2, mid + 1, end, idx, val);

        // TODO completed: No additional update is needed here because arr[idx] is updated at the leaf.
    }

    // Public function to update the element at index with a new value.
    void update(int index, int val) {
        updating(0, 0, n - 1, index, val);
    }
};

int main() {
    // Define a sample input array.
    vector<int> arr = {3, 6, 4, 25, 5, 13, 18};

    // Create a SegmentTree object using the input array.
    SegmentTree *Tree = new SegmentTree(arr);

    // Update the element at index 2 (value 4) to 10.
    Tree->update(2, 10);

    // Query the sum in the range [1, 5] and print the result.
    cout << Tree->query(1, 5) << endl;

    return 0;
}
