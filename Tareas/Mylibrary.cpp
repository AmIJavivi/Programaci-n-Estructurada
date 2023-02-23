void posto0(){
    if(posicion1 == 10){
        posicion1 = 0;
    }
    if(posicion2 == 10){
        posicion2 = 0;
    }
}

void printscreen(){
    system("cls");

    int contador = 0; 
    int rep = 0;

    while(rep != 2){
        while(contador != 10)
        {
            if(rep == 0){
                if(contador == posicion1){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("->");
                    SetConsoleTextAttribute(hConsole, 10);
                }
                printf("[%s] ",arreglo1[contador]);
                SetConsoleTextAttribute(hConsole, 15);
            }else if(rep == 1){
                if(contador == posicion2){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("->");
                    SetConsoleTextAttribute(hConsole, 10);
                }
                printf("[%s] ",arreglo2[contador]);
                SetConsoleTextAttribute(hConsole, 15);
            }
            contador++;
        }
        printf("\n\n");
        rep++;
        contador = 0;
    }
    
}

bool validate(int seleccion){
    if(float(seleccion) != 1){
        fflush(stdin);
        printf("Ese no es un valor valido, revisa las opciones e intenta de nuevo\n\n");
        return false;
    }else{
        return true;
    }
}

void inserttoarr(int arreglodes, bool borrar){
    if(borrar){
        if(arreglodes == 1){
            strcpy(arreglo1[posicion1], "");
            posicion1 += 1;
        }else if(arreglodes == 2){
            strcpy(arreglo2[posicion2], "");
            posicion2 += 1;
        }
    }else{
       printf("\n[Valor]: ");
        if(arreglodes == 1){
            fgets(arreglo1[posicion1], 20, stdin);
            arreglo1[posicion1][strcspn(arreglo1[posicion1], "\n")] = 0;
            posicion1 += 1;
        }else if(arreglodes == 2){
            fgets(arreglo2[posicion2], 20, stdin);
            arreglo2[posicion2][strcspn(arreglo2[posicion2], "\n")] = 0;
            posicion2 += 1;
        }
    }
}

void passin(int arreglodes){
    if(arreglodes == 1){
        posicion1 += 1;
    }else if(arreglodes == 2)
        posicion2 += 1;
}

void cleanarr(int arreglodes){
    int contador = 0;

    if(arreglodes == 1){
        while(contador != 10){
            strcpy(arreglo1[contador], "");
            contador++;
        }
        posicion1 = 0;  
    }else if(arreglodes == 2){
        while(contador != 10){
            strcpy(arreglo2[contador], "");
            contador++;
        }
        posicion2 = 0;
    }
}

void gotoarr(int arreglodes){
    printf("\n[Ir a la posicion]: ");
    if(arreglodes == 1){
        if(float(scanf("%d",&posicion1)) != 1 or (posicion1 < 1 or posicion1 > 10)){
            printf("\n\nEste valor esta fuera del arreglo, introduce uno valido.\n");
            system("pause");
            fflush(stdin);
        }else{
            posicion1 -= 1;
        }
    }else if(arreglodes == 2){
        if(float(scanf("%d",&posicion2)) != 1 or (posicion2 < 1 or posicion2 > 10)){
            printf("\n\nEste valor esta fuera del arreglo, introduce uno valido.\n");
            system("pause");
            fflush(stdin);
        }else{
            posicion2 -= 1;
        }
    }   
}

void unir(){
    int n = 0;
    int x = 0;

    /* Copiando los valores del arreglo arreglo1 al arreglo arreglo3. */
    for(int i = 0; i <= 9; i++){
        strcpy(arreglo3[i], arreglo1[i]);
        n++;
        x++;
    }
    
    /* Comparando las dos matrices y si el valor no está en la segunda matriz, lo agregará a la segunda
    matriz. */
    for(int i = 0; i <= 9; i++){
        int cont = 0;
        while(cont != n){
            if(string(arreglo2[i]) == string(arreglo3[cont])){
                break;
            }else{
                cont++;
            }if(cont == n){
                x++;
                strcpy(arreglo3[x], arreglo2[i]);
            }
        }
    }

    /* Imprimiendo los elementos de la matriz. */
    for(int i = 0; i <= 2*n; i++){
        printf("[%s] ",arreglo3[i]);
    }
    
    system("pause");
}

void interseccion(){
    int cont = 0;



   /* Comparar los elementos de dos arreglos y si son iguales, es copiar el elemento a un tercer
   arreglo. */
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(string(arreglo1[i]) == string(arreglo2[j])) {
                strcpy(arreglo3[cont++], arreglo1[i]);
                break;
            }
        }
    }

    /* Imprimiendo los elementos de la matriz. */
    for(int i = 0; i <= 9; i++){
        printf("[%s] ",arreglo3[i]);
    }
    
    system("pause");
}

void diferencia(){
    int cont = 0;
    /* Comparando los valores de las dos matrices y si son iguales, copia el valor de la segunda matriz
    en la tercera matriz. */
    for (int i = 0; i < 10; i++) {
        bool existe = false;
        for (int j = 0; j < 10; j++) {
            if(string(arreglo1[i]) == string(arreglo2[j])) {
                existe = true;
                break;
            }
        }
        if(!existe){
            strcpy(arreglo3[cont++], arreglo1[i]);
        }
    }
    
    /* Imprimiendo los valores de la matriz. */
    for(int i = 0; i <= 9; i++){
        printf("[%s] ",arreglo3[i]);
    }

    system("pause");
}

void complemento(){
    int n = 0;

    /* Copiando los valores de la primera matriz a la tercera matriz. */
    for(int i = 0; i <= 9; i++){
        strcpy(arreglo3[i], arreglo1[i]);
        n++;
    }

    /* Comprobando si el valor de la matriz es el mismo que el valor de la otra matriz. */
    for(int i = 0; i <= 9; i++){
        int cont = 0;
        while(cont != n){
            if(string(arreglo2[i]) == string(arreglo3[cont])){
                break;
            }else{
                cont++;
            }if(cont == n){
                strcpy(arreglo3[i + n], arreglo2[i]);
            }
        }
    }
    
    int cont2 = 0;
    int rep = 0;
    
    /* Comparando los valores de las dos matrices y si son iguales, copia el valor de la segunda matriz
    en la tercera matriz. */
    for(int i = 0; i < 20; i++) {
        bool existe = false;
        for(int j = 0; j < 10; j++) {
            if(string(arreglo3[i]) == string(arreglo2[j])) {
                existe = true;
                break;
            }
        }
        if(existe) {
            strcpy(arreglo3[cont2++], arreglo2[i]);
        }
    }


    /* Imprimiendo los valores de la matriz. */
    for(int i = 0; i <= 19; i++){
        printf("[%s] ",arreglo3[i]);
    }

    system("pause");
}