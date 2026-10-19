
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

class SmartFileOrganizer {
private:
    Node* head;

public:
    SmartFileOrganizer() {
        head = NULL;
    }

    // Add a file or folder name
    void addEntry() {
        Node* newNode = new Node;

        cout << "Enter file or folder name: ";
        cin.ignore();
        getline(cin, newNode->name);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Entry added successfully!\n";
    }

    // Display all entries
    void displayEntries() {
        if (head == NULL) {
            cout << "Organizer is empty.\n";
            return;
        }

        Node* temp = head;
        int count = 1;

        cout << "\n--- File and Folder List ---\n";

        while (temp != NULL) {
            cout << count << ". " << temp->name << endl;
            temp = temp->next;
            count++;
        }
    }

    // Search for an entry
    void searchEntry() {
        if (head == NULL) {
            cout << "Organizer is empty.\n";
            return;
        }

        string searchName;
        cout << "Enter name to search: ";
        cin.ignore();
        getline(cin, searchName);

        Node* temp = head;

        while (temp != NULL) {
            if (temp->name == searchName) {
                cout << "Entry found: " << temp->name << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Entry not found.\n";
    }

    // Delete an entry
    void deleteEntry() {
        if (head == NULL) {
            cout << "Organizer is empty.\n";
            return;
        }

        string deleteName;
        cout << "Enter name to delete: ";
        cin.ignore();
        getline(cin, deleteName);

        Node* temp = head;
        Node* previous = NULL;

        while (temp != NULL &&
               temp->name != deleteName) {
            previous = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Entry not found.\n";
            return;
        }

        if (previous == NULL) {
            head = temp->next;
        } else {
            previous->next = temp->next;
        }

        delete temp;
        cout << "Entry deleted successfully!\n";
    }

    // Count entries
    void countEntries() {
        Node* temp = head;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Total entries: " << count << endl;
    }

    // Release allocated memory
    ~SmartFileOrganizer() {
        Node* temp = head;

        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    SmartFileOrganizer organizer;
    int choice;

    do {
        cout << "\n===== SMART FILE ORGANIZER =====\n";
        cout << "1. Add File/Folder Name\n";
        cout << "2. Display All Entries\n";
        cout << "3. Search Entry\n";
        cout << "4. Delete Entry\n";
        cout << "5. Count Total Entries\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                organizer.addEntry();
                break;

            case 2:
                organizer.displayEntries();
                break;

            case 3:
                organizer.searchEntry();
                break;

            case 4:
                organizer.deleteEntry();
                break;

            case 5:
                organizer.countEntries();
                break;

            case 6:
                cout << "Exiting Smart File Organizer.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

