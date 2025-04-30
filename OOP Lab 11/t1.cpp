#include <any>
#include <stdexcept>
#include <vector>
#include <typeindex>
#include <iostream>

using namespace std;

class BadTypeException : public runtime_error {
public:
    BadTypeException(const string& what) : runtime_error(what) {}
};

class TypeSafeContainer {
private:
    struct Entry {
        type_index type;
        any value;
    };
    
    vector<Entry> storage;

public:
    template<typename T>
    void store(const T& value) {
        storage.push_back({typeid(T), value});
    }

    template<typename T>
    T get() const {
        const type_index target_type = typeid(T);
        
        for (const auto& entry : storage) {
            if (entry.type == target_type) {
                try {
                    return any_cast<T>(entry.value);
                } catch (const bad_any_cast&) {
                    throw BadTypeException("Type mismatch in stored value");
                }
            }
        }
        
        throw BadTypeException("Type not found in container");
    }

    template<typename T>
    bool contains() const {
        const type_index target_type = typeid(T);
        for (const auto& entry : storage) {
            if (entry.type == target_type) {
                return true;
            }
        }
        return false;
    }

    size_t size() const {
        return storage.size();
    }
};
