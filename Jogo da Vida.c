#include<stdio.h>
#include<stdlib.h>

GerarAleatorio(int **mat1, int linha, int coluna){
// Preenchendo a Matriz com 0 e 1
    int  i,j;
    srand(time(NULL));
    for (i=1;i<linha-1;i++) {
        for (j=1;j<coluna-1;j++) {
            mat1[i][j]=rand()%2;
        }
    }
}

ZerarMatriz(int **mat1,int **mat2,int **mat3, int linha, int coluna){
//Zera as tres natrizes para nao ter lixo
    int  i,j;
    for (i=0;i<linha;i++) {
        for (j=0;j<coluna;j++) {
            mat1[i][j]=0;
            mat2[i][j]=0;
            mat3[i][j]=0;
        }
    }
}

ComparacaoMatUmComMatTres(int **mat1,int **mat3, int linha, int coluna){
// mat3 recebe m1 para poder comparar
    int  i,j;
    for (i=1;i<linha-1;i++) {
        for (j=1;j<coluna-1;j++) {
            mat3[i][j] = mat1[i][j];
        }
    }
    printf("\n");
}

ContarVizinhos(int **mat1,int **mat2, int linha, int coluna){
//FUNÇÂO contar vizinhos
    int  i,j;
    for (i=1;i<linha-1;i++){
              for (j=1;j<coluna-1;j++){
                    if (mat1[i-1][j-1]==1)
                        mat2[i][j]++;
                    if (mat1[i-1][j]==1)
                        mat2[i][j]++;
                    if (mat1[i-1][j+1]==1)
                        mat2[i][j]++;
                    if (mat1[i][j-1]==1)
                        mat2[i][j]++;
                    if (mat1[i][j+1]==1)
                        mat2[i][j]++;
                    if (mat1[i+1][j-1]==1)
                        mat2[i][j]++;
                    if (mat1[i+1][j]==1)
                        mat2[i][j]++;
                    if (mat1[i+1][j+1]==1)
                        mat2[i][j]++;
              }
    }
}

RegrasDoJogo(int **mat1,int **mat2, int linha, int coluna){
//Criando estruturas condicionais para as regras do jogo
    int  i,j;
    for (i=1;i<linha-1;i++) {
        for (j=1;j<coluna-1;j++) {
            if(mat1[i][j]==1){
               if((mat2[i][j]>3) || (mat2[i][j]<2))
                  mat1[i][j]=0;
            }
            if(mat1[i][j]==0){
               if(mat2[i][j]==3)
                  mat1[i][j]=1;
            }
        }
    }
}

AtualizacaooDeMatrizes(int **mat1, int **mat3, int linha, int coluna){
// FUNÇÃO parada da atualização
//Contador para parar o do/while, para não entrar num loop infinito
    int  i,j;
    int cont;
    for (i=1;i<linha-1;i++) {
        for (j=1;j<coluna-1;j++) {
           cont=0;
           if(mat1[i][j] != mat3[i][j]){
               cont=1;
            }
            if(cont == 1)
                return 1;
            else
                return 0;
            break;

        }
    }
    printf("\n");
}

ImprimeMatriz(int **mat1, int linha, int coluna){
//FUNÇÃO imprime jogo
//Imprime o Jogo!
    int  i,j;
    system("cls");
    printf("            JOGO DA VIDA");
    printf("\n");
    for (i=1;i<linha-1;i++){
           for (j=1;j<coluna-1;j++){
               if(mat1[i][j]==1)
                printf ("º");
               else
                printf (" ");
           }
        printf ("\n");
    }
}

CopiarMatriz(int **mat1,int **mat3, int linha, int coluna){
//FUNÇÃO copiar matriz
// Copia da matriz para comparar
    int  i,j;
    for (i=1;i<linha-1;i++) {
        for (j=1;j<coluna-1;j++) {
            mat3[i][j] = mat1[i][j];
        }
    }
}

ZerarMatDois(int **mat2, int linha, int coluna){
//FUNÇÃO zerar matriz
//Zerando a Matriz Contadora
    int  i,j;
    for (i=0;i<linha;i++) {
        for (j=0;j<coluna;j++) {
            mat2[i][j]=0;
        }
    }
}

IniciarJogo(int **mat1,int **mat2,int **mat3, int lin, int col){
//FUNÇÂO para inicio do jogo chamando outras funções
    do{
        ContarVizinhos(mat1, mat2, lin, col);
        RegrasDoJogo(mat1, mat2, lin, col);
        AtualizacaooDeMatrizes(mat1, mat3, lin, col);
        ImprimeMatriz(mat1, lin, col);
        CopiarMatriz(mat1, mat3, lin, col);
        ZerarMatDois(mat2, lin, col);
    //Condição para parar o jogo!
    }while (AtualizacaooDeMatrizes(mat1, mat3, lin, col) != 1);
}


main () {

int i, l, c;


printf("             JOGO DA VIDA");
printf("\n");
printf("\n");

printf("Digite o numero de linhas:");
scanf("%d", &l);
printf("Digite o numero de colunas:");
scanf("%d", &c);
printf("\n");

//Inseri outro system pause para aparecer o cabeçalho!
system("pause");

//Declarando ponteiro para ponteiro para fazer Alocação Dinâmica de Memória
int **mat1, **mat2, **mat3;

mat1=(int*)malloc(l*sizeof(int *));
for(i=0;i<c;i++){
    mat1[i] = (int*)malloc(c * sizeof(int));
}

mat2=(int*)malloc(l*sizeof(int *));
for(i=0;i<c;i++){
    mat2[i] = (int*)malloc(c * sizeof(int));
}

mat3=(int*)malloc(l*sizeof(int *));
for(i=0;i<c;i++){
    mat3[i] = (int*)malloc(c * sizeof(int));
}

ZerarMatriz(mat1, mat2, mat3, l, c);
GerarAleatorio(mat1, l, c);
ComparacaoMatUmComMatTres(mat1, mat2, l, c);

IniciarJogo(mat1, mat2, mat3, l, c);

system("pause");
}
