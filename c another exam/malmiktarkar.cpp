#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Urun
{ char UrunAd[10];

  float Alis;
  
  float Satis; 
  
  int miktar;
};

void KarHesapla()

{ FILE *oku;

  struct Urun urun2;
  
  int i=0,j=0,Miktar[100];
  
  float kar=0,kartut=0;
  
  char ch;
  
  oku=fopen("stok.txt","a+b");
  
  if(oku==NULL){printf("dosya acilmadi"); exit(1);}
  
  printf("\nDosyanin Içerigi:\n");
  
  while(!feof(oku))
  
  { if( fread(&urun2,sizeof(struct Urun),1,oku)!=0)
  
    { fread(&ch,sizeof(char),1,oku);
    
      printf("%s\t",urun2.UrunAd);
      
      printf("%f\t",urun2.Alis);
      
      printf("%f\t",urun2.Satis);
      
      printf("%d\t",urun2.miktar);
      
      printf("\n");
      
      kartut=((urun2.Satis-urun2.Alis)*urun2.miktar);
      
      kar=kar+kartut;
    }
  }  
  printf("\nMagazanin toplam kari: %.2f TL\n",kar);
  
  fclose(oku);
}

int main()
{ FILE *yaz;

  struct Urun urun1;
  
  int i=0,j=0,Miktar1;
  
  float AlisFiyati1,SatisFiyati1;
  
  char StokAdi1[100];                       
  
  printf("Urunun Adi: ");  scanf("%s",&urun1.UrunAd);  
  
  printf("Alis Fiyati: "); scanf("%f",&urun1.Alis); 
  
  printf("Satis Fiyati: ");scanf("%f",&urun1.Satis);  
  
  printf("Adet: ");        scanf("%d",&urun1.miktar);   
  
  yaz=fopen("c:\\Stok.dat","a+b");
  
  if(yaz==NULL){printf("dosya acilmadi"); exit(1);}
  
  fwrite(&urun1,sizeof(struct Urun),1,yaz);
  
  fwrite("\n",sizeof(char),1,yaz);
  
  fclose(yaz);
  
  KarHesapla();
  
  getch();
}
