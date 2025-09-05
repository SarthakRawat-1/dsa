// Problem Statement :- Do all 3 traversals in a single traversal.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void allTraversals(Node* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
    if (root == NULL) return;

    // Preorder (Root)
    preorder.push_back(root->val);

    // Left subtree
    allTraversals(root->left, preorder, inorder, postorder);

    // Inorder (Left → Root → Right)
    inorder.push_back(root->val);

    // Right subtree
    allTraversals(root->right, preorder, inorder, postorder);

    // Postorder (Left → Right → Root)
    postorder.push_back(root->val);
}

// Iterative approach
void allTraversals(Node* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
    if (!root) return;

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto [node, state] = st.top();
        st.pop();

        if (state == 1) {
            // Preorder
            preorder.push_back(node->val);
            st.push({node, 2});
            if (node->left) st.push({node->left, 1});
        }
        else if (state == 2) {
            // Inorder
            inorder.push_back(node->val);
            st.push({node, 3});
            if (node->right) st.push({node->right, 1});
        }
        else {
            // Postorder
            postorder.push_back(node->val);
        }
    }
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> preorder, inorder, postorder;
    allTraversals(root, preorder, inorder, postorder);

    cout << "Preorder: ";
    for (int x : preorder) cout << x << " ";
    cout << "\nInorder: ";
    for (int x : inorder) cout << x << " ";
    cout << "\nPostorder: ";
    for (int x : postorder) cout << x << " ";
    cout << endl;
}
