#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
  
struct Urun
{ char UrunAd[10];

  float Alis;
  
  float Satis; 
  
  int miktar;
};

struct isci {

char isim[15];

char soyadi[15];

char  tc[12];

char tel[11];

} kisi[200],kisiokuma[200],kisisil[200];

int kayit_ekle();

int ara_bul();

int listele();

int bul_degistir();

int kayit_sil();

char menu();

int sayac;

int patron();

int KarHesapla();

int mevcut=0;


int main()
{
	
	int i, iscikayit;
	
for(;;)
{
    char gecici[255];
    
    int secim;
    
    system("cls");
    
    printf("patron girisi icin 1 e basiniz\n");
    
    printf("mal kayit ve kari goruntulemek icin 2 ye basiniz\n");
 
    fgets(gecici, sizeof(gecici), stdin); 
    
    secim = atoi(gecici);
    
    if( secim == 1 )
	{
        patron();
    }
	
	else if( secim == 2 )
	{
            FILE *yaz;

            struct Urun urun1;
  
            int i=0,j=0,Miktar1;
  
            float AlisFiyati1,SatisFiyati1;
  
            char StokAdi1[100];                   
  
            printf("Urunun Adi: ");     scanf("%s",&urun1.UrunAd);  
  
            printf("Malzeme Fiyati: "); scanf("%f",&urun1.Alis); 
  
            printf("Satis Fiyati: ");   scanf("%f",&urun1.Satis);  
  
            printf("Adet: ");           scanf("%d",&urun1.miktar);   
  
            yaz=fopen("stok.txt","a+b");
  
            if(yaz==NULL){printf("dosya acilmadi"); exit(1);}
  
            fwrite(&urun1,sizeof(struct Urun),1,yaz);
  
            fwrite("\n",sizeof(char),1,yaz);
  
            fclose(yaz);
  
            KarHesapla();

            break;
        }
		
		else continue;
    }
    
    
      getch();
      
}
  
  
  int patron()
{
    char secim;
    
    do{
        secim=menu();
        
        switch(secim)
        {
           case '1': kayit_ekle();break;
           case '2': listele();break;
           case '3': ara_bul();break;
           case '4': bul_degistir();break;
           case '5': kayit_sil();break;
        }
    }while(secim<='5' && secim>='1');
 
}
    
char menu()

{
    char menusayialgilama;
    
    printf("Ýsci kaydi eklemek icin 1 e \nÝsci listelemek icin 2 ye \nÝsci arayip bulmak icin 3 e\nÝsci bulup degistir icin 4 e \n");
    printf("Ýsci silmek icin 5 e \nProgrami kapatmak ve kaydetmek icin baska bir tusa basiniz\n");
    
    menusayialgilama=getch();
    
    return menusayialgilama;
    
}

    int kayit_ekle()
{
    
        char kayit_eklesayialgilama;
        
        FILE *dosya;
        
        dosya=fopen("ödev.txt","a");
 
    do{
    	
	printf("%d.kisi adi giriniz\n",mevcut+1);
    
    scanf("%s",kisi[sayac].isim);
    
    fflush(stdin);
    
    printf("%d.kisinin soyadi giriniz\n",mevcut+1);
    
    scanf("%s",kisi[sayac].soyadi);
    
    fflush(stdin);
    
    printf("%d.kisi tc sini giriniz\n",mevcut+1);
    
    scanf("%s",&kisi[sayac].tc);
    
    fflush(stdin);
    
    printf("%d.kisi telefon numarasini giriniz\n",mevcut+1);
    
    scanf("%s",&kisi[sayac].tel);
    
    fflush(stdin);
    
    mevcut++;
    
    printf("yeni kayit icin e'ye basin ve menuye donmek icin herhangi bir tusa basin");
    
	kayit_eklesayialgilama=getch();
 
    fprintf(dosya,"%s\t%s\t%s\t%s\t\n",kisi[sayac].isim,kisi[sayac].soyadi,kisi[sayac].tc,kisi[sayac].tel);
    
    sayac++;
    
    }while(kayit_eklesayialgilama=='e' || kayit_eklesayialgilama=='E');
    
    fclose(dosya);

}

int listele()
{
	
   FILE *dosya;
   
   dosya=fopen("ödev.txt","r");
   
   int sayac2=0,i;
   
   while(!feof(dosya)){
   
        fscanf(dosya,"%s%s%s%s",kisiokuma[sayac2].isim,kisiokuma[sayac2].soyadi,&kisiokuma[sayac2].tc,&kisiokuma[sayac2].tel);
    
        sayac2++;
    }
   
    for(i=0;i<(sayac2-1);i++)
       printf("\t%s\t%s\t%s\t%s\n",kisiokuma[i].isim,kisiokuma[i].soyadi,kisiokuma[i].tc,kisiokuma[i].tel);
       
    fclose(dosya);
    
}

