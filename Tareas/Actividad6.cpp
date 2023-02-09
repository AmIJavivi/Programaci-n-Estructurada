/******************** Presentacion ********************
[Nombre]: Garnica Escamilla Luis Javier.
[Fecha]: 09 de Febrero de 2023.
[Programa]: Actividad6.cpp 
Centro Universitario de los Altos.
Ingenieria en Comptuacion 2do Semestre.
[Profesor]: Franco Casillas Sergio.
[Descripcion]:  Este programa realiza 3 operaciones distintas con 2 matrices aleatorias 
 o proporcionadas por el usuario
******************************************************/
#include <stdlib.h>     //Gracias a esta libreria podremos utilizar el comando Srand(), el cual nos sirve para cambiar la semilla del programa
#include <iostream>     //Libreria estandar

using namespace std;

/* Declarando una variable llamada tamano e inicializándola a 0, lo cual nos servira a manera de limite */
int tamano = 0;
/* Declarando 3 matrices de maximo 10x10. */
int matriza[10][10]; 
int matrizb[10][10];
int matrizr[10][10];

/* Una función que imprime las matrices. */
void imprimir();
/* Llenar las matrices con números aleatorios. */
void llenar();
/* Una función que suma o resta dos matrices. */
void adicion(int seleccion);
/* Multiplicando las dos matrices. */
void multiplicar();
/* Imprimiendo el resultado de la operación. */
void resultado();
/* Una función que imprime un menú y le pide al usuario que seleccione una opción. */
void menu();
/* Una función que permite al usuario editar los valores de las matrices. */
void editar();

int main(){
    /* Aleatorizacion de la semilla para el generador de números aleatorios. */
    srand((unsigned)time(NULL));
    system("cls");


    /* Solicitar al usuario que ingrese el tamaño de la matriz + Validacion */
    printf("[Tama%co de las matrices cuadradas]: ", 164); 
    if(float(scanf("%d",&tamano))!= 1){
        system("cls");
        fflush(stdin);
        main();
    }
    system("cls");
    
    llenar();
    imprimir();
    menu();
    system("cls");
    imprimir();
    resultado();
    
    system("pause");
    return 0;
}

/**
 * Una función que se utiliza para editar el contenido de las matrices
 */
void editar(){
    int fila;
    int columna;
    int matriz;
    int valor;

  /* Solicitar al usuario que ingrese un valor y, si el valor no es un número, le pedirá al usuario que
  ingrese un número nuevamente. */
    printf("[Matriz]: ");
    if(float(scanf("%d",&matriz)) != 1){
        fflush(stdin);
        system("cls");
        imprimir();
        editar();
    }
   /* Comprobando si la entrada del usuario es válida. */
    if(matriz < 1 or matriz > 2){
        fflush(stdin);
        system("cls");
        imprimir();
        editar();
    }
   
    /* Un ciclo que seguirá pidiendo al usuario un valor hasta que el usuario ingrese un valor válido, en este caso filas*/
    while(true){
        printf("[Fila]: ");
        if(float(scanf("%d",&fila)) != 1){
            fflush(stdin);
            system("cls");
            imprimir();
            printf("[Matriz]: %d\n",matriz);
        }else if(fila < 0 or fila > tamano){
            fflush(stdin);
            system("cls");
            imprimir();
            printf("[Matriz]: %d\n",matriz);
        }else{
            break;
        }
        
    }

    /* Un ciclo que seguirá pidiendo al usuario un valor hasta que el usuario ingrese un valor válido, en este caso columnas*/
    while(true){
        printf("[Columna]: ");
        if(float(scanf("%d",&columna)) != 1){
            fflush(stdin);
            system("cls");
            imprimir();
            printf("[Matriz]: %d\n",matriz);
            printf("[Fila]: %d\n",fila);
        }else if(columna < 0 or columna > tamano){
            fflush(stdin);
            system("cls");
            imprimir();
            printf("[Matriz]: %d\n",matriz);
            printf("[Fila]: %d\n",fila);
        }else{
            break;
        }
    }
     /* Un ciclo que seguirá pidiendo al usuario un valor hasta que el usuario ingrese un valor válido, en este caso el valor final*/
    while(true){
        printf("[Valor]: ");
        if(float(scanf("%d",&valor)) != 1){
            fflush(stdin);
            system("cls");
            imprimir();
            printf("[Matriz]: %d\n",matriz);
            printf("[Fila]: %d\n",fila);
            printf("[Columna]: %d\n",columna);
        }else{
            if(matriz == 1){
                matriza[fila - 1][columna - 1] = valor;    
            }else if(matriz == 2){
                matrizb[fila - 1][columna - 1] = valor;
            }
        }
        break;
    }
    system("cls");
    imprimir();
    menu();
}

