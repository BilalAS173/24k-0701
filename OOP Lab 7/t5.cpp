#include <iostream>
#include <string>
using namespace std;
class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    Media(string title, string pubDate, string id, string pub)
        : title(title), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }

    string getTitle() const { 
        return title;
     }
    string getPublicationDate() const {
         return publicationDate; 
        }
    virtual string getAuthor() const { 
        return ""; 
    }
};

class Book : public Media {
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string title, string pubDate, string id, string pub,
         string author, string isbn, int pages)
        : Media(title, pubDate, id, pub), author(author), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nNumber of Pages: " << numberOfPages << endl;
    }

    string getAuthor() const override { return author; }
};

class DVD : public Media {
    string director;
    string duration;
    string rating;

public:
    DVD(string title, string pubDate, string id, string pub,
        string director, string duration, string rating)
        : Media(title, pubDate, id, pub), director(director), duration(duration), rating(rating) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << "\nRating: " << rating << endl;
    }
};

class CD : public Media {
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string title, string pubDate, string id, string pub,
       string artist, int tracks, string genre)
        : Media(title, pubDate, id, pub), artist(artist), numberOfTracks(tracks), genre(genre) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nNumber of Tracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

class Magazine : public Media {
    string issueNumber;
    string editor;

public:
    Magazine(string title, string pubDate, string id, string pub,
             string issueNumber, string editor)
        : Media(title, pubDate, id, pub), issueNumber(issueNumber), editor(editor) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << "\nEditor: " << editor << endl;
    }
};
void searchByTitle(const Media* media[], int size, const string& title) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (media[i]->getTitle() == title) {
            media[i]->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No media found with title: " << title << endl;
    }
}

void searchByAuthor(const Media* media[], int size, const string& author) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (media[i]->getAuthor() == author) {
            media[i]->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No media found by author: " << author << endl;
    }
}

int main() {
    Media* mediaItems[] = {
        new Book("The Great Gatsby", "1925-04-10", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180),
        new DVD("Inception", "2010-07-16", "D001", "Warner Bros.", "Christopher Nolan", "148 min", "PG-13"),
        new CD("Thriller", "1982-11-30", "C001", "Epic Records", "Michael Jackson", 9, "Pop"),
        new Magazine("National Geographic", "2021-01-01", "M001", "National Geographic Society", "January 2021", "Susan Goldberg")
    };
    const int mediaCount = 4;
    cout << "Searching for title 'Inception':\n";
    searchByTitle(mediaItems, mediaCount, "Inception");
    cout << "\nSearching for author 'F. Scott Fitzgerald':\n";
    searchByAuthor(mediaItems, mediaCount, "F. Scott Fitzgerald");
    cout << "\nSearching for non-existent title 'Unknown':\n";
    searchByTitle(mediaItems, mediaCount, "Unknown");
    for (int i = 0; i < mediaCount; i++) {
        delete mediaItems[i];
    }

    return 0;
}
