#include <stdio.h>
#include <conio.h>

int main()
{
	int sol=20, sag=4, sonuc;
	char islem;
	
	switch(islem)
	{
		case'+':
			sonuc= sol + sag;
			break;
		case'-':
			sonuc= sol - sag;
			break;
		case'*':
			sonuc= sol * sag;
			break;
		case'/':
			sonuc= sol / sag;
			break;
			default:
				printf("boyle bir islem yok");
				break;
	}
	
	printf("%d",sonuc);
	getch();
}
