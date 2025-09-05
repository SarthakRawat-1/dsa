// Problem Statment :- https://leetcode.com/problems/recover-binary-search-tree/description/

// One method is to find inorder traversal, ideally it should be asc but it won't be becz swap. So, we will store inorder traversal in vector, then sort, and then using this, refill values in BST.
// As notice, it time complexity will be n log n becz sorting. But we need not sort the entire vector.
// In the vect, simply check every ele with it's adjacent, when we find such pair which is not in ascending order, we know this might be one of the swapped one, this is a mistake pair. You will find two of such mistakes pair.
// Then we have to simply swap first mistake's pair first element with second mistake's pair second element.
// However, it can happen that u only get one mistake pair. If so, then swap both elements of pair. You won't get more than two mistake pairs.

// There exists an even better method to solve without extra space. Use Morris Traversal using the prev and curr ptrs.
// We will keep updating them accordingly when we visit nodes and when curr < prev, it means here asc order is broken which should not be possible in inorder traversal. So this is one of the mistake pair. The continue and find another mistake pair if it exists and then swapping is same as before.

// Btw for swapping in both methodsm u can simply do with two ptrs initialized with -1, say first and second. When u find first msitake pair update first with it's first element and second with it;s second element. Next time when u get another mistake pair, u will know that this is second one as both first and second are not -1, so in this just update second with second element of second mistake pair.
// Then simply swap first and second. In the morris traversal method, the diff is first and second initially store null and then store address instead of node value.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recoverTree(TreeNode* root) {
    TreeNode* curr = NULL;     // to find inorder predecessor
    TreeNode* present = NULL;  // current node in inorder traversal
    TreeNode* last = NULL;     // previous node in inorder traversal
    TreeNode* first = NULL;    // first node to swap
    TreeNode* second = NULL;   // second node to swap

    while (root) {
        // Case 1: no left child → visit this node directly
        if (!root->left) {
            last = present;
            present = root;

            // check if inorder property breaks (inversion)
            if (last && last->val > present->val) {
                if (!first) {
                    first = last;     // first wrong node
                    second = present; // second wrong node
                } else {
                    second = present; // update second if another inversion found
                }
            }

            root = root->right; // move right
        } else { 
            // Case 2: left child exists → find inorder predecessor
            curr = root->left;
            while (curr->right && curr->right != root) {
                curr = curr->right;
            } 

            // If left subtree not yet threaded
            if (!curr->right) {
                curr->right = root;   // create thread to root
                root = root->left;    // move left
            } else { 
                // Left subtree already visited → break the thread
                curr->right = NULL;

                last = present;
                present = root;

                // check for inversion
                if (last && last->val > present->val) {
                    if (!first) {
                        first = last;
                        second = present;
                    } else {
                        second = present;
                    }
                }

                root = root->right; // move right
            }
        }
    }

    // swap values of the two incorrect nodes
    int num = first->val;
    first->val = second->val;
    second->val = num;
}


int main( ){

}