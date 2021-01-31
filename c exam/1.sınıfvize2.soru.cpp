#include <stdio.h>
#include <conio.h>
// karşılarında ne old yazıyordu ilk soruda d y vardı onlarda ad tanımlamalarıyla ilgiliydi.
//3. soruda srandı soruyordu 5 ile 23 arasında rastgelesayı aldırıyordu
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
