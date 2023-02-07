#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int a[10][10];
  int contador1, contador2 = 0;
  while(contador1 != 10){
    while(contador2 != 10){
      a[contador1][contador2] = contador1;  
      contador2 += 1;
    }
    contador1 += 1;
  }

  contador1, contador2 = 0;

  while(contador1 != 10){
    while(contador2 != 10){
      cout<<a[contador1][contador2];  
      contador2 += 1;
    }
    contador1 += 1;
  }

  system("pause");
}