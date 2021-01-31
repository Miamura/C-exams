#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
extern const short int Personel_Sayisi=200;

extern const char *Dosya_Adi="pesoneller.dat";

extern const bool Otomatik_Sicil_Durum=1;

short int En_Son_Personel_No;

using namespace std;

struct Personeller
{
 short int sicil;
 
 char ad[10];
 
 char soyad[10];
 
 float brut;
 
 unsigned short int yas;
 
 bool cinsiyet;
 
}
Personel[Personel_Sayisi];
FILE *dosya;
extern int main                  ( int argc , char *argv[] );
extern int Menuler               (  );
extern int Yeni_Personel         (  );
extern int Personel_Degistir     (  );
extern int Personel_Sil          (  );
extern int Personel_Goruntule    (  );
extern int Cikis                 (  );
extern int Ekrani_Temizle        (  );
extern int En_Son_Personel       (  );
extern int Personelleri_Oku      (  );
extern int Dosya_Bosalt          (  );
extern int Dur                   (  );
extern int Oku                   (  );
extern int Personelleri_Kaydet   ( int Engel );
extern int Sicilli_Ara           ( int Sicil );
extern int Otomatik_Sicil        (  );
extern int main( int argc , char *argv[] )
{
 Oku();
 Menuler();
 return 0;
}

