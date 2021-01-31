#include <stdio.h>
#include <conio.h>

int main()
{
	char ad[10];
	int soyad;
	
	printf("adiniz : ");
	scanf("%s", &ad);
	printf("yasiniz : ");
	scanf("%d", &soyad);
	
	printf("merhaba %s yasiniz %d",ad,soyad);
	getch();
	return 0;
}
