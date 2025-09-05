#include <iostream>
using namespace std;

// So for any node x in a BST:
// Inorder Predecessor of x = the node that comes just before x in inorder traversal (the next smaller element).
// Inorder Successor of x = the node that comes just after x in inorder traversal (the next larger element).

// Structure for a BST node
struct Node {
    int key;
    Node *left, *right;
    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

// Utility function to insert a new node in BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

/*
    Function to find Inorder Predecessor and Successor
    of a given key in BST.

    predecessor = just smaller node
    successor   = just larger node
*/
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (!root) return;

    // If key is found
    if (root->key == key) {
        // Case 1: Find max in left subtree for predecessor
        if (root->left) {
            Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        // Case 2: Find min in right subtree for successor
        if (root->right) {
            Node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }

    // If key is smaller than root, go left
    if (key < root->key) {
        suc = root; // possible successor
        findPreSuc(root->left, pre, suc, key);
    }
    // If key is larger than root, go right
    else {
        pre = root; // possible predecessor
        findPreSuc(root->right, pre, suc, key);
    }
}

// Utility function to print inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Driver code
int main() {
    /*
        Example BST:

                  20
                 /  \
               10    30
              /  \     \
             5   15     40
    */

    Node* root = nullptr;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 40);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << "\n";

    int key = 20;
    Node* pre = nullptr;
    Node* suc = nullptr;

    findPreSuc(root, pre, suc, key);

    if (pre != nullptr)
        cout << "Predecessor of " << key << " is " << pre->key << "\n";
    else
        cout << "No Predecessor for " << key << "\n";

    if (suc != nullptr)
        cout << "Successor of " << key << " is " << suc->key << "\n";
    else
        cout << "No Successor for " << key << "\n";

    return 0;
}
