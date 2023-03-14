#include <iostream>
#include <string.h>

using namespace std;

bool asignada = false;
char frase[100];
char frase_a_concatenar[100];

#include "Libreria12.cpp"

int main(){
	/* Declarar las variables que se utilizarán en el programa. */
	int vocales_de_la_frase, consonantes_de_la_frase, espacios_de_la_frase = 0;
	char seleccion = ' ';

	/* Le pide al usuario que ingrese una frase y luego la asigna a la variable `frase`. */
	if(!asignada){
		printf("[Frase]: ");
		gets(frase);
		asignada = true;
	}

	system("cls");
	printf("[Frase actual]: %s\n\n", frase);
	printf("Opciones: \n[Contar componentes] = 1\n[Es palindromo] = 2\n[Convertir a Mayusculas] = 3\n[Convertir a Minusculas] = 4\n[Concatenar otra frase] = 5\n[Salir] = 0");
	printf("\n\n[Seleccion]: ");
		
	/* Está comprobando si la entrada es un número. */
	if(!esvalido(scanf("%d", &seleccion))){
		fflush(stdin);
		main();
	}
	/* Una declaración de cambio. */
	switch(seleccion){
		case 0:
			abort();
			break;
		case 1:
			contar(&vocales_de_la_frase, &consonantes_de_la_frase, &espacios_de_la_frase);
			printf("[Vocales]: %d\t[Consonantes]: %d\t[Espacios]: %d\n\n", vocales_de_la_frase, consonantes_de_la_frase-1, espacios_de_la_frase);
			break;
		case 2:
			es_palindromo(frase);
			break;
		case 3:
		case 4:
			for(int i = 0; i <= strlen(frase) - 1; i++){
				if(seleccion == 3){
					frase[i] = cambiar_a_mayuscula_o_minuscula(frase[i], true);
				}else if(seleccion == 4){
					frase[i] = cambiar_a_mayuscula_o_minuscula(frase[i], false);
				}
			}
			break;
		case 5:
		 	fflush(stdin);
			printf("[Frase a concatenar]: ");
			gets(frase_a_concatenar);
			strcat(frase,frase_a_concatenar);
			break;
		default:
			printf("\n\nCaptura una opcion valida\n\n");
			break;
	}
	system("pause");
	main();
}