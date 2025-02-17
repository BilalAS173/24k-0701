#include <iostream>
using namespace std;
class DynamicArray {
private:
    int* data;
    int length;

public:
    // Default constructor
    DynamicArray() : data(nullptr), length(0) {}

    // Parameterized constructor
    DynamicArray(int n) : length(n) {
        data = new int[n]();
    }

    // Copy constructor (Deep Copy)
    DynamicArray(const DynamicArray& other) : length(other.length) {
        data = new int[length];
        for (int i = 0; i < length; ++i)
            data[i] = other.data[i];
    }

    // Move constructor
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    // Copy assignment operator (Deep Copy)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new int[length];
            for (int i = 0; i < length; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    // Move assignment operator
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // Get size of the array
    int size() const { return length; }

    // Access elements
    int& at(int index) { return data[index]; }
    const int& at(int index) const { return data[index]; } // Const version for read-only access

    // Resize the array
    void resize(int newSize) {
        int* newData = new int[newSize]();
        for (int i = 0; i < (newSize < length ? newSize : length); ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        length = newSize;
    }
};
