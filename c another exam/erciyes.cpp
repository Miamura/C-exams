#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[])
{        
    int sayi,i,j,k,sayac; //kullan�c�dan alaca��m�z say� ve 3 tane for d�ng�s� i�in i,j,k
    int dizi[10]={0,0,0,0,0,0,0,0,0,0}; //1-9 aras�nda say�lar� bar�nd�ran dizi �-� yerine �0� 
    printf("sayi gir :"); 
    scanf("%d",&sayi); 
	  
    for(i=sayi;i>=1;i--) 
	{                                                
    dizi[sayi-1]=i; //9. say� 10 a e�it
    printf("\n"); 
    for(j=0;j<=sayi-1;j++)
	{  
    printf("%d ",dizi[j]); 
    }                                                                                      
           sayac=sayi;           
           for(k=i-2;k<=sayi+2;k++)
	{     
           dizi[k]=sayac; 
           sayac--;
	}                                                                                               
    }                      
  getch();	
  return 0;
}
