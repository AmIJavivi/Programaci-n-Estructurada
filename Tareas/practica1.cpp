#include <iostream>
#include <stdlib.h>

using namespace std;

const int n = 2;

void llenar(int ar[][n], int tam);
void printx(int ar[][n], int tam);

int main(){
    srand((unsigned)time(NULL));
    int mat[n][n];

    llenar(mat,n);
    printx(mat,n);
}

void llenar(int ar[][n], int tam){
    for(int f = 0; f < tam; f++){
        for(int c = 0; c<tam;c++){
            ar[f][c] =- 100 + rand()%300;

        }
    }
}

void printx(int ar[][n], int tam){
    for(int f = 0; f < tam; f++){
        for(int c = 0; c<tam;c++){
            cout<<"["<<ar[f][c]<<"]"<<endl;
        }
    }
}