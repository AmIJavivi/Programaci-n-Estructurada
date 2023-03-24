#include <iostream>
#include <limits>
#include <fstream>
#include <string>

using namespace std;

struct Amigo {
    char nombre[100];
    char apellidos[100];
    char ciudad[100];
    char estado[100];
    char municipio[30];
    int edad;
    float estatura;
};

Amigo amigos[5];

#include "Libreria14.cpp"

int main(){
    system("cls");
    char seleccion;

    cout<<"\t\t\t\t\t\t[1 = Leer]\t[2 = Escribir]\t[3 = Salir]\r[Modo]: ";
    cin>>seleccion;
    fflush(stdin);

    switch(seleccion){
        case '1':
            leer();
            break;
        case '2':
            escribir();
            break;
        case '3':
            abort();
            break;
        default:
            main();
            break;
    }
    system("pause");
    main();
}

