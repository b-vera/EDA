#include <stdio.h>

int main (){
	int a[5];
	int i;
	for(i=0;i<5;i++){
		printf("ingrese numero");
		scanf("%i",&a[i]);
	}
	for(i=4;i>=0;i--){
		printf("%d\n",a[i]);
	}
	return 0;
}