#include <iostream>

using namespace std;

int main(){
	int salida = 0;
	int contador = 0;
	int numero = 0;

	while(salida == 0){
		system("cls");
		
		contador = 0;
		
		printf("[Numero]: ");
		scanf("%d",&numero);
		
		if(numero > 0 && numero <= 500){
			printf("*Sumarle de 5 en 5, 100 veces\v");
			while(contador != 100){
				numero += 5;
				contador ++;
				printf("%d - %d\n",contador, numero);
			}
		}
		else if(numero > 500 && numero <= 1000){
			printf("*Sumarle de 5 en 5, 100 veces\v");
			while(contador != 50){
				numero += 10;
				contador ++;
				printf("%d - %d\n",contador, numero);
			}
		}
		else{
			printf("No se puede calcular el valor");
		}
		printf("\n\n\nDeseas terminar con el programa \t\t[Si = 1]\t[No = 0]\n\n[Respuesta]: ");
		scanf("%d",&salida);
	}
	return 0;
}
	