#include <iostream>

using namespace std;

double potencia(int x, int y);
double potenciaddos(int x, int y);
int factorial(int n);
int factorialrec(int n);

int main(){
    double potenciado = factorialrec(10);

    printf("%f",potenciado);   
}

double potencia(int x, int y){
    double resultado = 1;
    for(int i = 1;i <= y;i++){
        resultado = resultado * x;
        printf("a\n");
    }
    return resultado;
}

double potenciaddos(int x, int y){
    if(y == 0){
        return 1;
    }else{
        return x*(potenciaddos(x,y-1));
    }
}

int factorial(int n){
    int fact = 1;
    for(int i = 1; i<=n;i++){
        fact = i * fact;
    }
    return fact;
}

int factorialrec(int n){
    if(n == 0){
        return 1;
    }else{
        return factorial(n-1)*n;
    }
}