#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayIndexOutOfBounds : public runtime_error {
public:
    ArrayIndexOutOfBounds(const string& message) 
        : runtime_error(message) {}
};

template<typename T>
class SafeArray {
private:
    T* data;
    size_t size_;

public:
    // Constructor
    SafeArray(size_t size) : size_(size) {
        data = new T[size];
    }

    // Destructor
    ~SafeArray() {
        delete[] data;
    }

    // Copy constructor
    SafeArray(const SafeArray& other) : size_(other.size_) {
        data = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator
    SafeArray& operator=(const SafeArray& other) {
        if (this != &other) {
            delete[] data;
            size_ = other.size_;
            data = new T[size_];
            for (size_t i = 0; i < size_; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Size accessor
    size_t size() const {
        return size_;
    }

    // Index operator with bounds checking
    T& operator[](int index) {
        if (index < 0 || static_cast<size_t>(index) >= size_) {
            throw ArrayIndexOutOfBounds(
                "Index " + to_string(index) + 
                " out of bounds for array of size " + 
                to_string(size_));
        }
        return data[index];
    }

    // Const version of index operator
    const T& operator[](int index) const {
        if (index < 0 || static_cast<size_t>(index) >= size_) {
            throw ArrayIndexOutOfBounds(
                "Index " + to_string(index) + 
                " out of bounds for array of size " + 
                to_string(size_));
        }
        return data[index];
    }
};

int main() {
    try {
        // Create a SafeArray of integers
        SafeArray<int> arr(5);

        // Fill the array
        for (int i = 0; i < 5; ++i) {
            arr[i] = (i + 1) * 10;
        }

        // Print the array
        cout << "Array contents: ";
        for (int i = 0; i < 5; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Test bounds checking
        cout << "Attempting to access arr[5]: ";
        cout << arr[5] << endl;  // This will throw

    } catch (const ArrayIndexOutOfBounds& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        SafeArray<string> strArr(3);
        strArr[0] = "Hello";
        strArr[1] = "World";
        strArr[2] = "!";

        cout << "\nString array: ";
        for (int i = 0; i < 3; ++i) {
            cout << strArr[i] << " ";
        }
        cout << endl;

        cout << "Attempting to access strArr[-1]: ";
        cout << strArr[-1] << endl;  // This will throw

    } catch (const ArrayIndexOutOfBounds& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}