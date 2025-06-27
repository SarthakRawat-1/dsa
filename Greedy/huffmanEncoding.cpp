// Problem Statement :- https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

// Let's say we want to encode a message which has 6 distinct alphabets/letters. We will identify each of these with only 3 bits (0 or 1s).
// For eg :- Let's say we encoded a as 000, b as 001, c as 010 etc.
// Now, the one who we send these encoding, we also have to send this table to that decoder so it knows which bit sequence depicts what.

// We can make it more efficient. We count frequencies of all elements.
// The highest frequency letter should be represented by the reduced number of bits like, we can represent them by just 0.
// But this is problematic, let's say we have three letters one encoded as 0 and other as 010 and third as 00. We receive a message :- 0010 Now how do we know which represents what.

// Here's how Huffman solves this.
// We take the lowest two frequency elements. Combine/Add them. Add it again to the stack. Now again take two lowest elements (consider the combined result too). Repeat the cycle.
// Btw visualize it as tree, with the lowest coming left and second lowest coming to right and parent being the combined.
// When only one element remains (this is the root node), we can simmply name the nodes. Start from the top fo the tree created. When we go to left we give 0 and on right we give 1 on the edges.
// Now just go to nodes which represent the elements. The numbers u came across by while travelling the edges is the number encoding for that letter.
// This will give a variable length ensuring the most frequent elements get lower number of bits.

// Eg :- [ a:5, b:9, c:12, d:13, e:16, f:45 ]
//      N5(100)
//   0 /       \ 1
//  f(45)     N4(55)
//         0 /     \ 1
//       N2(25)   N3(30)
//    0 /   1 \ 0 /    \ 1
//   c(12)  d(13)N1(14) e(16)
//               0 /    \ 1
//              a(5)   b(9)
// a → 1100
// b → 1101
// c → 100
// d → 101
// e → 111
// f → 0

// Now let's say we got an encoded message :- 1001000101
// We go to the tree start from root node, as first digit in encoded messsage is 1, we go right, the node we arrived at is not a letter but a combiend node, so we continue.
// We got 0, so left and again 0 so left, and finally we got to c which was a letter node. So this is c. Continue this further.

// Every node in that tree will require left and right pointer, with frequency and character. For combined nodes use an arbitrary character like $.

#include <bits/stdc++.h>
using namespace std;

// Define a class for tree nodes in the Huffman tree
class Node {
    public:
    int freq;       // Frequency of the character
    char c;         // Character (for leaf nodes), use '$' for internal nodes
    Node *left, *right; // Pointers to left and right children

    // Constructor to initialize a node
    Node(int frequency, char name) {
        freq = frequency;
        c = name;
        left = NULL;
        right = NULL;
    }
};

// Comparator class to order the priority queue (min-heap based on frequency)
class comp {
    public:
    // Overload the function call operator to create a min-heap
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Preorder traversal to generate Huffman codes
// `temp` accumulates the path (bit string), `ans` stores final codes
void preorder(Node* root, string &temp, vector<string> &ans) {
    if (!root) return;

    // If it's a leaf node (no children), save the current path as its code
    if (!root->left && !root->right) {
        ans.push_back(temp);
        return;
    }

    // Traverse left with '0' appended
    temp.push_back('0');
    preorder(root->left, temp, ans);
    temp.pop_back();  // Backtrack

    // Traverse right with '1' appended
    temp.push_back('1');
    preorder(root->right, temp, ans);
    temp.pop_back();  // Backtrack
}

// Main function to generate Huffman codes
vector<string> huffmanCodes(string S, vector<int> f, int N) {
    // Min-heap (priority queue) to store tree nodes ordered by frequency
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Step 1: Push all characters with their frequencies into the heap
    for (int i = 0; i < N; i++) {
        pq.push(new Node(f[i], S[i]));
    }

    // Step 2: Build Huffman Tree
    while (pq.size() > 1) {
        // Take two nodes with the smallest frequencies
        Node* first = pq.top();
        pq.pop();
        Node* second = pq.top();
        pq.pop();

        // Create a new internal node with combined frequency
        Node* root = new Node(first->freq + second->freq, '$');
        root->left = first;
        root->right = second;

        // Push the new combined node back into the heap
        pq.push(root);
    }

    // Final node left in the queue is the root of the Huffman tree
    Node* root = pq.top();
    pq.pop();

    vector<string> ans;  // To store the Huffman codes
    string temp;         // Temporary string to build each code

    // Step 3: Generate codes via preorder traversal
    preorder(root, temp, ans);

    return ans;
}

int main() {
    // Sample input characters and their frequencies
    string S = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    int N = S.length();

    // Call the Huffman encoding function
    vector<string> codes = huffmanCodes(S, freq, N);

    // Output the result
    cout << "Huffman Codes for characters:\n";
    for (int i = 0; i < N; ++i) {
        cout << S[i] << " → " << codes[i] << "\n";
    }

    return 0;
}

