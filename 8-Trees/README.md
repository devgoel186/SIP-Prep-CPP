# TREES

**Depth of x** - No. of edges in path from root to x

**Height of x** - No. of edges in path from x to a leaf

**Height of tree** - Height of root

**Binary tree** - A tree in which each node can have at least 2 children

**Strict/proper/full binary tree** - Every node other than the leaf nodes has 2 children

**Complete binary tree** - All levels except possibly last level are completely filled and all nodes are as left as possible. Max nodes at level i = 2^i

**Perfect binary tree** - All levels are completely filled
Number of nodes of tree with height h - 2^h - 1

**Balanced binary tree** - Difference between height of left and right subtree for every node is not more than k (mostly 1)

**Binary Search Tree** - A binary tree in which for each node, value of all nodes in the left subtree is lesser or equal and value of all the values of all the nodes in right subtree is greater.

**Height** - No. of edges in longest path from root to a leaf; height of an empty tree = -1

## IMPLEMENTATION

1. Using dynamically created nodes
2. Arrays -
   - Left child of a node at 2i + 1
   - Right child of a node at 2i + 2
