#include "Utils.h"
#include <iostream>

int Utils::getInput(char* input) {
    char c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        if (c != ' ') input[i++] = c;
    }
    return i;
}

void Utils::trocaFile(std::string& fileName) {
    fileName = (fileName == "fita1.txt") ? "fita2.txt" : "fita1.txt";
}
