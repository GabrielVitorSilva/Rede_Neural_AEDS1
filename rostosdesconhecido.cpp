#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
    
void calcularTransposta(double matriz[][10], double transposta[][4]);
void ProdCruzado(double matriz1[][10], double matriz2[][4], double produto[][4]);
void ProdCruzado3(double matriz1[][4], double matriz2[][1], double produto[][1]);
double ProdCruzado4(double matriz1[][4], double matriz2[][1]);

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
    
    // Criando uma matriz correspondente a um rosto desconhecido
    double x1[4][1] = {
        { 1},
        {-1}, 
        { 1},
        {-1}};
        
    double x1T[1][4];

    // Calculando a transposta de x1
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 1; j++) {
            x1T[j][i] = x1[i][j];
        }
    }

    double x1linha[4][1];
    
    // Calculando x1'
    ProdCruzado3(W, x1, x1linha);
    
    double x1linhaT[1][4];

    // Calculando x1'T
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 1; j++){
            x1linhaT[j][i] = x1linha[i][j];
        }
    }

    double numerador = ProdCruzado4(x1linhaT, x1);

    double primeiraRaiz = ProdCruzado4(x1linhaT, x1linha);

    primeiraRaiz = sqrt(primeiraRaiz);

    double segundaRaiz = ProdCruzado4(x1T, x1);

    segundaRaiz = sqrt(segundaRaiz);

    double denominador = primeiraRaiz * segundaRaiz;

    double precisao1 = numerador/denominador;

    cout << precisao1;
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

void ProdCruzado3(double matriz1[][4], double matriz2[][1], double produto[][1]){
    for(int i = 0; i < 4 ; i++){
        for(int j = 0; j < 1; j++){
            produto[i][j] = 0;
        }
    }

    for(int i = 0; i < 4 ; i++){
        for(int j = 0; j < 1; j++){
            for(int k = 0; k < 4; k++){
                produto[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

double ProdCruzado4(double matriz1[][4], double matriz2[][1]) {
    double produto = 0;
    
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 4; k++) {
                produto += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    return produto;
}
