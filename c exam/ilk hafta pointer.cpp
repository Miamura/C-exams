#include <stdio.h>

int main(){
	int sayi5=5;
    int sayi2=2;
    int sayi3=3;
	
	int *p1;
	int *p2;
	
	
	printf("degiskenin degeri : %d \n", sayi5);
	printf("adresi : %p \n", &sayi5);
	
	printf("degiskenin degeri : %d \n", sayi2);
	printf("adresi : %p \n", &sayi2);
	
	printf("degiskenin degeri : %d \n", p1);
	printf("adresi : %p \n", p1);
	
	p1 = &sayi2;
	
	printf("degiskenin degeri : %d \n", p1);
	printf("adresi : %p \n", p1);
	
	
	printf("degiskenin degeri : %d \n", sayi3);
	printf("adresi : %p \n", &sayi3);
	
	printf("degiskenin degeri : %d \n", p2);
	printf("adresi : %p \n", p2);
	
	p2 = &sayi5;
	sayi3 = *p2;
	
	printf("degiskenin degeri : %d \n", sayi3);
	printf("adresi : %p \n", &sayi3);
	
	

	
}
