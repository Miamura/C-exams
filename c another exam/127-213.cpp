#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i,a[1000];
    srand(time(NULL));//time.h yazmam�z gerkiyor bu kod rastgele say�y� bir daha rastgele yapar.
	for(i=0;i<1000;i++)
	{
		a[i]=rand()%87+127;//mod 127 ile 213 aras�nda say� 
	}
	for(i=0;i<1000;i++)
	{
		printf("%d. rastgele sayi : %d\n",i,a[i]);
	}
	getch();
	return 0;
}
