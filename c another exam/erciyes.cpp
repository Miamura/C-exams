#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[])
{        
    int sayi,i,j,k,sayac; //kullanýcýdan alacaðýmýz sayý ve 3 tane for döngüsü için i,j,k
    int dizi[10]={0,0,0,0,0,0,0,0,0,0}; //1-9 arasýnda sayýlarý barýndýran dizi “-” yerine “0” 
    printf("sayi gir :"); 
    scanf("%d",&sayi); 
	  
    for(i=sayi;i>=1;i--) 
	{                                                
    dizi[sayi-1]=i; //9. sayý 10 a eþit
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
