/* Importación de las bibliotecas `iostream` y `string.h` */
#include <iostream>
#include <string.h>

using namespace std;

char gato_matriz[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int puntos[3] = {0,0,0};
char nombres[3][20] = {"Jugador 1","Jugador 2","GATOBOT"};
bool asignado1, asignado2 = false;
int casillas = 0;

#include "libreria15.cpp"

int main(){
    /* Declarando una variable llamada `seleccion` de tipo `int`. */
    int seleccion;

    /* Una función que genera un número aleatorio. */
    srand((unsigned)time(NULL));

    /* Imprimiendo el menú. */
    printf("El Gato\n\n[Opciones]:\t\t\t\t[Puntuacion]\t[%s]: %d [%s]: %d [%s]: %d\n\t[1 = vs CPU]\n\t[2 = vs Jugador]\n\n[Seleccion]: ",nombres[0],puntos[0],nombres[1],puntos[1],nombres[2],puntos[2]);
    /* Comprobando si la entrada es un número y si está entre 1 y 2. */
    while(!scanf("%d",&seleccion) or !(1 <= seleccion and seleccion <= 2)){
        printf("[Seleccion Valida]: ");
        fflush(stdin);
    }

    fflush(stdin);
    
    /* Una declaración de cambio. */
    switch(seleccion){
        case 1:
            /* Comprobando si la variable `asignado1` es falsa. */
            if(!asignado1){
                printf("[Nombre Jugador 1]: ");
                gets(nombres[0]);
                fflush(stdin);   
                asignado1 = true;
            }
            /* Un bucle while que se ejecutará hasta que la función `vscpu()` devuelva un valor `true`. */
            while(!vscpu()){
            }
            break;
        case 2:
            /* Comprobando si la variable `asignado1` es falsa. */
            if(!asignado1){
                printf("[Nombre Jugador 1]: ");
                gets(nombres[0]);
                fflush(stdin);   
                asignado1 = true;
            }
            /* Comprobando si la variable `asignado2` es falsa. */
            if(!asignado2){
                printf("[Nombre Jugador 2]: ");
                gets(nombres[1]);
                fflush(stdin);   
                asignado2 = true;
            }
            /* Un ciclo while que se ejecutará hasta que la función `vsjugador()` devuelva un valor
            `true`. */
            while(!vsjugador()){
            }
            break;
    }
    llenar_gato(3);
    system("cls");
    main();
}