/******************** Presentacion ********************
[Nombre]: Garnica Escamilla Luis Javier.
[Fecha]: 30 de Enero de 2023.
[Programa]: Actividad4.cpp 
Centro Universitario de los Altos.
Ingenieria en Comptuacion 2do Semestre.
[Profesor]: Franco Casillas Sergio.
[Descripcion]:  Este programa permitira jugar al ahorcado
******************************************************/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Act13lib.h"

using namespace std;

bool esta_en_la_frase(char frase[], char letra);
int fallos = 0;
char letra_seleccionada = ' '; 

int main(){
    system("cls");
    imprimir(); 
    srand((unsigned)time(NULL));
    
    /* Declarar las variables que se utilizarán en el programa. */
    int salir, conterror = 0;
    char palabras[20][40] = {"TIA PAOLA", "CHAYANNE ES MI APA", "JUANITO PEREZ DE LA O", "CARLOS SALINAS", "PEDRITO SOLA", "PATY CHAPOY", "LOPEZ OBRADOR", "NEVER GONNA GIVE YOU UP", "MICHAEL", "ARANDAS", "VOLLEYBALL", "MINECRAFT", "ME JODI LA RODILLA", "PROFE PONGAME DIEZ", "PRINTF","HOLA MUNDO","POR ESO JOVEN","DREAM ON","ANDRES MANUEL","CAMILO SESTO"};
    char* frase_a_utilizar = palabras[rand()%19];
    char aciertos[strlen(frase_a_utilizar)];
    
    /* Inicializando el array `aciertos` con espacios. */
    for(int i = 0; i <= (strlen(frase_a_utilizar)) - 1; i++){
        aciertos[i] = ' ';
    }

    /* Un bucle infinito. */
    while(true){
        system("cls");
        imprimir();
        /* Está comprobando si el usuario ha perdido el juego. */
        if(fallos == 6){
            color(10);
            printf("\n\n\n\n\t\t\tPERDISTE!\n\n\n\t[Reintentar = 1]\t[Salir = 0]\n\n[Seleccion]: ");
        }
        /* Está comprobando si el usuario ha ganado el juego. */
        if(string(aciertos) == string(frase_a_utilizar)){
            color(10);
            printf("\n\n\n\n\t\t\tGanaste!\n\n\n\t[Reintentar = 1]\t[Salir = 0]\n\n[Seleccion]: ");
        }
        /* Es comprobar si el usuario ha perdido o ganado el juego. */
        if((fallos == 6) or (string(aciertos) == string(frase_a_utilizar))){
            scanf("%d", &salir);
            if(salir == 0){
                system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
                abort();
            }else{
                color(15);
                fflush(stdin);
                fallos = 0;
                main();
            }
        }
    
        /* Imprimir la palabra con espacios y guiones bajos. */
        for(int i = 0; i <= (strlen(frase_a_utilizar)) - 1; i++){
            if(frase_a_utilizar[i] == ' '){
               printf("\n");
            }else if(aciertos[i] == ' '){
               printf(" _ ");
            }else{
                printf(" %c ", aciertos[i]);
            }
        }
        printf("\n\n[Errores]: %d", fallos);

        fase(fallos);
        
        printf("\n\n[letra]: ");
        scanf("%c", &letra_seleccionada);
        letra_seleccionada = cambiar_a_mayuscula_o_minuscula(letra_seleccionada, true);
        

       /* Comprobando si la letra está en la palabra. */
        for(int i = 0; i <= (strlen(frase_a_utilizar)) - 1; i++){
            if(frase_a_utilizar[i] == letra_seleccionada){
                aciertos[i] = letra_seleccionada;
            }
        }
        /* Es comprobar si la letra es una vocal. */
        switch(letra_seleccionada){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                fallos++;
                break;
            default:
               /* Comprobando si la letra está en la frase. */
                if(!esta_en_la_frase(frase_a_utilizar,letra_seleccionada)){
                    fallos += 1;
                    fflush(stdin);
                    system("pause");
                }  
                break;
        }
       /* Es comprobar si la letra está en la frase. */
        if(esta_en_la_frase(frase_a_utilizar,letra_seleccionada)){
            fallos -= 1;
        } 
    }

}

