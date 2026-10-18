
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void searchNode(Node* root, int key, int parent, int depth,
                bool hasParent, bool &found)
{
    if (root == NULL)
        return;

    if (root->data == key)
    {
        found = true;

        cout << "\nNode found: " << root->data << endl;

        if (hasParent)
            cout << "Parent node: " << parent << endl;
        else
            cout << "Parent node: None (Root node)" << endl;

        cout << "Depth: " << depth << endl;

        if (root->left != NULL && root->right != NULL)
            cout << "Child status: Both left and right children exist"
                 << endl;
        else if (root->left != NULL)
            cout << "Child status: Only left child exists" << endl;
        else if (root->right != NULL)
            cout << "Child status: Only right child exists" << endl;
        else
            cout << "Child status: No children (Leaf node)" << endl;

        if (root->left != NULL)
            cout << "Left child: " << root->left->data << endl;
        else
            cout << "Left child: None" << endl;

        if (root->right != NULL)
            cout << "Right child: " << root->right->data << endl;
        else
            cout << "Right child: None" << endl;

        return;
    }

    searchNode(root->left, key, root->data, depth + 1,
               true, found);

    searchNode(root->right, key, root->data, depth + 1,
               true, found);
}

int main()
{
    Node* root = NULL;
    int n, value, key, choice;

    cout << "BINARY TREE CHILD IDENTIFICATION\n";
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "The binary tree is empty." << endl;
        return 0;
    }

    cout << "Enter root node value: ";
    cin >> value;
    root = createNode(value);

    Node* nodes[100];
    int count = 1;
    nodes[0] = root;

    for (int i = 1; i < n; i++)
    {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        nodes[count] = createNode(value);

        int parentIndex;
        char side;

        cout << "Enter parent node value: ";
        cin >> parentIndex;

        cout << "Enter side (L for left, R for right): ";
        cin >> side;

        Node* parentNode = NULL;

        for (int j = 0; j < count; j++)
        {
            if (nodes[j]->data == parentIndex)
            {
                parentNode = nodes[j];
                break;
            }
        }

        if (parentNode == NULL)
        {
            cout << "Parent not found. Node not attached.\n";
            delete nodes[count];
            continue;
        }

        if (side == 'L' || side == 'l')
        {
            if (parentNode->left == NULL)
                parentNode->left = nodes[count];
            else
            {
                cout << "Left child already exists.\n";
                delete nodes[count];
                continue;
            }
        }
        else if (side == 'R' || side == 'r')
        {
            if (parentNode->right == NULL)
                parentNode->right = nodes[count];
            else
            {
                cout << "Right child already exists.\n";
                delete nodes[count];
                continue;
            }
        }
        else
        {
            cout << "Invalid side.\n";
            delete nodes[count];
            continue;
        }

        count++;
    }

    do
    {
        cout << "\nEnter node to search: ";
        cin >> key;

        bool found = false;

        searchNode(root, key, 0, 0, false, found);

        if (!found)
            cout << "Node " << key << " not found in the tree."
                 << endl;

        cout << "\nSearch another node? (1 = Yes, 0 = No): ";
        cin >> choice;

    } while (choice == 1);

    cout << "\nProgram ended successfully.\n";

    return 0;
}
