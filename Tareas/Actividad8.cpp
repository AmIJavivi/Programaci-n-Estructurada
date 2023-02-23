/******************** Presentacion ********************
[Nombre]: Garnica Escamilla Luis Javier.
[Fecha]: 30 de Enero de 2023.
[Programa]: Actividad4.cpp 
Centro Universitario de los Altos.
Ingenieria en Comptuacion 2do Semestre.
[Profesor]: Franco Casillas Sergio.
[Descripcion]:  Este programa calcula la serir de fibonacci hasta el "N" termino, utilizando
 el ciclo basico que el usuario prefiera.
******************************************************/
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;
 
/**
 * Este comando sirve especificamente para cambiar el color de la consola
 */
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

char arreglo1[10][40];
char arreglo2[10][40]; 
char arreglo3[20][40];
int posicion1, posicion2 = 0;

#include "Mylibrary.cpp"

/* Un menú que llama a otras funciones. Puede utilizar el parámetro "selección", la opción que el
usuario eligió. */
void menu(int seleccion, int arreglodes);

int main(){
    int seleccion, arreglodes, booltemp = 0;

    posto0();
    printscreen();

    printf("Que deseas hacer?\n\n[Borrar = 1]\t[Editar = 2]\t[Pasar = 3]\t[Ir a la posicion n = 4]\t");
    SetConsoleTextAttribute(hConsole, 9);
    printf("[Vaciar el arreglo = 5]\n\n\t\t\t\t\t\t[Operaciones = 6]\t\t[Salir = 0]");
    SetConsoleTextAttribute(hConsole, 15);
    printf("\r[Seleccion]: ");
    if(!validate(scanf("%d",&seleccion))){
        printf("%d",seleccion);
        fflush(stdin);
        main();
    }
    printf("[Arreglo]: ");
    if(!validate(scanf("%d",&arreglodes))){
        printf("%d",arreglodes);
        fflush(stdin);
        main();
    }else{
        menu(seleccion, arreglodes);
    }

    system("pause");
    main();
    
    system("pause");
}

void menu(int seleccion, int arreglodes){
    switch(seleccion){
        case 0:
            printf("Gracias, vuelva pronto :)\n\n");
            system("pause");
            break;
        case 1:
            fflush(stdin);
            inserttoarr(arreglodes,true);
            break;
        case 2:
            fflush(stdin);
            inserttoarr(arreglodes,false);
            break;
        case 3:
            passin(arreglodes);
            fflush(stdin);
            break;
        case 4:
            gotoarr(arreglodes);
            fflush(stdin);
            break;
        case 5:
            fflush(stdin);
            cleanarr(arreglodes);
        case 6:
            printf("\n\n*Union*\n\n");
            unir();
            printf("\n\n*Inteseccion*\n\n");
            interseccion();
            printf("\n\n*Diferencia*\n\n");
            diferencia();
            printf("\n\nComplemento\n\n");
            complemento();
            fflush(stdin);
            break;
        default:
            fflush(stdin);
            main();
    }
}