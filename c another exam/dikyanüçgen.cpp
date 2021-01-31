#include <stdio.h>
#include <conio.h>

int main()
{
	int i,j,k,sonuc,boyut,yildizsayisi;
	
	printf("sayi giriniz : ");
	scanf("%d",&boyut);
	if(boyut%2 == 0)
	boyut += 1;
	yildizsayisi = 1;
	
	for(i=0;i<boyut;i++)
	{
		for(j=0;j<yildizsayisi;j++)
		printf("*");
		 if(i < boyut / 2)
            yildizsayisi+=1;
        else
            yildizsayisi-=1;
            printf("\n");
	}
	
}
