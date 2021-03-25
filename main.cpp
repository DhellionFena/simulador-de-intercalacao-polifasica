#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <list>
// ENTRADA: I N T E R C A L A C A O B A L A N C E A D A

void reset_fita(std::string file_name)
{
    std::ofstream arquivo;
    arquivo.open(file_name.c_str(), std::ios::trunc);
    arquivo.close();
}

void bubble_sort(char *v, int quant)
{
    char aux;
    int i, j, trocou = 1;
    for (i = 0; i < quant - 1 && trocou; i++)
    {
        trocou = 0;
        for (j = 0; j < quant - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                trocou = 1;
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

char ler_caracter(std::string arquivo, int indice)
{
    //vai ler o arquivo e pegar o seus caracteres
    std::ifstream arq;
    arq.open(arquivo.c_str());
    int cont = 0;
    char caracter;

    while (cont <= indice)
    {
        arq >> caracter;
        cont++;
    }

    arq.close();
    return caracter;
}

void grava_char(char character, std::string nome_arq)
{
    // Adiciona char em um arquivo
    std::ofstream arquivo; //abri arquivo de escrita
    arquivo.open(nome_arq.c_str(), std::ios::app);
    arquivo << character;
    arquivo.close();
}

int trocaFile(std::string &file_name)
{
    if (file_name == "fita1.txt")
    {
        file_name = "fita2.txt";
        return 0;
    }

    if (file_name == "fita2.txt")
    {
        file_name = "fita1.txt";
        return 0;
    }
}

int getInput(char *input)
{
    char c;
    int i = 0;

    do
    {
        c = getchar();

        if (c == '\n')
            break;
        if (c != ' ')
        {
            input[i] = c;
            i++;
        }
    } while (c != '\n');

    return i;
}

int trocar_bloco(int *cont_especial, std::list<char> &bloco, std::string &file_name, char *heap)
{
    if ((cont_especial[0] == 1) && (cont_especial[1] == 1) && (cont_especial[2] == 1))
    {

        cont_especial[0] = 0;
        cont_especial[1] = 0;
        cont_especial[2] = 0;
        bloco.push_back('#');
        // Armazena na fita
        while (!bloco.empty())
        {
            grava_char(bloco.front(), file_name);
            bloco.pop_front();
        }

        trocaFile(file_name);
        bubble_sort(heap, 3);

        return 1;
    }

    return 1;
}

int menorValor(char *vetor,int *cont_compara)
{
    //retorna indice com menor valor
    if(vetor[0] != '\0' && vetor[1] != '\0'){
    	if (vetor[0] != '#' && vetor[1] != '#')
	    {
	        if (vetor[0] <= vetor[1] && vetor[0] != '#')
	        {
	            return 0;
	        }
	        else if (vetor[1] <= vetor[0] && vetor[1] != '#')
	        {
	            return 1;
	        }
	    }
	    else if (vetor[0] == '#' && vetor[1] != '#')
	    {
	
	        return 1;
	    }
	    else if (vetor[0] != '#' && vetor[1] == '#')
	    {
	        return 0;
	    }
	}else if(vetor[0] == '\0' && vetor[1] != '\0'){
		return 1;
	}else if(vetor[1] == '\0' && vetor[0] != '\0'){
		return 0;
	}else{
		return 3;
	}
	
	    
}

int main(void)
{
    char input[27], heap[3], aux, compara[2], tempc[2];
    int indice = 3, cont_especial[3] = {0, 0, 0}, cont_compara[2] = {0, 0}, tam, temp;
    std::list<char> bloco;
    std::string file_name = "fita1.txt";
    std::string auxFile, file1, file2, file_vazio;
	
    // Resetando as fitas
    reset_fita("fita1.txt");
    reset_fita("fita2.txt");
    reset_fita("fita3.txt");

    tam = getInput(input);
	
	for(int i=0;i<tam;i++){
		std::cout << input[i];
	}
    heap[0] = input[0];
    heap[1] = input[1];
    heap[2] = input[2];

    bubble_sort(heap, 3);

    //guardou no bloco
    for (int i = 0; i <= tam; i++)
    {

        bloco.push_back(heap[0]);
        aux = heap[0];
        heap[0] = input[indice];
        indice++;

        if (aux > heap[0])
        {

            if (cont_especial[2] == 0)
            {
                aux = heap[0];
                heap[0] = heap[2];
                heap[2] = aux;
                if (heap[0] > heap[1])
                {
                    aux = heap[0];
                    heap[0] = heap[1];
                    heap[1] = aux;
                }
                cont_especial[2]++;
            }
            else if (cont_especial[1] == 0)
            {
                aux = heap[0];
                heap[0] = heap[1];
                heap[1] = aux;
                cont_especial[1]++;
            }
            else if (cont_especial[0] == 0)
            {
                cont_especial[0]++;
            }
        }
        else
        {

            if (cont_especial[2] == 0)
            {
                bubble_sort(heap, 3);
            }
            else if (cont_especial[1] == 0)
            {
                if (heap[0] > heap[1])
                {
                    aux = heap[0];
                    heap[0] = heap[1];
                    heap[1] = aux;
                }
            }
        }

        trocar_bloco(cont_especial, bloco, file_name, heap);
    }

    grava_char('\0', "fita1.txt");
    grava_char('\0', "fita2.txt");

    // Início da interação polifásica
    file1 = "fita1.txt";
    file2 = "fita2.txt";
    file_vazio = "fita3.txt";
    
    while (1)
    {
        
        
        	compara[0] = ler_caracter(file1, cont_compara[0]);
        	compara[1] = ler_caracter(file2, cont_compara[1]);
		
        	
        if (compara[0] == '#' && compara[1] == '#')
        {

            // O proximo valor poderá ser outro char ou um \0
            tempc[0] = ler_caracter(file1, cont_compara[0] + 1);
            tempc[1] = ler_caracter(file2, cont_compara[1] + 1);

            if (tempc[0] == '\0' && tempc[1] == '\0')
            {
                reset_fita(file1);
                reset_fita(file2);
                break;
            }
            else if (tempc[0] == '\0')
            {
                // Acabou fita 1 e ainda tem resto na fita 2
                
                grava_char('\0', file_vazio);
                cont_compara[0] = 0;
                cont_compara[1]++;
                auxFile = file_vazio; // file3
                file_vazio = file1; // file1
                file1 = auxFile; //file3
                reset_fita(file_vazio);
                
            }
            else if (tempc[1] == '\0')
            {
                // Acabou fita 2 e ainda tem resto na fita 1
                grava_char('\0', file_vazio);
                cont_compara[1] = 0;
                cont_compara[0]++;
                auxFile = file_vazio;
                file_vazio = file2;
                file2 = auxFile;
                reset_fita(file_vazio);
                
            }
            else
            {
                // O proximo char é um charactere
                cont_compara[0]++;
                cont_compara[1]++;

                grava_char('#', file_vazio);
            }
        }
        else
        {
            temp = menorValor(compara,cont_compara);
            if(temp == 3){
            	reset_fita(file1);
                reset_fita(file2);
            	break;
			}else{
            grava_char(compara[temp], file_vazio);
			
            cont_compara[temp]++;
			}
            
        }
    }
}