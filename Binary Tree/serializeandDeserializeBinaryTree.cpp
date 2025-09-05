// Problem Statement :- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// DFS-based Codec (Preorder Serialization & Deserialization)
class CodecDFS {
public:
    // --- Serialize ---
    // Encodes a tree to a single string using preorder traversal.
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    // --- Deserialize ---
    // Decodes your encoded string to reconstruct the binary tree.
    TreeNode* deserialize(const string& data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        return deserializeHelper(ss);
    }

private:
    // Recursive helper for serialization (preorder: root-left-right)
    void serializeHelper(TreeNode* node, string& result) {
        if (!node) {
            result += "n ";  // marker for null node
            return;
        }
        result += to_string(node->val) + " ";  // record current node
        serializeHelper(node->left, result);   // recurse left
        serializeHelper(node->right, result);  // recurse right
    }

    // Recursive helper for deserialization
    TreeNode* deserializeHelper(stringstream& ss) {
        string val;
        ss >> val;  // read next token
        if (val == "n") {
            return nullptr;  // null marker
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(ss);   // build left subtree
        node->right = deserializeHelper(ss);  // build right subtree
        return node;
    }
};

// Utility: Inorder traversal to verify correctness
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Build a sample tree:
    //       1
    //      / \
    //     2   3
    //        / \
    //       4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    CodecDFS codec;

    cout << "Original tree (inorder): ";
    inorder(root);
    cout << endl;

    // Serialize
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    // Deserialize
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Tree after deserialization (inorder): ";
    inorder(deserialized);
    cout << endl;

    return 0;
}
