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

using namespace std;

int main(){
    srand((unsigned)time(NULL));
    
    char palabras[20][40] = {"Palabra", "polola", "carmelita", "Carlos salinas", "de gortari", "andres Manuel", "lopez obrador", "every day i wake up", "carmelita", "carmelita"};

    int frase = rand() % 10;
    printf("%s",palabras[frase]);
    system("pause");
    main();
}