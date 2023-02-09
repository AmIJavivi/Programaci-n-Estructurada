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

int arreglo[10];
int posicion, sumatoriatotal = 0;

/**
 * Este comando sirve especificamente para cambiar el color de la consola
 */
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void vaciar();          //TODO Debo documentar mas en las declaraciones y funciones
void editar();
void pasar();
void imprimir();
void borrar();
void ira();
void menu(int seleccion);


/**
 * La funcion principal se encarga de llamar a la funcion imprimir, pregunta que hacer y
 * llama a la funcion menu.
 */

int main(){
    int seleccion = 0;
    
    if(posicion == 10){
        posicion = 0;
    }

    imprimir();
    
    printf("Estas en la posicion %d del arreglo, que deseas hacer?\n\n[Borrar = 1]\t[Editar = 2]\t[Pasar = 3]\t[Ir a la posicion n = 4]\t",posicion);
    SetConsoleTextAttribute(hConsole, 9);
    printf("[Vaciar el arreglo = 5]\n\n\t\t\t\t\t\t\t\t\t\t[Salir = 0]");
    SetConsoleTextAttribute(hConsole, 15);
    printf("\r[Seleccion]: ");
    
    if(float(scanf("%d",&seleccion))!= 1){
        printf("Ese no es un valor valido, revisa las opciones e intenta de nuevo\n\n");
        fflush(stdin);
        system("pause");
        main();
    }else{
        menu(seleccion);
    }
}


/**
 * Es un menú que llama a otras funciones.
 * Puede utilizar el parametro "seleccion", opción que eligió el usuario.
 */
void menu(int seleccion){
    switch(seleccion){
        case 0:
            printf("Gracias, vuelva pronto :)\n\n");
            system("pause");
            break;
        case 1:
            fflush(stdin);
            borrar();
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
    
    if(float(scanf("%d",&posicion)) != 1 or (posicion < 0 or posicion > 9)){
        printf("\n\nEste valor esta fuera del arreglo, introduce uno valido.\n");
        system("pause");
        fflush(stdin);
        imprimir();
        menu(4);
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
        arreglo[contador] = 0;
        contador++;
    }
    posicion = 0;
    sumatoriatotal = 0;
    
    main();
}


/**
 * Imprime el arreglo y la suma del mismo.
 */
void imprimir(){
    system("cls");

    int contador = 0;

    while(contador != 10)
    {
        if(contador == posicion){
            
            SetConsoleTextAttribute(hConsole, 9);
            printf("->");
            SetConsoleTextAttribute(hConsole, 10);

        }

        printf("[%d] ",arreglo[contador]);
        SetConsoleTextAttribute(hConsole, 15);
        
        contador++;
    }
    SetConsoleTextAttribute(hConsole, 11);
    printf("\t\t[Sumatoria]: [%d]\n\n",sumatoriatotal);
    SetConsoleTextAttribute(hConsole, 15);
}


/**
 * Toma una posición en el arreglo, y le pide al usuario que ingrese un nuevo
 * valor para el elemento en esa posición, si no es un numero pide que ingrese 
 * un valor valido
 */
void editar(){
    int temporal = arreglo[posicion];

    printf("\n[Numero]: ");

    if(float(scanf("%d",&arreglo[posicion])) != 1){
        printf("Escribe un valor valido, porfavor\n\n");
        fflush(stdin);
        system("pause");
        imprimir();
        menu(2);
    }else{
        sumatoriatotal -= temporal;
        sumatoriatotal += arreglo[posicion];
        posicion += 1;
    }
    main();
}

/**
 * Suma uno a la posicion y regresa a la funcion principal.
 */
void pasar(){
    posicion += 1;
    main();
}

/**
 * Elimina el elemento de la lista correspondiente a la posicion.
 */
void borrar(){
    sumatoriatotal -= arreglo[posicion];
    arreglo[posicion] = 0;
    posicion += 1;
    
    main(); 
}