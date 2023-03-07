/******************** Presentacion ********************
[Nombre]: Garnica Escamilla Luis Javier.
[Fecha]: 02 de Marzo de 2023.
[Programa]: Actividad9.cpp 
Centro Universitario de los Altos.
Ingenieria en Comptuacion 2do Semestre.
[Profesor]: Franco Casillas Sergio.
[Descripcion]:  Este programa realiza 4 operaciones distintas con 2 matrices aleatorias 
 o proporcionadas por el usuario
******************************************************/
#include <stdlib.h>     //Gracias a esta libreria podremos utilizar el comando Srand(), el cual nos sirve para cambiar la semilla del programa
#include <iostream>     //Libreria estandar
#include "Javi.h"       //Libreria que cuenta con los comandos color() y gotoxy()

using namespace std;    //Referencia al marco de trabajo

/* Declarando una variable llamada tamano e inicializándola a 0, lo cual nos servira a manera de limite */
int tamano = 0;
/* Declarando 3 matrices de maximo 10x10. */
int matriza[20][20]; 
int matrizb[20][20];
int matrizr[20][20];
int matrizt[20][20];

/* Declarando el primer y unico void, llamado menu*/
void menu();

/* Esta libreria se encarga de la declaracion externa de las funciones*/
#include "Libreria9.cpp"

int main(){

    /* Limpiando la pantalla. */
    system("cls");

    /* Cambiando el color del texto. */
    color(14);
    printf("[Tama%co de las matrices cuadradas]: ", 164); 
    color(15);

    /* Comprobando si la entrada del usuario es válida. */
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

/**
 * Imprime un menú y, dependiendo de la elección del usuario, llama a otra función.
 * return sirve para regresar al main() sin ejecutar nada
 */
void menu(){
    system("cls");
    imprimir();
    int seleccion;

    /* Impresión de un menú para que el usuario seleccione una opción. */
    color(14);
    printf("\nQue deseas hacer?\t\t\t[Suma = 1]\t[Resta = 2]\t[Multiplicacion = 3]\t[Editar = 4]\n\t\t\t\t\t[Vaciar = 5]\t[LLenar al azar = 6]\t[Dividir = 7]\t[Salir = 0]\r[Seleccion]: ");
    /* Está comprobando si la entrada del usuario es válida. */
    if(!validate(scanf("%d",&seleccion))){
        system("pause");
        fflush(stdin);
        system("cls");
        imprimir();
        menu();
    }
    /* Una declaración de cambio que se utilizará para determinar lo que el usuario quiere hacer. */
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
            /* Borrar la pantalla, vaciar las matrices, imprimir las matrices y llamar a la función de menú. */
            fflush(stdin);
            vaciar();
            system("cls");
            imprimir();
            menu();
            break;
        case 6:
            /* Llama a la función `llenar()` llena las matrices con números aleatorios, limpia la pantalla, imprime las matrices 5y llamando a la función
            `menu()` que está imprimiendo el menú. */
            llenar();
            system("cls");
            imprimir();
            menu();
            break;
        case 7:
            /* Borrar la pantalla, vaciar el búfer de entrada y llamar a la función `dividir()`. */
            system("cls");
            fflush(stdin);
            dividir();
            break;
        case 0:
            /* Vaciar el búfer de entrada. */
            fflush(stdin);
            return;
            break;
        default:
            /* Está imprimiendo un mensaje, esperando que el usuario presione una tecla, limpiando la
            pantalla, imprimiendo las matrices y llamando a la función del menú. */
            printf("Imprime un valor valido, porfavor\n\n");
            system("pause");
            fflush(stdin);
            system("cls");
            imprimir();
            menu();
            break;
    }
    if(seleccion == 0){
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