// AVL trees are self-balancing BST, which means that the tree height is kept to a minimum so that a very fast runtime is guaranteed for searching, inserting and deleting nodes, with time complexity O(log n).
// The difference between heights of left and right subtrees for any node cannot be more than one.

// Check out these articles for more detail :- https://www.freecodecamp.org/news/avl-tree-insertion-rotation-and-balance-factor/
//                                             https://www.geeksforgeeks.org/introduction-to-avl-tree/

// We find the difference in tree height using the formula :- L (Left) - R (Right)
// Hence, if unbalanced, and the difference is positive, then Left subtree has unbalance (more height) otherwise Right subtree has unabalance.