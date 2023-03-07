/******************** Presentacion ********************
[Nombre]: Garnica Escamilla Luis Javier.
[Fecha]: 30 de Enero de 2023.
[Programa]: Actividad4.cpp 
Centro Universitario de los Altos.
Ingenieria en Comptuacion 2do Semestre.
[Profesor]: Franco Casillas Sergio.
[Descripcion]:  Este programa permitira crear un vector de n cantidad de terminos, llenarlo al azar o manualmente,
                ordenarlo y finalmente buscar un valor en el.
******************************************************/
#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

int arreglo[51];
int tamano, posicion = 0;
bool asignado = false;
/**
 * Este comando sirve especificamente para cambiar el color de la consola
 */
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void menu(int seleccion);

#include "Libreria10.cpp"

/**
 * Le pregunta al usuario el tamaño de la matriz, luego le pregunta al usuario los valores de la
 * matriz o en su defecto la llena al azar, luego le pregunta al usuario qué quiere hacer con la matriz.
 */
int main(){
    int seleccion;

    system("cls");
    
    /* Comprobando si la variable `asignado` es falsa, si lo es, le pedirá al usuario el tamaño de la
    matriz. */
    if(asignado == false){
        printf("[Tama%co]: ",164);
        if(esvalido(scanf("%d", &tamano)) and tamano <= 50){
            asignado = true;
        }else{
            main();
        }
    }
    posto0();
    
    imprimir();
    
    color(15);
    printf("\n\nQue deseas hacer?\n\n[Llenar manualmente= 1]\t[Llenar al azar = 2]\t[Vaciar el arreglo = 3]\n\n\t\t\t[Ordenar = 4]\t\t[Buscar = 5]\t[Salir = 0]");
    printf("\r[Seleccion]: ");
    
    /* Está verificando si la entrada del usuario es válida, si lo es, llamará a la función `menu()`
    con la entrada del usuario como parámetro, si no lo es, llamará a la función `main()`
    nuevamente. */
    if(!esvalido(scanf("%d",&seleccion))){
        main();
    }else if(seleccion == 0){
        system("pause");
        abort();
    }else{
        menu(seleccion);
    }
}

/**
 * Una función que toma un número entero como argumento y llama a la funcion especificada en el switch.
 * seleccion es el número de la opción que el usuario seleccionó.
 */
void menu(int seleccion){
    int numerobuscado;
    fflush(stdin);

    /* Una declaración de cambio que toma la entrada del usuario y llama a la función especificada en
    el cambio. */
    switch(seleccion){
        case 1:
            posicion = 0;
            editar(false);
            break;
        case 2:
            editar(true);
            break;
        case 3:
            vaciar();
            break;
        case 4:
            /* Preguntar al usuario qué método de ordenamiento quiere usar. */
            switch(seleccionord()){
                case 1:
                    burbuja();
                    break;
                case 2:
                    quicksort(0, tamano-1);
                    break;
            }
            break;
        case 5:
            printf("[Numero]: ");
            /* Comprobando si la entrada del usuario es válida, si lo es, llamará a la función
            `busquedabin()` con la entrada del usuario como parámetro, si no, llamará de nuevo a la
            función `menu()` con el número 5 como parámetro.*/
            if(esvalido(scanf("%d",&numerobuscado))){
                busquedabin(numerobuscado);
                system("pause");
            }else{
                system("cls");
                imprimir();
                menu(5);
            }
            break;
        default:
            break;
    }
    main();
}