#include <Windows.h>
		
gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hcon,dwPos);
}
gotox(int x){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	
	dwPos.X = x;
	
	SetConsoleCursorPosition(hcon,dwPos);
}

color(int color){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, color);
}

/*Impresión del título del juego.*/
void imprimir(){
    printf("      ___           ___           ___           ___           ___           ___           ___           ___     \n     /\\  \\         /\\__\\         /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\  \\    \n    /::\\  \\       /:/  /        /::\\  \\       /::\\  \\       /::\\  \\       /::\\  \\       /::\\  \\       /::\\  \\   \n   /:/\\:\\  \\     /:/__/        /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\  \n  /::\\~\\:\\  \\   /::\\  \\ ___   /:/  \\:\\  \\   /::\\~\\:\\  \\   /:/  \\:\\  \\   /::\\~\\:\\  \\   /:/  \\:\\__\\   /:/  \\:\\  \\ \n /:/\\:\\ \\:\\__\\ /:/\\:\\  /\\__\\ /:/__/ \\:\\__\\ /:/\\:\\ \\:\\__\\ /:/__/ \\:\\__\\ /:/\\:\\ \\:\\__\\ /:/__/ \\:|__| /:/__/ \\:\\__\\ \n \\/__\\:\\/:/  / \\/__\\:\\/:/  / \\:\\  \\ /:/  / \\/_|::\\/:/  / \\:\\  \\  \\/__/ \\/__\\:\\/:/  / \\:\\  \\ /:/  / \\:\\  \\ /:/  /\n      \\::/  /       \\::/  /   \\:\\  /:/  /     |:|::/  /   \\:\\  \\            \\::/  /   \\:\\  /:/  /   \\:\\  /:/  / \n      /:/  /        /:/  /     \\:\\/:/  /      |:|\\/__/     \\:\\  \\           /:/  /     \\:\\/:/  /     \\:\\/:/  /  \n     /:/  /        /:/  /       \\::/  /       |:|  |        \\:\\__\\         /:/  /       \\::/__/       \\::/  /   \n     \\/__/         \\/__/         \\/__/         \\|__|         \\/__/         \\/__/         ~~            \\/__/    \n\n\n\n");
}

/*Es una función que imprime el verdugo.*/
void fase(int fase){
    gotoxy(50,16);
    printf("   _ _ _ _ _ _ _ _\n");
    gotoxy(50,17);
    printf("   |   /         |\n");
    gotoxy(50,18);
    printf("   |  /          |\n");
    gotoxy(50,19);
    printf("   | /           |\n");
    switch(fase){
        case 0:
            gotoxy(50,20);
            printf("   |/\n");
            gotoxy(50,21);
            printf("   |\n");
            gotoxy(50,22);
            printf("   |\n");
            gotoxy(50,23);
            printf("   |\n");
            break;
        case 1:
            gotoxy(50,20);
            printf("   |/          (x_x)\n");
            gotoxy(50,21);
            printf("   |\n");
            gotoxy(50,22);
            printf("   |\n");
            gotoxy(50,23);
            printf("   |\n");
            break;
        case 2:
            gotoxy(50,20);
            printf("   |/          (x_x)\n");
            gotoxy(50,21);
            printf("   |             |\n");
            gotoxy(50,22);
            printf("   |             |\n");
            gotoxy(50,23);
            printf("   |\n");
            break;
        case 3:
            gotoxy(50,20);
            printf("   |/          (x_x)\n");
            gotoxy(50,21);
            printf("   |            /| \n");
            gotoxy(50,22);
            printf("   |             | \n");
            gotoxy(50,23);
            printf("   |\n");
            break;
        case 4:
            gotoxy(50,20);
            printf("   |/          (x_x)\n");
            gotoxy(50,21);
            printf("   |            /|\\ \n");
            gotoxy(50,22);
            printf("   |             | \n");
            gotoxy(50,23);
            printf("   |\n");
            break;
        case 5:
            gotoxy(50,20);
            printf("   |/          (x_x)\n");
            gotoxy(50,21);
            printf("   |            /|\\ \n");
            gotoxy(50,22);
            printf("   |             | \n");
            gotoxy(50,23);
            printf("   |            / \n");
            break;
        case 6:
            gotoxy(50,20);
            printf("   |/          (x_x)\n");
            gotoxy(50,21);
            printf("   |            /|\\ \n");
            gotoxy(50,22);
            printf("   |             | \n");
            gotoxy(50,23);
            printf("   |            / \\\n");
    }
    gotoxy(50,24);
    printf("___|________ \n");
    gotoxy(50,25);
    printf("   |       /| \n");
    gotoxy(50,26);
    printf("          / | \n");
    gotoxy(50,27);
    printf("_________/   \n");
    gotoxy(50,28);
    printf("         | 	\n");
    gotoxy(50,29);
    printf("         | 	 \n");
}

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

bool esta_en_la_frase(char frase[], char letra){
    for(int i = 0; i <= strlen(frase); i++){
        if(frase[i] == letra){
            return true;
            break;
        }
    }
    return false;
}