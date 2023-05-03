#include <iostream>

using namespace std;

int modificar_p(int valor);

int main(){
    int valor_p = 900;
    int * puntero_p = &valor_p;

    printf("valor:%d \t\t ubicacion:%8p\n",valor_p,puntero_p);

    valor_p = modificar_p(valor_p);
    puntero_p = &valor_p;

    printf("\n\nvalor:%d \t\t ubicacion:%8p\n",valor_p,puntero_p);

    system("pause");
}

int modificar_p(int valor){
    int modificar_x = 90;

    printf("\n[Anadir a valor]: 90");
    
    return modificar_x + valor;
}