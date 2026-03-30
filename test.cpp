#include <iostream>
#include <fstream>
#include "Set.h"
#include <filesystem>
using namespace myns;

// print helper
void log(std::ostream& out, const std::string& message) {
    std::cout << message << std::endl;
    out << message << std::endl;
}

int main() {
    std::cout << "Working dir: " << std::filesystem::current_path() << std::endl;
    std::ofstream file("C:\\Users\\Ernestas K\\CLionProjects\\IP2Ernesto\\log.txt");
    if (!file) {
        std::cout << "error opening log file" << std::endl;
        return 1;
    }

    log(file, " TEST START ");
    for (int i = 0; i < 5; i++) {
        // insert
        try {
            Set s;
            s += 1;
            s += 2;
            log(file, (s[1] && s[2]) ? "Test 1 PASS" : "Test 1 FAIL");
        } catch (...) {
            log(file, "Test 1 FAIL (exception)");
        }

        // dup
        try {
            Set s;
            s += 5;
            s += 5;
            log(file, "Test 2 FAIL (no exception)");
        } catch (...) {
            log(file, "Test 2 PASS");
        }

        // delete
        try {
            Set s;
            s += 10;
            s -= 10;
            log(file, (!s[10]) ? "Test 3 PASS" : "Test 3 FAIL");
        } catch (...) {
            log(file, "Test 3 FAIL (exception)");
        }

        // update
        try {
            Set s;
            s += 1;
            s *= 100;
            log(file, (s[100]) ? "Test 4 PASS" : "Test 4 FAIL");
        } catch (...) {
            log(file, "Test 4 FAIL (exception)");
        }

        //  clear
        try {
            Set s;
            s += 1;
            !s;
            log(file, (!s[1]) ? "Test 5 PASS" : "Test 5 FAIL");
        } catch (...) {
            log(file, "Test 5 FAIL (exception)");
        }

        // copy
        try {
            Set s1;
            s1 += 1;
            Set s2 = s1;
            log(file, (s2[1]) ? "Test 6 PASS" : "Test 6 FAIL");
        } catch (...) {
            log(file, "Test 6 FAIL (exception)");
        }

        // comparison1
        try {
            Set s1, s2;
            s1 += 1;
            s2 += 1;
            log(file, (s1 == s2) ? "Test 7 PASS" : "Test 7 FAIL");
        } catch (...) {
            log(file, "Test 7 FAIL (exception)");
        }
    }
    log(file, "TEST END");

    file.close();
    return 0;
}