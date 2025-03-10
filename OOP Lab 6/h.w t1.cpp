#include <iostream>
using namespace std;

class books {
protected:
string genre;
public:
books(string g): genre(g) {}
};
class novel: public books {
    protected:
    string name;
    string author;
    public:
    novel (string g, string n, string a): books(g), name(n), author(a) {}
    void showinfo () {
        cout<<"The book name is: "<<name<<endl;
        cout<<"The book author is: "<<author<<endl;
        cout<<"The book genre is: "<<genre<<endl;
    }
};
class mystery: public books {
    protected:
    string name;
    string author;
    public:
    mystery (string g, string n, string a): books(g), name(n), author(a) {}
    void showinfo () {
        cout<<"The book name is: "<<name<<endl;
        cout<<"The book author is: "<<author<<endl;
        cout<<"The book genre is: "<<genre<<endl;
    }
};
int main () {
    novel n("Novel", "The Silent Patient","Alex Michaelides");
    mystery m("Mystery","The big sleep","Raymon Chandler");
    n.showinfo();
    m.showinfo();
    return 0;
}