//
// Created by dn034088 on 12/14/2023.
//

#include "main.h"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

int main() {
    std::string line;
    std::ifstream dummy("dummy.txt");

    if (file.is_open()) {
        while (std::getline(dummy, line)) {
            // using printf() in all tests for consistency
            printf("%s", line.c_str());
        }
}