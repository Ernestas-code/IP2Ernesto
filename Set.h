#ifndef SET_H
#define SET_H

#include <string>

namespace myns {

class Set {
private:
        class Impl;
        Impl* impl;

public:
        Set();
        ~Set();
        Set(const Set& other);
        Set& operator=(const Set& other);


        Set& operator+=(int value);
        Set& operator-=(int value);
        Set& operator*=(int value);

        bool operator[](int value) const;
        void operator!();
        std::string toString() const;

        bool operator==(const Set& other) const;
        bool operator!=(const Set& other) const;
        bool operator<(const Set& other) const;
        bool operator<=(const Set& other) const;
        bool operator>(const Set& other) const;
        bool operator>=(const Set& other) const;
    };

}

#endif