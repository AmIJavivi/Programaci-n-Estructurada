#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include "Javi.h"

using namespace std;

int main(){
	srand((unsigned)time(NULL));
	int x;x=0;
	int y;y=20;
	int c;c=0;
	
	for(int s=0;s<=80;s++){
	
	c=rand()%2;
	if(c==0){
		y++;
		gotoxy(x,y);
		printf("*");
		x++;
	}
	else if(c==1){
		y--;
		gotoxy(x,y);
		printf("*");
		x++;
	}
	
	}
	
    system("pause");
    system("cls");
    main();
}