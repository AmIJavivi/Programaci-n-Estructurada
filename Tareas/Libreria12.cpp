/**
 * Comprueba si la entrada es un flotante o no.
 * seleccion Es la entrada del usuario.
 * Regresara un valor booleano, verdadero en caso de ser un valor valido, falso
 * en caso contrario
 */
bool esvalido(int seleccion){
    if(float(seleccion) != 1){
        fflush(stdin);
        return false;
    }else{
        fflush(stdin);
        return true;
    }
}

/**
 * Toma un carácter y un booleano, y devuelve el carácter en caso contrario
 * 
 * el parametro caracter_a_evaluar se refiere a la cadena a evaluar.
 * el parametro cambiar_a_mayusculas Si es verdadero, la función cambiará el carácter a mayúsculas. Si es
 * falso, lo cambiará a minúsculas.
 * 
 * regresara el código ASCII del carácter.
 */
int cambiar_a_mayuscula_o_minuscula(char caracter_a_evaluar, bool cambiar_a_mayusculas){ //True cambia a mayusculas, False cambia a minusculas
	/* Comprobando si el carácter está entre A y Z. */
	if((65 <= int(caracter_a_evaluar)) and (int(caracter_a_evaluar) <= 90)){
		if(!cambiar_a_mayusculas){
			return (int(caracter_a_evaluar) + 32);
		}
	}
	/* Comprobando si el carácter está entre a y z. */
	if((97 <= int(caracter_a_evaluar)) and (int(caracter_a_evaluar) <= 122)){
		if(cambiar_a_mayusculas){
			return (int(caracter_a_evaluar) - 32);
		}
	}
	return (int(caracter_a_evaluar));
}

/**
 * Comprueba si la cadena es un palíndromo.
 * 
 * el parametro frase_a_evaluar Esta es la cadena que será evaluada.
 */
void es_palindromo(char frase_a_evaluar[]){
	int aciertos = 0;
	int tamano =(strlen(frase_a_evaluar) - 1);

	/* Un bucle for que está iterando a través de la cadena y la cambia a minusculas. */
	for(int i = 0; i <= tamano; i++){
		frase_a_evaluar[i] = cambiar_a_mayuscula_o_minuscula(frase_a_evaluar[i],false);
	}

	/* Iterando a través de la cadena y comparando con la misma cadena en orden inverso */
	for(int i = 0; i <= tamano; i++){
		if(int(frase_a_evaluar[i]) == int(frase_a_evaluar[tamano - i])){
			aciertos++;
		}else{
			printf("\nLa frase %s NO es un palindromo\n\n", frase_a_evaluar);
			break;
		}if(aciertos == tamano){
			printf("\nLa frase %s es un palindromo\n\n", frase_a_evaluar);
			break;
		}
	}
}

/**
 * Cuenta las vocales, consonantes y espacios en una cadena
 * 
 * el parametro vocales puntero a la variable que almacenará el número de vocales
 * el parametro consonantes puntero a la variable que almacenará el número de consonantes
 * el parametro espacios puntero a la variable que almacenará el número de espacios
 * 
 * regreso el número de vocales, consonantes y espacios en la cadena.
 */
int contar(int *vocales, int *consonantes, int *espacios){
	int vocales_contadas, consonantes_contadas, espacios_contados = 0;
	int tamano = (strlen(frase)-1);
	for(int i = 0; i <= tamano; i++){
		/* Comprobando si el carácter es una letra. */
		if(((65 <= int(frase[i])) and (int(frase[i]) <= 90)) or ((97 <= int(frase[i])) and (int(frase[i]) <= 122))){
			/* Una declaración de cambio.*/
			switch(frase[i]){
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					vocales_contadas++; //Vocales
					break;
				default:
					consonantes_contadas++; //Consonantes
					break;
			}
		}
		/* Una declaración de cambio. */
		switch(frase[i]){
			case ' ':
				espacios_contados++;//Espacios
				break;
			default:
				break;
		}
	}
	/* Devolviendo los valores de las variables. */
	*vocales = vocales_contadas; 
	*consonantes = consonantes_contadas;
	*espacios = espacios_contados;
	return 0; 
}