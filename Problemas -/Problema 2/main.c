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

/*
if (arr[0] > arr[1])
    {
        first = arr[0];
        second = arr[1];
    }
    else
    {
        first = arr[1];
        second = arr[0];
    }

*/


int encontra_soma(int arquivos[], int n, int c){
    
    int first, second, soma = 0, maior = 0, i;
    
    first = arquivos[1];
    second = arquivos[0];

    for (i = 2; i<n; i ++){
        
        if (arquivos[i] > first){
            second = first;
            first = arquivos[i];
            
            if((first + second) <= c){
                soma = second + first;
            }
        }
 
        else if (arquivos[i] > second && arquivos[i] != first){
            second = arquivos[i];  
            
            if((arquivos[i] + first) <= c){
                soma = second + first;
            }
        }
    }
    return soma;
}


int main(){
    int n, c, maior_valor, possivel, i, j ,soma=0;
    int arquivos[MAX];
    
    scanf("%d %d", &n, &c);
    
    for(i=0;i<n;i++){
        scanf("%d", &arquivos[i]);
    }
    
    MergeSort(arquivos, 0, n);

    /*for(i=1;i<n+1;i++){
        printf("%d ", arquivos[i]);
    }*/

    soma = encontra_soma(arquivos, n+1, c);


    if(soma != 0){
        printf("%d\n", soma);
    }
    if(soma == 0){
        printf("NONE\n");
    }    

    return 0;
}