/******************** Presentacion ********************
[Nombre]: Garnica Escamilla Luis Javier.
[Fecha]: 30 de Enero de 2023.
[Programa]: Actividad4.cpp 
Centro Universitario de los Altos.
Ingenieria en Comptuacion 2do Semestre.
[Profesor]: Franco Casillas Sergio.
[Descripcion]:  Este programa calcula la serir de fibonacci hasta el "N" termino, utilizando
 el ciclo basico que el usuario prefiera.
******************************************************/

#include <iostream>

using namespace std;

/* Esta es una variable global que guarda el numero de terminos que el usuario desea calcular.*/
int nfibonacci;

void menu();
void salida();
void ffor();
void fwhile();
void fdowhile();

/**
 *? Esta funcion pregunta al usuario un valor, si el valor no es un numero entero, pregunta al usuario
 *? un numero valido, si el numero es mayor que 46 o menor que 1, pregunta al usuario por un numero dentro
 *? del rango, si el numero es valido, llama a la funcion "menu".
 */
int main(){
    system("cls");
    system("color 0B");

    printf("[Cantidad de terminos a calcular]: ");
    if(float(scanf("%d",&nfibonacci)) != 1){                       //!Validacion del termino de entrada
        printf("Captura un valor valido!\n");
        system("pause");
		fflush(stdin);
        main();
	}else{
        if(nfibonacci >= 46){
    		printf("\nEl valor que deseas calcular es demasiado grande para el \ntipo de dato INT, escribe uno mas pequeno\n\n");
    		system("pause");
    		main();
		}else if(nfibonacci < 1){		   	                                              //*La validacion es correcta 
            printf("\nEl valor que deseas calcular esta por debajo de 1, por lo \ntanto no mostrara nada, ingresa un valor mayor o igual a 1\n\n");
    		system("pause");
    		main();
        }
        menu();
    }
    salida();
}

/**
 *? Pregunta al usuario si quiere salir del programa, en caso de que acepte, sale del programa, sino
 *? reinicia la funcion.
 */
void salida(){
    int valorsalida;
    
    system("cls");

    printf("Deseas terminar con el programa?\t\t[1 = Si]\t[0 = No]\n");
    scanf("%d",&valorsalida);
   
    switch(valorsalida){
            case 0:
                fflush(stdin);
                main();
                break;
            case 1:
                break;
            default:
                fflush(stdin);
                salida();
                break;
    }
}

/**
 *? Es un menu que pregunta al usuario como desea ejecutar el programa, y llama a la funcion que se
 *? encarga de ejecutarla.
 */
void menu(){
    int seleccion;

    system("cls");

    printf("Como deseas realizarlo \t\t[1 = For]\t[2 = While]\t[3 = Do While]\n[Seleccion]: ");
    scanf("%d",&seleccion);
    
    switch(seleccion){
            case 1:
                ffor();
                break;
            case 2:
                fwhile();
                break;
            case 3:
                fdowhile();
                break;
            default:
                printf("\n\nEscribe un valor valido porfavor\n");
                fflush(stdin);
                system("pause");
                menu();
        }
    system("pause");
}

/**
 *? Esta funcion se encarga de tomar los 2 primeros numeros de la secuencia, los suma, reemplaza el
 *? primero con el valor del segundo, el valor del segundo por la suma de los anteriores, imprime el
 *? valor de la suma y la posicion.
 */
void ffor(){
    int vfibonacci, valor2 = 0;
    int valor1 = 1;
    int final = nfibonacci;

	printf("\nVal\t\t-\t\tPos\n");
    
	for(int c = 0;c <= final - 1 ; c += 1){
        vfibonacci = valor1 + valor2;
        valor1 = valor2;
        valor2 = vfibonacci;
       
        printf("%d\t\t-\t\t%d\n",vfibonacci,c+1);
    }
}

/**
 *? Esta funcion se encarga de tomar los 2 primeros numeros de la secuencia, los suma, reemplaza el
 *? primero con el valor del segundo, el valor del segundo por la suma de los anteriores, imprime el
 *? valor de la suma y la posicion.
 */
void fwhile(){
    int vfibonacci, c, valor2 = 0;
    int valor1 = 1;
    int final = nfibonacci;
	
    printf("\nVal\t\t-\t\tPos\n");
    
	while(c != final){
        vfibonacci = valor1 + valor2;
        valor1 = valor2;
        valor2 = vfibonacci;
    	printf("%d\t\t-\t\t%d\n",vfibonacci,c+1);
        c += 1;
    }
}

/**
 *? Esta funcion se encarga de tomar los 2 primeros numeros de la secuencia, los suma, reemplaza el
 *? primero con el valor del segundo, el valor del segundo por la suma de los anteriores, imprime el
 *? valor de la suma y la posicion.
 */
void fdowhile(){
    int vfibonacci, c, valor2 = 0;
    int valor1 = 1;
    int final = nfibonacci;
	
    printf("\nVal\t\t-\t\tPos\n");

    do{
        vfibonacci = valor1 + valor2;
        valor1 = valor2;
        valor2 = vfibonacci;
        printf("%d\t\t-\t\t%d\n",vfibonacci,c+1);
        c += 1;
    }while(c  != final);
}