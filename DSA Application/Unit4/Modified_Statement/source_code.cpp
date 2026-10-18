
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data, height;
    Node *left, *right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int height(Node *n) {
    return (n == NULL) ? 0 : n->height;
}

int getBalance(Node *n) {
    return (n == NULL) ? 0 :
           height(n->left) - height(n->right);
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

Node* insert(Node *root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else {
        cout << "Duplicate value ignored: " << value << endl;
        return root;
    }

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int b = getBalance(root);

    if (b > 1 && value < root->left->data) {
        cout << "LL Imbalance at " << root->data
             << ": Right Rotation\n";
        return rightRotate(root);
    }

    if (b < -1 && value > root->right->data) {
        cout << "RR Imbalance at " << root->data
             << ": Left Rotation\n";
        return leftRotate(root);
    }

    if (b > 1 && value > root->left->data) {
        cout << "LR Imbalance at " << root->data
             << ": Left then Right Rotation\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && value < root->right->data) {
        cout << "RL Imbalance at " << root->data
             << ": Right then Left Rotation\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void displayTree(Node *root, int space = 0) {
    if (root == NULL)
        return;

    space += 5;
    displayTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << root->data << endl;

    displayTree(root->left, space);
}

int main() {
    Node *root = NULL;
    int n, value;

    cout << "AVL Tree Imbalance Detection\n";
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number of nodes.\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << "Enter node value " << i << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\n\nFinal Balanced AVL Tree:\n";
    displayTree(root);

    cout << "\nProgram completed successfully.\n";

    return 0;
}

