Algorithm 

1. Start the program and initialize an empty AVL tree with node data, left and right pointers, and height.

2. Input the number of nodes to be inserted into the AVL tree.

3. Read the node value from the user and insert it into the tree according to the Binary Search Tree (BST) property.

4. Update the height of each node after insertion by calculating the maximum height of its left and right subtrees and adding one.

5. Calculate the balance factor of each node by subtracting the height of the right subtree from the height of the left subtree.

6. Check for imbalance by determining whether the balance factor of any node is greater than 1 or less than -1.

7. Identify the type of imbalance based on the insertion position:

- LL (Left-Left): Perform a right rotation.
- RR (Right-Right): Perform a left rotation.
- LR (Left-Right): Perform a left rotation followed by a right rotation.
- RL (Right-Left): Perform a right rotation followed by a left rotation.

8. Perform the required rotation to restore balance and update the heights of the affected nodes.

9. Repeat the insertion and balancing process for all remaining node values until every value has been inserted and the AVL tree is balanced.

10. Display the detected imbalance and rotation performed, followed by the inorder traversal of the balanced AVL tree.

11. Stop the program.
