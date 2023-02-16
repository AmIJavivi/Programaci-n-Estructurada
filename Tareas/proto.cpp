/**
 * *|CURSOR_MARCADOR|*
 */
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
 
char arreglo1[10][40];
char arreglo2[10][40];
char arreglo3[20][40];
char temporal[1][40];
int posicion1 = 0;
int posicion2 = 0;

/**
 * Este comando sirve especificamente para cambiar el color de la consola
 */
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


/* Una función que imprime el complemento de las dos matrices. */
void complemento();
/* Uniendo las dos matrices. */
void unir();
/* Comparando las dos matrices e imprimiendo los valores que no están en ambas matrices. */
void diferencia();
/* Una función que imprime la intersección de las dos matrices. */
void interseccion();
/* Una función que elimina la matriz y restablece la posición y la suma a 0. */
void vaciar(int arreglodes);
/* Le pide al usuario un valor y luego lo guarda en la matriz. */
void editar(int arreglodes);
/* Agregando uno a la posición y volviendo a la función principal. */
void pasar(int arreglodes);
/* Imprimiendo la matriz y la suma de la matriz. */
void imprimir();
/* Eliminación del elemento de la lista correspondiente a la posición. */
void borrar(int arreglodes);
/* Solicitar al usuario una posición en la matriz, y si la entrada no es un número o no está en la
matriz, le pide al usuario que ingrese un número válido. */
void ira(int arreglodes);
/* Un menú que llama a otras funciones. Puede utilizar el parámetro "selección", la opción que el
usuario eligió. */
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
    printf("[Vaciar el arreglo = 5]\n\n\t\t\t\t\t\t[Operaciones = 6]\t\t[Salir = 0]");
    SetConsoleTextAttribute(hConsole, 15);
    
    printf("\r[Seleccion]: ");
    /* Comprobando si la entrada es un número. */
    if(float(scanf("%d",&seleccion))!= 1){
        printf("Ese no es un valor valido, revisa las opciones e intenta de nuevo\n\n");
        fflush(stdin);
        system("pause");
        main();

    }
    /* Al verificar si la entrada del usuario es 0 o 6, si lo es, llamará a la función de menú, si no,
    le pedirá al usuario que ingrese un valor para la variable arreglodes. */
    if((seleccion == 0)or(seleccion == 6)){
        menu(seleccion, arreglodes);
    }else{
        printf("[En que arreglo\?]: \n\n");
        if(float(scanf("%d",&arreglodes)) != 1){
            printf("Ese no es un valor valido, revisa las opciones e intenta de nuevo\n\n");
            fflush(stdin);
            system("pause");
            main();
        }else{
            menu(seleccion, arreglodes);
        }
    }
}

void complemento(){
    int n = 0;

    /* Copiando los valores de la primera matriz a la tercera matriz. */
    for(int i = 0; i <= 9; i++){
        strcpy(arreglo3[i], arreglo1[i]);
        n++;
    }

    /* Comprobando si el valor de la matriz es el mismo que el valor de la otra matriz. */
    for(int i = 0; i <= 9; i++){
        int cont = 0;
        while(cont != n){
            if(string(arreglo2[i]) == string(arreglo3[cont])){
                break;
            }else{
                cont++;
            }if(cont == n){
                strcpy(arreglo3[i + n], arreglo2[i]);
            }
        }
    }
    
    int cont2 = 0;

    /* Comparando los valores de las dos matrices y si son iguales, copia el valor de la segunda matriz
    en la tercera matriz. */
    for(int i = 0; i < 10; i++) {
        bool existe = false;
        for(int j = 0; j < 10; j++) {
            if(string(arreglo3[i]) == string(arreglo2[j])) {
                existe = true;
                break;
            }
        }
        if(existe) {
            strcpy(arreglo3[cont2++], arreglo2[i]);
        }
    }


    /* Imprimiendo los valores de la matriz. */
    for(int i = 0; i <= 9; i++){
        printf("[%s] ",arreglo3[i]);
    }

    system("pause");
}

/**
 * Resta los elementos de la matriz al de la matriz b.
 */
void diferencia(){
    int cont = 0;

    /* Comparando los valores de las dos matrices y si son iguales, copia el valor de la segunda matriz
    en la tercera matriz. */
    for (int i = 0; i < 10; i++) {
        bool existe = false;
        for (int j = 0; j < 10; j++) {
            if(string(arreglo1[i]) == string(arreglo2[j])) {
                existe = true;
                break;
            }
        }
        if(!existe) {
            strcpy(arreglo3[cont++], arreglo1[i]);
        }
    }
    
    /* Imprimiendo los valores de la matriz. */
    for(int i = 0; i <= 9; i++){
        printf("[%s] ",arreglo3[i]);
    }

    system("pause");
}

/**
 * Toma dos matrices de enteros y devuelve una nueva matriz que contiene los elementos que están
 * presentes en ambas matrices de entrada.
 */
