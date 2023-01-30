/******************** Presentacion ********************
[Nombre]: Garnica Escamilla Luis Javier.
[Fecha]: 26 de Enero de 2023.
[Programa]: Actividad3.cpp 
Centro Universitario de los Altos.
Ingenieria en Comptuacion 2do Semestre.
[Profesor]: Franco Casillas Sergio.
[Descripcion]: Este programa cumple con las especificaciones dadas en la tarea.
******************************************************/

#include <iostream>

using namespace std;

int main(){
	int salida = 0;
	int contador = 0;
	int numero = 0;							//*Declaracion de variables de tipo entero

	while(salida == 0){						//* Bucle_principal Inicio del ciclo principal
		system("cls");						//!lIMPIAR LA PANTALLA EN CADA REPETICION
		
		contador = 0;						//Reinicio de la variable contador
		
		printf("[Numero]: ");
		scanf("%d",&numero);
		
		if(numero > 0 && numero <= 500){						//?Si el numero es mayor a 0 y menor o igual a 500
			printf("*Sumarle de 5 en 5, 100 veces\v");
			while(contador != 100){
				numero += 5;
				contador ++;
				printf("%d - %d\n",contador, numero);
			}
		}
		else if(numero > 500 && numero <= 1000){				//?Sino, si el numero es mayor a 500 y menor o igual a 1000
			printf("*Sumarle de 5 en 5, 100 veces\v");
			while(contador != 50){
				numero += 10;
				contador ++;
				printf("%d - %d\n",contador, numero);
			}
		}
		else{													//?Sino
			printf("No se puede calcular el valor");
		}
		printf("\n\n\nDeseas terminar con el programa \t\t[Si = 1]\t[No = 0]\n\n[Respuesta]: ");
		scanf("%d",&salida);
	}															//*Fin del ciclo principal
	return 0;
}
	