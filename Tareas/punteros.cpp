#include <iostream>

using namespace std;

void modificar_p(int * direccion);

int main(){
    int valor_p = 900;
    int * puntero_p = &valor_p;

    printf("valor:%d \t\t ubicacion:%8p\n",valor_p,puntero_p);
    modificar_p(&valor_p);
    printf("\n\nvalor:%d \t\t ubicacion:%8p\n",valor_p,puntero_p);

    system("pause");
}

void modificar_p(int *direccion){
    int modificar_x = 90;

    printf("\n[Anadir a valor]: 90");

    *direccion = *direccion + modificar_x;
}