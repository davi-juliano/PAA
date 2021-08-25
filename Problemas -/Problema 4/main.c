#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c){ //Funcão de verificar o mínimo entre três valores
    if(a <= b && a <= c){
		return a;
	}
	else if(b <= a && b <= c){
		return b;
	}
	else if(c <= a && c <= b){
		return c;
	}
}

int distance(char *string1, char *string2){
    int n = strlen(string1); //Tamanho da primeira string
    int m = strlen(string2); //Tamanho da segunda string
    int i, j, aux2, aux1;
    
    int *vetor = (int*) calloc((n+1),sizeof(int)); //O vetor de subscrição da matriz da quantidade de trocas
    
    for (j=1; j<=n; j++){ //Inicialização do vetor
        vetor[j] = j;
    }
    for(i=1; i<= m; i++) {
        vetor[0] = i;
        for (j=1, aux2 = i-1; j<=n; j++){
            aux1 = vetor[j]; // Coluna anterior do vetor na posição antiga
            vetor[j] = min(vetor[j] + 1, vetor[j-1] + 1, aux2+(string1[j-1] == string2[i-1] ? 0 : 1)); //Preenchimento com o valor mínimo de trocas nas três possibilidades
            aux2 = aux1; // Subscrição da última coluna pela coluna anterior 
        }
    }
    return vetor[n];
}

int main(){
  char *string1 = (char*)calloc(10000, sizeof(char));
  char *string2 = (char*)calloc(10000, sizeof(char));

  fgets(string1, 10000, stdin);
  fgets(string2, 10000, stdin);
  
  int i = distance(string1, string2);
  
  printf("%d\n", i);
  
  return 0;
}