extern int Menuler( )
{
 Ekrani_Temizle();
 auto char Secim;
 cout << "1.Yeni Personel" <<      endl;
 
 cout << "2.Personel Degistir" <<  endl;
 
 cout << "3.Personel Sil" <<       endl;
 
 cout << "4.Personel Goruntule" << endl;
 
 cout << "5.Cikis" <<              endl;
 
 cout << "Seciminiz:";
 
 Secim = getche();
 
 switch ( Secim )
 
 {
 case '1' : Yeni_Personel();       break;
 
 case '2' : Personel_Degistir();   break;
 
 case '3' : Personel_Sil();        break;
 
 case '4' : Personel_Goruntule();  break;
 
 case '5' : Cikis();               break;
 
 default  : Menuler();             break;
 
 }
 return 0;
}
extern int Otomatik_Sicil (  )
{
 auto short int sicil = -1;
 
 struct tm *zaman;
 
 time_t ayar;
 
 time( &ayar );
 
 zaman = gmtime( &ayar );
 
 srand( zaman -> tm_sec );
 
 while( sicil = rand() % 65536 ) if( Sicilli_Ara( sicil ) == -1 ) break;
 
 return sicil;
}
extern int Oku (  )
{
 En_Son_Personel_No = En_Son_Personel();
 
 Personelleri_Oku();
 
 return 0;
}
extern int Dur (  )
{
 system( "PAUSE" );
 return 0;
}
extern int Sicilli_Ara ( int Sicil)
{
 auto short int No = -1;
 register int Sayac;
 for( Sayac = 0; Sayac <= En_Son_Personel_No; Sayac++ )if( Personel[Sayac].sicil == Sicil )No = Sayac;
 
 return No;
}
extern int Dosya_Bosalt (  )
{
 dosya = fopen( Dosya_Adi , "w" );
 fwrite( "" , 0 , 1 , dosya );
 fclose( dosya );
 return 0;
}
extern int Personelleri_Oku (  )
{
 dosya = fopen( Dosya_Adi , "r" );
 if( dosya )
 {
  fread( &Personel , sizeof(Personel) , 1 , dosya );
  fclose( dosya );
 }
 return 0;
}
extern int Personelleri_Kaydet ( int Engel )
{
 register int Sayac;
 Dosya_Bosalt();
 dosya = fopen( Dosya_Adi , "a+" );
 for ( Sayac = 0 ; Sayac <= En_Son_Personel_No ; Sayac++ ){
  if( ( Sayac != Engel &&Engel >= 0 ) || Engel < 0)fwrite( &Personel[Sayac] , sizeof(Personel[0]) , 1 , dosya );
 }
 fclose( dosya );
 Oku();
 return 0;
}
extern int En_Son_Personel (  )
{
 auto int Kayit = 0;
 dosya = fopen( Dosya_Adi , "r" );
 if( dosya )
 {
  fseek( dosya , 0 , SEEK_END );
  Kayit = ftell( dosya ) / sizeof( Personel[0] );
  fclose( dosya );
 }
 return Kayit-1;
}
extern int Ekrani_Temizle(  )
{
 system( "CLS" );
 return 0;
}
extern int Yeni_Personel(  )
{
 auto char cinsiyet;
 Ekrani_Temizle();
 fflush( stdin );
 
 En_Son_Personel_No = En_Son_Personel() +1;
 Personel[En_Son_Personel_No].sicil = -1;
 
 if( !Otomatik_Sicil_Durum )
 {
  cout << "Sicil No:";
  cin  >> Personel[En_Son_Personel_No].sicil;
 } else Personel[En_Son_Personel_No].sicil = Otomatik_Sicil();
 cout << "Ad:";
 cin  >> Personel[En_Son_Personel_No].ad;
 cout << "Soyad:";
 cin  >> Personel[En_Son_Personel_No].soyad;
 cout << "Brut:";
 cin  >> Personel[En_Son_Personel_No].brut;
 cout << "Yas:";
 cin  >> Personel[En_Son_Personel_No].yas;
 cout << "Cinsiyet [E/K]:";
 cinsiyet = getche();
 if( cinsiyet == 'K' )Personel[En_Son_Personel_No].cinsiyet = 0; else Personel[En_Son_Personel_No].cinsiyet = 1;
 Personelleri_Kaydet( -1 );
 Menuler();
 return 0;
}
extern int Personel_Degistir( **** )
{
 auto short int sicil , no;
 auto char cinsiyet;
 Ekrani_Temizle();
 fflush( stdin );
 cout << "Sicil No:";
 cin  >> sicil;
 no = Sicilli_Ara( sicil );
 
 if( no != -1 )
 {
  cout << "Yeni Sicil No:";
  cin  >> Personel[no].sicil;
  cout << "Yeni Ad:";
  cin  >> Personel[no].ad;
  cout << "Yeni Soyad:";
  cin  >> Personel[no].soyad;
  cout << "Yeni Brut:";
  cin  >> Personel[no].brut;
  cout << "Yeni Yas:";
  cin  >> Personel[no].yas;
  cout << "Cinsiyet:";
  cinsiyet =  getche();
  if( cinsiyet == 'K' )Personel[no].cinsiyet = 0; else Personel[no].cinsiyet = 1;
  Personelleri_Kaydet( -1 );
 }
 
 Menuler();
 return 0;
}
extern int Personel_Sil( **** )
{
 auto short int sicil , no;
 Ekrani_Temizle();
 fflush( stdin );
 cout << "Sicil No:";
 cin  >> sicil;
 no = Sicilli_Ara( sicil );
 if( no != -1 )Personelleri_Kaydet( no );
 
 Menuler();
 return 0;
}
extern int Personel_Goruntule( **** )
{
 register int Sayac;
 auto char brut[13],cinsiyet;
 Ekrani_Temizle();
 printf("%6s%11s%11s%14s%4s %5s","Sicil","Ad","Soyad","Brut","Yas","Cinsiyet");
 cout << endl;
 for ( Sayac = 0; Sayac <= En_Son_Personel_No; Sayac++ )
 {
  sprintf(brut,"%6.6f",Personel[Sayac].brut);
  
  if( Personel[Sayac].cinsiyet )cinsiyet = 'E'; else cinsiyet = 'K';
  
  printf("%6u%11s%11s%14s%4d%5c\n",Personel[Sayac].sicil,Personel[Sayac].ad,Personel[Sayac].soyad,brut,Personel[Sayac].yas,cinsiyet);
  
 }
 
 cout << endl;
 
 Dur();
 
 Menuler();
 
 return 0;
}
extern int Cikis( **** )
{
 exit(0);
 return 0;
}
