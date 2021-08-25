#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 100000
 
void Merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1=0, fim2=0;
    tamanho = fim-inicio+1;
    p1=inicio;
    p2=meio+1;
    temp=(int*)malloc(tamanho*sizeof(int));
    if(temp!=NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2])
                    temp[i]=V[p1++];
                
                else
                    temp[i]=V[p2++];
                    
                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1)
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];
            }
        }
    for(j=0, k=inicio; j<tamanho; j++, k++)
        V[k]=temp[j];
        
    }
    free(temp);
}
 
void MergeSort(int *V, int inicio, int fim){  //Função do Prof. André Backes (prof da Ufu) com ordenação por MergeSort
    int meio;                           //Link da aula: https://www.youtube.com/watch?v=RZbg5oT5Fgw&list=PL8iN9FQ7_jt6H5m4Gm0H89sybzR9yaaka&index=51
    if(inicio<fim){
        meio=floor((inicio+fim)/2);
        MergeSort(V, inicio, meio);
        MergeSort(V, meio+1, fim);
        Merge(V, inicio, meio, fim); //Merge também é uma função do código do professor André
    }
}
 
int main(){
    int n, c, maior=0, i, j, k ,soma=0, possivel;
    int arquivos[MAX];
    
    scanf("%d %d", &n, &c);
    
    for(i=0;i<n;i++){
        scanf("%d", &arquivos[i]);
    }
    
    MergeSort(arquivos, 0, n-1); //aplica o merge para facilidades
    
    i=0;
    while(i < n && arquivos[i] < c){ //Itera em uma quantidade n, ou até o arq ser < c.
        j=i+1;
        while(j < n && arquivos[j] < c){
            soma = arquivos[i] + arquivos[j];
            if(soma > c){ //quebra o laco caso a soma dê maior que c.
                break;
            }
            if(soma > maior && soma < c){ //Guarda o maior para o caso de haver uma maior soma
                maior = soma;
            }
            if(soma > maior && soma == c){ //Se deu igual a c, qubra os dois lacos, e encontramos o valor ótimo.
                maior = soma;
                arquivos[i] = c; 
                break;
            }
            j++;
        }
        i++;
    }
    
    if(maior != 0){
        printf("%d\n", maior);
    }
    if(maior == 0){
        printf("NONE\n");
    }    
 
    return 0;
}