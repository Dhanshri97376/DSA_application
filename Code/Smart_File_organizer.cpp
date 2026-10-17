
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

        // Initialize all child pointers
        for (int i = 0; i < 20; i++) {
            child[i] = NULL;
        }
    }
};

class Organizer {
private:
    Node* root;

    // Find a folder by its name
    Node* findFolder(Node* p, const string& name) {
        if (p == NULL)
            return NULL;

        if (!p->isFile && p->name == name)
            return p;

        for (int i = 0; i < p->count; i++) {
            Node* result = findFolder(p->child[i], name);

            if (result != NULL)
                return result;
        }

        return NULL;
    }

    // Display the folder tree
    void showTree(Node* p, int level) {
        if (p == NULL)
            return;

        for (int i = 0; i < level; i++)
            cout << "    ";

        if (p->isFile)
            cout << "[File] ";
        else
            cout << "[Folder] ";

        cout << p->name << endl;

        for (int i = 0; i < p->count; i++) {
            showTree(p->child[i], level + 1);
        }
    }

    // Free dynamically allocated memory
    void deleteTree(Node* p) {
        if (p == NULL)
            return;

        for (int i = 0; i < p->count; i++) {
            deleteTree(p->child[i]);
        }

        delete p;
    }

public:
    Organizer() {
        string name;

        cout << "Enter root folder name: ";
        getline(cin, name);

        if (name.empty())
            name = "MyFiles";

        root = new Node(name, false);

        cout << "Root folder created successfully: "
             << name << endl;
    }

    ~Organizer() {
        deleteTree(root);
    }

    void createFolder() {
        string parentName, folderName;

        cout << "Enter parent folder name: ";
        getline(cin, parentName);

        Node* parent = findFolder(root, parentName);

        if (parent == NULL) {
            cout << "Folder not found! "
                 << "Enter an existing folder name.\n";
            return;
        }

        if (parent->count >= 20) {
            cout << "This folder cannot contain more items.\n";
            return;
        }

        cout << "Enter new folder name: ";
        getline(cin, folderName);

        if (folderName.empty()) {
            cout << "Folder name cannot be empty!\n";
            return;
        }

        parent->child[parent->count] =
            new Node(folderName, false);

        parent->count++;

        cout << "Folder created successfully!\n";
    }

    void addFile() {
        string folderName, fileName;

        cout << "Enter folder name: ";
        getline(cin, folderName);

        Node* folder = findFolder(root, folderName);

        if (folder == NULL) {
            cout << "Folder not found! "
                 << "Enter an existing folder name.\n";
            return;
        }

        if (folder->count >= 20) {
            cout << "This folder cannot contain more items.\n";
            return;
        }

        cout << "Enter file name (example: notes.txt): ";
        getline(cin, fileName);

        if (fileName.empty()) {
            cout << "File name cannot be empty!\n";
            return;
        }

        folder->child[folder->count] =
            new Node(fileName, true);

        folder->count++;

        cout << "File added successfully!\n";
    }

    void display() {
        cout << "\n========== FILE TREE ==========\n";
        showTree(root, 0);
        cout << "===============================\n";
    }
};

int main() {
    Organizer obj;
    int choice;

    while (true) {
        cout << "\n===== SMART FILE ORGANIZER =====\n";
        cout << "1. Create Folder\n";
        cout << "2. Add File\n";
        cout << "3. Display Tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                obj.createFolder();
                break;

            case 2:
                obj.addFile();
                break;

            case 3:
                obj.display();
                break;

            case 4:
                cout << "Exiting Smart File Organizer.\n";
                return 0;

            default:
                cout << "Invalid choice! Choose 1 to 4.\n";
        }
    }

    return 0;
}

