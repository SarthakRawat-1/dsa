// Problem Statement :- https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=problem-list-v2&envId=binary-search-tree

// We will start by taking the middle element of array (for even elements, there will be two mid, you can take any of them), this will be our root node of BST.
// All elements to the right of middle element will be greater than it, so they will make the right subtree and similarly left subtree will be created by elements to the left of middle element.
// Now that we have got two separate arrays (one for left, one for right) in a sense, we can start afresh for these. Again, finding center, then using that as root element, rest of the array is divided into separate parts again.
// We will do this for left subarrays first for all, till we can, then moving on to right subarrays.

// For GFG, I will be coding this in a separate function :-
// There can be multiple trees formed with this, based on what we are taking as middle element. Here, we are forming that tree, whose preorder traversal will be lexicographically smallest.
// For this, we will calculate mid normally how we calculate in Binary Search. 
// Preorder, you can find after creating the tree or you can even find it while creating the tree, as we will be creating BST such that nodes are created in a preorder manner.

// NOTE :- We can find preorder traversal with sorted array even without creating a tree, because of how tree is created. Read the above two points.

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Leetcode solution
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        // Base case: If start > end, there are no elements to process
        if (start > end) {
            return nullptr;
        }

        // Find the middle element to make it the root
        int mid = start + (end - start) / 2;

        // Create a new node with the middle element
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively construct the left subtree using the left subarray
        root->left = buildTree(nums, start, mid - 1);

        // Recursively construct the right subtree using the right subarray
        root->right = buildTree(nums, mid + 1, end);

        return root;
    }

    // GFG solution
//     void ArrayToBST(vector<int>& arr, int start, int end, vector<int>& ans) {
//         if (start > end) {
//             return;
//         }

//         int mid = start + (end - start) / 2;
//         ans.push_back(arr[mid]);

//         ArrayToBST(arr, start, mid - 1, ans);
//         ArrayToBST(arr, mid + 1, end, ans);
//     }

//    vector<int> sortedArrayToBST(vector<int>& nums) {
//        vector<int> ans;

//        ArrayToBST(nums, 0, nums.size() - 1, ans);

//        return ans;
//    }

};

// Helper function to create a tree node
TreeNode* createNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) {
    return new TreeNode(val, left, right);
}

// Helper function to print the tree in in-order traversal
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inOrderTraversal(root->left);   // Visit left subtree
    cout << root->val << " ";      // Visit root
    inOrderTraversal(root->right); // Visit right subtree
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9}; // Example input

    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);

    cout << "In-order Traversal of BST: ";
    inOrderTraversal(root); // Output should be the sorted array
    cout << endl;

    return 0;
}