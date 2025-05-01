#include <iostream>
using namespace std;
template<typename T>
class Base {
protected:
    T val1, val2;
public:
    Base(T v1, T v2) : val1(v1), val2(v2) {}
    virtual ~Base() = default;
    
    T multiplyBase() const { 
        cout << "Base multiplication: " << val1 << " * " << val2;
        return val1 * val2; 
    }
};

template<typename T>
class Derived : public Base<T> {
    T val3, val4;
public:
    Derived(T v1, T v2, T v3, T v4) 
        : Base<T>(v1, v2), val3(v3), val4(v4) {}
    
    T multiplyAll() const {
        T baseResult = Base<T>::multiplyBase();
        cout << " = " << baseResult << endl;
        cout << "Derived multiplication: " << val3 << " * " << val4;
        T derivedResult = val3 * val4;
        cout << " = " << derivedResult << endl;
        return baseResult * derivedResult;
    }
};

int main() {
     Derived<int> intCalc(2, 3, 4, 5);
    cout << "Testing with integers:" << endl;
    int result = intCalc.multiplyAll();
    cout << "Final result: " << result << endl << endl;
    Derived<double> doubleCalc(1.5, 2.5, 3.5, 4.5);
    cout << "Testing with doubles:" << endl;
    double dResult = doubleCalc.multiplyAll();
    cout << "Final result: " << dResult << endl;

    return 0;
}