int ara_bul()
{
    char kelime[150];
    
    printf("Aranacak Kelimeyi girin");

    scanf("%s",&kelime);

    FILE *dosya;

    dosya=fopen("ödev.txt","r");

    int sayac3=0,i;

    while(!feof(dosya)){

        fscanf(dosya,"%s%s%s%s",kisiokuma[sayac3].isim,kisiokuma[sayac3].soyadi,&kisiokuma[sayac3].tc,&kisiokuma[sayac3].tel);
    
        sayac3++;

    }
 
    for(i=0;i<(sayac3-1);i++){

        if(strcmp(kelime,kisiokuma[i].isim)==0)
 
        {
        
            printf("%d\t%s\t%s\t%s\t%s\n",i+1,kisiokuma[i].isim,kisiokuma[i].soyadi,kisiokuma[i].tc,kisiokuma[i].tel);

        }

    }

    fclose(dosya);

}

int bul_degistir()
{
    char kelime[150];
    
    printf("Degisecek Kisiyi girin");

    scanf("%s",&kelime);

    FILE *dosya;

    dosya=fopen("ödev.txt","r");

    int sayac4=0,i;

    while(!feof(dosya)){

        fscanf(dosya,"%s%s%s%s",kisiokuma[sayac4].isim,kisiokuma[sayac4].soyadi,&kisiokuma[sayac4].tc,&kisiokuma[sayac4].tel);
    
        sayac4++;     

    }

    for(i=0;i<(sayac4-1);i++){

        if(strcmp(kelime,kisiokuma[i].isim)==0)
 
        {
            printf("%d. kisinin adini giriniz",i+1);
            
            scanf("%s",kisiokuma[i].isim);
            
            fflush(stdin);
            
            printf("%d. kisinin soyadini giriniz",i+1);
            
            scanf("%s",kisiokuma[i].soyadi);
            
            fflush(stdin);
            
            printf("%d. kisinin tcsini giriniz",i+1);
            
            scanf("%s",kisiokuma[i].tc); 
            
            fflush(stdin);
            
            printf("%s. kisinin telefonunu giriniz",i+1);
            
            scanf("%s",kisiokuma[i].tel);
            
            fflush(stdin);
 
        }

    }
    
    fclose(dosya);
    
   

    FILE *dosya2;

    dosya2=fopen("ödev.txt","w");

    int i2;

    for(i2=0;i2<(sayac4-1);i2++){

        fprintf(dosya2,"%s\t%s\t%s\t%s\n",kisiokuma[i2].isim,kisiokuma[i2].soyadi,kisiokuma[i2].tc,kisiokuma[i2].tel);

    }

    fclose(dosya2);

}
 
 
int kayit_sil()
{

    char kelime[150];

    printf("Silinecek Kisiyi girin");

    scanf("%s",&kelime);

    FILE *dosya;

    dosya=fopen("ödev.txt","r");

    int sayac5=0,i=0,kacinci;

    while(!feof(dosya)){

        fscanf(dosya,"%s%s%s%s",kisiokuma[sayac5].isim,kisiokuma[sayac5].soyadi,&kisiokuma[sayac5].tc,&kisiokuma[sayac5].tel);
    
        sayac5++;    

    }
 
    for(i=0;i<(sayac5-1);i++){

        if(strcmp(kelime,kisiokuma[i].isim)==0)
 
        {            
		    kacinci=i;
        }
 
   }

   for(i=0;i<(kacinci);i++){

        strcpy(kisisil[i].isim,kisiokuma[i].isim);
    
       

        strcpy(kisisil[i].soyadi,kisiokuma[i].soyadi);
    
        strcpy(kisisil[i].tc,kisiokuma[i].tc);
       

        strcpy(kisisil[i].tel,kisiokuma[i].tel);
       

    }

   

    for(i=(kacinci+1);i<=(sayac5-1);i++){

        strcpy(kisisil[i-1].isim,kisiokuma[i].isim);
    
        strcpy(kisisil[i-1].soyadi,kisiokuma[i].soyadi);
    
        strcpy(kisisil[i-1].tc,kisiokuma[i].tc);
    
        strcpy(kisisil[i-1].tel,kisiokuma[i].tel);
     
    }
 
    fclose(dosya);
 
    

    FILE *dosya2;

    dosya2=fopen("ödev.txt","w");

    int i2;

    for(i2=0;i2<(sayac5-1);i2++){

        fprintf(dosya2,"%s\t%s\t%s\t%s\n",kisisil[i2].isim,kisisil[i2].soyadi,kisisil[i2].tc,kisisil[i2].tel);

    }
    
    mevcut--;

    fclose(dosya2);
 
}


int KarHesapla()
 { 
		FILE *oku;

        struct Urun urun2;

        int i=0,j=0,Miktar[100];
  
        float kar=0,kartut=0;
  
        char ch;
  
        oku=fopen("stok.txt","a+b");
  
        if(oku==NULL)
		{
			
		    printf("dosya acilmadi"); exit(1);
		    
		}
		
        printf("\nDosyanin icerigi:\n");
   
        while(!feof(oku))
  
        { 
				
	        if( fread(&urun2,sizeof(struct Urun),1,oku)!=0)
  
           {
					   
   	            fread(&ch,sizeof(char),1,oku);
    
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


