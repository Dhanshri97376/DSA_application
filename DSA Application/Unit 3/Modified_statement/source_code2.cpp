#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

// Add a new song
void addSong(string name)
{
    Node* newNode = new Node;
    newNode->song = name;
    newNode->prev = tail;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    cout << "Song added successfully: " << name << endl;
}

// Remove a song
void removeSong(string name)
{
    Node* temp = head;

    while (temp != NULL && temp->song != name)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song not found in playlist." << endl;
        return;
    }

    if (temp == head)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    if (temp == tail)
        tail = temp->prev;
    else
        temp->next->prev = temp->prev;

    cout << "Song removed successfully: " << temp->song << endl;
    delete temp;
}

// Search for a song
void searchSong(string name)
{
    Node* temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->song == name)
        {
            cout << "Song found at position "
                 << position << ": " << temp->song << endl;
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Song not found in playlist." << endl;
}

// Display all songs
void displayPlaylist()
{
    if (head == NULL)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;
    int position = 1;

    cout << "\n----- Music Playlist -----" << endl;

    while (temp != NULL)
    {
        cout << position << ". " << temp->song << endl;
        temp = temp->next;
        position++;
    }
}

// Navigate forward
void playForward(string name)
{
    Node* temp = head;

    while (temp != NULL && temp->song != name)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Song not found in playlist." << endl;
        return;
    }

    if (temp->next != NULL)
        cout << "Next song: " << temp->next->song << endl;
    else
        cout << "This is the last song in the playlist." << endl;
}

// Navigate backward
void playBackward(string name)
{
    Node* temp = head;

    while (temp != NULL && temp->song != name)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Song not found in playlist." << endl;
        return;
    }

    if (temp->prev != NULL)
        cout << "Previous song: " << temp->prev->song << endl;
    else
        cout << "This is the first song in the playlist." << endl;
}

// Free dynamically allocated memory
void clearPlaylist()
{
    Node* temp = head;

    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
    tail = NULL;
}

int main()
{
    int choice;
    string name;

    do
    {
        cout << "\n===== MUSIC PLAYLIST MANAGEMENT =====" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Remove Song" << endl;
        cout << "3. Search Song" << endl;
        cout << "4. Display Playlist" << endl;
        cout << "5. Next Song" << endl;
        cout << "6. Previous Song" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(1000, '\n');

        switch (choice)
        {
            case 1:
                cout << "Enter song name: ";
                getline(cin, name);
                addSong(name);
                break;

            case 2:
                cout << "Enter song name to remove: ";
                getline(cin, name);
                removeSong(name);
                break;

            case 3:
                cout << "Enter song name to search: ";
                getline(cin, name);
                searchSong(name);
                break;

            case 4:
                displayPlaylist();
                break;

            case 5:
                cout << "Enter current song name: ";
                getline(cin, name);
                playForward(name);
                break;

            case 6:
                cout << "Enter current song name: ";
                getline(cin, name);
                playBackward(name);
                break;

            case 7:
                clearPlaylist();
                cout << "Playlist closed successfully." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
