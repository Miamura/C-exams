#include <stdio.h>
#include <conio.h>

int main()
{
	int a=5,b=7,toplam,fark,carpim,kalan;
	float bolum;
	
	toplam=a+b;
	fark=a-b;
	carpim=a*b;
    bolum =(float)a/(float)b;
	
	printf("a ve b nin ; \nToplami : %d\nFarki : %d\nCarpimi : %d\n",toplam,fark,carpim);
	printf("bolumu : %.10f",bolum);
	
	getch();
}
