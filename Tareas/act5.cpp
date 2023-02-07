#include <iostream>

using namespace std;

int arreglo[10];
int posicion = 0;

void vaciar();
void imprimir();

int main(){
    int seleccion = 0;
    
    imprimir();

    
    printf("Estas en la posicion %d del arreglo, que deseas hacer?\n\n\t\t\t\t\t\t[Borrar = 2]\t[Escribir = 3]\t[Pasar = 4]\t[Vaciar el arreglo = 1][Seleccion]: ", posicion);
    scanf("%d",&seleccion);
    
    switch(seleccion){
    case 1:
        vaciar();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        fflush(stdin);
        main();
    }

    return 0;
}

void vaciar(){
    int contador = 0;

    while(contador != 10){
        arreglo[contador] = 0;
        printf("%d",arreglo[contador]);
        contador++;
        system("pause");
    }
}

void imprimir(){
    int contador = 0;

    while(contador != 10)
    {
        printf("[%d] ", arreglo[contador]);
        contador++;
    }
    printf("\n\n\n");
}
