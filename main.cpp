#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node of a Doubly Linked List
struct Song
{
    string title, artist, album;
    Song* prev;
    Song* next;

    Song(string t, string a, string al)
    {
        title = t;
        artist = a;
        album = al;
        prev = NULL;
        next = NULL;
    }
};

class Playlist
{
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist()
    {
        head = tail = current = NULL;
    }

    void addSong()
    {
        string title, artist, album;

        cin.ignore(numeric_limits<streamsize>::max(), '\\n');
        cout << "\\nEnter song title: ";
        getline(cin, title);
        cout << "Enter artist name: ";
        getline(cin, artist);
        cout << "Enter album name: ";
        getline(cin, album);

        Song* newSong = new Song(title, artist, album);

        if (head == NULL)
        {
            head = tail = current = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "\\nSong added successfully!\\n";
    }

    void displayPlaylist()
    {
        if (head == NULL)
        {
            cout << "\\nPlaylist is empty.\\n";
            return;
        }

        Song* temp = head;
        int count = 1;
        cout << "\\n========== PLAYLIST ==========\\n";
        while (temp != NULL)
        {
            cout << count << ". " << temp->title << " - "
                 << temp->artist << " [" << temp->album << "]\\n";
            temp = temp->next;
            count++;
        }
        cout << "==============================\\n";
    }

    void playCurrent()
    {
        if (current == NULL)
        {
            cout << "\\nPlaylist is empty.\\n";
            return;
        }
        cout << "\\nNow Playing: " << current->title << " - "
             << current->artist << "\\nAlbum: " << current->album << endl;
    }

    void nextSong()
    {
        if (current == NULL)
            cout << "\\nPlaylist is empty.\\n";
        else if (current->next == NULL)
            cout << "\\nYou are already at the last song.\\n";
        else
        {
            current = current->next;
            playCurrent();
        }
    }

    void previousSong()
    {
        if (current == NULL)
            cout << "\\nPlaylist is empty.\\n";
        else if (current->prev == NULL)
            cout << "\\nYou are already at the first song.\\n";
        else
        {
            current = current->prev;
            playCurrent();
        }
    }

    void searchSong()
    {
        if (head == NULL)
        {
            cout << "\\nPlaylist is empty.\\n";
            return;
        }

        string title;
        cin.ignore(numeric_limits<streamsize>::max(), '\\n');
        cout << "\\nEnter song title to search: ";
        getline(cin, title);

        Song* temp = head;
        while (temp != NULL)
        {
            if (temp->title == title)
            {
                cout << "\\nSong Found!\\nTitle  : " << temp->title
                     << "\\nArtist : " << temp->artist
                     << "\\nAlbum  : " << temp->album << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "\\nSong not found.\\n";
    }

    void deleteSong()
    {
        if (head == NULL)
        {
            cout << "\\nPlaylist is empty.\\n";
            return;
        }

        string title;
        cin.ignore(numeric_limits<streamsize>::max(), '\\n');
        cout << "\\nEnter song title to delete: ";
        getline(cin, title);

        Song* temp = head;
        while (temp != NULL)
        {
            if (temp->title == title)
            {
                if (temp == head)
                    head = temp->next;
                if (temp == tail)
                    tail = temp->prev;
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;

                if (current == temp)
                {
                    if (temp->next != NULL)
                        current = temp->next;
                    else
                        current = temp->prev;
                }

                delete temp;
                cout << "\\nSong deleted successfully!\\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\\nSong not found.\\n";
    }

    void reversePlaylist()
    {
        if (head == NULL)
        {
            cout << "\\nPlaylist is empty.\\n";
            return;
        }

        Song* node = head;
        while (node != NULL)
        {
            Song* temp = node->prev;
            node->prev = node->next;
            node->next = temp;
            node = node->prev;
        }

        Song* temp = head;
        head = tail;
        tail = temp;
        cout << "\\nPlaylist reversed successfully!\\n";
    }

    void clearPlaylist()
    {
        Song* temp = head;
        while (temp != NULL)
        {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = current = NULL;
        cout << "\\nPlaylist cleared successfully!\\n";
    }

    ~Playlist()
    {
        Song* temp = head;
        while (temp != NULL)
        {
            Song* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    Playlist playlist;
    int choice;

    do
    {
        cout << "\\n\\n========================================\\n";
        cout << "       MUSICAL PLAYLIST MANAGER\\n";
        cout << "========================================\\n";
        cout << "1. Add Song\\n";
        cout << "2. Display Playlist\\n";
        cout << "3. Play Current Song\\n";
        cout << "4. Play Next Song\\n";
        cout << "5. Play Previous Song\\n";
        cout << "6. Search Song\\n";
        cout << "7. Delete Song\\n";
        cout << "8. Reverse Playlist\\n";
        cout << "9. Clear Playlist\\n";
        cout << "0. Exit\\n";
        cout << "========================================\\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: playlist.addSong(); break;
            case 2: playlist.displayPlaylist(); break;
            case 3: playlist.playCurrent(); break;
            case 4: playlist.nextSong(); break;
            case 5: playlist.previousSong(); break;
            case 6: playlist.searchSong(); break;
            case 7: playlist.deleteSong(); break;
            case 8: playlist.reversePlaylist(); break;
            case 9: playlist.clearPlaylist(); break;
            case 0: cout << "\\nThank you for using Musical Playlist Manager!\\n"; break;
            default: cout << "\\nInvalid choice! Please try again.\\n";
        }
    } while (choice != 0);

    return 0;
}
