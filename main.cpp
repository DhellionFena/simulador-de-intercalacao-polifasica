#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <list>
// ENTRADA: I N T E R C A L A C A O B A L A N C E A D A 

void reset_fita(std::string file_name) {
    std::ofstream arquivo;
    arquivo.open(file_name.c_str(), std::ios::trunc);
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
    arquivo.open(nome_arq.c_str(), std::ios::app);
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

int getInput(char * input) {
    char c;
    int i = 0;
    
    do {
        c = getchar();

        if (c == '\n') break;
        if (c != ' ') {
            input[i] = c;
            i++;
        }
    } while (c != '\n');

    return i;
}

int trocar_bloco(int * cont_especial, std::list<char> &bloco, std::string &file_name, char* heap) {
    if ((cont_especial[0] == 1) && (cont_especial[1] == 1) && (cont_especial[2] == 1)) {

        cont_especial[0] = 0;
        cont_especial[1] = 0;
        cont_especial[2] = 0;
        bloco.push_back(' ');
        // Armazena na fita
        while(!bloco.empty()){
            grava_char(bloco.front(), file_name);
            bloco.pop_front();
        }

        trocaFile(file_name);
        bubble_sort(heap, 3);

        return 1;
    }

    return 1;
}

int main(void) {
    char input[27], heap[3], aux;
    int indice = 3, cont_especial[3] = {0,0,0}, tam;
    std::list<char> bloco;
    std::string file_name = "fita1.txt";

    // Resetando as fitas
    reset_fita("fita1.txt");
    reset_fita("fita2.txt");
    reset_fita("fita3.txt");

    tam = getInput(input);

    heap[0] = input[0];
    heap[1] = input[1];
    heap[2] = input[2];
    
    bubble_sort(heap, 3);

    //guardou no bloco
    for(int i = 0; i <= tam; i++){
        
        
        bloco.push_back(heap[0]);
        aux = heap[0];
        heap[0] = input[indice];
        indice++;

        if (aux > heap[0]) {
                
            if (cont_especial[2] == 0) {
                aux = heap[0]; 
                heap[0] = heap[2];
                heap[2] = aux; 
                if(heap[0] > heap[1]) {
                    aux = heap[0]; 
                    heap[0] = heap[1];
                    heap[1] = aux;
                }
                cont_especial[2]++;

            } else if (cont_especial[1] == 0) {
                aux = heap[0]; 
                heap[0] = heap[1];
                heap[1] = aux; 
                cont_especial[1]++;

            } else if (cont_especial[0] == 0){
                cont_especial[0]++;
                
            }
            
        } else {

            if (cont_especial[2] == 0){
                bubble_sort(heap,3);

            }else if (cont_especial[1] == 0) {
                if(heap[0] > heap[1]) {
                    aux = heap[0]; 
                    heap[0] = heap[1];
                    heap[1] = aux;
                }
            }
        }
        
        trocar_bloco(cont_especial, bloco, file_name,heap);
    }
    
}