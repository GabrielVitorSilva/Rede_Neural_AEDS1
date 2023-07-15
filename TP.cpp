#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

void calcularTransposta(double matriz[][10], double transposta[][4]);

void ProdCruzado(double matriz1[][10], double matriz2[][4], double produto[][4]);

void ProdCruzado2(double matriz1[][4], double matriz2[][10], double produto[][10]);

int main()
{
    double W[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    double X[4][10] =  {
        { 1,-1,-1, 1,-1, 1, 1,-1,-1, 1},
        { 1,-1,-1,-1, 1,-1, 1,-1, 1, 1},
        { 1, 1,-1,-1,-1, 1, 1,-1, 1,-1},
        {-1,-1,-1, 1,-1, 1, 1, 1,-1, 1}};

    double XT[10][4];

    calcularTransposta(X, XT);

    // Estocando os rostos nas matrizes
    ProdCruzado(X, XT, W);

    double Xlinha[4][10];

    // Calculando X' para ser usado futuramente na formula do cosseno
    ProdCruzado2(W, X, Xlinha);

    double numeradores[10];

    // Zerando a matriz numeradores
    for (int i = 0; i < 10; i++)
    {
        numeradores[i] = 0;
    }

    // Obtendo e guardandos os valores da matriz numeradores
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            numeradores[j] = numeradores[j] + Xlinha[i][j] * X[i][j];
        }
    }

    double primeiraRaiz[10];

    // Zerando a matriz das primeiras raizes
    for (int i = 0; i < 10; i++)
    {
        primeiraRaiz[i] = 0;
    }

    // Obtendo e guardando os valores dos quadrados das primeira raizes
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            primeiraRaiz[j] = primeiraRaiz[j] + Xlinha[i][j] * Xlinha[i][j];
        }
    }

    // Calculando a raiz dos quadrados das primeiras raizes
    for (int i = 0; i < 10; i++)
    {
        primeiraRaiz[i] = sqrt(primeiraRaiz[i]);
    }

    double segundaRaiz[10];
    
    // Zerando a matriz das primeiras raizes
    for (int i = 0; i < 10; i++)
    {
        segundaRaiz[i] = 0;
    }

    // Obtendo e guardando os valores dos quadrados das segundas raizes
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            segundaRaiz[j] = segundaRaiz[j] + X[i][j] * X[i][j];
        }
    }

    // Calculando a raiz dos quadrados das primeiras raizes
    for (int i = 0; i < 10; i++)
    {
        segundaRaiz[i] = sqrt(segundaRaiz[i]);
    }

    double denominadores[10];

    // Multiplicando os valores da primeira raiz com a segunda raiz por meio da multiplicacao de Hadamard, obtendo os denominadores
    for (int i = 0; i < 10; i++)
    {
        denominadores[i] = primeiraRaiz[i] * segundaRaiz[i];
    }

    double precisoes[10];

    // Ao dividirmos os numeradores pelos denominadores, obtemos as precisoes para cada rosto
    for (int i = 0; i < 10; i++)
    {
        precisoes[i] = numeradores[i] / denominadores[i];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << setw(13) << precisoes[i];
    }

    

    return 0;
}

void calcularTransposta(double matriz[][10], double transposta[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            transposta[j][i] = matriz[i][j];
        }
    }
}

void ProdCruzado(double matriz1[][10], double matriz2[][4], double produto[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            produto[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                produto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void ProdCruzado2(double matriz1[][4], double matriz2[][10], double produto[][10])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            produto[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                produto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void ProdCruzado3(double matriz1[][4], double matriz2[][1], double produto[][1]){
    for(int i = 4; i < 4 ; i++){
        for(int j = 0; j < 1; j++){
            produto[i][j] = 0;
        }
    }

    for(int i = 4; i < 4 ; i++){
        for(int j = 0; j < 1; j++){
            for(int k = 0; k < 4; k++){
                produto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}