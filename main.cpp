#include <iostream>
#include <list>
#include "FileManager.h"
#include "Sorting.h"
#include "Intercalacao.h"
#include "Utils.h"

/*Equipe: 
Rodrigo Cunha da Silva Franco
Marcos Vinicius Leal Machado
Antonio Cesar Nunes de Azevedo Filho
Amanda Bandeira Rigaud Lima
Felipe Azevedo Ribeiro
*/

// ENTRADA: I N T E R C A L A C A O B A L A N C E A D A

int main() {
    char input[27], heap[3], compara[2];
    int contEspecial[3] = {0, 0, 0}, contCompara[2] = {0, 0}, tam, index = 3;
    std::list<char> bloco;
    std::string file1 = "fita1.txt", file2 = "fita2.txt", fileVazio = "fita3.txt";

    FileManager::resetFile(file1);
    FileManager::resetFile(file2);
    FileManager::resetFile(fileVazio);

    tam = Utils::getInput(input);
    for (int i = 0; i < 3; i++) heap[i] = input[i];

    Sorting::bubbleSort(heap, 3);
    Intercalacao::heapSort(bloco, heap, index, contEspecial, tam, input, file1);

    FileManager::writeChar('\0', file1);
    FileManager::writeChar('\0', file2);
    
    Intercalacao::intercalacaoPolifasica(compara, file1, file2, fileVazio, contCompara);
}
