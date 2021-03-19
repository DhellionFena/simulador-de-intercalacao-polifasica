//Intercalação balanceada  
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>



#define QUANT_CHAR 3

// INPUT: O R D E N A N D O I N F O D O A R Q U I V O

// Limpa as fitas

void reset_fita(std::string file_name) {
    std::ofstream arquivo;
    arquivo.open(file_name, std::ios::trunc);
    arquivo.close();
}

void limpa_fitas() {

    std::string file_name[6] = {
        "fita1.txt", 
        "fita2.txt" , 
        "fita3.txt" , 
        "fita4.txt" , 
        "fita5.txt" ,
        "fita6.txt"
    };

    std::ofstream arquivo;//abri arquivo de escrita
    for (std::string &files : file_name) {
        arquivo.open(files, std::ios::trunc);
        arquivo.close();
    }
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

int menorValor(char *vetor) {

    if (vetor[0] != '\0' && vetor[1] != '\0' && vetor[2] != '\0' ) {
        if (vetor[0] <= vetor[1] && vetor[0] <= vetor[2]) {
            return 0;
        }
        else if (vetor[1] <= vetor[0] && vetor[1] <= vetor[2]) {
            return 1;
        }
        else {
            return 2;
        }
        
    }
    //caso 0 seja nulo
    else if(vetor[1] != '\0' && vetor[2] != '\0') {
        if (vetor[1] <= vetor[2]) {
            return 1;
        }
        else {
            return 2;
        }
    }
    //caso 1 seja nulo
    else if (vetor[0] != '\0' && vetor[2] != '\0') {
        if (vetor[0] <= vetor[2]) {
            return 0;
        }
        else {
            return 2;
        }
    }
    //caso 2 seja nulo
    else if (vetor[0] != '\0' && vetor[1] != '\0') {
        if (vetor[0] <= vetor[1]) {
            return 0;
        }
        else {
            return 1;
        }
    }
    //caso 1 e 2 sejam nulos
    else if (vetor[0] != '\0' && vetor[1]=='\0' && vetor[2] == '\0') {
        return 0;
    }
    //caso 0 e 2 sejam nulos
    else if (vetor[0] == '\0' && vetor[1] !='\0' && vetor[2] == '\0') {
        return 1;
    }
    //caso 0 e 1 sejam nulos
    else if (vetor[0] == '\0' && vetor[1] =='\0' && vetor[2] != '\0') {
        return 2;
    }
    else return 4;
    
}

char ler_caracter(std::string arquivo, int indice) {
    //vai ler o arquivo e pegar o seus caracteres
    std::ifstream arq;
    arq.open(arquivo);
    int cont = 0;
    char caracter;

    while (cont <= indice) {
        arq >> caracter;
        cont++;
    }

    // std::cout << caracter<< "\n";
    
    arq.close();
    return caracter;
}

void gravar(char *bloco, int tamanho, std::string nome_arq) {
    // Adiciona char em um arquivo 

    std::ofstream arquivo;//abri arquivo de escrita
    arquivo.open(nome_arq, std::ios::app);
    for(int i=0; i< tamanho;i++){
        if(bloco[i]!='\0'){
            arquivo << bloco[i];
        }
    }
    arquivo.close();
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
        file_name = "fita3.txt";
        return 0;
    }
    
    if (file_name == "fita3.txt"){
        file_name = "fita1.txt";
        return 0;
    }
}

int trocaFile2(std::string &file_name) {
    if (file_name == "fita4.txt") {
        file_name = "fita5.txt";
        return 0;
    }
    
    if (file_name == "fita5.txt"){
        file_name = "fita6.txt";
        return 0;
    }
    
    if (file_name == "fita6.txt"){
       file_name = "fita4.txt";
        return 0;
    }
}

void resetVetor(char *v) {
    for (int i=0; i < QUANT_CHAR; i++) {
        v[i] = '\0';
    }
}

int main(void) {
    std::string file_name;
    file_name = "fita1.txt"; // fita inicial
    char input[QUANT_CHAR];
    char c;
    int j = 0, cont[QUANT_CHAR]={0,0,0}, temp, multi=0 ;

    limpa_fitas();
    // Grava os inputs separadamente e ordena em um arquvio
    do {
        c = getchar();

        if (c == '\n') break;
        if (c != ' ') {
            input[j] = c;
            if (j == 2) {
                bubble_sort(input, QUANT_CHAR); 
                gravar(input, QUANT_CHAR, file_name);
                resetVetor(input);
                
                // troca file_name
                trocaFile(file_name);
                j = 0;
            } else j++;
        }
    } while (c != '\n');

    // ordena o resto
    if (input[0] != '\0') {
        if(input[1] !='\0'){
            bubble_sort(input, 2);
            gravar(input, 2, file_name);
        }else{
            gravar(input, 1, file_name);
        }
    }

    grava_char('\0', "fita1.txt");
    grava_char('\0', "fita2.txt");
    grava_char('\0', "fita3.txt");

    file_name = "fita4.txt";

// ----------------------------
    while (multi < 9) {
        // cont = 3 3 3
        // null null null
        resetVetor(input);
        
        if(cont[0]<3)
            input[0] = ler_caracter("fita1.txt", cont[0]+multi);
        
        if (cont[1]<3)
            input[1] = ler_caracter("fita2.txt", cont[1]+multi);

        if (cont[2]<3)
            input[2] = ler_caracter("fita3.txt", cont[2]+multi);
        
        temp = menorValor(input);

        if (temp != 4) {
            if (cont[temp] <= 3) {
            grava_char(input[temp], file_name);
            cont[temp]++;
            }
        }

        if (input[0]=='\0' && input[1]=='\0' && input[2]=='\0') {
            trocaFile2(file_name);
            std::cout << "troquei de file: " << file_name.c_str() << "\n"; 
            cont[0] = 0;
            cont[1] = 0;
            cont[2] = 0;
            multi += 3;
        }
    }

    //--------------------------------------
    multi = 0;
    cont[0] = 0; cont[1] = 0; cont[2] = 0;
    reset_fita("fita1.txt");
    file_name = "fita1.txt";

    grava_char('\0', "fita4.txt");
    grava_char('\0', "fita5.txt");
    grava_char('\0', "fita6.txt");

    while (1) {
        // cont = 3 3 3
        // null null null
        resetVetor(input);
        
        input[0] = ler_caracter("fita4.txt", cont[0]+multi);
        input[1] = ler_caracter("fita5.txt", cont[1]+multi);
        input[2] = ler_caracter("fita6.txt", cont[2]+multi);
        
        temp = menorValor(input);
        
        if (temp != 4) {
            grava_char(input[temp], file_name);
            cont[temp]++;
        }

        if (input[0]=='\0' && input[1]=='\0' && input[2]=='\0') {
            break;
        }
    }
}

