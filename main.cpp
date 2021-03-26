#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <list>

/*Equipe: 
Rodrigo Cunha da Silva Franco
Marcos Vinicius Leal Machado
Antonio Cesar Nunes de Azevedo Filho
Amanda Bandeira Rigaud Lima
Felipe Azevedo Ribeiro
*/

// ENTRADA: I N T E R C A L A C A O B A L A N C E A D A

void reset_fita(std::string file_name)//vai criar as fitas no inicio e ou limpalas caso existam
{
    std::ofstream arquivo;
    arquivo.open(file_name.c_str(), std::ios::trunc);
    arquivo.close();
}

void bubble_sort(char *v, int quant)//vai ordenar
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

int trocaFile(std::string &file_name)//vai ficar alternando as fitas
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

int getInput(char *input)//ira pegar a entrada do teclado e retornar o seu tamanho
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

int trocar_bloco(int *cont_especial, std::list<char> &bloco, std::string &file_name, char *heap)//ira realizar a troca de bloco 
{
    if ((cont_especial[0] == 1) && (cont_especial[1] == 1) && (cont_especial[2] == 1))//se todos os cont_especial for 1 ira ocorrer a troca de bloco
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
    //retorna indice com menor valor, e ou retorna o caracter se a comparacao ocorrer entre um \0 ou um #
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

void heap_sort(std::list <char> &bloco, char *heap,int indice,int *cont_especial,int tam,char *input,std::string &file_name){
	char aux;

	for (int i = 0; i <=tam; i++)//inicio do heap sort
    {

        if(i<tam){
		bloco.push_back(heap[0]);//adicionando a posicao 0 do heap no bloco
		}
        aux = heap[0];
        heap[0] = input[indice];
        indice++;

        if (aux > heap[0])//compacao se o caracter que saiu e maior que o que entrou
        {

            if (cont_especial[2] == 0)//analisando os caracteres especiais
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
            else if (cont_especial[1] == 0)//analisando caracteres especiais
            {
                aux = heap[0];
                heap[0] = heap[1];
                heap[1] = aux;
                cont_especial[1]++;
            }
            else if (cont_especial[0] == 0)//analisando caracteres especiais
            {
                cont_especial[0]++;
            }
        }
        else//se o caracter que saiu for menor ou igual do que o que entrou
        {

            if (cont_especial[2] == 0)//se os 3 caracteres ainda sao normais
            {
                bubble_sort(heap, 3);
            }
            else if (cont_especial[1] == 0)//se so possui 2 caracteres normais
            {
                if (heap[0] > heap[1])
                {
                    aux = heap[0];
                    heap[0] = heap[1];
                    heap[1] = aux;
                }
            }
        }

        trocar_bloco(cont_especial, bloco, file_name, heap);//quando todos os cont_especial forem igual a 1 ira ocorrer uma mudanca de bloco
    }
}

void interacao_polifasica(char *compara, std::string &file1, std::string &file2, std::string &file_vazio, int *cont_compara){
	char tempc[2];
	int temp;
	std::string auxFile;
	while (1)
    {
        
        	compara[0] = ler_caracter(file1, cont_compara[0]);
        	compara[1] = ler_caracter(file2, cont_compara[1]);
		
        	
        if (compara[0] == '#' && compara[1] == '#')
        {

            // O proximo valor poderá ser outro char ou um \0
            tempc[0] = ler_caracter(file1, cont_compara[0] + 1);
            tempc[1] = ler_caracter(file2, cont_compara[1] + 1);

            if (tempc[0] == '\0' && tempc[1] == '\0')//se entrar ira terminar o programa
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
                auxFile = file_vazio; //processo de troca de fitas
                file_vazio = file1; 
                file1 = auxFile; 
                reset_fita(file_vazio);
                
            }
            else if (tempc[1] == '\0')
            {
                // Acabou fita 2 e ainda tem resto na fita 1
                grava_char('\0', file_vazio);
                cont_compara[1] = 0;
                cont_compara[0]++;
                auxFile = file_vazio; //processo de troca de fitas
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
        else // os valores sao diferentes de #
        {
            temp = menorValor(compara,cont_compara);
            if(temp == 3){//se for igual a 3 vai escerrar o codigo
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

int main(void)
{
    char input[27], heap[3], compara[2];
    int indice = 3, cont_especial[3] = {0, 0, 0} , cont_compara[2] = {0, 0}, tam, temp;
    //cont_especial serve para identificar quais os caracters marcados
    std::list<char> bloco;
    std::string file_name = "fita1.txt";
    std::string auxFile, file1, file2, file_vazio;
	
    // Resetando as fitas
    reset_fita("fita1.txt");
    reset_fita("fita2.txt");
    reset_fita("fita3.txt");

    tam = getInput(input);//obtendo a entrada e o tamanho do input
	
    heap[0] = input[0];
    heap[1] = input[1];
    heap[2] = input[2];

    bubble_sort(heap, 3);//organizando a primeiro heap

    //guardou no bloco
    heap_sort(bloco,heap,indice,cont_especial,tam,input,file_name);//ordenacao de blocos

    grava_char('\0', "fita1.txt");
    grava_char('\0', "fita2.txt");

    // Início da interação polifásica
    file1 = "fita1.txt";
    file2 = "fita2.txt";
    file_vazio = "fita3.txt";
    
    interacao_polifasica(compara,file1,file2,file_vazio,cont_compara);//interacao polifasica

}