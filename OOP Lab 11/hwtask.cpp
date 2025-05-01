#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class StackUnderflowException : public runtime_error {
public:
    StackUnderflowException() 
        : runtime_error("Stack underflow - operation on empty stack") {}
};
template<typename T>
class Stack {
    vector<T> elements;
public:
    void push(const T& item) {
        elements.push_back(item);
    }

    T pop() {
        if(empty())
            throw StackUnderflowException();
        T topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    T& top() {
        if(empty())
            throw StackUnderflowException();
        return elements.back();
    }

    bool empty() const { return elements.empty(); }
    size_t size() const { return elements.size(); }
};

int main() {
    Stack<string> stack;

    try {
        stack.push("First");
        stack.push("Second");
        stack.push("Third");
        cout << "Stack size: " << stack.size() << endl;
        cout << "Top element: " << stack.top() << endl;
        cout << "\nPopping elements:" << endl;
        while(!stack.empty()) {
            cout << "Popped: " << stack.pop() << endl;
            cout << "Remaining size: " << stack.size() << endl;
        }

        cout << "\nAttempting to pop from empty stack..." << endl;
        stack.pop();
    } catch(const StackUnderflowException& e) {
        cerr << "ERROR: " << e.what() << endl;
    }
    return 0;
}
