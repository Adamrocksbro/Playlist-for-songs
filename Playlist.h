#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iostream>
using namespace std;

class PlaylistNode {
public:
    PlaylistNode();
    PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nextNode);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode() const;

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif
