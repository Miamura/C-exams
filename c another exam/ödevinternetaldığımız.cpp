#include <stdio.h>//k�t�phane ekleniyor
#include <windows.h>//k�t�phane ekleniyor
struct OGRENCI {//ogrenci struct yap�s� tan�mlan�yor
char isim[15];//struct yap�s� de�i�kenleri
int vize;//struct yap�s� de�i�kenleri
int final;//struct yap�s� de�i�kenleri
char bolum[15];//struct yap�s� de�i�kenleri
}kisi[10],yedek[10],silinecek[10];//struct yap�s�na ki�i ve yedek isimleri veriliyor
void kayit_ekle();//fonksiyonlar tan�mlan�yor
void ara_bul();//fonksiyonlar tan�mlan�yor
void listele();//fonksiyonlar tan�mlan�yor
void bul_degistir();//fonksiyonlar tan�mlan�yor
void kayit_sil();//fonksiyonlar tan�mlan�yor
char menu();//fonksiyonlar tan�mlan�yor
int sayac;//global bir sayac eklendi ki�i sy�s�n� bulmak i�in
main()
{//ana fonksiyon
    char secim;//secim ad�nda bir de�i�en tan�mlan�yor
    do{
        secim=menu();//menuden gelen tu� alg�lan�yor
        switch(secim)//menuden gelen veriyi kar��la�t�rmaya sokuyor
        {
           case '1': kayit_ekle();break;//menuden gelen veri 1 ise kay�t ekleme fonksiyonu �a��r�l�yor
           case '2': listele();break;//menuden gelen veri 2 ise listeleme fonksiyonu �a��r�l�yor
           case '3':ara_bul();break;//menuden gelen veri 3 ise arabul fonksiyonu �a��r�l�yor
           case '4':bul_degistir();break;//menuden gelen veri 4 ise buldegistir fonksiyonu �a��r�l�yor
           case '5':kayit_sil();break;//menuden gelen veri 5 ise kay�t silfonksiyonu �a��r�l�yor
 
        }
    }while(secim<='5' && secim>='1');//kar��la�t�rma menuden gelen verilerin 1 ile 5 aras�nda ise
 
    }//ana fonksiyon sonu
char menu(){//menu fonksiyonu
    char tus;//tus ad�nda char tipinde de�i�ken tan�mlan�yor
    printf("1-kayit ekle\n2-listele\n3-arabul\n4-buldegistir\n5-sil\n");//manu se�enekleri ekrana yazd�r�l�yor
    tus=getch();//kullan�c�n�n girdi�i tu� alg�lan�yor
    return tus;//menu fonksiyonunun �a��r�ld��� yere kullan�c�n�n girdi�i tu� d�nd�r�l�yor
}//menu fonksiyonu sonu
    void kayit_ekle(){//kay�t ekleme fonksiyonu
        char tus2;//tus2 ad�nda char tipinde de�i�ken tan�mlan�yor
        FILE *dosya;//file tipinde bir dosya ad�nda bir pointer tan�mlan�yor
        dosya=fopen("a.txt","w");//dosya �nceki verilerin �st�ne yazmak i�in a��l�yor
 
    do{printf("%d.ki�i adi giriniz",sayac+1);//kullan�c�dan isim isteniyor
    scanf("%s",kisi[sayac].isim);//kullan�c�n� girdi�i veri struct yap�s�na aktar�l�yor
    fflush(stdin);//veri de�i�kene aktar�ld�ktan sonra gerekli alan bo�alt�l�yor
    printf("%d.ki�inin b�l�m giriniz",sayac+1);//kullan�c�dan b�l�m isteniyor
    scanf("%s",kisi[sayac].bolum);//kullan�c�n� girdi�i veri struct yap�s�na aktar�l�yor
    fflush(stdin);//veri de�i�kene aktar�ld�ktan sonra gerekli alan bo�alt�l�yor
    printf("%d.ki�i vizesi giriniz",sayac+1);//kullan�c�dan vize isteniyor
    scanf("%d",&kisi[sayac].vize);//kullan�c�n� girdi�i veri struct yap�s�na aktar�l�yor
    fflush(stdin);//veri de�i�kene aktar�ld�ktan sonra gerekli alan bo�alt�l�yor
    printf("%d.ki�i finali giriniz",sayac+1);//kullan�c�dan final isteniyor
    scanf("%d",&kisi[sayac].final);//kullan�c�n� girdi�i veri struct yap�s�na aktar�l�yor
    fflush(stdin);//veri de�i�kene aktar�ld�ktan sonra gerekli alan bo�alt�l�yor
    printf("yeni kayit i�in e basin ve men�ye d�nmek i�in herhangi bir tusa basin");//veriler girildikten sonra kullan�c�dan yeni veri girmek istermisiniz diye soruluyor
    tus2=getch();//kullan�c�n�n girdi�i karakter tus2 de�i�kenine aktar�l�yor
 
fprintf(dosya,"%s\t%s\t%d\t%d\n",kisi[sayac].isim,kisi[sayac].bolum,kisi[sayac].vize,kisi[sayac].final);//veriler dosyaya yaz�l�yor
sayac++;//whilei�in sayac 1 artt�r�l�yor
    }while(tus2=='e' || tus2=='E');//e�er kullan�c� devam etmek isterse tekrar d�n
fclose(dosya);//dosya kapat�l�yor
}//kay�t ekleme fonksiyonusonu
void listele(){//listele fonksiyonu
FILE *dosya;//file tipinde bir dosya ad�nda bir pointer tan�mlan�yor
dosya=fopen("a.txt","r");//dosya �nceki verileri okumak i�in a��l�yor
int a=0,i;//de�i�kenler tan�mlan�yor
while(!feof(dosya)){//dosya sonuna kadar d�n
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].vize,&yedek[a].final);//veriler dosyadan okunuyor
a++;      //while i�in a artt�r�l�yor
}//dosya sonuna kadar d�n sonu
for(i=0;i<(a-1);i++)//yedek yap�s�n�n sonuna kadar d�n�l�yor
printf("%d\t%s\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].bolum,yedek[i].vize,yedek[i].final);//okunan veriler ekrana yaz�l�yor
fclose(dosya);//dosya kapat�l�yor
}//listele fonksiyonu sonu
void ara_bul(){//arabul fonksiyonu
    char kelime[150];//kelima ad�nda char tipinde bir de�i�ken tan�mlan�yor
printf("Aranacak Kelimeyi girin");//kullan�c�dan aranacak veri isteniyor
scanf("%s",&kelime);//girilen veri kelime de�i�kenine aktar�l�yor
FILE *dosya;//file tipinde bir dosya ad�nda bir pointer tan�mlan�yor
dosya=fopen("a.txt","r");//dosya �nceki verileri okumak i�in a��l�yor
int a=0,i;//de�i�kenler tan�mlan�yor d�ng�ler i�in
while(!feof(dosya)){//dosya sonuna kadar d�n
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].vize,&yedek[a].final);//dosyadan veriler okunup yedek yap�s�na aktar�l�yor
a++;     //while i�in a 1 artt�r�l�yor
 }//dosya sonuna kadar d�n sonu
