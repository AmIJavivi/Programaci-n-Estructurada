#include <iostream>

using namespace std;

int main(){
    int tamano,suma;

    scanf("%d",&tamano);
    int vector1[tamano], vector2[tamano];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < tamano; j++){
            if(i == 0){
                scanf("%d",&vector1[j]);
            }else if(i == 1){
                scanf("%d",&vector2[j]);
            }else{
                suma += vector1[j]*vector2[j];
            }
        } 
    }

    printf("%d",suma);

    return 0;
}