#include "Link.h"

void main(){
	int x;
	x = Main_Menu();
	printf("test outer");
	printf("\n");
	if (x==1){
		main_2();
	}
}
