Algorithm:-

1. Start the program.
2. Initialize an empty doubly linked list to store song details.
3. Display the menu containing options to add, delete, search, display, play the next song, play the previous song, and exit.
4. Accept the user's choice.
5. Perform the selected operation:
   - **Add Song:** Enter the song name and artist name, create a new node, and insert it into the playlist.
   - **Delete Song:** Enter the song name, search for it, and delete the corresponding node if found.
   - **Search Song:** Search the playlist for the specified song and display its details if available.
   - **Display Playlist:** Traverse the linked list and display all songs.
   - **Play Next Song:** Move to the next song using the next pointer, if available.
   - **Play Previous Song:** Move to the previous song using the previous pointer, if available.
6. If the selected operation is invalid, display an appropriate error message.
7. Return to the menu and accept another choice.
8. If the user selects Exit, release the dynamically allocated memory used by the playlist.
9. Stop the program.


