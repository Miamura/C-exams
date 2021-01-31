#include <stdio.h>//kütüphane ekleniyor
#include <windows.h>//kütüphane ekleniyor
struct OGRENCI {//ogrenci struct yapýsý tanýmlanýyor
char isim[15];//struct yapýsý deðiþkenleri
int vize;//struct yapýsý deðiþkenleri
int final;//struct yapýsý deðiþkenleri
char bolum[15];//struct yapýsý deðiþkenleri
}kisi[10],yedek[10],silinecek[10];//struct yapýsýna kiþi ve yedek isimleri veriliyor
void kayit_ekle();//fonksiyonlar tanýmlanýyor
void ara_bul();//fonksiyonlar tanýmlanýyor
void listele();//fonksiyonlar tanýmlanýyor
void bul_degistir();//fonksiyonlar tanýmlanýyor
void kayit_sil();//fonksiyonlar tanýmlanýyor
char menu();//fonksiyonlar tanýmlanýyor
int sayac;//global bir sayac eklendi kiþi syýsýný bulmak için
main()
{//ana fonksiyon
    char secim;//secim adýnda bir deðiþen tanýmlanýyor
    do{
        secim=menu();//menuden gelen tuþ algýlanýyor
        switch(secim)//menuden gelen veriyi karþýlaþtýrmaya sokuyor
        {
           case '1': kayit_ekle();break;//menuden gelen veri 1 ise kayýt ekleme fonksiyonu çaðýrýlýyor
           case '2': listele();break;//menuden gelen veri 2 ise listeleme fonksiyonu çaðýrýlýyor
           case '3':ara_bul();break;//menuden gelen veri 3 ise arabul fonksiyonu çaðýrýlýyor
           case '4':bul_degistir();break;//menuden gelen veri 4 ise buldegistir fonksiyonu çaðýrýlýyor
           case '5':kayit_sil();break;//menuden gelen veri 5 ise kayýt silfonksiyonu çaðýrýlýyor
 
        }
    }while(secim<='5' && secim>='1');//karþýlaþtýrma menuden gelen verilerin 1 ile 5 arasýnda ise
 
    }//ana fonksiyon sonu
