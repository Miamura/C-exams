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

int tc;

int tel;

} kisi[50],kisiokuma[50],kisisil[50];

int kayit_ekle();

int ara_bul();

int listele();

int bul_degistir();

int kayit_sil();

char menu();

int sayac;

int patron();

int KarHesapla();


int main()
{
	
	int i, iscikayit;
	
	
	
for(;;)
{
    char gecici[255];
    
    int secim;
    
    system("cls");
    
    printf("patron girisi icin 1 e basiniz\n");
    
    printf("isci girisi icin 2 ye basiniz\n");
 
    fgets(gecici, sizeof(gecici), stdin); 
    
    secim = atoi(gecici);
    
    if( secim == 1 )
	{
        patron();
        
        
    }
	
	else if( secim == 2 )
	{
        printf("yoklama icin 1e basiniz\n");
  
        printf("mal kayit icin 2ye basiniz\n");
  
        fgets(gecici, sizeof(gecici), stdin);
        
		secim = atoi(gecici);
        
        if( secim == 1 )// yoklama
		{
            
            break;
        }
		
		else if( secim == 2 )// mal kayit
		{
           
            FILE *yaz;

            struct Urun urun1;
  
            int i=0,j=0,Miktar1;
  
            float AlisFiyati1,SatisFiyati1;
  
            char StokAdi1[100];                       
  
            printf("Urunun Adi: ");  scanf("%s",&urun1.UrunAd);  
  
            printf("Alis Fiyati: "); scanf("%f",&urun1.Alis); 
  
            printf("Satis Fiyati: ");scanf("%f",&urun1.Satis);  
  
            printf("Adet: ");        scanf("%d",&urun1.miktar);   
  
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
    }
    
      getch();
      
  }
  
  
  int patron()
{
    char secim;
    
    do{
        secim=menu();
        
        switch(secim)//menuden gelen veriyi kar��la�t�rmaya sokuyor
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
    
    printf("�sci kaydi eklemek icin 1 e \n�sci listelemek icin 2 ye \n�sci arayip bulmak icin 3 e\n�sci bulup degistir icin 4 e \n�sci silmek icin 5 e \nProgrami kapatmak icin baska bir tusa basiniz\n");
    
    menusayialgilama = getch(); //kullan�c�n�n girdi�i tu� alg�lan�yor
    
    return menusayialgilama;
    
}

    int kayit_ekle()
{
    
        char kayit_eklesayialgilama;
        char gecici[255];
        
        FILE *dosya;
        
        dosya=fopen("a.txt","a");
 
    do{
    	
	printf(" %d.kisi adi giriniz\n",sayac+1);
    
    scanf("%s",kisi[sayac].isim);
    
    fflush(stdin);
    
    printf("%d.kisinin soyadi giriniz\n",sayac+1);
    
    scanf("%s",kisi[sayac].soyadi);
    
    fflush(stdin);
    
    printf("%d.kisi tc sini giriniz\n",sayac+1);
    
    for( ; ; )
	{
        fgets(gecici,sizeof(gecici),stdin);
        
        if( strlen(gecici) == 12 ){
            kisi[sayac].tc = atoi(gecici);
            if( kisi[sayac].tc > 10000000000 ) break;
        }
    }
    
    fflush(stdin);
    
    printf("%d.kisi telefon numarasini giriniz\n",sayac+1);
    
    for( ; ; )
	{
        fgets(gecici,sizeof(gecici),stdin);
        
        if( strlen(gecici) == 11 ){
            kisi[sayac].tel = atoi(gecici);
            if( kisi[sayac].tel > 1000000000 ) break;
        }
    }
    
    fflush(stdin);
    
    printf("yeni kayit icin e'ye basin ve menuye donmek icin herhangi bir tusa basin");
    
	kayit_eklesayialgilama=getch();
 
    fprintf(dosya,"%s\t%s\t%d\t%d\n",kisi[sayac].isim,kisi[sayac].soyadi,kisi[sayac].tc,kisi[sayac].tel);//veriler dosyaya yaz�l�yor
    
    sayac++;
    
    }while(kayit_eklesayialgilama=='e' || kayit_eklesayialgilama=='E');
    
    fclose(dosya);

}

int listele()
{
	
   FILE *dosya;
   
   dosya=fopen("a.txt","r");
   
   int sayac2=0,i;
   
   while(!feof(dosya)){//dosya sonuna kadar d�n
   
        fscanf(dosya,"%s%s%d%d",kisiokuma[sayac2].isim,kisiokuma[sayac2].soyadi,&kisiokuma[sayac2].tc,&kisiokuma[sayac2].tel);
    
        sayac2++;      

   }//dosya sonuna kadar d�n sonu
   
    for(i=0;i<(sayac2-1);i++)//yedek yap�s�n�n sonuna kadar d�n�l�yor
       printf("%d\t%s\t%s\t%d\t%d\n",i+1,kisiokuma[i].isim,kisiokuma[i].soyadi,kisiokuma[i].tc,kisiokuma[i].tel);//okunan veriler ekrana yaz�l�yor
       
    fclose(dosya);//dosya kapat�l�yor
    
}

int ara_bul()
{
    char kelime[150];
    
    printf("Aranacak Kelimeyi girin");

    scanf("%s",&kelime);

    FILE *dosya;//file tipinde bir dosya ad�nda bir pointer tan�mlan�yor

    dosya=fopen("a.txt","r");//dosya �nceki verileri okumak i�in a��l�yor

    int sayac3=0,i;

    while(!feof(dosya)){//dosya sonuna kadar d�n

        fscanf(dosya,"%s%s%d%d",kisiokuma[sayac3].isim,kisiokuma[sayac3].soyadi,&kisiokuma[sayac3].tc,&kisiokuma[sayac3].tel);//dosyadan veriler okunup yedek yap�s�na aktar�l�yor
    
        sayac3++;     //while i�in a 1 artt�r�l�yor

    }//dosya sonuna kadar d�n sonu
 
    for(i=0;i<(sayac3-1);i++){//yedek yap�s�n�n sonuna kadar d�n�l�yor

        if(strcmp(kelime,kisiokuma[i].isim)==0)
 
        {//e�er aranan kelime yedek yap�s�n�n ismine e�it ise a�a��dakileri yap
        
            printf("%d\t%s\t%s\t%d\t%d\n",i+1,kisiokuma[i].isim,kisiokuma[i].soyadi,kisiokuma[i].tc,kisiokuma[i].tel);//veriler ekrana yad�r�l�yor

        }//e�er aranan kelime yedek yap�s�n�n ismine e�it ise a�a��dakileri yap sonu

    }//yedek yap�s�n�n sonuna kadar d�n�l�yorsonu

    fclose(dosya);//dosya kapat�l�yor

}

int bul_degistir()
{
    char kelime[150];
    
    printf("Degisecek Kisiyi girin");//degisecek kisi kulan�c�dan al�n�yor

    scanf("%s",&kelime);//kullan�c�n�n girdi�i veri kelime de�i�kenine atan�yor

    FILE *dosya;

    dosya=fopen("a.txt","r");

    int sayac4=0,i;

    while(!feof(dosya)){//dosya sonuna kadar d�n�l�yor ba�lang��

        fscanf(dosya,"%s%s%d%d",kisiokuma[sayac4].isim,kisiokuma[sayac4].soyadi,&kisiokuma[sayac4].tc,&kisiokuma[sayac4].tel);//dosyadan al�nan veriler yedek yap�s�na aktar�l�yor
    
        sayac4++;     //yedek de�i�kenini her seferinde farkl� gelmesi i�in a her seferinde artt�r�l�yor

    }//dosya sonuna kadar d�n�l�yor sonu

    for(i=0;i<(sayac4-1);i++){//yedek yap�s�na al�nan verilerin i�leme sokulmas�

        if(strcmp(kelime,kisiokuma[i].isim)==0)//e�er de�i�ecek kelime yedek yap�s�n�n ismine e�it ise a�a��dakileri yap
 
        {
            printf("%d. ki�inin ad�n� giriniz",i+1);//kullan�c�dan yeni isim isteniyor
            
            scanf("%s",kisiokuma[i].isim);//isim yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
            
            printf("%d. kisinin soyadini giriniz",i+1);//kullan�c�dan yeni b�l�m isteniyor
            
            scanf("%s",kisiokuma[i].soyadi);//b�l�m yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
            
            printf("%d. kisinin tcsini giriniz",i+1);//kullan�c�dan yeni vize isteniyor
            
            scanf("%d",&kisiokuma[i].tc); //vize yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
            
            printf("%d. ki�inin telefonunu giriniz",i+1);//kullan�c�dan yeni final isteniyor
            
            scanf("%d",&kisiokuma[i].tel);//final yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
 
        }

    }//yedek yap�s�na al�nan verilerin i�leme sokulmas� sonu
    
    fclose(dosya);//dosya sadece okunmak i�in a��lan dosya kapat�l�yor
    
    //�imdi bu k�s�mda de�i�tirilen yedek yap�s�n� a.txtnin �zerine yazarak bul de�i�tir �rne�imizi bitirece�iz

    FILE *dosya2;//file tipinde bir dosya2 pointer� tan�mlan�yor

    dosya2=fopen("a.txt","w");//a.txt dosyas� �nceki veriler silinecek �ekilde a��l�yor

    int i2;//integer tipinde for d�ng�s� i�in i2 de�i�keni olu�turuluyor

    for(i2=0;i2<(sayac4-1);i2++){//yine yedek de�i�keninin sonuna kadar d�n�l�yor

        fprintf(dosya2,"%s\t%s\t%d\t%d\n",kisiokuma[i2].isim,kisiokuma[i2].soyadi,kisiokuma[i2].tc,kisiokuma[i2].tel);

    }//yedek de�i�keninin sonuna kadar d�nme sonu

    fclose(dosya2);//a��lan dosya kapat�l�yor

}//bul de�i�tir fonksiyonu sonu
 
 
int kayit_sil()
{

    char kelime[150];

    printf("Silinecek Ki�iyi girin");

    scanf("%s",&kelime);

    FILE *dosya;

    dosya=fopen("a.txt","r");

    int sayac5=0,i=0,kacinci;//kullan�lacak de�i�kenler tan�mlan�yor

    while(!feof(dosya)){//dosya sonuna kadar d�n�l�yor ba�lang��

        fscanf(dosya,"%s%s%d%d",kisiokuma[sayac5].isim,kisiokuma[sayac5].soyadi,&kisiokuma[sayac5].tc,&kisiokuma[sayac5].tel);//dosyadan al�nan veriler yedek yap�s�na aktar�l�yor
    
        sayac5++;     //yedek de�i�kenini her seferinde farkl� gelmesi i�in a her seferinde artt�r�l�yor

    }//dosya sonuna kadar d�n�l�yor sonu
 
    for(i=0;i<(sayac5-1);i++){//yedek yap�s�na al�nan verilerin i�leme sokulmas�

        if(strcmp(kelime,kisiokuma[i].isim)==0)//e�er silinmesi gereken ki�i ad� yedek yap�s�n�n ismine e�it ise a�a��dakileri yap
 
        {            
		    kacinci=i;//aranan verinin ka��nc� oldu�u bulunuyor
        }//e�er silinmesi gereken ki�i ad� yedek yap�s�n�n ismine e�it ise a�a��dakileri yapsonu
 
   }//yedek yap�s�na al�nan verilerin i�leme sokulmas� sonu

   for(i=0;i<(kacinci);i++){//verinin bulundu�u yere kadar d�n

        strcpy(kisisil[i].isim,kisiokuma[i].isim);
    
        //kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor

        strcpy(kisisil[i].soyadi,kisiokuma[i].soyadi);
    
        //kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor

        kisisil[i].tc=kisiokuma[i].tc;
    
        //kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor

        kisisil[i].tel=kisiokuma[i].tel;
    
        //kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor

    }

    //verinin bulundu�u yere kadar d�n sonu

    for(i=(kacinci+1);i<=(sayac5-1);i++){//silinen veriden sonrakini silinecek k�sm�na ata

        strcpy(kisisil[i-1].isim,kisiokuma[i].isim);//kac�nc�dan sonra olan k�s�mlar silinen yap�s�na aktar�l�yor
    
        strcpy(kisisil[i-1].soyadi,kisiokuma[i].soyadi);//kac�nc�dan sonra  olan k�s�mlar silinen yap�s�na aktar�l�yor
    
        kisisil[i-1].tc=kisiokuma[i].tc;//kac�nc�dan sonra  olan k�s�mlar silinen yap�s�na aktar�l�yor
    
        kisisil[i-1].tel=kisiokuma[i].tel;//kac�nc�dan sonra  olan k�s�mlar silinen yap�s�na aktar�l�yor
    
    }//silinen veriden sonrakini silinecek k�sm�na ata sonu
 
    fclose(dosya);//dosya sadece okunmak i�in a��lan dosya kapat�l�yor
 
    //�imdi bu k�s�mda de�i�tirilen yedek yap�s�n� a.txtnin �zerine yazarak bul de�i�tir �rne�imizi bitirece�iz

    FILE *dosya2;//file tipinde bir dosya2 pointer� tan�mlan�yor

    dosya2=fopen("a.txt","w");//a.txt dosyas� �nceki veriler silinecek �ekilde a��l�yor

    int i2;//integer tipinde for d�ng�s� i�in i2 de�i�keni olu�turuluyor

    for(i2=0;i2<(sayac5-1);i2++){//yine silinecek de�i�keninin sonuna kadar d�n�l�yor

        fprintf(dosya2,"%s\t%s\t%d\t%d\n",kisisil[i2].isim,kisisil[i2].soyadi,kisisil[i2].tc,kisisil[i2].tel);

    }//silinecek de�i�keninin sonuna kadar d�nme sonu

    fclose(dosya2);//a��lan dosya kapat�l�yor
 
}//kayitsil fonksiyonu sonu


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
