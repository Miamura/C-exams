#include <stdio.h>
#include <conio.h>
// kar��lar�nda ne old yaz�yordu ilk soruda d y vard� onlarda ad tan�mlamalar�yla ilgiliydi.
//3. soruda srand� soruyordu 5 ile 23 aras�nda rastgelesay� ald�r�yordu
int main()
{
	int deger;
	deger = 12;
	printf("%d",deger++);
	printf("%d",deger);
	printf("%d",++deger);
	deger = ++deger / 5;
	printf("%d",deger);
	deger = ++deger / 2 ;
	printf("%d",deger);
	
	getch();
}
