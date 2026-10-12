# Musical Playlist Manager in C++

## Project Description
The Musical Playlist Manager is a menu-driven C++ application that stores and manages songs using a **Doubly Linked List**. Each song stores its title, artist, and album. The links in both directions allow navigation to the next and previous songs.

## Features
- Add a song to the playlist
- Display all songs
- Play the current song
- Move to the next or previous song
- Search for a song by title
- Delete a song by title
- Reverse the playlist
- Clear the playlist
- Release allocated memory when the program ends

## Data Structure Used
**Doubly Linked List:** Each `Song` node contains `prev` and `next` pointers. This allows traversal in both directions and supports insertion/deletion by updating neighbouring links.

## Folder Structure
```text
Musical-Playlist-Manager/
├── README.md
├── Problem_Statement.pdf
├── Source_Code/
│   └── main.cpp
├── Output/
│   └── output.pdf
└── Documentation/
    └── Report.pdf
```

## How to Compile and Run
Using a C++ compiler such as `g++`:

```bash
g++ Source_Code/main.cpp -o playlist
./playlist
```

On Windows Command Prompt, run the executable with:
```bat
playlist.exe
```

If you use Dev-C++, open `Source_Code/main.cpp`, select **Execute > Compile & Run** (or press F11, depending on your version).

## Sample Menu
```text
========================================
       MUSICAL PLAYLIST MANAGER
========================================
1. Add Song
2. Display Playlist
3. Play Current Song
4. Play Next Song
5. Play Previous Song
6. Search Song
7. Delete Song
8. Reverse Playlist
9. Clear Playlist
0. Exit
========================================
Enter your choice:
```

## Notes
- Search and delete compare song titles exactly, including capitalization.
- The program is a console simulation; it displays the selected song but does not play audio.
