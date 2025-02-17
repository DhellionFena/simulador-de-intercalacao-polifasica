#ifndef INTERCALACAO_H
#define INTERCALACAO_H

#include <list>
#include <string>

class Intercalacao {
public:
    static void heapSort(std::list<char>& bloco, char* heap, int& index, int* contEspecial, int tam, char* input, std::string& fileName);
    static void intercalacaoPolifasica(char* compara, std::string& file1, std::string& file2, std::string& fileVazio, int* contCompara);
};

#endif
