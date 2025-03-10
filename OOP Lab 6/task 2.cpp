#include<iostream>
using namespace std;
class mediafile {
    protected:
    string filepath;
    int size;
    public:
    mediafile(string s, int b): filepath(s), size(b) {}
    virtual void play() {
cout<<"Playing file..."<<endl;
    }
    virtual void stop () {
cout<<"Stopped playing file..."<<endl;
    }
    virtual void showinfo () {
        cout<<"File path: "<<filepath<<endl;
        cout<<"File size (in Kb): "<<size<<endl;
    }
    virtual ~mediafile() {}
};
class visualmedia: virtual public mediafile {
public:
visualmedia(string s, int b): mediafile(s, b) {}
void showinfo () override {
    cout<<"File path: "<<filepath<<endl;
    cout<<"File size (in Kb): "<<size<<endl;
}
void play() override  {
    cout<<"Playing visual media..."<<endl;
    }
    void stop() override {
        cout<<"Stopped playing visual media..."<<endl;
    }
};
class audiomedia: virtual public mediafile {
public:
audiomedia(string s, int b): mediafile(s,b) {}
void play() override  {
    cout<<"Playing audio..."<<endl;
    }
    void stop() override {
        cout<<"Stopped playing audio..."<<endl;
    }
   void showinfo () override {
        cout<<"File path: "<<filepath<<endl;
        cout<<"File size (in Kb): "<<size<<endl;
    }
};
class videofile: public visualmedia, public audiomedia {
    public:
videofile(string s, int b): mediafile(s,b),visualmedia(s, b), audiomedia(s,b) {}
void play() override  {
cout<<"Playing video..."<<endl;
}
void stop() override {
    cout<<"Stopped playing video..."<<endl;
}
void showinfo () override {
    cout<<"File path: "<<filepath<<endl;
    cout<<"File size (in Kb): "<<size<<endl;
}

};
int main () {
videofile v("documents",5);
audiomedia am("downloads",10);
visualmedia m("Desktop",15);

mediafile* a=&v;
mediafile* b=&am;
mediafile*c=&m;
a->showinfo();
a->play();
a->stop();

b->showinfo();
b->play();
b->stop();

c->showinfo();
c->play();
c->stop();

return 0;
}