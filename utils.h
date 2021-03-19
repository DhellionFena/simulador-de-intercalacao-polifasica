#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

void reset_fita(std::string file_name) {
    std::ofstream arquivo;
    arquivo.open(file_name, std::ios::trunc);
    arquivo.close();
}

void bubble_sort(char *v, int quant) {
    char aux;
    int i, j, trocou = 1;
    for (i=0; i<quant-1&&trocou; i++) {
        trocou = 0;
        for (j=0; j<quant-1-i; j++) {
            if (v[j] > v[j+1]) { 
                trocou = 1;
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void grava_char(char character,std::string nome_arq) {
    // Adiciona char em um arquivo 
    std::ofstream arquivo;//abri arquivo de escrita
    arquivo.open(nome_arq, std::ios::app);
    arquivo << character;
    arquivo.close();
}

int trocaFile(std::string &file_name) {
    if (file_name == "fita1.txt") {
        file_name = "fita2.txt";
        return 0;
    }
    
    if (file_name == "fita2.txt"){
        file_name = "fita1.txt";
        return 0;
    }
}