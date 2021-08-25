#include <string.h>
#include <stdio.h>

int main(){
    int j=0;
    long long int x, y, i, soma=0, numaux=0;
    
    scanf("%lld %lld", &x, &y);
    
    for(i=x;i<=y;i++){ //Percorreremos o intervalo de valores entre x e y
        numaux=i;
        while(numaux>0){ //Utilizaremos o algoritmo de euclides pra tomar os valores na base 2
            if((int)numaux%2 == 1){
                soma++; //Tomo apenas os valores iguais a 1
            }
            numaux = numaux/2;
        }
		    
    }
    printf("%lld", soma); //Apresento a soma

    return 0;
}