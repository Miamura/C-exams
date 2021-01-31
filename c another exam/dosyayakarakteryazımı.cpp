#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	char yazi;
	FILE *ornek_dosya;

	if((ornek_dosya=fopen("aba.txt","w"))==NULL)
	{
		puts("dosya acilamiyor");
		getch();
		exit(0);
	}
	yazi='anne';
	fputs(yazi,ornek_dosya);
	fclose(ornek_dosya);
	
	getch();
	
}
