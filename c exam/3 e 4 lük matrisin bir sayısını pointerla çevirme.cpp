#include <stdio.h> 
#include <stdlib.h>

int main()
{
int matris[3][4]={1,2,3,4,5,6,7,8,9,10,11,12},
	i=0,
	j=0,
	indis=0;  				 
int *pointer= &matris[0][0]; 

printf("   3x4 Matris\n");

printf(" ----------------\n");  


for(j=0;j<3;j++){    

	for(i=0;i<4;i++) 
	{
		 if(indis<10)printf(" %d  ",*(pointer+indis++));  //�una tak�lmay�n sadece g�rsel olarak daha ��k g�r�nmesi i�in if kulland�m.
		 else printf("%d  ",*(pointer+indis++));  
	}
	printf("\n"); //Matris �eklini almas� i�in alt sat�ra ge�tim.
}

printf(" ----------------\n");  


printf("Silmek istedidiniz elemanin indisini yazin[0-11] :");

scanf("%d",&j);

for(;;)//Sonsuz d�ng� ile e�er istenilenin d���nda bir say� girerse uyaracak ve tekrar girmesini isteyecek.
{
	if(j>=0 && j<12)
	break; // Break kulland���m i�in else kullanmama gerek yok
	printf("[0-11] araliginda bir sayi girin : ");
	scanf("%d",&j);
}
printf("%d. indisli %d elemani siliniyor...\n",j,*(pointer+j));

for(j;j<12;j++)  //Se�ilen indisten ba�layarak son indise kadar d�ng� ol�tur.
{
	(pointer+j) = (pointer+j+1) ; //Se�ilen indisteki g�stericinin i�eri�ine bir sonraki g�stericinin i�eri�ini ata
}

          *(pointer+11)=0; //Son indiste rastgele bir say� gelecek. Soruda g�sterildi�i gibi 0 olarak de�i�tir.

//Matrisin son halini g�r�nt�lemek i�in ayn� kodu yaz�yorum...

printf("Yeni 3x4 Matris\n"); 

printf(" ----------------\n");  

indis=0;

for(j=0;j<3;j++){    
					 
	for(i=0;i<4;i++) 
	{                           		
		 if(indis<10)printf(" %d  ",*(pointer+indis++));  
		 else printf("%d  ",*(pointer+indis++));  
	}
	printf("\n"); 
}

printf(" ----------------\n");  

return 0;
}
