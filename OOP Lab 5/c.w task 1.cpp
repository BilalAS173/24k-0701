#include <iostream>
using namespace std;
class car;
class Engine;
class Engine {
private:
bool isrunning;
public:
bool getisrunning () {
    return isrunning;
}
void start () {
    cout<<"Engine started."<<endl;
}
void stop () {
    cout<<"Engine stopped running. "<<endl;
}
};
class car {
    private:
    Engine engine;
    public:
    void startcar () {
        engine.start();
    }
    void stopcar () {
        engine.stop();
    }
};
int main () {
    car Car;
    Car.startcar();
    Car.stopcar();
}