/******************** Presentacion ********************
[Nombre]: Garnica Escamilla Luis Javier.
[Fecha]: 09 de Febrero de 2023.
[Programa]: Actividad6.cpp 
Centro Universitario de los Altos.
Ingenieria en Comptuacion 2do Semestre.
[Profesor]: Franco Casillas Sergio.
[Descripcion]:  Este programa realiza 4 operaciones distintas con 2 matrices aleatorias 
 o proporcionadas por el usuario
******************************************************/
#include <stdlib.h>     //Gracias a esta libreria podremos utilizar el comando Srand(), el cual nos sirve para cambiar la semilla del programa
#include <iostream>     //Libreria estandar
#include "Javi.h"

using namespace std;

/* Declarando una variable llamada tamano e inicializándola a 0, lo cual nos servira a manera de limite */
int tamano = 0;
/* Declarando 3 matrices de maximo 10x10. */
int matriza[10][10]; 
int matrizb[10][10];
int matrizr[10][10];
int matrizt[10][10];

void menu();

#include "Libreria9.cpp"

int main(){
    /* Aleatorizacion de la semilla para el generador de números aleatorios. */
    system("cls");

    color(14);
    printf("[Tama%co de las matrices cuadradas]: ", 164); 
    color(15);
    if(!(validate(scanf("%d",&tamano))) or (tamano > 12 or tamano < 2 )){
        system("pause");
        system("cls");
        main();
    }
    system("cls");
    
    llenar();
    menu();
   
    
    system("pause");
    return 0;
}

void menu(){
    system("cls");
    imprimir();
    int seleccion;

    /* Impresión de un menú para que el usuario seleccione una opción. */
    color(14);
    printf("\nQue deseas hacer?\t\t\t[Suma = 1]\t[Resta = 2]\t[Multiplicacion = 3]\t[Editar = 4]\n\t\t\t\t\t[Vaciar = 5]\t[LLenar al azar = 6]\t[Dividir = 7]\t[Salir = 0]\r[Seleccion]: ");
    if(!validate(scanf("%d",&seleccion))){
        system("pause");
        fflush(stdin);
        system("cls");
        imprimir();
        menu();
    }
    switch(seleccion){
        case 1:
            fflush(stdin);
            adicion(1);             //Suma
            break;
        case 2:
            fflush(stdin);
            adicion(2);             //Resta
            break;
        case 3:
            fflush(stdin);
            multiplicar();
            break;
        case 4:
            fflush(stdin);
            editar();
            break;
        case 5:
            fflush(stdin);
            vaciar();
            system("cls");
            imprimir();
            menu();
            break;
        case 6:
            llenar();
            system("cls");
            imprimir();
            menu();
            break;
        case 7:
            system("cls");
            fflush(stdin);
            dividir();
            break;
        case 0:
            fflush(stdin);
            break;
        default:
            printf("Imprime un valor valido, porfavor\n\n");
            system("pause");
            fflush(stdin);
            system("cls");
            imprimir();
            menu();
            break;
    }
    if((seleccion == 0) or (seleccion == 7)){
        return;
    }else{
        system("cls");
        imprimir();
        resultado();
        fflush(stdin);
        system("pause");
        menu();
    }
}

