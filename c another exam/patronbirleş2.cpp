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
        
        switch(secim)//menuden gelen veriyi karþýlaþtýrmaya sokuyor
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
    
    printf("Ýsci kaydi eklemek icin 1 e \nÝsci listelemek icin 2 ye \nÝsci arayip bulmak icin 3 e\nÝsci bulup degistir icin 4 e \nÝsci silmek icin 5 e \nProgrami kapatmak icin baska bir tusa basiniz\n");
    
    menusayialgilama = getch(); //kullanýcýnýn girdiði tuþ algýlanýyor
    
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
 
    fprintf(dosya,"%s\t%s\t%d\t%d\n",kisi[sayac].isim,kisi[sayac].soyadi,kisi[sayac].tc,kisi[sayac].tel);//veriler dosyaya yazýlýyor
    
    sayac++;
    
    }while(kayit_eklesayialgilama=='e' || kayit_eklesayialgilama=='E');
    
    fclose(dosya);

}

int listele()
{
	
   FILE *dosya;
   
   dosya=fopen("a.txt","r");
   
   int sayac2=0,i;
   
   while(!feof(dosya)){//dosya sonuna kadar dön
   
        fscanf(dosya,"%s%s%d%d",kisiokuma[sayac2].isim,kisiokuma[sayac2].soyadi,&kisiokuma[sayac2].tc,&kisiokuma[sayac2].tel);
    
        sayac2++;      

   }//dosya sonuna kadar dön sonu
   
    for(i=0;i<(sayac2-1);i++)//yedek yapýsýnýn sonuna kadar dönülüyor
       printf("%d\t%s\t%s\t%d\t%d\n",i+1,kisiokuma[i].isim,kisiokuma[i].soyadi,kisiokuma[i].tc,kisiokuma[i].tel);//okunan veriler ekrana yazýlýyor
       
    fclose(dosya);//dosya kapatýlýyor
    
}

int ara_bul()
{
    char kelime[150];
    
    printf("Aranacak Kelimeyi girin");

    scanf("%s",&kelime);

    FILE *dosya;//file tipinde bir dosya adýnda bir pointer tanýmlanýyor

    dosya=fopen("a.txt","r");//dosya önceki verileri okumak için açýlýyor

    int sayac3=0,i;

    while(!feof(dosya)){//dosya sonuna kadar dön

        fscanf(dosya,"%s%s%d%d",kisiokuma[sayac3].isim,kisiokuma[sayac3].soyadi,&kisiokuma[sayac3].tc,&kisiokuma[sayac3].tel);//dosyadan veriler okunup yedek yapýsýna aktarýlýyor
    
        sayac3++;     //while için a 1 arttýrýlýyor

    }//dosya sonuna kadar dön sonu
 
    for(i=0;i<(sayac3-1);i++){//yedek yapýsýnýn sonuna kadar dönülüyor

        if(strcmp(kelime,kisiokuma[i].isim)==0)
 
        {//eðer aranan kelime yedek yapýsýnýn ismine eþit ise aþaðýdakileri yap
        
            printf("%d\t%s\t%s\t%d\t%d\n",i+1,kisiokuma[i].isim,kisiokuma[i].soyadi,kisiokuma[i].tc,kisiokuma[i].tel);//veriler ekrana yadýrýlýyor

        }//eðer aranan kelime yedek yapýsýnýn ismine eþit ise aþaðýdakileri yap sonu

    }//yedek yapýsýnýn sonuna kadar dönülüyorsonu

    fclose(dosya);//dosya kapatýlýyor

}

