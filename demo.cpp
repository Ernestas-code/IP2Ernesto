#include <iostream>
#include "Set.h"

using namespace MyNS;

int main() {
    try {
        Set s;
        s += 10;
        s += 20;
        s += 30;
        std::cout << "After insert: " << s.toString() << std::endl;
        std::cout << "Contains 20? " << (s[20] ? "Yes" : "No") << std::endl;
        std::cout << "Contains 99? " << (s[99] ? "Yes" : "No") << std::endl;
        s *= 100;
        std::cout << "After update: " << s.toString() << std::endl;
        s -= 20;
        std::cout << "After delete: " << s.toString() << std::endl;
        Set s2;
        s2 += 1;
        s2 += 2;

        std::cout << "s == s2? " << (s == s2) << std::endl;
        std::cout << "s != s2? " << (s != s2) << std::endl;
        std::cout << "s > s2? " << (s > s2) << std::endl;
        std::cout << "s < s2? " << (s < s2) << std::endl;

        Set s3 = s;
        std::cout << "Copied set: " << s3.toString() << std::endl;
        !s;
        std::cout << "After clear: " << s.toString() << std::endl;

        try {
            s2 += 1; // dup
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}