/**
 * Multiplica dos matrices juntas
 */
void multiplicar(){
    for(int x = 0; x < tamano; ++x){
        for(int y = 0; y < tamano; ++y){
            for(int z = 0; z < tamano; ++z){
                matrizr[x][y] += matrizb[x][z] * matriza[z][y];
            }
        }
    }
}

/**
 * Imprime el menú para que el usuario elija.
 */
void menu(){
    int seleccion;

    /* Impresión de un menú para que el usuario seleccione una opción. */
    printf("\nQue deseas hacer?\t\t\t[Suma = 1]\t[Resta = 2]\t[Multiplicacion = 3]\t[Editar = 4]\n[Seleccion]: ");
    if(float(scanf("%d",&seleccion)) != 1){
        printf("Imprime un valor valido, porfavor\n\n");
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
        default:
            fflush(stdin);
            menu();
            break;
    }
}

/**
 * Imprime el resultado de la función.
 */
void resultado(){
    printf("[Resultado]: \n");
    
    int x = 0;
    int y = 0;

    while(y != tamano){
        while(x != tamano){
            printf("[%d]\t",matrizr[x][y]);
            x++;
        }
        x = 0;
        y ++;
        printf("\n");
    }
}

/**
 * Suma o resta el valor de la variable seleccion a la variable en cuestion.
 * 
 * El parametro "seleccion" El número de la opción seleccionada por el usuario.
 */
void adicion(int seleccion){
    int cont = 0;
    int x = 0;
    int y = 0;

    while (cont != 2){
        while(y != tamano){
            while(x != tamano){
                if(seleccion == 1){
                    matrizr[x][y] = matriza[x][y] + matrizb[x][y];    
                }else if(seleccion == 2){
                    matrizr[x][y] = matriza[x][y] - matrizb[x][y];
                }
                x++;
            }
            x = 0;
            y ++;
        }
        x = 0;
        y = 0;
        cont ++;
    }
}

/**
 * Llena una matriz con números aleatorios
 */
void llenar(){
    int cont = 0;
    int x = 0;
    int y = 0;

    /* Llenar las matrices con números aleatorios. */
    while (cont != 2){
        while(y != tamano){
            while(x != tamano){
               if(cont == 0){
                    matriza[x][y] = -100 + rand() % 200;
                }else if(cont == 1){
                    matrizb[x][y] = -100 + rand() % 200;
                }
                x++;
            }
            x = 0;
            y ++;
        }
        x = 0;
        y = 0;
        cont ++;
    }
}

/**
 * Imprime el contenido de las dos matrices.
 */
void imprimir(){
    int cont = 0;
    int x = 0;
    int y = 0;

    /* Imprimiendo las dos matrices. */
    while (cont != 2){
        printf("[Matriz]: %d\n",cont + 1);
        while(y != tamano){
            while(x != tamano){
               if(cont == 0){
                    printf("[%d]\t",matriza[x][y]);
                }else if(cont == 1){
                    printf("[%d]\t",matrizb[x][y]);
                }
                x++;
            }
            x = 0;
            y ++;
            printf("\n");
        }
        x = 0;
        y = 0;
        printf("\n");
        cont ++;
    }
}