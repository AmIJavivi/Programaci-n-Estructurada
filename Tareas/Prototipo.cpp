#include <iostream>

using namespace std;

int main(){
    float numero;
    
    printf("[Numero]: ");
   

    if(scanf("%f",&numero) !=  1){
        printf("letra");
    }else{
        printf("Numero %f",numero);
    }

    system("pause");
    return 0;
}