char menu(){//menu fonksiyonu
    char tus;//tus adýnda char tipinde deðiþken tanýmlanýyor
    printf("1-kayit ekle\n2-listele\n3-arabul\n4-buldegistir\n5-sil\n");//manu seçenekleri ekrana yazdýrýlýyor
    tus=getch();//kullanýcýnýn girdiði tuþ algýlanýyor
    return tus;//menu fonksiyonunun çaðýrýldýðý yere kullanýcýnýn girdiði tuþ döndürülüyor
}//menu fonksiyonu sonu
    void kayit_ekle(){//kayýt ekleme fonksiyonu
        char tus2;//tus2 adýnda char tipinde deðiþken tanýmlanýyor
        FILE *dosya;//file tipinde bir dosya adýnda bir pointer tanýmlanýyor
        dosya=fopen("a.txt","w");//dosya önceki verilerin üstüne yazmak için açýlýyor
 
    do{printf("%d.kiþi adi giriniz",sayac+1);//kullanýcýdan isim isteniyor
    scanf("%s",kisi[sayac].isim);//kullanýcýný girdiði veri struct yapýsýna aktarýlýyor
    fflush(stdin);//veri deðiþkene aktarýldýktan sonra gerekli alan boþaltýlýyor
    printf("%d.kiþinin bölüm giriniz",sayac+1);//kullanýcýdan bölüm isteniyor
    scanf("%s",kisi[sayac].bolum);//kullanýcýný girdiði veri struct yapýsýna aktarýlýyor
    fflush(stdin);//veri deðiþkene aktarýldýktan sonra gerekli alan boþaltýlýyor
    printf("%d.kiþi vizesi giriniz",sayac+1);//kullanýcýdan vize isteniyor
    scanf("%d",&kisi[sayac].vize);//kullanýcýný girdiði veri struct yapýsýna aktarýlýyor
    fflush(stdin);//veri deðiþkene aktarýldýktan sonra gerekli alan boþaltýlýyor
    printf("%d.kiþi finali giriniz",sayac+1);//kullanýcýdan final isteniyor
    scanf("%d",&kisi[sayac].final);//kullanýcýný girdiði veri struct yapýsýna aktarýlýyor
    fflush(stdin);//veri deðiþkene aktarýldýktan sonra gerekli alan boþaltýlýyor
    printf("yeni kayit için e basin ve menüye dönmek için herhangi bir tusa basin");//veriler girildikten sonra kullanýcýdan yeni veri girmek istermisiniz diye soruluyor
    tus2=getch();//kullanýcýnýn girdiði karakter tus2 deðiþkenine aktarýlýyor
 
fprintf(dosya,"%s\t%s\t%d\t%d\n",kisi[sayac].isim,kisi[sayac].bolum,kisi[sayac].vize,kisi[sayac].final);//veriler dosyaya yazýlýyor
sayac++;//whileiçin sayac 1 arttýrýlýyor
    }while(tus2=='e' || tus2=='E');//eðer kullanýcý devam etmek isterse tekrar dön
fclose(dosya);//dosya kapatýlýyor
}//kayýt ekleme fonksiyonusonu
void listele(){//listele fonksiyonu
FILE *dosya;//file tipinde bir dosya adýnda bir pointer tanýmlanýyor
dosya=fopen("a.txt","r");//dosya önceki verileri okumak için açýlýyor
int a=0,i;//deðiþkenler tanýmlanýyor
while(!feof(dosya)){//dosya sonuna kadar dön
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].vize,&yedek[a].final);//veriler dosyadan okunuyor
a++;      //while için a arttýrýlýyor
}//dosya sonuna kadar dön sonu
for(i=0;i<(a-1);i++)//yedek yapýsýnýn sonuna kadar dönülüyor
printf("%d\t%s\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].bolum,yedek[i].vize,yedek[i].final);//okunan veriler ekrana yazýlýyor
fclose(dosya);//dosya kapatýlýyor
}//listele fonksiyonu sonu
void ara_bul(){//arabul fonksiyonu
    char kelime[150];//kelima adýnda char tipinde bir deðiþken tanýmlanýyor
printf("Aranacak Kelimeyi girin");//kullanýcýdan aranacak veri isteniyor
scanf("%s",&kelime);//girilen veri kelime deðiþkenine aktarýlýyor
FILE *dosya;//file tipinde bir dosya adýnda bir pointer tanýmlanýyor
dosya=fopen("a.txt","r");//dosya önceki verileri okumak için açýlýyor
int a=0,i;//deðiþkenler tanýmlanýyor döngüler için
while(!feof(dosya)){//dosya sonuna kadar dön
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].vize,&yedek[a].final);//dosyadan veriler okunup yedek yapýsýna aktarýlýyor
a++;     //while için a 1 arttýrýlýyor
 }//dosya sonuna kadar dön sonu
