#include "Playlist.h"

PlaylistNode::PlaylistNode()
    : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

PlaylistNode::PlaylistNode(string id, string name, string artist, int length)
    : uniqueID(id), songName(name), artistName(artist), songLength(length), nextNodePtr(nullptr) {}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    nodePtr->nextNodePtr = this->nextNodePtr;
    this->nextNodePtr = nodePtr;
}

void PlaylistNode::SetNext(PlaylistNode* nextNode) {
    nextNodePtr = nextNode;
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}
