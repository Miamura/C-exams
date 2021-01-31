#include <stdio.h>
#include <conio.h>

int hesapla(int x,int y)
{
	
}

int main(){
	float gun,sayi1,i;
	
	printf("para : ");
	scanf("%f",&sayi1);
	printf("gun : ");
	scanf("%f",&gun);
	
	for(i=0;i<=gun;i++)
	{
         sayi1 = sayi1+(sayi1/100*0.65);
	}
	printf("%f", sayi1);
	
	getch();
}
