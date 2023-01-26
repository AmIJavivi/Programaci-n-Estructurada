#include <iostream>

using namespace std;

int main(){
    int actividad = 2;
    char genero = 'H';
    float edad = 18;
    int fecha = 26;
    int octal = 12;
    system("color 04");
    printf("[Actividad %d]: \"Impresion de caracteres\" \v\v[Nombre]:\t\tGarnica Escamilla Luis Javier\n[Edad]:\t\t\t%f \n[Genero]:\t\t%c \n[Residencia]:\t\tArandas, Jalisco\n[Fecha]:\t\t%u\\01\\23\n[Carrera]:\t\tIngenieria en Computacion\n[Semestre]:\t\t%o\b\n[Numero favorito]: \t%o\n",actividad,edad,genero,fecha,actividad,octal);
    system("pause");
}