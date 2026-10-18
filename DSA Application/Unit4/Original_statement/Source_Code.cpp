
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
    if (n == NULL)
        return 0;
    return n->height;
}

int balanceFactor(Node *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
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
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int b = balanceFactor(root);

    if (b > 1 && value < root->left->data) {
        cout << "LL Imbalance: Right Rotation\n";
        return rightRotate(root);
    }

    if (b < -1 && value > root->right->data) {
        cout << "RR Imbalance: Left Rotation\n";
        return leftRotate(root);
    }

    if (b > 1 && value > root->left->data) {
        cout << "LR Imbalance: Left then Right Rotation\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && value < root->right->data) {
        cout << "RL Imbalance: Right then Left Rotation\n";
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

int main() {
    Node *root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter node value: ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nBalanced AVL Tree (Inorder): ";
    inorder(root);

    cout << "\n";
    return 0;
}

