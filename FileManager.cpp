#include "FileManager.h"

void FileManager::resetFile(const std::string& fileName) {
    std::ofstream file(fileName, std::ios::trunc);
}

void FileManager::writeChar(char character, const std::string& fileName) {
    std::ofstream file(fileName, std::ios::app);
    file << character;
}

char FileManager::readChar(const std::string& fileName, int index) {
    std::ifstream file(fileName);
    char character;
    int count = 0;

    while (count <= index && file >> character) {
        count++;
    }
    
    return character;
}
