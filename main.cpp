#include "Playlist.h"
#include <iostream>
#include <string>
using namespace std;

void ShowMenu(const string& title);
void ShowPlaylist(const string& title, PlaylistNode* head);
void RemoveSong(PlaylistNode*& head, PlaylistNode*& tail);
void ChangePosition(PlaylistNode*& head, PlaylistNode*& tail);
void OutputSongsByArtist(PlaylistNode* head);
void OutputTotalTime(PlaylistNode* head);

int main() {
    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr;
    string title;
    char choice;

    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    cout << endl;

    do {
        ShowMenu(title);
        cin >> choice;
        cin.ignore();

        if (choice == 'a') {
            string id, name, artist;
            int length;

            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, id);
            cout << "Enter song's name:" << endl;
            getline(cin, name);
            cout << "Enter artist's name:" << endl;
            getline(cin, artist);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> length;
            cin.ignore();
            cout << endl;

            PlaylistNode* newNode = new PlaylistNode(id, name, artist, length);
            if (!head) {
                head = tail = newNode;
            } else {
                tail->SetNext(newNode);
                tail = newNode;
            }
        } else if (choice == 'o') {
            ShowPlaylist(title, head);
        } else if (choice == 'd') {
            RemoveSong(head, tail);
        } else if (choice == 'c') {
            ChangePosition(head, tail);
        } else if (choice == 's') {
            OutputSongsByArtist(head);
        } else if (choice == 't') {
            OutputTotalTime(head);
        }
    } while (choice != 'q');

    return 0;
}

void ShowMenu(const string& title) {
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
}

void ShowPlaylist(const string& title, PlaylistNode* head) {
    cout << title << " - OUTPUT FULL PLAYLIST" << endl;
    if (!head) {
        cout << "Playlist is empty" << endl;
        cout << endl;
        return;
    }
    int position = 1;
    for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
        cout << position++ << "." << endl;
        curr->PrintPlaylistNode();
        cout << endl;
    }
}

void RemoveSong(PlaylistNode*& head, PlaylistNode*& tail) {
    if (!head) {
        cout << "REMOVE SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        string id;
        getline(cin, id);
        cout << "Playlist is empty." << endl;
        cout << endl;
        return;
    }

    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    string id;
    getline(cin, id);

    PlaylistNode* prev = nullptr;
    PlaylistNode* curr = head;

    while (curr && curr->GetID() != id) {
        prev = curr;
        curr = curr->GetNext();
    }

    if (!curr) {
        cout << "Song with ID " << id << " not found." << endl;
        cout << endl;
        return;
    }

    if (curr == head) {
        head = head->GetNext();
    } else {
        prev->SetNext(curr->GetNext());
    }

    if (curr == tail) {
        tail = prev;
    }

    cout << "\"" << curr->GetSongName() << "\" removed." << endl;
    cout << endl;

    delete curr;
}

void ChangePosition(PlaylistNode*& head, PlaylistNode*& tail) {
    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    int currentPosition, newPosition;
    cin >> currentPosition;
    cout << "Enter new position for song:" << endl;
    cin >> newPosition;
    cin.ignore();

    if (!head || currentPosition == newPosition) {
        return;
    }

    PlaylistNode* prev = nullptr;
    PlaylistNode* curr = head;
    int index = 1;

    while (curr && index < currentPosition) {
        prev = curr;
        curr = curr->GetNext();
        ++index;
    }

    if (!curr) {
        return;
    }

    if (curr == head) {
        head = head->GetNext();
    } else {
        prev->SetNext(curr->GetNext());
    }

    if (curr == tail) {
        tail = prev;
    }

    curr->SetNext(nullptr);

    if (newPosition <= 1) {
        curr->SetNext(head);
        head = curr;
    } else {
        PlaylistNode* newPrev = nullptr;
        PlaylistNode* newCurr = head;
        int newIndex = 1;

        while (newCurr && newIndex < newPosition) {
            newPrev = newCurr;
            newCurr = newCurr->GetNext();
            ++newIndex;
        }

        curr->SetNext(newCurr);

        if (newPrev) {
            newPrev->SetNext(curr);
        }

        if (!newCurr) {
            tail = curr;
        }
    }

    cout << "\"" << curr->GetSongName() << "\" moved to position " << newPosition << endl;
    cout << endl;
}

void OutputSongsByArtist(PlaylistNode* head) {
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl;
    string artistName;
    getline(cin, artistName);
    cout << endl;

    int position = 1;
    for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext(), ++position) {
        if (curr->GetArtistName() == artistName) {
            cout << position << "." << endl;
            curr->PrintPlaylistNode();
            cout << endl;
        }
    }
}

void OutputTotalTime(PlaylistNode* head) {
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    int totalTime = 0;

    for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
        totalTime += curr->GetSongLength();
    }

    cout << "Total time: " << totalTime << " seconds" << endl;
    cout << endl;
}
