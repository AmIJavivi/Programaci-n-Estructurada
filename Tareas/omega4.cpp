#include <iostream>

using namespace std;

int valor, total, t = 1;

int modulo(){
    for(int i = 0; i <= valor; i++){
        t = t*(valor-i);
        total += t;    
    }
}

int main(){
    scanf("%d",&valor);
    printf("%d",total);
}