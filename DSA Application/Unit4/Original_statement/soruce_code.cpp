
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    bool isFile;
    Node* child[20];
    int count;

    Node(string n, bool f) {
        name = n;
        isFile = f;
        count = 0;
    }
};

class Organizer {
    Node* root;

    Node* find(Node* p, string name) {
        if (p == NULL) return NULL;

        if (!p->isFile && p->name == name)
            return p;

        for (int i = 0; i < p->count; i++) {
            Node* r = find(p->child[i], name);
            if (r != NULL) return r;
        }
        return NULL;
    }

    void show(Node* p, int level) {
        for (int i = 0; i < level; i++)
            cout << "   ";

        cout << (p->isFile ? "[File] " : "[Folder] ")
             << p->name << endl;

        for (int i = 0; i < p->count; i++)
            show(p->child[i], level + 1);
    }

public:
    Organizer() {
        string name;
        cout << "Enter root folder name: ";
        getline(cin, name);

        if (name == "") name = "MyFiles";

        root = new Node(name, false);
        cout << "Root folder created!\n";
    }

    void createFolder() {
        string parent, name;

        cout << "Enter parent folder name: ";
        getline(cin, parent);

        Node* p = find(root, parent);

        if (p == NULL) {
            cout << "Folder not found! Try the root name first.\n";
            return;
        }

        if (p->count == 20) {
            cout << "Folder is full!\n";
            return;
        }

        cout << "Enter new folder name: ";
        getline(cin, name);

        if (name == "") {
            cout << "Name cannot be empty!\n";
            return;
        }

        p->child[p->count] = new Node(name, false);
        p->count++;

        cout << "Folder created successfully!\n";
    }

    void addFile() {
        string folder, name;

        cout << "Enter folder name: ";
        getline(cin, folder);

        Node* p = find(root, folder);

        if (p == NULL) {
            cout << "Folder not found!\n";
            return;
        }

        if (p->count == 20) {
            cout << "Folder is full!\n";
            return;
        }

        cout << "Enter file name: ";
        getline(cin, name);

        if (name == "") {
            cout << "Name cannot be empty!\n";
            return;
        }

        p->child[p->count] = new Node(name, true);
        p->count++;

        cout << "File added successfully!\n";
    }

    void display() {
        cout << "\n--- FILE TREE ---\n";
        show(root, 0);
    }
};

int main() {
    Organizer obj;
    int choice;

    while (true) {
        cout << "\n1. Create Folder\n";
        cout << "2. Add File\n";
        cout << "3. Display Tree\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a number.\n";
            continue;
        }

        cin.ignore(10000, '\n');

        if (choice == 1)
            obj.createFolder();
        else if (choice == 2)
            obj.addFile();
        else if (choice == 3)
            obj.display();
        else if (choice == 4)
            break;
        else
            cout << "Invalid choice!\n";
    }

    return 0;
}