for(i=0;i<(a-1);i++){//yedek yap�s�n�n sonuna kadar d�n�l�yor
 if(strcmp(kelime,yedek[i].isim)==0)
        {//e�er aranan kelime yedek yap�s�n�n ismine e�it ise a�a��dakileri yap
printf("%d\t%s\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].bolum,yedek[i].vize,yedek[i].final);//veriler ekrana yad�r�l�yor
}//e�er aranan kelime yedek yap�s�n�n ismine e�it ise a�a��dakileri yap sonu
}//yedek yap�s�n�n sonuna kadar d�n�l�yorsonu
fclose(dosya);//dosya kapat�l�yor
}//arabul fonksiyonu sonu
void bul_degistir(){//bul de�i�rtir fonksiyonu
    char kelime[150];
printf("Degisecek Kisiyi girin");//degisecek kisi kulan�c�dan al�n�yor
scanf("%s",&kelime);//kullan�c�n�n girdi�i veri kelime de�i�kenine atan�yor
FILE *dosya;//file tipinde bir dosya pointer� tan�mlan�yor
dosya=fopen("a.txt","r");//a.txt dosyas� sadece okunmak i�in yaz�l�yor
int a=0,i;//kullan�lacak de�i�kenler tan�mlan�yor
while(!feof(dosya)){//dosya sonuna kadar d�n�l�yor ba�lang��
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].vize,&yedek[a].final);//dosyadan al�nan veriler yedek yap�s�na aktar�l�yor
a++;     //yedek de�i�kenini her seferinde farkl� gelmesi i�in a her seferinde artt�r�l�yor
}//dosya sonuna kadar d�n�l�yor sonu
for(i=0;i<(a-1);i++){//yedek yap�s�na al�nan verilerin i�leme sokulmas�
 if(strcmp(kelime,yedek[i].isim)==0)//e�er de�i�ecek kelime yedek yap�s�n�n ismine e�it ise a�a��dakileri yap
        {
            printf("%dninci ki�inin ad�n� giriniz",i+1);//kullan�c�dan yeni isim isteniyor
            scanf("%s",yedek[i].isim);//isim yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
            printf("%dninci ki�inin b�l�m�n� giriniz",i+1);//kullan�c�dan yeni b�l�m isteniyor
            scanf("%s",yedek[i].bolum);//b�l�m yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
            printf("%dninci ki�inin vizesini giriniz",i+1);//kullan�c�dan yeni vize isteniyor
            scanf("%d",&yedek[i].vize); //vize yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
            printf("%dninci ki�inin Finalini giriniz",i+1);//kullan�c�dan yeni final isteniyor
            scanf("%d",&yedek[i].final);//final yedek yap�s�n�n de�i�ecek k�sm�na atan�yor
            fflush(stdin);//de�i�kene aktar�ld�ktan sonra o k�s�m bo�alt�l�yor
 
}
}//yedek yap�s�na al�nan verilerin i�leme sokulmas� sonu
fclose(dosya);//dosya sadece okunmak i�in a��lan dosya kapat�l�yor
 
