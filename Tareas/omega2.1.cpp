#include <iostream>

using namespace std;

int main(){
    int tamano;
    bool mayorque = true;

    scanf("%d",&tamano);
    int vector1[tamano], vector2[tamano];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < tamano; j++){
            if(i == 0){
                scanf("%d",&vector1[j]);
            }else if(i == 1){
                scanf("%d",&vector2[j]);
            }else{
                if(vector1[j] > vector2[j]){
                }else{
                    mayorque = false;
                    break;
                }
            }
        } 
    }

    if(mayorque){
        printf("1");
    }else{
        printf("0");
    }

    system("pause");

    return 0;
}