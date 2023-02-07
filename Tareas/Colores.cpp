#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int cont = 0;
    
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    

    while(cont != 20){
        SetConsoleTextAttribute(hConsole, cont);
        printf("%d",cont);
        cont += 1;
    }

    system("pause");

}