/* Importación de las bibliotecas `iostream` y `string.h` */
#include <iostream>
#include <math.h>
#include "Javi.h"

using namespace std;

int torres[8][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int discos, movimientos = 0;
float minimos;
bool llena = false;


void llenar();
void perfectos();
void imprimir_gui();
bool validar_si_arriba_es_mayor(int torre_inicio, int torre_destino, int &casilla_inicio, int &casilla_destino);

int main(){
    if(!llena){
        llenar();
        llena = true;
    }
    system("cls");
    perfectos();
    imprimir_gui();

    int torre_inicio, torre_destino = 0;

    color(7); 
    printf("[Torre inicio]: ");
    while(!scanf("%d",&torre_inicio) or (torre_inicio < 1 or torre_inicio > 3)){
        printf("[Torre inicio]: ");
    }
    printf("[Torre destino]: ");
    while(!scanf("%d",&torre_destino) or (torre_destino < 1 or torre_destino > 3)){
        printf("[Torre destino]: ");
    }
    
    int casilla_destino, casilla_inicio = 0;

    if(validar_si_arriba_es_mayor(torre_inicio-1, torre_destino-1, casilla_inicio, casilla_destino)){
        torres[7-casilla_destino][torre_destino-1] = torres[7-casilla_inicio+1][torre_inicio-1];
        torres[7-casilla_inicio+1][torre_inicio-1] = 0;
        movimientos+=1;
    }

    main();
    
}

void perfectos(){
    minimos = (pow(2,discos))-1;
}

void imprimir_gui(){
    printf("[Movimientos \"Perfectos\"]: %f\t\t[Movimintos realizados]: %d\n\n",minimos,movimientos);
    for(int i = 0; i <= 7; i++){
        for(int j = 0; j <= 2; j++){
            color(torres[i][j]+7);
            printf("[==%d==]\t",torres[i][j]);
        }
        printf("\n");
    }
}

void llenar(){
    printf("[Discos]: ");
    while(!scanf("%d",&discos) or (discos < 3 or discos > 7)){
        system("cls");
        fflush(stdin);
        printf("[Discos]: ");
    }
    
    for(int i = 0; i <= discos; i++){
        torres[7-i][0] = discos - i;
    }
}

bool validar_si_arriba_es_mayor(int torre_inicio, int torre_destino, int &casilla_inicio, int &casilla_destino){
    int casilladestino = 0;
    for(casilladestino = 0; casilladestino <= 7; casilladestino++){
        printf("%d",casilladestino);
        if(torres[7-casilladestino][torre_destino] == 0){
            break;
        }        
    }
    int casillainicio = 0;
    for(casillainicio = 0; casillainicio <= 7; casillainicio++){
        if(torres[7-casillainicio][torre_inicio] == 0){
            break;
        }
        printf("%d",casillainicio);
    }
    if(casilladestino == 0 or (torres[7-casilladestino+1][torre_destino] > torres[7-casillainicio+1][torre_inicio])){
         casilla_inicio = casillainicio;
        casilla_destino = casilladestino;
        printf("Sip");
        return 1;
        
    }else{
        printf("Nop");
        return 0;
    }
}
