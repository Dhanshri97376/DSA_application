
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* findNode(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    Node* result = findNode(root->left, key);

    if (result != NULL)
        return result;

    return findNode(root->right, key);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int key;

    cout << "Binary Tree Child Identification\n";
    cout << "Enter node value to check: ";
    cin >> key;

    Node* target = findNode(root, key);

    if (target == NULL) {
        cout << "Node not found in the tree.\n";
    } else {
        cout << "Node: " << target->data << endl;

        if (target->left != NULL)
            cout << "Left child: "
                 << target->left->data << endl;
        else
            cout << "No left child.\n";

        if (target->right != NULL)
            cout << "Right child: "
                 << target->right->data << endl;
        else
            cout << "No right child.\n";

        if (target->left != NULL &&
            target->right != NULL)
            cout << "Result: Both children.\n";
        else if (target->left != NULL)
            cout << "Result: Left child only.\n";
        else if (target->right != NULL)
            cout << "Result: Right child only.\n";
        else
            cout << "Result: No children (leaf node).\n";
    }

    return 0;
}
