// Tree is a type of Data structure that represent a hierarchial relationship between data elements called nodes.

// Imagine a family tree where :- Each person (Node) :- Represents a node in the tree.
// Parent-Child Relationships :- Define how people are related. A parent node will have links to its child nodes.
// The Ancestor (Root) :- The oldest ancestor at the top is the root node of the tree.
// Descendants (Children) :- These are the child nodes connected to their parent.
// Leaf Nodes :- People who have no children are leaf nodes (at the ends of the tree).
//                John (Root)
//                 /        \
//         Sarah (L)        Michael (R)
//         /     \            /       \
// Alice (LL)    Bob (LR)  Kevin (RL)  Nancy (RR)

// A Binary Tree is a special type of tree data structure where each node has at most two children, referred to as the left child and right child.
//                1 (Root)
//               /         \
//         2 (L)             3 (R)
//        /     \           /     \
//   4 (LL)    5 (LR)   6 (RL)    7 (RR)


// Terminologies of Tree :-

// 1. Root :- The root is the topmost node of a tree. It is the only node in the tree that has no parent. In a binary tree, there is only one root node.
// 2. Node :- A node is a fundamental part of a tree data structure that contains data and may link to other nodes. Each node can have zero or more child nodes.
// 3. Parent :- A parent is a node that has one or more child nodes. In a tree, every node (except the root) has exactly one parent.
// 4. Child :- A child is a node that is a direct descendant of another node, called its parent. A node can have multiple children, but each child has only one parent.
// 5. Leaf :- A leaf is a node that does not have any children. In other words, it is the end point of a branch in the tree. Leaves are the terminal nodes of the tree.
// 6. Ancestor :- An ancestor of a node is any predecessor node on the path from the root to that node. This includes the node's parent, grandparent, and so on up to the root.
// 7. Descendant :- A descendant of a node is any node that can be reached by traversing downwards from that node. This includes children, grandchildren, and so on.
// 8. Level :- The level of a node indicates its depth in the tree, starting from the root at level 0. The level of a node increases by one for each step down the tree.
// 9. Siblings :- Siblings are nodes that share the same parent. They are on the same level and are direct children of the same node.
// 10. Height :- The height of a tree is the length of the longest path from the root to a leaf node. It is the number of edges in the longest path from the root to a leaf. For a tree with only one node (the root), the height is 0.
// 11. Degree :- The degree of a node is the number of children it has. A leaf node has a degree of 0, while the root may have a degree of 1 or more, depending on how many children it has.
// 12. Edges :- An edge is a connection between two nodes in a tree. Each edge connects a parent node to a child node. The number of edges in a tree is always one less than the number of nodes.