//�imdi bu k�s�mda de�i�tirilen yedek yap�s�n� a.txtnin �zerine yazarak bul de�i�tir �rne�imizi bitirece�iz
FILE *dosya2;//file tipinde bir dosya2 pointer� tan�mlan�yor
dosya2=fopen("a.txt","w");//a.txt dosyas� �nceki veriler silinecek �ekilde a��l�yor
int i2;//integer tipinde for d�ng�s� i�in i2 de�i�keni olu�turuluyor
for(i2=0;i2<(a-1);i2++){//yine yedek de�i�keninin sonuna kadar d�n�l�yor
fprintf(dosya2,"%s\t%s\t%d\t%d\n",yedek[i2].isim,yedek[i2].bolum,yedek[i2].vize,yedek[i2].final);
}//yedek de�i�keninin sonuna kadar d�nme sonu
fclose(dosya2);//a��lan dosya kapat�l�yor
}//bul de�i�tir fonksiyonu sonu
 
 
void kayit_sil(){//kayit sil fonksiyonu
char kelime[150];
printf("Silinecek Ki�iyi girin");//silinecek ki�i kulan�c�dan al�n�yor
scanf("%s",&kelime);//kullan�c�n�n girdi�i veri kelime de�i�kenine atan�yor
FILE *dosya;//file tipinde bir dosya pointer� tan�mlan�yor
dosya=fopen("a.txt","r");//a.txt dosyas� sadece okunmak i�in yaz�l�yor
int a=0,i=0,kacinci;//kullan�lacak de�i�kenler tan�mlan�yor
while(!feof(dosya)){//dosya sonuna kadar d�n�l�yor ba�lang��
    fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].vize,&yedek[a].final);//dosyadan al�nan veriler yedek yap�s�na aktar�l�yor
a++;     //yedek de�i�kenini her seferinde farkl� gelmesi i�in a her seferinde artt�r�l�yor
}//dosya sonuna kadar d�n�l�yor sonu
 
for(i=0;i<(a-1);i++){//yedek yap�s�na al�nan verilerin i�leme sokulmas�
 if(strcmp(kelime,yedek[i].isim)==0)//e�er silinmesi gereken ki�i ad� yedek yap�s�n�n ismine e�it ise a�a��dakileri yap
        {            kacinci=i;//aranan verinin ka��nc� oldu�u bulunuyor
                   }//e�er silinmesi gereken ki�i ad� yedek yap�s�n�n ismine e�it ise a�a��dakileri yapsonu
 
}//yedek yap�s�na al�nan verilerin i�leme sokulmas� sonu
for(i=0;i<(kacinci);i++){//verinin bulundu�u yere kadar d�n
    strcpy(silinecek[i].isim,yedek[i].isim);
//kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor
    strcpy(silinecek[i].bolum,yedek[i].bolum);
//kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor
    silinecek[i].vize=yedek[i].vize;
//kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor
    silinecek[i].final=yedek[i].final;
//kac�nc�ya kadar olan k�s�mlar silinen yap�s�na aktar�l�yor
}
//verinin bulundu�u yere kadar d�n sonu
for(i=(kacinci+1);i<=(a-1);i++){//silinen veriden sonrakini silinecek k�sm�na ata
    strcpy(silinecek[i-1].isim,yedek[i].isim);//kac�nc�dan sonra olan k�s�mlar silinen yap�s�na aktar�l�yor
    strcpy(silinecek[i-1].bolum,yedek[i].bolum);//kac�nc�dan sonra  olan k�s�mlar silinen yap�s�na aktar�l�yor
    silinecek[i-1].vize=yedek[i].vize;//kac�nc�dan sonra  olan k�s�mlar silinen yap�s�na aktar�l�yor
    silinecek[i-1].final=yedek[i].final;//kac�nc�dan sonra  olan k�s�mlar silinen yap�s�na aktar�l�yor
}//silinen veriden sonrakini silinecek k�sm�na ata sonu
 
 
fclose(dosya);//dosya sadece okunmak i�in a��lan dosya kapat�l�yor
 
//�imdi bu k�s�mda de�i�tirilen yedek yap�s�n� a.txtnin �zerine yazarak bul de�i�tir �rne�imizi bitirece�iz
FILE *dosya2;//file tipinde bir dosya2 pointer� tan�mlan�yor
dosya2=fopen("a.txt","w");//a.txt dosyas� �nceki veriler silinecek �ekilde a��l�yor
int i2;//integer tipinde for d�ng�s� i�in i2 de�i�keni olu�turuluyor
for(i2=0;i2<(a-1);i2++){//yine silinecek de�i�keninin sonuna kadar d�n�l�yor
fprintf(dosya2,"%s\t%s\t%d\t%d\n",silinecek[i2].isim,silinecek[i2].bolum,silinecek[i2].vize,silinecek[i2].final);
}//silinecek de�i�keninin sonuna kadar d�nme sonu
fclose(dosya2);//a��lan dosya kapat�l�yor
 
}//kayitsil fonksiyonu sonu
