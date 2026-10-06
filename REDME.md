# 🎵 Musical Playlist Manager

A C++ based Musical Playlist Manager implemented using a Doubly Linked List.

## 📌 Project Description

The Musical Playlist Manager is a console-based application developed using C++.

It uses a Doubly Linked List to store and manage songs. Each song contains its title, artist, album, and pointers to the previous and next songs.

The Doubly Linked List allows the user to move both forward and backward through the playlist.

## ✨ Features

- Add Song
- Display Playlist
- Play Current Song
- Play Next Song
- Play Previous Song
- Search Song
- Delete Song
- Reverse Playlist
- Clear Playlist
- Exit

## 🧠 Data Structure

### Doubly Linked List

Each song is represented as a node.

```text
NULL
  |
  v
+---------+     +---------+     +---------+
| Song 1  | <-> | Song 2  | <-> | Song 3  |
+---------+     +---------+     +---------+
                                      |
                                      v
                                     NULL