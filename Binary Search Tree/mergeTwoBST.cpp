// Problem Statement :- https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

// One simple way is to take a single vector and insert all elements of both bst in that. Then sort the vector.
// Use two vector. Do inorder traversal on one bst and store nodes in first vector, same for second bst and it's vector. Then just merge two sorted vector using two ptrs.

#include <bits/stdc++.h>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Utility function to insert into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Inorder traversal to store BST elements into vector
void inorder(Node* root, vector<int> &ans) {
    if (!root) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

// Function to merge two BSTs into sorted list
vector<int> merge(Node* root1, Node* root2) {
    vector<int> ans1, ans2;
    
    // Store inorder of both BSTs
    inorder(root1, ans1);
    inorder(root2, ans2);

    // Merge two sorted arrays
    vector<int> ans;
    int i = 0, j = 0;

    while (i < ans1.size() && j < ans2.size()) {
        if (ans1[i] < ans2[j]) {
            ans.push_back(ans1[i]);
            i++;
        } else {
            ans.push_back(ans2[j]);
            j++;
        }
    }

    // Push remaining elements
    while (i < ans1.size()) ans.push_back(ans1[i++]);
    while (j < ans2.size()) ans.push_back(ans2[j++]);

    return ans;
}

// Driver code
int main() {
    /*
        BST 1:        10
                     /  \
                    5    20

        BST 2:       15
                    /  \
                   12   18

        Expected merged output = 5 10 12 15 18 20
    */

    Node* root1 = nullptr;
    root1 = insert(root1, 10);
    insert(root1, 5);
    insert(root1, 20);

    Node* root2 = nullptr;
    root2 = insert(root2, 15);
    insert(root2, 12);
    insert(root2, 18);

    vector<int> merged = merge(root1, root2);

    cout << "Merged BSTs elements: ";
    for (int x : merged) cout << x << " ";
    cout << "\n";

    return 0;
}


// Do simultaneous inorder traversal of both BSTs using two stacks.
// At each step, compare the top elements of the stacks and pick the smaller one (like merging two sorted arrays).
// This avoids storing all elements in vectors first → uses only O(h1 + h2) space instead of O(n1 + n2).

#include <bits/stdc++.h>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Utility to insert node into BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Iterative merge using stacks
vector<int> merge(Node* root1, Node* root2) {
    stack<Node*> s1, s2;
    vector<int> result;

    while (root1 || root2 || !s1.empty() || !s2.empty()) {
        // Push all left children of root1
        while (root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        // Push all left children of root2
        while (root2) {
            s2.push(root2);
            root2 = root2->left;
        }

        // If one stack is empty
        if (s1.empty()) {
            root2 = s2.top(); s2.pop();
            result.push_back(root2->data);
            root2 = root2->right;
        }
        else if (s2.empty()) {
            root1 = s1.top(); s1.pop();
            result.push_back(root1->data);
            root1 = root1->right;
        }
        else {
            // Compare stack tops
            if (s1.top()->data < s2.top()->data) {
                root1 = s1.top(); s1.pop();
                result.push_back(root1->data);
                root1 = root1->right;
            }
            else {
                root2 = s2.top(); s2.pop();
                result.push_back(root2->data);
                root2 = root2->right;
            }
        }
    }

    return result;
}

// Driver code
int main() {
    /*
        BST1:        10
                    /  \
                   5    20

        BST2:       15
                   /  \
                  12   18

        Expected merged output = 5 10 12 15 18 20
    */
    Node* root1 = nullptr;
    root1 = insert(root1, 10);
    insert(root1, 5);
    insert(root1, 20);

    Node* root2 = nullptr;
    root2 = insert(root2, 15);
    insert(root2, 12);
    insert(root2, 18);

    vector<int> merged = merge(root1, root2);

    cout << "Merged BSTs elements: ";
    for (int x : merged) cout << x << " ";
    cout << "\n";

    return 0;
}
