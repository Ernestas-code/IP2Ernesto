#include "Set.h"
#include <stdexcept>
#include <sstream>

namespace myns {
class DuplicateException : public std::runtime_error {
public:
    DuplicateException() : std::runtime_error("Duplicate") {}
};

class Set::Impl {
public:
    int* data;
    int size;
    int capacity;

    Impl() : size(0), capacity(10) {
        data = new int[capacity];
    }
    ~Impl() {
        delete[] data;
    }
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
//update
    Set& Set::operator*=(int value) {
        if (impl->size == 0)
            throw std::runtime_error("empty set");
        impl->data[0] = value;
        return *this;
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
    bool Set::operator==(const Set& other) const { return impl->size == other.impl->size; }
    bool Set::operator!=(const Set& other) const { return !(*this == other); }
    bool Set::operator<(const Set& other) const { return impl->size < other.impl->size; }
    bool Set::operator<=(const Set& other) const { return impl->size <= other.impl->size; }
    bool Set::operator>(const Set& other) const { return impl->size > other.impl->size; }
    bool Set::operator>=(const Set& other) const { return impl->size >= other.impl->size; }

}