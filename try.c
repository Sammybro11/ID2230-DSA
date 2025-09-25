#include<stdio.h>

int x(int a){
	if(a>1 && a<5){
		 return x(a+1);
	}
	if(a>4){
		return 0;
	}
	printf("Hello there\n");
	return 0;
}

int main(){
	
	int y = x(2);

	return 0;
}
