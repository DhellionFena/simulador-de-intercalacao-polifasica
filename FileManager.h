#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <fstream>
#include <string>

class FileManager {
public:
    static void resetFile(const std::string& fileName);
    static void writeChar(char character, const std::string& fileName);
    static char readChar(const std::string& fileName, int index);
};

#endif
