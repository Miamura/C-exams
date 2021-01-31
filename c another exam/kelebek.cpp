#include <stdio.h>
#include <conio.h>

int main()
{
	int i,j,k,l,sonuc,boyut,yildizsayisi,bosluksayisi;
	printf("sayi giriniz : ");
	scanf("%d",&boyut);
	if(boyut%2 == 0)
	boyut += 1;
	yildizsayisi = 1;
	bosluksayisi = boyut - 2;
	
	for(i=0;i<boyut;i++)
	{
		for(j=0;j<yildizsayisi;j++)
		printf("*");
		for(k=0;k<bosluksayisi;k++)
		printf(" ");
		for(l=0;l<yildizsayisi;l++)
		printf("*");
		 if(i < boyut / 2){
		 
            yildizsayisi+=1;
            bosluksayisi-=2;
            }
        else{
		
            yildizsayisi-=1;
             bosluksayisi+=2;
             }
            printf("\n");
	}
	
}
