/**
 * Comprueba si la entrada del usuario es una opción válida.
 * 
 * seleccion La selección del usuario
 * return es un valor booleano.
 */
bool validate(int seleccion){
    if(float(seleccion) != 1){
        fflush(stdin);
        printf("Ese no es un valor valido, revisa las opciones e intenta de nuevo\n\n");
        return false;
    }else{
        return true;
    }
}

/**
 * Imprime las dos matrices.
 */
void imprimir(){
    int cont = 0;
    int x = 0;
    int y = 0;

    /* Imprimiendo las dos matrices. */
    while (cont != 2){
        color(9);
        printf("[Matriz]: %d\n",cont + 1);
        color(15);
        while(y != tamano){
            while(x != tamano){
               if(cont == 0){
                    printf("[%d]\t",matriza[x][y]);
                }else if(cont == 1){
                    printf("[%d]\t",matrizb[x][y]);
                }
                x++;
            }
            x = 0;
            y ++;
            printf("\n");
        }
        x = 0;
        y = 0;
        printf("\n");
        cont ++;
    }
}


/**
 * Rellena dos matrices con números aleatorios.
 */
void llenar(){
    srand((unsigned)time(NULL));
    
    int cont = 0;
    int x = 0;
    int y = 0;

    /* Llenar las matrices con números aleatorios. */
    while (cont != 2){
        while(y != tamano){
            while(x != tamano){
               if(cont == 0){
                    matriza[x][y] = -200+rand()%600;
                }else if(cont == 1){
                    matrizb[x][y] = -200+rand()%600;
                }
                x++;
            }
            x = 0;
            y ++;
        }
        x = 0;
        y = 0;
        cont ++;
    }
}

/**
 * Le pide al usuario una matriz, una fila y una columna, y luego pide que se coloque un valor en la
 * fila y la columna especificadas.
 */
void editar(){
    int fila;
    int columna;
    int matriz;
    int valor;

  /* Solicitar al usuario que ingrese un valor y, si el valor no es un número, le pedirá al usuario que
  ingrese un número nuevamente. */
    printf("[Matriz]: ");
    if((!validate(scanf("%d",&matriz))) or (matriz < 1 or matriz > 2)){
        fflush(stdin);
        system("cls");
        imprimir();
        editar();
    }
    /* Un ciclo que seguirá pidiendo al usuario un valor hasta que el usuario ingrese un valor válido, en este caso filas*/
    while(true){
        printf("[Fila]: ");
        if((!validate(scanf("%d",&fila))) or (fila < 0 or fila > tamano)){
            system("cls");
            imprimir();
            printf("[Matriz]: %d\n",matriz);
        }else{
            break;
        }
    }

    /* Un ciclo que seguirá pidiendo al usuario un valor hasta que el usuario ingrese un valor válido, en este caso columnas*/
    while(true){
        printf("[Columna]: ");
        if((!validate(scanf("%d",&columna))) or (columna < 0 or columna > tamano)){
            system("cls");
            imprimir();
            printf("[Matriz]: %d\n",matriz);
            printf("[Fila]: %d\n",fila);
        }else{
            break;
        }
    }
     /* Un ciclo que seguirá pidiendo al usuario un valor hasta que el usuario ingrese un valor válido, en este caso el valor final*/
    while(true){
        printf("[Valor]: ");
        if(!validate(scanf("%d",&valor))){
            system("cls");
            imprimir();
            printf("[Matriz]: %d\n",matriz);
            printf("[Fila]: %d\n",fila);
            printf("[Columna]: %d\n",columna);
        }else{
            if(matriz == 1){
                matriza[fila - 1][columna - 1] = valor;    
            }else if(matriz == 2){
                matrizb[fila - 1][columna - 1] = valor;
            }
            break;
        }
        
    }
    system("cls");
    imprimir();
    menu();
}

/**
 * Suma el valor de la variable seleccion a la variable suma.
 * 
 * seleccion es el número de la opción seleccionada por el usuario.
 */
void adicion(int seleccion){
    int cont = 0;
    int x = 0;
    int y = 0;

    while (cont != 2){
        while(y != tamano){
            while(x != tamano){
                if(seleccion == 1){
                    matrizr[x][y] = matriza[x][y] + matrizb[x][y];    
                }else if(seleccion == 2){
                    matrizr[x][y] = matriza[x][y] - matrizb[x][y];
                }
                x++;
            }
            x = 0;
            y ++;
        }
        x = 0;
        y = 0;
        cont ++;
    }
}

/**
 * Multiplica dos números.
 */
void multiplicar(){
    for(int x = 0; x < tamano; ++x){
        for(int y = 0; y < tamano; ++y){
            for(int z = 0; z < tamano; ++z){
                matrizr[x][y] += matrizb[x][z] * matriza[z][y];
            }
        }
    }
}

/**
 * Divide las dos matrices.
 */
void dividir(){
    int x = 0;
    int y = 0;
    multiplicar();
    /* Llenar las matrices con números aleatorios. */
    while(y != tamano){
        while(x != tamano){
            matrizt[x][y] = matrizr[y][x];
            x++;
        }
        x = 0;
        y ++;
    }
    x = 0;
    y = 0;
    imprimir();
    
    printf("\n\n[Division]: \n\n");
    while(y != tamano){
        while(x != tamano){
            printf("[%d]\t",matrizt[x][y]);
            x++;
        }
        x = 0;
        y ++;
        printf("\n");
    }
}

/**
 * Borra los valores de las matrices
 */
void vaciar(){
    int cont = 0;
    int x = 0;
    int y = 0;

    /* Llenar las matrices con números aleatorios. */
    while (cont != 2){
        while(y != tamano){
            while(x != tamano){
               if(cont == 0){
                    matriza[x][y] = 0;
                }else if(cont == 1){
                    matrizb[x][y] = 0;
                }
                x++;
            }
            x = 0;
            y ++;
        }
        x = 0;
        y = 0;
        cont ++;
    }

}

/**
 * *|CURSOR_MARCADOR|*
 */
void resultado(){
    color(9);
    printf("[Resultado]: \n");
    
    int x = 0;
    int y = 0;

    color(15);
    while(y != tamano){
        while(x != tamano){
            printf("[%d]\t",matrizr[x][y]);
            x++;
        }
        x = 0;
        y ++;
        printf("\n");
    }
    x = 0;
    y = 0;
}