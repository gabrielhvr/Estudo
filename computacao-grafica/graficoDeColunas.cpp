// O QUE FALTA:
//
// BOTAR TÍTULO/LEGENDA NO GRAFICO
// INFORMAÇÕES EXTRAS (mais sorteados, menos sorteados)
// CORRIGIR FUNÇÃO DO IDX DOS MAIORES VALORES


// INFORMAÇÕES IMPORTANTES:
// 
// N° 0 NÃO PODE SER JOGADO, POR ISSO NÃO FOI UTILIDO NOS ARRAYS
// SE VC QUISER 20 IDX NO GRAFICO, BOTAR 21 JÁ QUE O 0 É DESCONSIDERADO

// TESTAR:
// 
// NA FUNCAO IDX, AO INVES DE PASSAR 3 FUNCOES,
// PASSAR SOMENTE MAIN E IDX, E CRIAR COPIA SORTED
// DENTRO DA FUNCAO IDX

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstdio>

int i = 0, j = 0, temp = 0;
const int TAMANHO = 21;
int mapa[TAMANHO];
time_t t;

void printArray(int l[TAMANHO]) { // printa valores de um array
	
	for (i = 0; i < TAMANHO; i++) {
	
		printf("%d\n", l[i]);
	
	}  
	
}

int copyArray(int l[TAMANHO], int l2[TAMANHO]) { // cria a copia de uma array
	
	for (i = 0; i < TAMANHO; i++) {
		
		l2[i] = l[i];
		
	}
	
	return l2[TAMANHO];
	
}

int valueDescendingSort(int l[TAMANHO]) { // vai ordenar os valores de idx 1 a 60 de forma decrescente
	
	for(i = 1; i < TAMANHO - 1; i++) {
	
		for(j = i + 1; j < TAMANHO; j++) {
	
			if (l[j] > l[i]) {
			
				temp = l[i];
				l[i] = l[j];
				l[j] = temp;
			
			}
		}                                            
		                                  
	}
	
	return l[TAMANHO];
	
	
} 

int idxDescendingSort(int sortedValues[TAMANHO], int mapa[TAMANHO], int idxSorted[TAMANHO]) { // incompleta:
																		// em caso de valores repetidos não funciona  
																		// a funão seria ordenar os idx, com base no valor delas
	int comp = 0;
	bool encontrou = false;
	
	for (i = 1; i < TAMANHO; i++) {
		
		
		for (j = 1; encontrou != true; j++) {
			
			encontrou = sortedValues[i] == mapa[j];
			
		}
		
		idxSorted[i] = j - 1;
		encontrou = false;
		
	}
	
	return idxSorted[TAMANHO];
	
}

int maxMapValue(int l[TAMANHO]) { 
	
	int maxValue = 0;
	
	for(i = 1; i < TAMANHO - 1; i++) {
	
		if (l[i] > maxValue) {
			
			maxValue = l[i];
			
		}                                
		                                  
	}
	
	return maxValue;
	
	
} 

void printGraph (int mapa[TAMANHO]) { // vai receber um array que representa cada número e sua frequência
									// Ex: mapa[5] armazena o int 10, quer dizer que 5 aparece 10 xs
	
	int maxValue = maxMapValue(mapa);
	
	// imprime colunas 
	
	for (i = maxValue; i > 0; i--) {
		
		printf("%2d  |", i);
		
		for (j = 1; j < TAMANHO; j++) {
			
			if (mapa[j] >= i) {
				
				printf("  %c%c", 219, 219);
				
			} else {
				
				printf("    ");
				
			}
			
		}
		
		printf("\n");
		
	}
	
	
	// imprimir linha horizintal
	printf("--------");
	for (i = 1; i < TAMANHO; i++) {
		
		printf("----");
		
	}
	
	// imrprime idx (números sorteados)
	
	printf("\n    |");
	
	for (i = 1; i < TAMANHO; i++) {
		
		printf("  %2d", i);
		
	} 
	
}

int main(){
	
	// definindo valores aleatórios para um array
	
	srand((unsigned) time(&t));

	for (i = 1; i < TAMANHO; i++) {
	
		mapa[i] = (rand() % 21);
	
	}
        
	// criando uma cópia do mapa e ordenando ela
	int sortedValues[TAMANHO];
	copyArray(mapa, sortedValues);
	valueDescendingSort(sortedValues);
	
	// não está funcionando
	int idxSorted[TAMANHO];
	copyArray(mapa, idxSorted);
	idxDescendingSort(sortedValues, mapa, idxSorted);

	printArray(mapa);
	
	printf("-----------------------------\n");
	
	printArray(sortedValues);
	
	printf("-----------------------------\n");
	
	printf("%d\n", maxMapValue(mapa));

	printf("-----------------------------\n");
	
	printGraph(mapa);
	
	
}
