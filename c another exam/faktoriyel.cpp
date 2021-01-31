#include <stdio.h>
#include <conio.h>

int fakt(int deger)
{
	int i , sonuc = 1;
	for(i=1;i<=deger;i++)
	{
		sonuc=i*sonuc;
	}
	return sonuc;
}

int main()
{
	int sayi, cevap;
	
	printf ("faktoriyeli alinacak sayi : ");
	scanf("%d",&sayi);
	
	cevap =fakt(sayi);
	
	printf("%d",cevap);
	
	getch();
	return 0;
}

