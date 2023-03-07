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
 * Cambia el color del texto en la consola.
 * colorin Será el color al que desea cambiar el texto.
 */
void color(int colorin){
    SetConsoleTextAttribute(hConsole, colorin);
}

/**
 * Si la posición es igual al tamaño del arreglo, entonces la posición se establece en 0
 */
void posto0(){
    if(posicion == tamano){
        posicion = 0;
    }
}

/**
 * Imprime el arreglo a lo mucho en filas de 10 elementos.
 */
void imprimir(){
    system("cls");

    int contador = 0;
    color(11);
    /* Un ciclo while que se ejecutará hasta que el valor de `contador` sea igual al valor de `tamano`. */
    while(contador != tamano){
        if(((contador % 10) == 0) and contador != 0){
            printf("\n");
        }
        printf("[%d]\t",arreglo[contador]);  
        contador++;
    }
    color(15);
}

/**
 * Le pide al usuario que seleccione un algoritmo de ordenamiento, y si el usuario ingresa una opción
 * válida, devuelve la opción el valor de la variable select.
 */
int seleccionord(){
    int select = 0;
    system("cls");
    color(15);
    /* Pidiendo al usuario que seleccione un algoritmo, y si el usuario ingresa una opción válida,
    devuelve el valor de la variable seleccionada. */
    printf("[1 = Burbuja]\t[2 = Quicksort]\n[Seleccion]: ");
    if(esvalido(scanf("%d",&select)) and (select == 1 or select == 2)){
        return select;
    }
    else{
        seleccionord();
    }
}

/**
 * Establece todos los elementos del arreglo a 0
 */
void vaciar(){
    int contador = 0;

    while(contador != tamano){
        arreglo[contador] = 0;
        contador++;
    }
}

/**
 * Una función que toma un booleano como parámetro y no devuelve nada.
 * 
 * azar: Si es verdadero, el programa generará un conjunto de numeros aleatorios. Si es falso, el programa
 * le pedirá al usuario un conjunto de numeros.
 */
void editar(bool azar){
    imprimir();
    while(posicion != tamano){
        if(azar){
            /* Asignación de un número aleatorio a la matriz. */
            arreglo[posicion] = rand()%200;
            posicion += 1; 
        }else{
            /* Pedirle al usuario que ingrese un número. */
            printf("\n[Numero %d]: ", posicion+1);
            if(esvalido(scanf("%d",&arreglo[posicion]))){
                posicion += 1;
            }else{
                printf("Escribe un valor valido, porfavor\n\n");
                system("pause");
                editar(false);
            }
        }
    }
}

/**
 * Cambia el valor de las variables valora y valorb.
 * 
 * valora: El valor del primer parámetro.
 * valorb: El valor del segundo parámetro.
 */
void cambiar(int valora, int valorb) {
    int temporal = arreglo[valora];
    arreglo[valora] = arreglo[valorb];
    arreglo[valorb] = temporal;
}

/**
 * Toma una matriz de números enteros y los ordena en orden ascendente con el metodo de burbuja
 */
void burbuja(){
    for(int a=0;a<tamano;a++){
		for(int b=0;b<tamano;b++){
			if(arreglo[b-1]>arreglo[b]){
				cambiar(b-1,b);
            }	
		}
	}
}

/**
 * minimo: el valor mínimo de la matriz
 * maximo: el índice máximo de la matriz
 */
int pivote(int minimo, int maximo){
    int puntop = arreglo[maximo];
    int i = minimo - 1;
    /* Un bucle for que se usa para iterar a través de la matriz. */
    for(int j = minimo; j <= maximo - 1; j++) {
        if(arreglo[j] < puntop){
            i++;
            cambiar(i, j);
        }
    }
    cambiar(i + 1, maximo);
    return (i + 1);
}

/**
 * minimo el índice del primer elemento de la matriz que se va a ordenar
 * maximo el último índice de la matriz
 */
void quicksort(int minimo, int maximo) {
    if(minimo < maximo){
        int menorpiv = pivote(minimo, maximo);
        quicksort(minimo, menorpiv - 1);
        quicksort(menorpiv + 1, maximo);
    }
}

/**
 * busqueda Es el número que desea encontrar.
 * Dentro de esta funcion se buscara el numero del parametro a base de la busqueda binaria.
 */
int busquedabin(int busqueda){
    int izquierda = 0; 
    int derecha = tamano- 1;
    /* Comprobando si el lado izquierdo es menor o igual que el lado derecho. */
    while (izquierda <= derecha){
        int mitad = floor((izquierda + derecha) / 2);
 
        int valorQueEstaEnElMedio = arreglo[mitad];
 
        /* Comprobando si el valor de `busqueda` es igual al valor de `valorQueEstaEnElMedio`. */
        if (busqueda == valorQueEstaEnElMedio){
            printf("[valor encontrado]: %d\t\t [Posicion]: %d\n\n",arreglo[mitad],mitad+1);
            return mitad;
        }
        
        /* Comprobando si el valor de `busqueda` es menor que el valor de `valorQueEstaEnElMedio`. */
        if (busqueda < valorQueEstaEnElMedio){
            derecha = mitad - 1;
        }/* Comprobando si el valor de `busqueda` es mayor que el valor de `valorQueEstaEnElMedio`. */
        if(busqueda > valorQueEstaEnElMedio){
            izquierda = mitad + 1;
        }
    }
    printf("[valor NO encontrado]\n\n");
    return -1;
}