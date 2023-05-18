#include <iostream>

using namespace std;

int x, y = 0;

void calculo(){
    if(x < 40){
        printf("%d",y*x);
    }else if(x < 50){
        printf("%f",((40*y)+((x-40)*(y*1.5))));
    }else{
        printf("%f",((40*y)+((x-40)*(y*2))));
    }
}

int main(){
    scanf("%d",&x);
    scanf("%d",&y);

    calculo();

    return 0;
}