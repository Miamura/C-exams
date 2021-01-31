#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>
#include <conio.h>

void hesapla(char Ad[],char Soyad[],int adet,float fiyat,int kacay)
{ FILE *oku,*yaz;

  int i;
  
  static char date[128];
  
  time_t t = time(NULL);
  
  struct tm *tp = localtime(&t); 
       
  float AylikTutar=(float)((adet*fiyat)/kacay);
  
  yaz=fopen("alisveris.txt","a+");  
  
  fprintf(yaz,"%s %s %s\n","Ad Soyad :" , Ad,Soyad);
  
  fprintf(yaz,"%s\t\t\t%s\n","Ödeme zamaný","Tutar");
  
   for(i=0;i<kacay;i++)
   {
        strftime(date, sizeof(date), "%d.%m.%Y", tp);
        fprintf(yaz,"%s\t\t\t%f\n",date,AylikTutar);
        if(tp->tm_mon==12)
        {    
	   	    tp->tm_year=tp->tm_year+1;
            tp->tm_mon=tp->tm_mon-11;
        }
   
        else
            tp->tm_mon=tp->tm_mon+1;
    }
    
    fprintf(yaz,"\n");
    
}

int main()
{ 
  char Ad[50],Soyad[50];
  
  int adet,kacay;
  
  float fiyat; 
  
  printf("Alisveris Yapan Kisinin Ad ve Soyadini Giriniz: \n");
  
  scanf("%s %s",&Ad,&Soyad);  
  
  printf("Alinan Urun Bilgileri ; \n");
  
  printf("Adet : ");  scanf("%d",&adet);
  
  printf("Fiyat : "); scanf("%f",&fiyat); 
  
  printf("Kac Ay Taksitlendirme Yapilsin? ");
  
  scanf("%d",&kacay); 
  
  hesapla(Ad,Soyad,adet,fiyat,kacay);
  
  printf("Islem tamamlanmistir...");
  
  getch();
}
