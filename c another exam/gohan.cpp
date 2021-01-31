#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc, char *argv[])
{
	int tamsayi[10],i=0,toplam=0,toplam2=0,say=0,toplam3=0,say2=0;
	
	for(i=0,i<10,i++)
	{
		printf("%d.indisdeki sayi gir : ",i);
		scanf("%d",&tamsayi[i]);
	}
	for(i=0,i<10,i++)
	{
		toplam+=tamsayi[i];
		if(tamsayi[i]<0)
		{
			toplam2+=tamsayi[i];
			say++;
		}
		if(tamsayi[i]>0 && i%2=0)
		{
			toplam3+=tamsayi[i];
			say2=++;
		}
	}
	printf("(cift)ortalama  : %d\n",(toplam3/say2));
	printf("(-)ortalama : %d\n",(toplam2/say));
	printf("ortalama : %d\n",(toplam/10));
	
	for(i=0;i<10;i++)
	{
		printf("%d. indisdeki sayi : %d \n",i,tamsayi[i]);
	}
	getch();
	return 0;
}


