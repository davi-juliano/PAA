#include <stdio.h>
#include <stdlib.h>

int caminho_maximo(int v[], int n){ //Verifica dois a dois no vetor qual é o índice do maior valor
    int i = 0, m = 0;
    for(i=0; i<n; i++){
        if(v[i]>v[m])
            m = i;
    }
    return m;
}

int percorre_matriz(int matriz[][12], int x, int y, int movimento[][2], int n){
    int caminhos[8];
    int i=0, x1=0, y1=0;
    matriz[x][y] = 2;
    
    for (i = 0; i < 8; i++){
        x1 = x + movimento[i][0];
        y1 = y + movimento[i][1];
        if(x1>0 && y1>0 && x1<=n && y1<=10 && matriz[x1][y1]==1){ //Verifica se é um caminho factivel
            caminhos[i] = percorre_matriz(matriz,x1,y1,movimento,n); //Chama a função novamente, partindo do ponto factível
        }
        else{
            caminhos[i] = 0;
        }
    }
    
    matriz[x][y] = 1;
    i = caminho_maximo(caminhos,8); //Chama a função que verifica qual é o maior caminho, dos caminhos factíveis
    i = caminhos[i]+1;
    return i;
}

int main(){
    int n = 0, i = 0, j = 0, a,b, t = 0;
    scanf("%d",&n);

    int matriz[12][12], movimentos[8][2];

    for(i=1; i<=n; i++){
        scanf("%d",&a);
        scanf("%d",&b);
        for(j=a+1; j<=a+b; j++){
            matriz[i][j] = 1;
            t+=1; // Valores totais sobre o espaço de soluções
        }
    }

    //Possíveis movimentos do cavalo, visto que trabalha com o canônico de cada coordenada dada.
    movimentos[0][0] = -2;  //(x-2,y-1), na coordenada de x 
    movimentos[0][1] = -1;  //(x-2,y-1), na coordenada de y
    movimentos[1][0] = -1;  //(x-1,y-2), na coordenada de x
    movimentos[1][1] = -2;  //(x-1,y-2), na coordenada de y
    movimentos[2][0] = 1;   //(x+1,y-2), na coordenada de x
    movimentos[2][1] = -2;  //(x+1,y-2), na coordenada de y
    movimentos[3][0] = 2;   //(x+2,y-1), na coordenada de x
    movimentos[3][1] = -1;  //(x+2,y-1), na coordenada de y
    movimentos[4][0] = -2;  //(x-2,y+1), na coordenada de x
    movimentos[4][1] = 1;   //(x-2,y+1), na coordenada de y
    movimentos[5][0] = -1;  //(x-1,y+2), na coordenada de x
    movimentos[5][1] = 2;   //(x-1,y+2), na coordenada de y
    movimentos[6][0] = 1;   //(x+1,y+2), na coordenada de x
    movimentos[6][1] = 2;   //(x+1,y+2), na coordenada de y
    movimentos[7][0] = 2;   //(x+2,y+1), na coordenada de x
    movimentos[7][1] = 1;   //(x+2,y+1), na coordenada de y

    int m = 0;
    m =  percorre_matriz(matriz,1,1,movimentos,n);
    printf("%d\n",(t-m));

    return 0;
}