void interseccion(){
    int cont = 0;

   /* Comparar los elementos de dos arreglos y si son iguales, es copiar el elemento a un tercer
   arreglo. */
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(string(arreglo1[i]) == string(arreglo2[j])) {
                strcpy(arreglo3[cont++], arreglo1[i]);
                break;
            }
        }
    }

    /* Imprimiendo los elementos de la matriz. */
    for(int i = 0; i <= 9; i++){
        printf("[%s] ",arreglo3[i]);
    }
    
    system("pause");
}

void unir(){
    int n = 0;

    /* Copiando los valores del arreglo arreglo1 al arreglo arreglo3. */
    for(int i = 0; i <= 9; i++){
        strcpy(arreglo3[i], arreglo1[i]);
        n++;
    }

    /* Comparando las dos matrices y si el valor no está en la segunda matriz, lo agregará a la segunda
    matriz. */
    for(int i = 0; i <= 9; i++){
        int cont = 0;
        while(cont != n){
            if(string(arreglo2[i]) == string(arreglo3[cont])){
                break;
            }else{
                cont++;
            }if(cont == n){
                strcpy(arreglo3[i + n], arreglo2[i]);
            }
        }
    }

    /* Imprimiendo los elementos de la matriz. */
    for(int i = 0; i <= 2*n; i++){
        printf("[%s] ",arreglo3[i]);
    }
    
    system("pause");
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
            editar(arreglodes);
            break;
        case 3:
            pasar(arreglodes);
            fflush(stdin);
            break;
        case 4:
            ira(arreglodes);
            fflush(stdin);
            break;
        case 5:
            fflush(stdin);
            vaciar(arreglodes);
            break;
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



/**
 * Le pide al usuario una posición en la matriz, y si la entrada no es un número o no está en la
 * matriz, le pide al usuario que ingrese un número válido
 */
void ira(int arreglodes){
    printf("\n[Ir a la posicion]: ");
    if(arreglodes == 1){
        if(float(scanf("%d",&posicion1)) != 1 or (posicion1 < 1 or posicion1 > 10)){
            printf("\n\nEste valor esta fuera del arreglo, introduce uno valido.\n");
            system("pause");
            fflush(stdin);
            imprimir();
            menu(4, 1);
        }else{
            posicion1 -= 1;
            main();
        }
    }else if(arreglodes == 2){
        if(float(scanf("%d",&posicion2)) != 1 or (posicion2 < 1 or posicion2 > 10)){
            printf("\n\nEste valor esta fuera del arreglo, introduce uno valido.\n");
            system("pause");
            fflush(stdin);
            imprimir();
            menu(4, 1);
        }else{
            posicion2 -= 1;
            main();
        }
    }
    
    
    
    
}


/**
 * Es una función que borra el arreglo y restablece la posición y la suma a 0
 */
void vaciar(int arreglodes){
    int contador = 0;

    if(arreglodes == 1){
        while(contador != 10){
            strcpy(arreglo1[contador], "");
            contador++;
        }
        posicion1 = 0;  
    }else if(arreglodes == 2){
        while(contador != 10){
            strcpy(arreglo2[contador], "");
            contador++;
        }
        posicion2 = 0;
    }
    
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
                printf("[%s] ",arreglo1[contador]);
                SetConsoleTextAttribute(hConsole, 15);
            }else if(rep == 1){
                if(contador == posicion2){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("->");
                    SetConsoleTextAttribute(hConsole, 10);
                }
                printf("[%s] ",arreglo2[contador]);
                SetConsoleTextAttribute(hConsole, 15);
            }
            contador++;
        }
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
void editar(int arreglodes){
    printf("\n[Valor]: ");


    

    if(arreglodes == 1){
        fgets(arreglo1[posicion1], 20, stdin);
        arreglo1[posicion1][strcspn(arreglo1[posicion1], "\n")] = 0;
        posicion1 += 1;
        main();
    }else if(arreglodes == 2){
        fgets(arreglo2[posicion2], 20, stdin);
        arreglo2[posicion2][strcspn(arreglo2[posicion2], "\n")] = 0;
        posicion2 += 1;
        main();
    }
    else{
        main();
    }
}

/**
 * Suma uno a la posicion y regresa a la funcion principal.
 */
void pasar(int arreglodes){
    if(arreglodes == 1){
        posicion1 += 1;
    }else if(arreglodes == 2)
        posicion2 += 1;
    main();
}

/**
 * Elimina el elemento de la lista correspondiente a la posicion.
 */
void borrar(int arreglodes){
    if(arreglodes == 1){
        strcpy(arreglo1[posicion1], "");
        posicion1 += 1;    
    }else if(arreglodes == 2){
        strcpy(arreglo2[posicion2], "");
        posicion2 += 1;
    }
    main(); 
}