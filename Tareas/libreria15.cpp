bool revisar_lleno(){
    /* Comprobando si el tablero está lleno. */
    casillas = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            /* Comprobando si el tablero está lleno. */
            if(gato_matriz[i][j] == ' '){
                break;
            }else{
                casillas += 1;
            }
        }   
    }
}

/**
 * Comprueba si el jugador ha ganado comprobando si hay tres X u O en una fila, columna o diagonal.
 * 
 * regresa Un valor booleano.
 */
bool revisar_victoria(){
        /* Comprobar si el jugador 1 ha ganado. */
    if(((gato_matriz[0][0] == 'X') and (gato_matriz[0][1] == 'X') and (gato_matriz[0][2] == 'X')) or ((gato_matriz[1][0] == 'X') and (gato_matriz[1][1] == 'X') and (gato_matriz[1][2] == 'X')) or ((gato_matriz[2][0] == 'X') and (gato_matriz[2][1] == 'X') and (gato_matriz[2][2] == 'X')) 
    or ((gato_matriz[0][0] == 'X') and (gato_matriz[1][0] == 'X') and (gato_matriz[2][0] == 'X')) or ((gato_matriz[0][1] == 'X') and (gato_matriz[1][1] == 'X') and (gato_matriz[2][1] == 'X')) or ((gato_matriz[0][2] == 'X') and (gato_matriz[1][2] == 'X') and (gato_matriz[2][2] == 'X'))
    or ((gato_matriz[0][0] == 'X') and (gato_matriz[1][1] == 'X') and (gato_matriz[2][2] == 'X')) or ((gato_matriz[0][2] == 'X') and (gato_matriz[1][1] == 'X') and (gato_matriz[2][0] == 'X'))){
        printf("%s Gana\n\n",nombres[0]);
        puntos[0] += 1;
        system("pause");
        return true;
    }else if/* Comprobar si el jugador 2 ha ganado. */
    (((gato_matriz[0][0] == 'O') and (gato_matriz[0][1] == 'O') and (gato_matriz[0][2] == 'O')) or ((gato_matriz[1][0] == 'O') and (gato_matriz[1][1] == 'O') and (gato_matriz[1][2] == 'O')) or ((gato_matriz[2][0] == 'O') and (gato_matriz[2][1] == 'O') and (gato_matriz[2][2] == 'O')) 
    or ((gato_matriz[0][0] == 'O') and (gato_matriz[1][0] == 'O') and (gato_matriz[2][0] == 'O')) or ((gato_matriz[0][1] == 'O') and (gato_matriz[1][1] == 'O') and (gato_matriz[2][1] == 'O')) or ((gato_matriz[0][2] == 'O') and (gato_matriz[1][2] == 'O') and (gato_matriz[2][2] == 'O'))
    or ((gato_matriz[0][0] == 'O') and (gato_matriz[1][1] == 'O') and (gato_matriz[2][2] == 'O')) or ((gato_matriz[0][2] == 'O') and (gato_matriz[1][1] == 'O') and (gato_matriz[2][0] == 'O'))){
        printf("%s Gana\n\n",nombres[1]);
        puntos[1] += 1;
        system("pause");
        return true;
    }
    else if(/* Comprobar si el bot ha ganado. */
    ((gato_matriz[0][0] == '0') and (gato_matriz[0][1] == '0') and (gato_matriz[0][2] == '0')) or ((gato_matriz[1][0] == '0') and (gato_matriz[1][1] == '0') and (gato_matriz[1][2] == '0')) or ((gato_matriz[2][0] == '0') and (gato_matriz[2][1] == '0') and (gato_matriz[2][2] == '0')) 
    or ((gato_matriz[0][0] == '0') and (gato_matriz[1][0] == '0') and (gato_matriz[2][0] == '0')) or ((gato_matriz[0][1] == '0') and (gato_matriz[1][1] == '0') and (gato_matriz[2][1] == '0')) or ((gato_matriz[0][2] == '0') and (gato_matriz[1][2] == '0') and (gato_matriz[2][2] == '0'))
    or ((gato_matriz[0][0] == '0') and (gato_matriz[1][1] == '0') and (gato_matriz[2][2] == '0')) or ((gato_matriz[0][2] == '0') and (gato_matriz[1][1] == '0') and (gato_matriz[2][0] == '0'))){
        printf("%s Gana\n\n",nombres[2]);
        puntos[2] += 1;
        system("pause");
        return true;
    }else{
        return false;    
    }
}


