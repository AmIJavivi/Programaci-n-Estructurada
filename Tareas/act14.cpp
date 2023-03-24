#include <fstream>
#include <iostream>
#include <string>

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
	int tamano, seleccion = 0;
	fstream archivo("personas.txt");
	
	char linea[100]; 

	cout<<"\t\t\tPractica 12"<<endl;
	cout<<"\t\t\t==========="<<"\n"<<endl;
	cout<<"Hecho por:	Luis Javier Garnica Escamilla\n\n"<<endl;

	cout<<"\t\t\t\t[Leer]: 1\t[Escribir]: 2\r[Modo]: ";
	cin>>seleccion;


	if(seleccion == 1){
		if(archivo.is_open()){
			string linea;
			while(getline(archivo, linea)){
				cout << "Una línea: ";
				cout << linea << endl;
			}
		}
	}else if(seleccion == 2){
		cout<<"[Tamaño de la agenda]: ";
		cin>>tamano;

		persona *amigos = new persona[tamano];

		
		system("pause");

		if (!archivo.is_open()) {
			cout << "No se pudo abrir el archivo" << endl;
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
			cout<<"Municipio del amigo "<<i+1<<": "<<amigos[i].municipio<<"\n\n";
		}

		for(int i=0;i<tamano;i++){
			archivo<<amigos[i].nombre<<","<<amigos[i].apellidos<<","<<amigos[i].edad<<","<<amigos[i].estatura<<","<<amigos[i].ciudad<<","<<amigos[i].estado<<","<<amigos[i].municipio<<",\n";
		}
	}
	
	archivo.close();

	system("pause");
}