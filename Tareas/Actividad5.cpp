#include <iostream>
#include <windows.h>
#include <cstdlib>

#define sleep

using namespace std;

int arreglo[10];
int posicion, sumatoriatotal = 0;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void vaciar();
void editar();
void pasar();
void imprimir();
void borrar();
void ira();
void menu(int seleccion);

int main(){
    int seleccion = 0;
    
    if(posicion == 10){
        posicion = 0;
    }

    imprimir();
    
    printf("Estas en la posicion %d del arreglo, que deseas hacer?\n\n[Borrar = 1]\t[Editar = 2]\t[Pasar = 3]\t[Ir a la posicion n = 4]\t",posicion);
    SetConsoleTextAttribute(hConsole, 4);
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

    return 0;
}

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

void imprimir(){
    system("cls");

    int contador = 0;

    while(contador != 10)
    {
        if(contador == posicion){
            
            SetConsoleTextAttribute(hConsole, 4);
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

void pasar(){
    posicion += 1;
    main();
}

void borrar(){
    sumatoriatotal -= arreglo[posicion];
    arreglo[posicion] = 0;
    posicion += 1;
    
    main(); 
}