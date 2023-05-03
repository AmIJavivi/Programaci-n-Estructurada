#include <iostream>

using namespace std;

int main(){
  int numero, tamano = 0;
  cin>>tamano;
  
  int arreglo[tamano];

  for(int i = 0; i < tamano; i++){
    cin>>arreglo[i];
  }

  cin>>numero;

  for(int i = 0; i < tamano; i++){
    if(arreglo[i] % numero == 0){
      cout<<arreglo[i]<<" ";
    }else{
      cout<<"X ";
    }
  }

  return 0;
}