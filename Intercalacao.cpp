#include "Intercalacao.h"
#include "FileManager.h"
#include "Sorting.h"
#include <utility>


void Intercalacao::heapSort(std::list<char>& bloco, char* heap, int& index, int* contEspecial, int tam, char* input, std::string& fileName) {
    for (int i = 0; i <= tam; i++) {
        if (i < tam) bloco.push_back(heap[0]);
        char aux = heap[0];
        heap[0] = input[index++];
        
        if (aux > heap[0]) {
            if (contEspecial[2] == 0) {
                std::swap(heap[0], heap[2]);
                if (heap[0] > heap[1]) std::swap(heap[0], heap[1]);
                contEspecial[2]++;
            } else if (contEspecial[1] == 0) {
                std::swap(heap[0], heap[1]);
                contEspecial[1]++;
            } else {
                contEspecial[0]++;
            }
        } else {
            if (contEspecial[2] == 0) Sorting::bubbleSort(heap, 3);
            else if (contEspecial[1] == 0 && heap[0] > heap[1]) std::swap(heap[0], heap[1]);
        }
    }
}

void Intercalacao::intercalacaoPolifasica(char* compara, std::string& file1, std::string& file2, std::string& fileVazio, int* contCompara) {
    while (true) {
        compara[0] = FileManager::readChar(file1, contCompara[0]);
        compara[1] = FileManager::readChar(file2, contCompara[1]);

        if (compara[0] == '#' && compara[1] == '#') {
            char temp0 = FileManager::readChar(file1, contCompara[0] + 1);
            char temp1 = FileManager::readChar(file2, contCompara[1] + 1);

            if (temp0 == '\0' && temp1 == '\0') break;
            else if (temp0 == '\0') { contCompara[0] = 0; contCompara[1]++; }
            else if (temp1 == '\0') { contCompara[1] = 0; contCompara[0]++; }
            else { contCompara[0]++; contCompara[1]++; }

            FileManager::writeChar('#', fileVazio);
        } else {
            FileManager::writeChar(compara[0] < compara[1] ? compara[0] : compara[1], fileVazio);
            contCompara[compara[0] < compara[1] ? 0 : 1]++;
        }
    }
}
