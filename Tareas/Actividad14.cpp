#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct persona{
	char nombre[100];
    char apellidos[100];
    char ciudad[100];
    char estado[100];
    char municipio[100];
    char calle[100];
	char edad[4];
	char estatura[4];
};

int main(){
	FILE *archivo;
	char linea[100];
	int posicion;
	bool encontrado = false;
	
	cout<<"\t\t\tPractica 12"<<endl;
	cout<<"\t\t\t==========="<<"\n"<<endl;
	cout<<"Hecho por:	Luis Javier Garnica Escamilla\n\n"<<endl;
	

	int tamano = 0;

	cout<<"[Tamaño de la agenda]: ";
	cin>>tamano;

	persona *amigos = new persona[tamano];

	cout<<"[Leer]: 1 \t[Escribir]: 2\n";
	int modo = 0;
	cin>>modo;
	if(modo == 1){
		archivo = fopen("personas.txt", "r");
	}else if(modo == 2){
		archivo = fopen("personas.txt", "w");
		while(fgets(linea, 100, archivo) != NULL){
        	posicion = ftell(archivo);
        	if(strstr(linea, "") != NULL){
            	encontrado = true;
            	break;
       		}
    	}

		if(encontrado){
        	fseek(archivo, posicion, SEEK_SET);
        	fprintf(archivo, "Esta es la última línea.");
    	}else{
			fprintf(archivo, "Esta es la última línea.");
        	printf("El archivo está vacío.\n");
    	}
	}
	cout<<linea;
	system("pause");

	if(archivo == NULL){
        printf("No se pudo abrir el archivo.\n");
        return 1;
	}

	fflush(stdin);
	
	for(int i=0;i<tamano;i++){
		cout<<"Ingresa el nombre del amigo "<<i+1<<": ";
		cin.getline(amigos[i].nombre,100);
        fflush(stdin);
        cout<<"Ingresa los apellidos del amigo "<<i+1<<": ";
		cin.getline(amigos[i].apellidos,100);
        fflush(stdin);
        cout<<"Ingresa la ciudad del amigo "<<i+1<<": ";
		cin.getline(amigos[i].ciudad,100);
        fflush(stdin);
        cout<<"Ingresa el estado del amigo "<<i+1<<": ";
		cin.getline(amigos[i].estado,100);
        fflush(stdin);
        cout<<"Ingresa el municipio del amigo "<<i+1<<": ";
		cin.getline(amigos[i].municipio,30);
        fflush(stdin);
		cout<<"Ingresa la edad del amigo "<<i+1<<": ";
		cin>>amigos[i].edad;
        fflush(stdin);
		cout<<"Ingresa la estatura del amigo "<<i+1<<": ";
		cin>>amigos[i].estatura;
        fflush(stdin);
        
		system("cls");
	}

	for(int i=0;i<tamano;i++){
		cout<<"Nombre del amigo "<<i+1<<": "<<amigos[i].nombre<<endl;
		cout<<"Apellidos del amigo "<<i+1<<": "<<amigos[i].apellidos<<endl;
        cout<<"Edad del amigo "<<i+1<<": "<<amigos[i].edad<<endl;
        cout<<"Estatura del amigo "<<i+1<<": "<<amigos[i].estatura<<endl;
		cout<<"Ciudad del amigo "<<i+1<<": "<<amigos[i].ciudad<<endl;
        cout<<"Estado del amigo "<<i+1<<": "<<amigos[i].estado<<endl;
        cout<<"Municipio del amigo "<<i+1<<": "<<amigos[i].municipio<<endl;
	}

	for(int i=0;i<tamano;i++){
		fseek(archivo, posicion, SEEK_SET);
		fprintf(archivo,amigos[i].nombre,"\n");
		fprintf(archivo,amigos[i].edad,"\n");
		fprintf(archivo,amigos[i].estatura,"\n");
		fprintf(archivo,amigos[i].ciudad,"\n");
		fprintf(archivo,amigos[i].estado,"\n");
		fprintf(archivo,amigos[i].municipio,"\n");
	}
	
	fclose(archivo);

	system("pause");
}