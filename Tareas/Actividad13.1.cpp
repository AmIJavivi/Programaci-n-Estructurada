#include <iostream>
#include <string.h>

using namespace std;

char llenar(char frase[], char caracter);
void imprimir();
bool esta_en_la_frase(char frase[], char letra);
void ahorcar(int fase);

void titulo(){
    printf("      ___           ___           ___           ___           ___           ___           ___           ___     \n");
    printf("     /\\  \\         /\\__\\         /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\    \n");
    printf("    /::\\  \\       /:/  /        /::\\  \\       /::\\  \\       /::\\  \\       /::\\  \\       /::\\  \\       /::\\  \\   \n");
    printf("   /:/\\:\\  \\     /:/__/        /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\  \n");
    printf("  /::\\~\\:\\  \\   /::\\  \\ ___   /:/  \\:\\  \\   /::\\~\\:\\  \\   /:/  \\:\\  \\   /::\\~\\:\\  \\   /:/  \\:\\__\\   /:/  \\:\\  \\ \n");
    printf(" /:/\\:\\ \\:\\__\\ /:/\\:\\  /\\__\\ /:/__/ \\:\\__\\ /:/\\:\\ \\:\\__\\ /:/__/ \\:\\__\\ /:/\\:\\ \\:\\__\\ /:/__/ \\:|__| /:/__/ \\:\\__\\ \n");
    printf(" \\/__\\:\\/:/  / \\/__\\:\\/:/  / \\:\\  \\ /:/  / \\/_|::\\/:/  / \\:\\  \\  \\/__/ \\/__\\:\\/:/  / \\:\\  \\ /:/  / \\:\\  \\ /:/  /\n"); 
    printf("      \\::/  /       \\::/  /   \\:\\  /:/  /     |:|::/  /   \\:\\  \\            \\::/  /   \\:\\  /:/  /   \\:\\  /:/  / \n");
    printf("      /:/  /        /:/  /     \\:\\/:/  /      |:|\\/__/     \\:\\  \\           /:/  /     \\:\\/:/  /     \\:\\/:/  /  \n");
    printf("     /:/  /        /:/  /       \\::/  /       |:|  |        \\:\\__\\         /:/  /       \\::/__/       \\::/  /   \n");
    printf("     \\/__/         \\/__/         \\/__/         \\|__|         \\/__/         \\/__/         ~~            \\/__/    \n\n\n\n");
}

bool lleno_de_espacios = false;
int errores = 0;

char palabras[20][40] = {"palabra y pololo", "polola y sudadera", "juanito perez de la o", "Carlos salinas", "de gortari", "andres manuel", "lopez obrador", "every day i wake up", "caramelito", "caramelita"};
char* frase_a_utilizar = palabras[rand()%9];
char aciertos[strlen(frase_a_utilizar)];

int main(){
    
    
    
    if(!lleno_de_espacios){
        for(int i = 0; i <= (strlen(frase_a_utilizar)); i++){
            if(frase_a_utilizar[i] == ' '){
                aciertos[i] = '+';
            }else{
                aciertos[i] =  ' ';   
            }
        }
        lleno_de_espacios = true;
    }
    
    titulo();

    for(int i = 0; i <= (strlen(frase_a_utilizar)) - 1; i++){
        if(aciertos[i] == '+'){
           printf("\n");
        }else if(aciertos[i] == ' '){
            printf(" _ ");
        }else{
            printf(" %c ", aciertos[i]);
        }
    }

    printf("[Errores]: %d", errores);
    
    char letra_seleccionada = ' '; 
    
    printf("\n\n[letra]: ");
    scanf("%c", &letra_seleccionada);
    

    ahorcar(errores);
    system("cls");

    main();
    system("pause");
}

bool esta_en_la_frase(char frase[], char letra){
    for(int i = 0; i <= strlen(frase); i++){
        if(letra == frase[i]){
            return true;
            break;
        }
    }
}

void ahorcar(int fase){
    printf("\n\n   _ _ _ _ _ _ _ _\n");
    printf("   |   /         |\n");
    printf("   |  /          |\n");
    printf("   | /           |\n");
    switch(fase){
        case 0:
            printf("   |/\n");
            printf("   |\n");
            printf("   |\n");
            printf("   |\n");
            break;
        case 1:
            printf("   |/          (x_x)\n");
            printf("   |\n");
            printf("   |\n");
            printf("   |\n");
            break;
        case 2:
            printf("   |/          (x_x)\n");
            printf("   |             |\n");
            printf("   |             |\n");
            printf("   |\n");
            break;
        case 3:
            printf("   |/          (x_x)\n");
            printf("   |            /| \n");
            printf("   |             | \n");
            printf("   |\n");
            break;
        case 4:
            printf("   |/          (x_x)\n");
            printf("   |            /|\\ \n");
            printf("   |             | \n");
            printf("   |\n");
            break;
        case 5:
            printf("   |/          (x_x)\n");
            printf("   |            /|\\ \n");
            printf("   |             | \n");
            printf("   |            / \n");
            break;
        case 6:
            printf("   |/          (x_x)\n");
            printf("   |            /|\\ \n");
            printf("   |             | \n");
            printf("   |            / \\\n");
    }
    printf("___|________ \n");
    printf("   |       /| \n");
    printf("          / | \n");
    printf("_________/  | \n");
    printf("         | 	\n");
    printf("         | 	 \n");
    printf("         | 	 \n\n");
}
