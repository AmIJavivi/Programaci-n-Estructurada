#include <iostream>
#include <windows.h>
#include "Javi.h"

using namespace std;

int main(){
    int cont = 0;
    
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    

    while(cont != 30){
        color(cont);
        gotoxy(1,cont);
        printf("%d",cont);
        cont += 1;
    }

    system("pause");

}