for(i=0;i<(a-1);i++){//yedek yapýsýnýn sonuna kadar dönülüyor
 if(strcmp(kelime,yedek[i].isim)==0)
        {//eðer aranan kelime yedek yapýsýnýn ismine eþit ise aþaðýdakileri yap
printf("%d\t%s\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].bolum,yedek[i].vize,yedek[i].final);//veriler ekrana yadýrýlýyor
}//eðer aranan kelime yedek yapýsýnýn ismine eþit ise aþaðýdakileri yap sonu
}//yedek yapýsýnýn sonuna kadar dönülüyorsonu
fclose(dosya);//dosya kapatýlýyor
}//arabul fonksiyonu sonu
void bul_degistir(){//bul deðiþrtir fonksiyonu
    char kelime[150];
printf("Degisecek Kisiyi girin");//degisecek kisi kulanýcýdan alýnýyor
scanf("%s",&kelime);//kullanýcýnýn girdiði veri kelime deðiþkenine atanýyor
FILE *dosya;//file tipinde bir dosya pointerý tanýmlanýyor
dosya=fopen("a.txt","r");//a.txt dosyasý sadece okunmak için yazýlýyor
int a=0,i;//kullanýlacak deðiþkenler tanýmlanýyor
while(!feof(dosya)){//dosya sonuna kadar dönülüyor baþlangýç
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].vize,&yedek[a].final);//dosyadan alýnan veriler yedek yapýsýna aktarýlýyor
a++;     //yedek deðiþkenini her seferinde farklý gelmesi için a her seferinde arttýrýlýyor
}//dosya sonuna kadar dönülüyor sonu
for(i=0;i<(a-1);i++){//yedek yapýsýna alýnan verilerin iþleme sokulmasý
 if(strcmp(kelime,yedek[i].isim)==0)//eðer deðiþecek kelime yedek yapýsýnýn ismine eþit ise aþaðýdakileri yap
        {
            printf("%dninci kiþinin adýný giriniz",i+1);//kullanýcýdan yeni isim isteniyor
            scanf("%s",yedek[i].isim);//isim yedek yapýsýnýn deðiþecek kýsmýna atanýyor
            fflush(stdin);//deðiþkene aktarýldýktan sonra o kýsým boþaltýlýyor
            printf("%dninci kiþinin bölümünü giriniz",i+1);//kullanýcýdan yeni bölüm isteniyor
            scanf("%s",yedek[i].bolum);//bölüm yedek yapýsýnýn deðiþecek kýsmýna atanýyor
            fflush(stdin);//deðiþkene aktarýldýktan sonra o kýsým boþaltýlýyor
            printf("%dninci kiþinin vizesini giriniz",i+1);//kullanýcýdan yeni vize isteniyor
            scanf("%d",&yedek[i].vize); //vize yedek yapýsýnýn deðiþecek kýsmýna atanýyor
            fflush(stdin);//deðiþkene aktarýldýktan sonra o kýsým boþaltýlýyor
            printf("%dninci kiþinin Finalini giriniz",i+1);//kullanýcýdan yeni final isteniyor
            scanf("%d",&yedek[i].final);//final yedek yapýsýnýn deðiþecek kýsmýna atanýyor
            fflush(stdin);//deðiþkene aktarýldýktan sonra o kýsým boþaltýlýyor
 
}
}//yedek yapýsýna alýnan verilerin iþleme sokulmasý sonu
fclose(dosya);//dosya sadece okunmak için açýlan dosya kapatýlýyor
 
//þimdi bu kýsýmda deðiþtirilen yedek yapýsýný a.txtnin üzerine yazarak bul deðiþtir örneðimizi bitireceðiz
FILE *dosya2;//file tipinde bir dosya2 pointerý tanýmlanýyor
dosya2=fopen("a.txt","w");//a.txt dosyasý önceki veriler silinecek þekilde açýlýyor
int i2;//integer tipinde for döngüsü için i2 deðiþkeni oluþturuluyor
for(i2=0;i2<(a-1);i2++){//yine yedek deðiþkeninin sonuna kadar dönülüyor
fprintf(dosya2,"%s\t%s\t%d\t%d\n",yedek[i2].isim,yedek[i2].bolum,yedek[i2].vize,yedek[i2].final);
}//yedek deðiþkeninin sonuna kadar dönme sonu
fclose(dosya2);//açýlan dosya kapatýlýyor
}//bul deðiþtir fonksiyonu sonu
 
 
void kayit_sil(){//kayit sil fonksiyonu
char kelime[150];
printf("Silinecek Kiþiyi girin");//silinecek kiþi kulanýcýdan alýnýyor
scanf("%s",&kelime);//kullanýcýnýn girdiði veri kelime deðiþkenine atanýyor
FILE *dosya;//file tipinde bir dosya pointerý tanýmlanýyor
dosya=fopen("a.txt","r");//a.txt dosyasý sadece okunmak için yazýlýyor
int a=0,i=0,kacinci;//kullanýlacak deðiþkenler tanýmlanýyor
while(!feof(dosya)){//dosya sonuna kadar dönülüyor baþlangýç
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].vize,&yedek[a].final);//dosyadan alýnan veriler yedek yapýsýna aktarýlýyor
a++;     //yedek deðiþkenini her seferinde farklý gelmesi için a her seferinde arttýrýlýyor
}//dosya sonuna kadar dönülüyor sonu
 