/**
 * jugador El jugador al que le toca es.
 */
void llenar_gato(int jugador){
    int fila, columna = 0;
    switch(jugador){
        case 0:
            fila = rand()%3;
            columna = rand()%3;

            if(gato_matriz[fila][columna] == ' '){
                gato_matriz[fila][columna] = '0';
            }else{
                llenar_gato(jugador);
            }
            break;
        case 1:
        case 2:
            printf("[Introduce una Fila]: ");
            while((!scanf("%d",&fila)) or !(1 <= fila and fila <= 3)){
                printf("[Introduce una Fila valida]: ");
                fflush(stdin);
            }
            printf("[Introduce una Columna]: ");
            while(!scanf("%d",&columna) or !(1 <= columna and columna <= 3)){
                printf("[Introduce una Columna valida]: ");
                fflush(stdin);
            }
            if(!(gato_matriz[fila-1][columna-1] == ' ')){
                printf("[Introduce una casilla valida]\n");
                llenar_gato(jugador);
            }else{
                fila -= 1;
                columna -= 1;
                if(jugador == 1){
                    gato_matriz[fila][columna] = 'X';
                }else{
                    gato_matriz[fila][columna] = 'O';
                }    
            }
            break;
        case 3:
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    gato_matriz[i][j] = ' ';
                }   
            }
            break;
    }
}

void imprimir_gato(){
    system("cls");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("[%c] ",gato_matriz[i][j]);
        }   
        printf("\n");
    }
    printf("\n[%d]",casillas);
}



bool /* Una función que devuelve un valor booleano mientras se ejecuta un juego. */
vscpu(){
    imprimir_gato();
    llenar_gato(1);
    imprimir_gato();
    /* Comprobar si el jugador ha ganado. */
    if(revisar_victoria()){
        return true;
    }
    /* Al verificar si el tablero está lleno y si lo está, imprime "Empate" y devuelve verdadero. */
    if(revisar_lleno() and casillas == 9){
        printf("Empate");
        return true;
    }
    imprimir_gato();
    llenar_gato(0);
    imprimir_gato();
    /* Comprobar si el jugador ha ganado. */
    if(revisar_victoria()){
        return true;
    }
    /* Al verificar si el tablero está lleno y si lo está, imprime "Empate" y devuelve verdadero. */
    if(revisar_lleno() and casillas == 9){
        printf("Empate");
        return true;
    }
    return false;
}

/**
 * Devuelve un valor booleano.
 */
bool vsjugador(){
    imprimir_gato();
    llenar_gato(1);
    imprimir_gato();
    /* Comprobar si el jugador ha ganado. */
    if(revisar_victoria()){
        return true;
    }
   /* Verificando si el tablero está lleno y si lo está, imprime "Tie" y devuelve verdadero. */
    if(revisar_lleno() and casillas == 9){
        printf("Empate");
        return true;
    }
    imprimir_gato();
    llenar_gato(2);
    imprimir_gato();
    /* Comprobar si el jugador ha ganado. */
    if(revisar_victoria()){
        return true;
    }
    /* Comprueba si el tablero está lleno y, si lo está, imprime "Tie" y devuelve verdadero. */
    if(revisar_lleno() and casillas == 9){
        printf("Empate");
        system("pause");
        return true;
    }
    return false;
}
