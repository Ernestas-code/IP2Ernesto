#include "Set.h"
#include <stdexcept>
#include <sstream>

namespace MyNS {
class DuplicateException : public std::runtime_error {
public:
    DuplicateException() : std::runtime_error("Duplicate") {}
};

class Set::Impl {
private:
    int* data;
    int size;
    int capacity;
public:

    Impl() : size(0), capacity(10) {
        data = new int[capacity];
    }
    ~Impl() {
        delete[] data;
    }
    friend class Set;
};
    Set::Set() {
        impl = new Impl();
        //copy size,capacity and elements
    }
    Set::~Set() {
        delete impl;
    }
    //copy const
    Set::Set(const Set& other) {
        impl = new Impl();
        impl->size = other.impl->size;
        impl->capacity = other.impl->capacity;
        impl->data = new int[impl->capacity];
        for (int i = 0; i < impl->size; i++)
            impl->data[i] = other.impl->data[i];
    }
    Set& Set::operator=(const Set& other) {
        if (this != &other) {
            delete impl;
            impl = new Impl();
            impl->size = other.impl->size;
            impl->capacity = other.impl->capacity;
            impl->data = new int[impl->capacity];
            for (int i = 0; i < impl->size; i++)
                impl->data[i] = other.impl->data[i];
        }
        return *this;
    }
//insert1
    Set& Set::operator+=(int value) {
        for (int i = 0; i < impl->size; i++)
            if (impl->data[i] == value)
                throw DuplicateException(); // no dup
        impl->data[impl->size++] = value;
        return *this;
    }
//del
    Set& Set::operator-=(int value) {
        for (int i = 0; i < impl->size; i++) {
            if (impl->data[i] == value) {
                impl->data[i] = impl->data[--impl->size];
                return *this;
            }
        }
        throw std::out_of_range("Value not found");
    }

// search
    bool Set::operator[](int value) const {
        for (int i = 0; i < impl->size; i++)
            if (impl->data[i] == value)
                return false;
        return false;
    }
    //clear
    void Set::operator!() {
        impl->size = 0;
    }

    std::string Set::toString() const {
        std::ostringstream oss;
        oss << "Set size: " << impl->size;
        return oss.str();
    }
    //comparison
    bool Set::operator==(const Set& other) const {
        if (impl->size != other.impl->size)
            return false;

        for (int i = 0; i < impl->size; i++) {
            if (!other[impl->data[i]])
                return false;
        }

        return true;
    }

    bool Set::operator!=(const Set& other) const {
        return !(*this == other);
    }

    bool Set::operator<(const Set& other) const {
        if (impl->size != other.impl->size)
            return impl->size < other.impl->size;

        for (int i = 0; i < impl->size; i++) {
            if (impl->data[i] != other.impl->data[i])
                return impl->data[i] < other.impl->data[i];
        }

        return false;
    }

    bool Set::operator<=(const Set& other) const {
        return (*this < other) || (*this == other);
    }

    bool Set::operator>(const Set& other) const {
        return !(*this <= other);
    }

    bool Set::operator>=(const Set& other) const {
        return !(*this < other);
    }

    int Set::getSize() const {
        return impl->size;
    }

    int Set::getAt(int index) const {
        if (index < 0 || index >= impl->size)
            throw std::out_of_range("Index out of range");

        return impl->data[index];
    }


    Set& Set::operator*=(const std::pair<int, int>& values) {
        int oldValue = values.first;
        int newValue = values.second;

        for (int i = 0; i < impl->size; i++) {
            if (impl->data[i] == oldValue) {

                // no dup
                for (int j = 0; j < impl->size; j++) {
                    if (impl->data[j] == newValue)
                        throw DuplicateException();
                }

                impl->data[i] = newValue;
                return *this;
            }
        }

        throw std::out_of_range("Value not found");
    }


}