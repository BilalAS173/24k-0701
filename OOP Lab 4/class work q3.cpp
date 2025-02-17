#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray() {
        arr = nullptr;
        size = 0;
    }

    DynamicArray(int n) {
        size = n;
        arr = new int[size]();
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept {
        size = other.size;
        arr = other.arr;
        other.arr = nullptr;
        other.size = 0;
    }

    ~DynamicArray() {
        delete[] arr;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;
        delete[] arr;
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) return *this;
        delete[] arr;
        size = other.size;
        arr = other.arr;
        other.arr = nullptr;
        other.size = 0;
        return *this;
    }

    void resize(int newsize) {
        if (newsize <= 0) {
            delete[] arr;
            arr = nullptr;
            size = 0;
        } else {
            int* newarr = new int[newsize]();
            for (int i = 0; i < (newsize < size ? newsize : size); i++) {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            size = newsize;
        }
    }

    int getSize() const {
        return size;
    }

    int& operator[](int index) {
        return arr[index];
    }

    const int& operator[](int index) const {
        return arr[index];
    }
};

int main() {
    DynamicArray arr(5);
    for (int i = 0; i < arr.getSize(); i++) {
        arr[i] = i * 10;
    }

    cout << "Array contents are: ";
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.resize(7);
    cout << "Array after resizing is: ";
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    DynamicArray arrCopy = arr;
    cout << "Copied array is: ";
    for (int i = 0; i < arrCopy.getSize(); i++) {
        cout << arrCopy[i] << " ";
    }
    cout << endl;

    DynamicArray movedArr = std::move(arr);
    cout << "Moved array is: ";
    for (int i = 0; i < movedArr.getSize(); i++) {
        cout << movedArr[i] << " ";
    }
    cout << endl;

}
