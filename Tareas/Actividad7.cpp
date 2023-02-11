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
#include <windows.h>

using namespace std;

char arreglo1[10];
char arreglo2[10];
int posicion1, sumatoriatotal1 = 0;
int posicion2, sumatoriatotal2 = 0;

/**
 * Este comando sirve especificamente para cambiar el color de la consola
 */
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void vaciar();          //TODO Debo documentar mas en las declaraciones y funciones
void editar();
void pasar();
void imprimir();
void borrar(int arreglodes);
void ira();
void menu(int seleccion, int arreglodes);


/**
 * La funcion principal se encarga de llamar a la funcion imprimir, pregunta que hacer y
 * llama a la funcion menu.
 */

int main(){
    int seleccion = 0;
    int arreglodes = 0;
    
    if(posicion1 == 10){
        posicion1 = 0;
    }
    if(posicion2 == 10){
        posicion2 = 0;
    }

    imprimir();
    
    printf("Que deseas hacer?\n\n[Borrar = 1]\t[Editar = 2]\t[Pasar = 3]\t[Ir a la posicion n = 4]\t");
    SetConsoleTextAttribute(hConsole, 9);
    printf("[Vaciar el arreglo = 5]\n\n\t\t\t\t\t\t\t\t\t\t[Salir = 0]");
    SetConsoleTextAttribute(hConsole, 15);
    printf("\r[Seleccion]: ");
    scanf("%d",&seleccion);
    printf("[En que arreglo\?]: ");
    scanf("%d",&arreglodes);
    
    if(float(seleccion)!= 1){
        printf("Ese no es un valor valido, revisa las opciones e intenta de nuevo\n\n");
        fflush(stdin);
        system("pause");
        main();
    }else if(float(arreglodes) != 1){
        printf("Ese no es un valor valido, revisa las opciones e intenta de nuevo\n\n");
        fflush(stdin);
        system("pause");
        main();
    }else{
        menu(seleccion, arreglodes);
    }
}


/**
 * Es un menú que llama a otras funciones.
 * Puede utilizar el parametro "seleccion", opción que eligió el usuario.
 */
void menu(int seleccion, int arreglodes){
    switch(seleccion){
        case 0:
            printf("Gracias, vuelva pronto :)\n\n");
            system("pause");
            break;
        case 1:
            fflush(stdin);
            borrar(arreglodes);
            break;
        case 2:
            fflush(stdin);
            editar();
            break;
        case 3:
            pasar();
            fflush(stdin);
            break;
        case 4:
            ira();
            fflush(stdin);
            break;
        case 5:
            fflush(stdin);
            vaciar();
            break;
        default:
            fflush(stdin);
            main();
    }
}



/**
 * Le pide al usuario una posición en la matriz, y si la entrada no es un número o no está en la
 * matriz, le pide al usuario que ingrese un número válido
 */
void ira(){
    printf("\n[Ir a la posicion]: ");
    
    if(float(scanf("%d",&posicion1)) != 1 or (posicion1 < 0 or posicion1 > 9)){
        printf("\n\nEste valor esta fuera del arreglo, introduce uno valido.\n");
        system("pause");
        fflush(stdin);
        imprimir();
        menu(4, 1);
    }else{
        main();
    }
    
}


/**
 * Es una función que borra el arreglo y restablece la posición y la suma a 0
 */
void vaciar(){
    int contador = 0;

    while(contador != 10){
        arreglo1[contador] = 0;
        contador++;
    }
    posicion1 = 0;
    sumatoriatotal1 = 0;
    
    main();
}


/**
 * Imprime el arreglo y la suma del mismo.
 */
void imprimir(){
    system("cls");

    int contador = 0;
    int rep = 0;

    while(rep != 2){
        while(contador != 10)
        {
            if(rep == 0){
                if(contador == posicion1){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("->");
                    SetConsoleTextAttribute(hConsole, 10);
                }
                printf("[%c] ",arreglo1[contador]);
                SetConsoleTextAttribute(hConsole, 15);
            }else if(rep == 1){
                if(contador == posicion2){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("->");
                    SetConsoleTextAttribute(hConsole, 10);
                }
                printf("[%c] ",arreglo2[contador]);
                SetConsoleTextAttribute(hConsole, 15);
            }
            contador++;
        }
        /**
         *  if(rep == 0){
            SetConsoleTextAttribute(hConsole, 11);
            printf("\t\t[Sumatoria]: [%d]\n\n",sumatoriatotal1);
            SetConsoleTextAttribute(hConsole, 15);
        }else{
            SetConsoleTextAttribute(hConsole, 11);
            printf("\t\t[Sumatoria]: [%d]\n\n",sumatoriatotal2);
            SetConsoleTextAttribute(hConsole, 15);
        }
        */
        printf("\n\n");
        rep++;
        contador = 0;
    }
    
}


/**
 * Toma una posición en el arreglo, y le pide al usuario que ingrese un nuevo
 * valor para el elemento en esa posición, si no es un numero pide que ingrese 
 * un valor valido
 */
void editar(){
    int temporal = arreglo1[posicion1];

    printf("\n[Numero]: ");

    scanf("%c",&arreglo1[posicion1]);
    
    sumatoriatotal1 -= temporal;
    sumatoriatotal1 += arreglo1[posicion1];
    posicion1 += 1;

    main();
}

/**
 * Suma uno a la posicion y regresa a la funcion principal.
 */
void pasar(){
    posicion1 += 1;
    main();
}

/**
 * Elimina el elemento de la lista correspondiente a la posicion.
 */
void borrar(int arreglodes){
    if(arreglodes == 1){
        sumatoriatotal1 -= arreglo1[posicion1];
        arreglo1[posicion1] = 0;
        posicion1 += 1;    
    }else if(arreglodes == 2){
        sumatoriatotal2 -= arreglo2[posicion2];
        arreglo2[posicion2] = 0;
        posicion2 += 1;
    }
    main(); 
}