int bul_degistir()
{
    char kelime[150];
    
    printf("Degisecek Kisiyi girin");//degisecek kisi kulanýcýdan alýnýyor

    scanf("%s",&kelime);//kullanýcýnýn girdiði veri kelime deðiþkenine atanýyor

    FILE *dosya;

    dosya=fopen("a.txt","r");

    int sayac4=0,i;

    while(!feof(dosya)){//dosya sonuna kadar dönülüyor baþlangýç

        fscanf(dosya,"%s%s%d%d",kisiokuma[sayac4].isim,kisiokuma[sayac4].soyadi,&kisiokuma[sayac4].tc,&kisiokuma[sayac4].tel);//dosyadan alýnan veriler yedek yapýsýna aktarýlýyor
    
        sayac4++;     //yedek deðiþkenini her seferinde farklý gelmesi için a her seferinde arttýrýlýyor

    }//dosya sonuna kadar dönülüyor sonu

    for(i=0;i<(sayac4-1);i++){//yedek yapýsýna alýnan verilerin iþleme sokulmasý

        if(strcmp(kelime,kisiokuma[i].isim)==0)//eðer deðiþecek kelime yedek yapýsýnýn ismine eþit ise aþaðýdakileri yap
 
        {
            printf("%d. kiþinin adýný giriniz",i+1);//kullanýcýdan yeni isim isteniyor
            
            scanf("%s",kisiokuma[i].isim);//isim yedek yapýsýnýn deðiþecek kýsmýna atanýyor
            
            fflush(stdin);//deðiþkene aktarýldýktan sonra o kýsým boþaltýlýyor
            
            printf("%d. kisinin soyadini giriniz",i+1);//kullanýcýdan yeni bölüm isteniyor
            
            scanf("%s",kisiokuma[i].soyadi);//bölüm yedek yapýsýnýn deðiþecek kýsmýna atanýyor
            
            fflush(stdin);//deðiþkene aktarýldýktan sonra o kýsým boþaltýlýyor
            
            printf("%d. kisinin tcsini giriniz",i+1);//kullanýcýdan yeni vize isteniyor
            
            scanf("%d",&kisiokuma[i].tc); //vize yedek yapýsýnýn deðiþecek kýsmýna atanýyor
            
            fflush(stdin);//deðiþkene aktarýldýktan sonra o kýsým boþaltýlýyor
            
            printf("%d. kiþinin telefonunu giriniz",i+1);//kullanýcýdan yeni final isteniyor
            
            scanf("%d",&kisiokuma[i].tel);//final yedek yapýsýnýn deðiþecek kýsmýna atanýyor
            
            fflush(stdin);//deðiþkene aktarýldýktan sonra o kýsým boþaltýlýyor
 
        }

    }//yedek yapýsýna alýnan verilerin iþleme sokulmasý sonu
    
    fclose(dosya);//dosya sadece okunmak için açýlan dosya kapatýlýyor
    
    //þimdi bu kýsýmda deðiþtirilen yedek yapýsýný a.txtnin üzerine yazarak bul deðiþtir örneðimizi bitireceðiz

    FILE *dosya2;//file tipinde bir dosya2 pointerý tanýmlanýyor

    dosya2=fopen("a.txt","w");//a.txt dosyasý önceki veriler silinecek þekilde açýlýyor

    int i2;//integer tipinde for döngüsü için i2 deðiþkeni oluþturuluyor

    for(i2=0;i2<(sayac4-1);i2++){//yine yedek deðiþkeninin sonuna kadar dönülüyor

        fprintf(dosya2,"%s\t%s\t%d\t%d\n",kisiokuma[i2].isim,kisiokuma[i2].soyadi,kisiokuma[i2].tc,kisiokuma[i2].tel);

    }//yedek deðiþkeninin sonuna kadar dönme sonu

    fclose(dosya2);//açýlan dosya kapatýlýyor

}//bul deðiþtir fonksiyonu sonu
 
 
int kayit_sil()
{

    char kelime[150];

    printf("Silinecek Kiþiyi girin");

    scanf("%s",&kelime);

    FILE *dosya;

    dosya=fopen("a.txt","r");

    int sayac5=0,i=0,kacinci;//kullanýlacak deðiþkenler tanýmlanýyor

    while(!feof(dosya)){//dosya sonuna kadar dönülüyor baþlangýç

        fscanf(dosya,"%s%s%d%d",kisiokuma[sayac5].isim,kisiokuma[sayac5].soyadi,&kisiokuma[sayac5].tc,&kisiokuma[sayac5].tel);//dosyadan alýnan veriler yedek yapýsýna aktarýlýyor
    
        sayac5++;     //yedek deðiþkenini her seferinde farklý gelmesi için a her seferinde arttýrýlýyor

    }//dosya sonuna kadar dönülüyor sonu
 
    for(i=0;i<(sayac5-1);i++){//yedek yapýsýna alýnan verilerin iþleme sokulmasý

        if(strcmp(kelime,kisiokuma[i].isim)==0)//eðer silinmesi gereken kiþi adý yedek yapýsýnýn ismine eþit ise aþaðýdakileri yap
 
        {            
		    kacinci=i;//aranan verinin kaçýncý olduðu bulunuyor
        }//eðer silinmesi gereken kiþi adý yedek yapýsýnýn ismine eþit ise aþaðýdakileri yapsonu
 
   }//yedek yapýsýna alýnan verilerin iþleme sokulmasý sonu

   for(i=0;i<(kacinci);i++){//verinin bulunduðu yere kadar dön

        strcpy(kisisil[i].isim,kisiokuma[i].isim);
    
        //kacýncýya kadar olan kýsýmlar silinen yapýsýna aktarýlýyor

        strcpy(kisisil[i].soyadi,kisiokuma[i].soyadi);
    
        //kacýncýya kadar olan kýsýmlar silinen yapýsýna aktarýlýyor

        kisisil[i].tc=kisiokuma[i].tc;
    
        //kacýncýya kadar olan kýsýmlar silinen yapýsýna aktarýlýyor

        kisisil[i].tel=kisiokuma[i].tel;
    
        //kacýncýya kadar olan kýsýmlar silinen yapýsýna aktarýlýyor

    }

    //verinin bulunduðu yere kadar dön sonu

    for(i=(kacinci+1);i<=(sayac5-1);i++){//silinen veriden sonrakini silinecek kýsmýna ata

        strcpy(kisisil[i-1].isim,kisiokuma[i].isim);//kacýncýdan sonra olan kýsýmlar silinen yapýsýna aktarýlýyor
    
        strcpy(kisisil[i-1].soyadi,kisiokuma[i].soyadi);//kacýncýdan sonra  olan kýsýmlar silinen yapýsýna aktarýlýyor
    
        kisisil[i-1].tc=kisiokuma[i].tc;//kacýncýdan sonra  olan kýsýmlar silinen yapýsýna aktarýlýyor
    
        kisisil[i-1].tel=kisiokuma[i].tel;//kacýncýdan sonra  olan kýsýmlar silinen yapýsýna aktarýlýyor
    
    }//silinen veriden sonrakini silinecek kýsmýna ata sonu
 
    fclose(dosya);//dosya sadece okunmak için açýlan dosya kapatýlýyor
 
    //þimdi bu kýsýmda deðiþtirilen yedek yapýsýný a.txtnin üzerine yazarak bul deðiþtir örneðimizi bitireceðiz

    FILE *dosya2;//file tipinde bir dosya2 pointerý tanýmlanýyor

    dosya2=fopen("a.txt","w");//a.txt dosyasý önceki veriler silinecek þekilde açýlýyor

    int i2;//integer tipinde for döngüsü için i2 deðiþkeni oluþturuluyor

    for(i2=0;i2<(sayac5-1);i2++){//yine silinecek deðiþkeninin sonuna kadar dönülüyor

        fprintf(dosya2,"%s\t%s\t%d\t%d\n",kisisil[i2].isim,kisisil[i2].soyadi,kisisil[i2].tc,kisisil[i2].tel);

    }//silinecek deðiþkeninin sonuna kadar dönme sonu

    fclose(dosya2);//açýlan dosya kapatýlýyor
 
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