for(i=0;i<(a-1);i++){//yedek yapýsýna alýnan verilerin iþleme sokulmasý
 if(strcmp(kelime,yedek[i].isim)==0)//eðer silinmesi gereken kiþi adý yedek yapýsýnýn ismine eþit ise aþaðýdakileri yap
        {            kacinci=i;//aranan verinin kaçýncý olduðu bulunuyor
                   }//eðer silinmesi gereken kiþi adý yedek yapýsýnýn ismine eþit ise aþaðýdakileri yapsonu
 
}//yedek yapýsýna alýnan verilerin iþleme sokulmasý sonu
for(i=0;i<(kacinci);i++){//verinin bulunduðu yere kadar dön
    strcpy(silinecek[i].isim,yedek[i].isim);
//kacýncýya kadar olan kýsýmlar silinen yapýsýna aktarýlýyor
    strcpy(silinecek[i].bolum,yedek[i].bolum);
//kacýncýya kadar olan kýsýmlar silinen yapýsýna aktarýlýyor
    silinecek[i].vize=yedek[i].vize;
//kacýncýya kadar olan kýsýmlar silinen yapýsýna aktarýlýyor
    silinecek[i].final=yedek[i].final;
//kacýncýya kadar olan kýsýmlar silinen yapýsýna aktarýlýyor
}
//verinin bulunduðu yere kadar dön sonu
for(i=(kacinci+1);i<=(a-1);i++){//silinen veriden sonrakini silinecek kýsmýna ata
    strcpy(silinecek[i-1].isim,yedek[i].isim);//kacýncýdan sonra olan kýsýmlar silinen yapýsýna aktarýlýyor
    strcpy(silinecek[i-1].bolum,yedek[i].bolum);//kacýncýdan sonra  olan kýsýmlar silinen yapýsýna aktarýlýyor
    silinecek[i-1].vize=yedek[i].vize;//kacýncýdan sonra  olan kýsýmlar silinen yapýsýna aktarýlýyor
    silinecek[i-1].final=yedek[i].final;//kacýncýdan sonra  olan kýsýmlar silinen yapýsýna aktarýlýyor
}//silinen veriden sonrakini silinecek kýsmýna ata sonu
 
 
fclose(dosya);//dosya sadece okunmak için açýlan dosya kapatýlýyor
 
//þimdi bu kýsýmda deðiþtirilen yedek yapýsýný a.txtnin üzerine yazarak bul deðiþtir örneðimizi bitireceðiz
FILE *dosya2;//file tipinde bir dosya2 pointerý tanýmlanýyor
dosya2=fopen("a.txt","w");//a.txt dosyasý önceki veriler silinecek þekilde açýlýyor
int i2;//integer tipinde for döngüsü için i2 deðiþkeni oluþturuluyor
for(i2=0;i2<(a-1);i2++){//yine silinecek deðiþkeninin sonuna kadar dönülüyor
fprintf(dosya2,"%s\t%s\t%d\t%d\n",silinecek[i2].isim,silinecek[i2].bolum,silinecek[i2].vize,silinecek[i2].final);
}//silinecek deðiþkeninin sonuna kadar dönme sonu
fclose(dosya2);//açýlan dosya kapatýlýyor
 
}//kayitsil fonksiyonu sonu
