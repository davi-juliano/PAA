#include <string.h>
#include <stdio.h>
#include <math.h>

int main(){
    long long int x, y, i, soma=0, numaux=0, numero=0,formula=0, j=0, iteracoes1=0, iteracoes2=0, aux, qnt_it2;
    
    scanf("%lld %lld", &x, &y);
    
    numaux=x;
    while(numaux>0){
        if((int)numaux%2 == 1)
            soma++;
        numaux = numaux/2;
        j++;
    }
    iteracoes1=j;
    numero = x+1;
    
    while(j==iteracoes1){
        numaux = numero;
        j=0;
        while(numaux>0){
            if((int)numaux%2 == 1)
                soma++;
            numaux = numaux/2;
            j++;
        }
		numero++;
    }
    iteracoes1++;

    j=0;
    numaux=y;
    while(numaux>0){
        if((int)numaux%2 == 1)
            soma++;
        numaux = numaux/2;
        j++;
    }
    iteracoes2=j;
    numero = y-1;
    
    while(j==iteracoes2){
        numaux = numero;
        j=0;
        while(numaux>0){
            if((int)numaux%2 == 1)
                soma++;
            numaux = numaux/2;
            j++;
        }
		numero--;
    }
    iteracoes2--;
    
    qnt_it2 = iteracoes2;
    soma =  soma - (qnt_it2+1);
    
    for(i=iteracoes1;i<=iteracoes2;i++){
        formula = pow(2,(i-1)) + (pow(2,(i-1))*(i-1)/2);
		soma = soma + formula;
    }

    printf("%lld", soma);

    return 0;
}