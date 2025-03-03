#include <iostream>
#include <thread> 
#include <chrono>
using namespace std;
class Blend {
public:
    void blendJuice() {
        cout << "Blending juice...\n";
        for (int i = 0; i < 4; i++) {
            cout << "Blending...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        cout << "Juice blended!\n";
    }
};
class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice...\n";
        std::this_thread::sleep_for(std::chrono::seconds(5)); 
        cout << "Juice ground!\n";
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice() {
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Juice is ready to serve!\n";
    }
};
int main() {
    JuiceMaker myJuice;
    myJuice.makeJuice();
    return 0;
}
