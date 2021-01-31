#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 
struct ogrenci{
		int no;
       char ad[20];
       char soyad[20];
       float not1;
       float not2;
       float not3;
       float odev1;
       float odev2;
       float ort;
};

int sonnumara(void);
int satirsay(void);
void ogrekle(void);
void degistirsil(void);
void ogrsil(void);
void ogrgor(void);
void degistir(void);
float ortal(float a,float b,float c,float d,float e);
void notgiris(void);
void menu(void);
void notgor(void);
void ogrenci(void);
void ogretmen(void);

		
int main() {
	
	menu();

 return 0;
}

int sonnumara(void){
	int tut,k,i;
	FILE *dg;
	struct ogrenci a;
	dg= fopen ("ogrenci.txt","r");
	
	if(  dg == NULL )
	  {
        return(1000);
	  }
	k=satirsay()+1;
	
	
	
	for(i=0;i<k;i++){	
			fscanf(dg,"%d %s %s %f %f %f %f %f %f",&a.no,a.ad,a.soyad,&a.not1,&a.not2,&a.not3,&a.odev1,&a.odev2,&a.ort);
			tut=a.no;
		}
	fclose(dg);
	return(tut);
}



 int satirsay(void){
	FILE *dg;
	int  k=0;
	char ch;
    
	dg = fopen("ogrenci.txt", "r");
	
	 if(  dg == NULL )
	  {
       clrscr(); printf("ogrenci.txt dosyasi acilmadi. !\n"), exit(1);
	  }
	
	 while(!feof(dg))
	  {
       ch=getc(dg);
	   if(ch=='\n'){ k++; }
	  }
		fclose(dg);
		return (k);
		}    
		
void ogrekle(void){
	int  k=0,i=0,b,d;
    FILE *dg;
    struct ogrenci a;
	dg = fopen("ogrenci.txt", "a");
	
	
	
	 if(  dg == NULL )
	  {
       puts("ogrenci.txt dosyasi acilmadi. !\n");
       	dg = fopen("ogrenci.txt", "w");

	  }
	  k=satirsay()+1;
	 d=sonnumara()+1;
	  a.no=1001;
	  
	  if(k!=1){ 
       	a.no=d;
		fprintf(dg,"\n");
	   }
	 
	  printf("Kac ogrenci bilgisi gireceksiniz ? "); scanf("%d",&b);
     printf("%d ogrenciye ait bilgileri girin: \n\n",b);
     
	 while( i<b )
      {
       printf("%d. ogrencinin adi     : ",i+1); scanf("%s",a.ad);
       printf("%d. ogrencinin soyadi  : ",i+1); scanf("%s",a.soyad);

       printf("\n");

		a.not1=-1; a.not2=-1; a.not3=-1; a.odev1=-1; a.odev2=-1; a.ort=-1;
    	fprintf(dg,"%d\t%s\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f",a.no,a.ad,a.soyad,a.not1,a.not2,a.not3,a.odev1,a.odev2,a.ort); 
		a.no++;
		if(i==(b-1)){break;}
		fprintf(dg,"\n");i++;
		}
    
    fclose(dg); /* dosyayý kapat */

   clrscr(); puts("Bilgiler kaydedildi.\a"); printf("devam etmek icin bir tusa basiniz! \n"); getch(); 
}
void degistirsil(void){
	int i,b;
	struct ogrenci a;
	FILE *yd;
	FILE *dg;
	b=satirsay();
	yd=fopen("yedek.txt","r"); 
	dg = fopen("ogrenci.txt","w");  
		
	for(i=0;i<b;i++){
		fscanf(yd,"%d %s %s %f %f %f %f %f %f",&a.no,a.ad,a.soyad,&a.not1,&a.not2,&a.not3,&a.odev1,&a.odev2,&a.ort);
		fprintf(dg,"%d\t%s\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f",a.no,a.ad,a.soyad,a.not1,a.not2,a.not3,a.odev1,a.odev2,a.ort);	
		if(i==(b-1)){break;}
		fprintf(dg,"\n");
		 }
	 fclose (dg);
	 fclose (yd);
	}

void ogrsil(){
	int b,aranacak,deger=1,i;
	FILE *dg;
	FILE *yd;
	struct ogrenci a;
	b=satirsay()+1;
	 dg=fopen("ogrenci.txt","r");
	yd =fopen("yedek.txt","w");

	
	printf("Ogrenci numarasi :");
		scanf("%d",&aranacak);
		
	for(i=0;i<b;i++){		
		
		fscanf(dg,"%d %s %s %f %f %f %f %f %f",&a.no,a.ad,a.soyad,&a.not1,&a.not2,&a.not3,&a.odev1,&a.odev2,&a.ort);
		
		if(a.no==aranacak){deger=0;continue; }	
		
		fprintf(yd,"%d\t%s\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f",a.no,a.ad,a.soyad,a.not1,a.not2,a.not3,a.odev1,a.odev2,a.ort);	
		if (i==(b-1)){break;}
		fprintf(yd,"\n");
	}
	fclose (dg);
	fclose (yd);
	
	if (deger==1){ clrscr();
	 printf("Aradiginiz numaraya kayitli ogrenci bulunmamaktadir!\n\n Lutfen tanimli bir numara giriniz!\n\n");
	 ogrsil();
	 }
	 printf("%d numarali ogrenci basari ile silindi\n",aranacak); printf("devam etmek icin bir tusa basiniz! \n"); getch();
	 degistirsil();
}

void ogrgor(){
	float not1=0,not2=0,not3=0,odev1=0,odev2=0,ort=0;
	float anot1=0,anot2=0,anot3=0,aodev1=0,aodev2=0,aort=0;
	float d=0,f=0,g=0,h=0,j=0,k=0;
	int i=0;
		struct ogrenci a;
		FILE *dg;
		dg= fopen("ogrenci.txt","r");
		if(dg==NULL){clrscr(); printf("Henüz ogrenci kaydedilmemiþ.\n");
		}
		
		printf("Numara   Ad    Soyad   1.yaz.  2.yaz.  3.yaz.  1.odev  2.odev  ortalama\n");
		printf("------------------------------------------------------------------------\n");
		
	while (!feof(dg)) //dosyanýn sonu olmadýðý sürece devam eder
	{
	
	
 	fscanf(dg,"%d %s %s %f %f %f %f %f %f",&a.no,a.ad,a.soyad,&a.not1,&a.not2,&a.not3,&a.odev1,&a.odev2,&a.ort); // dosyadan verileri struct ile ayýrara okuduk
	
	if(!(a.not1==-1)){not1+=a.not1; d++; }
	if(!(a.not2==-1)){not2+=a.not2; f++;	}
	if(!(a.not3==-1)){not3+=a.not3; g++;	}
	if(!(a.odev1==-1)){odev1+=a.odev1; h++;	}
	if(!(a.odev2==-1)){odev2+=a.odev2; j++;	}
	if(!(a.ort==-1)){ort+=a.ort; k++;	}
	
	}
	anot1=(not1/d); anot2=(not2/f); anot3=(not3/g); aodev1=(odev1/h); aodev2=(odev2/j); aort=(ort/k);

	fclose(dg);
	dg=fopen("ogrenci.txt","r");
	while (!feof(dg)) //dosyanýn sonu olmadýðý sürece devam eder
	{
	
	
 	fscanf(dg,"%d %s %s %f %f %f %f %f %f",&a.no,a.ad,a.soyad,&a.not1,&a.not2,&a.not3,&a.odev1,&a.odev2,&a.ort); // dosyadan verileri struct ile ayýrara okuduk
	printf("%d\t%s\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\n",a.no,a.ad,a.soyad,a.not1,a.not2,a.not3,a.odev1,a.odev2,a.ort);	// okuduðumuz verileri yazdýrdýk
	i++;
	if (i%10==0){
		printf("------------------------------------------------------------------------\n");
		printf("Sinif ortalamasi:\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f \n",anot1,anot2,anot3,aodev1,aodev2,aort);
		printf("\n------------------------------------------------------------------------\n");
		printf("*        '-1' olarak gorunen notlar henuz girilmemis notlardir         *\n");
		printf("\n------------------------------------------------------------------------\n");
		printf("*       Diger sayfaya gecmek icin herhangi bir tusa basiniz...         *\n");
		printf("------------------------------------------------------------------------\n");
		getch(); clrscr();
		printf("Numara   Ad    Soyad   1.yaz.  2.yaz.  3.yaz.  1.odev  2.odev  ortalama\n");
		printf("------------------------------------------------------------------------\n");
	
	}
	
	
	}
	anot1=(not1/d); anot2=(not2/f); anot3=(not3/g); aodev1=(odev1/h); aodev2=(odev2/j); aort=(ort/k);
	printf("------------------------------------------------------------------------\n");
	printf("Sinif ortalamasi:\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f \n",anot1,anot2,anot3,aodev1,aodev2,aort);
	printf("\n------------------------------------------------------------------------\n");
	printf("*        '-1' olarak gorunen notlar henuz girilmemis notlardir         *\n");
	printf("------------------------------------------------------------------------\n");
	fclose(dg); 
}



void degistir(){
	int i,b;
	struct ogrenci a;
	FILE *yd;
	FILE *dg;
	b=satirsay()+1;

	yd=fopen("yedek.txt","r"); 
	dg = fopen("ogrenci.txt","w");  
		
	for(i=0;i<b;i++){
		fscanf(yd,"%d %s %s %f %f %f %f %f %f",&a.no,a.ad,a.soyad,&a.not1,&a.not2,&a.not3,&a.odev1,&a.odev2,&a.ort);
		fprintf(dg,"%d\t%s\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f",a.no,a.ad,a.soyad,a.not1,a.not2,a.not3,a.odev1,a.odev2,a.ort);	
		if(i==(b-1)){break;}
		fprintf(dg,"\n");
		 }
	 fclose (dg);
	 fclose (yd);
	}
float ortal(float a,float b,float c,float d,float e){
	float n,o,sonuc;
	n= (a+b+c)/3;
	o= (d+e)/2;
	
	sonuc= (n+o)/2;
	
	if (a==-1){return -1;}
	else if(b==-1){return -1;}
	else if(c==-1){
		if(d==-1){n=(a+b)/2; return n;}
		if(e==-1){n=(((a+b)/2)+d)/2; return n;}
		else{n=(a+b)/2; sonuc=(n+o)/2; return sonuc;}
		}
	else if(d==-1){return n;}
	else if(e==-1){o=(n+d)/2; return o;}
	else {return sonuc;}
}
		
void notgiris(){
	
	int i,b,deger=1,sec,geridon,f;
	int aranacak;
	FILE *dg;
	FILE *yd;
	struct ogrenci a;
	b=satirsay()+1;
	
	dg = fopen("ogrenci.txt", "r");
	yd = fopen("yedek.txt","w");
	
	if(  dg == NULL )
	  {
       puts("ogrenci.txt dosyasi acilmadi. !\n"), exit(1);
	  }
	if(  yd == NULL )
	  {
       puts("ogrenci.txt dosyasi acilmadi. !\n"), exit(1);
	  }
	  
	
	  
		printf("Ogrenci numarasi :");
		scanf("%d",&aranacak);
	
			
		for(i=0;i<b;i++){		
		
			fscanf(dg,"%d %s %s %f %f %f %f %f %f",&a.no,a.ad,a.soyad,&a.not1,&a.not2,&a.not3,&a.odev1,&a.odev2,&a.ort);
			if(a.no==aranacak)
			 {	
			 	do{
			 	printf("\n----------------------------------------------------------------\n");
			 	printf("*                                                              *\n");
			 	printf("*                                                              *\n");
				printf("*   %d numarali ogrencinin hangi notunu girmek istersiniz?   *\n" ,a.no);
			 	printf("*                                                              *\n");
			 	printf("*           *  1.yazili icin 1'i tuslayin                      *\n");
			 	printf("*           *  2.yazili icin 2'yi tuslayin                     *\n");
				printf("*           *  3.yazili icin 3'u tuslayin                      *\n");
				printf("*           *  1.odev icin 4'u tuslayin                        *\n");
				printf("*           *  2.odev icin 5'u tuslayin                        *\n");
				printf("*                                                              *\n");
				printf("*                                                              *\n");
				printf("----------------------------------------------------------------\n\n\n");
			 	scanf("%d",&sec);
			 	
				switch(sec){
					case 1:	while(f){ clrscr();
					printf("1.yazili notu =");			
							scanf("%f",&a.not1);
							if(a.not1<0){f=1; clrscr();printf("0-100 arasi sayi giriniz! \n");}
							else if (a.not1>100){f=1;clrscr(); printf("0-100 arasi sayi giriniz! \n");}
							else{f=0;}clrscr();
							geridon=0; 
					}break;
					case 2: while(f){clrscr();
					printf("2.yazili notu =");			
							scanf("%f",&a.not2);
							if(a.not2<0){f=1; clrscr();printf("0-100 arasi sayi giriniz! \n");}
							else if (a.not2>100){f=1;clrscr(); printf("0-100 arasi sayi giriniz! \n");}
							else{f=0;}clrscr();
							geridon=0; 
					}break;
					case 3: while(f){clrscr();
					printf("3.yazili notu =");			
							scanf("%f",&a.not3);
							if(a.not3<0){f=1; clrscr();printf("0-100 arasi sayi giriniz! \n");}
							else if (a.not3>100){f=1;clrscr(); printf("0-100 arasi sayi giriniz! \n");}
							else{f=0;}clrscr();
							geridon=0; 
					}break;
					case 4:	while(f){clrscr();
					printf("1.odev notu =");			
							scanf("%f",&a.odev1);
							if(a.odev1<0){f=1;clrscr(); printf("0-100 arasi sayi giriniz! \n");}
							else if (a.odev1>100){f=1;clrscr(); printf("0-100 arasi sayi giriniz! \n");}
							else{f=0;}clrscr();
							geridon=0; 
					}break;
					case 5:while(f){clrscr();
					printf("2.odev notu =");			
							scanf("%f",&a.odev2);
							if(a.odev2<0){f=1; clrscr();printf("0-100 arasi sayi giriniz! \n");}
							else if (a.odev2>100){f=1;clrscr(); printf("0-100 arasi sayi giriniz! \n");}
							else{f=0;}clrscr();
							geridon=0; 
					}break;		
					default:clrscr(); printf("lutfen birini secin!\n"); geridon=1;
				}
			 }while(geridon==1);
				deger=0;
			 }
			
			a.ort= ortal(a.not1,a.not2,a.not3,a.odev1,a.odev2);
		
			fprintf(yd,"%d\t%s\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\n",a.no,a.ad,a.soyad,a.not1,a.not2,a.not3,a.odev1,a.odev2,a.ort);
			if(i==(b-1)){break;}
			fprintf(yd,"\n");
		 }	
		
		 fclose (dg);
		 fclose (yd);
		if(deger==1){clrscr();
			printf("Aradiginiz numaraya kayitli ogrenci bulunmamaktadir!\n Lutfen tanimlili bir numara giriniz!\n");
		notgiris();
		}
		if(deger==0){
		degistir();
		}	 
	clrscr();
}
void menu(){
	int secim;
	printf("--------------------------------------------------------------\n");
	printf("*                                                            *\n");
	printf("*       ## Ogrenci not sistemine hosgeldiniz. ##             *\n");
	printf("*                                                            *\n");
	printf("*      *  Ogretmen girisi icin 1'i tuslayiniz.               *\n");
	printf("*      *  Ogrenci girisi icin 2'yi tuslayiniz.               *\n");
	printf("*      *  Cikmak icin 3'u tuslayiniz.                        *\n");
	printf("*                                                            *\n");
	printf("*                                                            *\n");	
	printf("--------------------------------------------------------------\n\n\n");
	scanf("%d",&secim);
	switch(secim){
	
	 case 1:{ clrscr(); ogretmen(); clrscr();
		break;
	 }
	 case 2:{ clrscr(); ogrenci(); clrscr();
		break;
	 }
	 case 3: exit(1);
	 default: clrscr(); printf("Yanlis bir tusa bastiniz!\nLütfen gecerli bir tuslama yapiniz.\n"); menu(); 
	}
}

void notgor(void){
	float not1=0,not2=0,not3=0,odev1=0,odev2=0,ort=0;
	float anot1=0,anot2=0,anot3=0,aodev1=0,aodev2=0,aort=0;
	float d=0,f=0,g=0,h=0,j=0,l=0;
	FILE *dg;
	int k,i,deger=0,no;
	struct ogrenci a;
	k=satirsay()+1;
	dg= fopen("ogrenci.txt","r");
	printf("numaranizi girin:"); 
	scanf("%d",&no);
	if(  dg == NULL )
	  {
       puts("ogrenci.txt dosyasi acilmadi. !\n"), exit(1);
	  }
	for(i=0;i<k;i++){
		fscanf(dg,"%d %s %s %f %f %f %f %f %f",&a.no,a.ad,a.soyad,&a.not1,&a.not2,&a.not3,&a.odev1,&a.odev2,&a.ort);  
	  if(!(a.not1==-1)){not1+=a.not1; d++; }
	if(!(a.not2==-1)){not2+=a.not2; f++;	}
	if(!(a.not3==-1)){not3+=a.not3; g++;	}
	if(!(a.odev1==-1)){odev1+=a.odev1; h++;	}
	if(!(a.odev2==-1)){odev2+=a.odev2; j++;	}
	if(!(a.ort==-1)){ort+=a.ort; l++;	}
	
	}
	anot1=(not1/d); anot2=(not2/f); anot3=(not3/g); aodev1=(odev1/h); aodev2=(odev2/j); aort=(ort/l); 
	fclose(dg);
	dg= fopen("ogrenci.txt","r");

	
	for(i=0;i<k;i++){
		fscanf(dg,"%d %s %s %f %f %f %f %f %f",&a.no,a.ad,a.soyad,&a.not1,&a.not2,&a.not3,&a.odev1,&a.odev2,&a.ort);
		if(no==a.no){
		printf("\n\n\nNumara   Ad    Soyad   1.yaz.  2.yaz.  3.yaz.  1.odev  2.odev  ortalama\n");
		printf("------------------------------------------------------------------------\n");
		printf("                                                                        \n");
		printf("%d\t%s\t%s\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\n",a.no,a.ad,a.soyad,a.not1,a.not2,a.not3,a.odev1,a.odev2,a.ort);
		
		deger=1;break;
		}	
	}
	printf("\n------------------------------------------------------------------------\n");
		printf("Sinif ortalamasi:\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f\t%3.1f \n",anot1,anot2,anot3,aodev1,aodev2,aort);
		printf("\n------------------------------------------------------------------------\n");
		printf("                                                                        \n");
		printf("------------------------------------------------------------------------\n");
		printf("*        '-1' olarak gorunen notlar henuz girilmemis notlardir         *\n");
		printf("------------------------------------------------------------------------\n");
	if(deger==0){ 
	printf("------------------------------------------------------------------------\n");
	printf("Girdiginiz numaraya kayitli ogrenci bulunamamistir!                     \n"); 
	printf("Ana menuye yonlendiriliyorsunuz, devam etmek icin bir tusa basin...     \n"); 	
	printf("------------------------------------------------------------------------\n"); getch(); ogrenci(); }
	fclose(dg);
}

void ogrenci(){
	
	int secim,b;
	printf("--------------------------------------------------------------\n");
	printf("*                                                            *\n");
	printf("*     ## Ogrenci not goruntuleme sistemine hosgeldiniz. ##   *\n");
	printf("*                                                            *\n");
	printf("*         *  Not goruntulemek icin 1'i tuslayin.             *\n");
	printf("*         *  Ana menuye donmek icin 2'yi tuslayin.           *\n");
	printf("*         *  Cikmak icin 3'u tuslayin.                       *\n");
	printf("*                                                            *\n");
	printf("*                                                            *\n");	
	printf("--------------------------------------------------------------\n\n\n");
	
	scanf("%d",&secim);
	switch(secim){
		case 1:{ clrscr(); notgor(); printf("Devam etmek icin bir tusa basiniz."); getch(); clrscr(); ogrenci();	break;	}
		case 2:{ clrscr(); menu(); break;	}
		case 3:{ exit(1); break;	}
		default:{ clrscr(); printf("Lütfen birini seçin! \n"); ogrenci(); }
		 
	}
	
}


void ogretmen(){
	int secim;
	
	printf("--------------------------------------------------------------\n");
	printf("*                                                            *\n");
	printf("*       ## Ogrenci not giris sistemine hosgeldiniz. ##       *\n");
	printf("*                                                            *\n");
	printf("*      *  Ogrenci eklemek icin 1'i tuslayiniz.               *\n");
	printf("*      *  Ogrenci silmek icin 2'yi tuslayiniz.               *\n");
	printf("*      *  Not girisi icin 3'u tuslayiniz.                    *\n");
	printf("*      *  Not goruntulemek icin 4'ü tuslayiniz.              *\n");
	printf("*      *  Ana menuye donmek icin 5'yi tuslayin.              *\n");
	printf("*      *  Cikmak icin 6'i tuslayin.                          *\n");
	printf("*                                                            *\n");
	printf("*                                                            *\n");	
	printf("--------------------------------------------------------------\n\n\n");
	
	scanf("%d",&secim);
	switch(secim){
		case 1 :clrscr();
		ogrekle(); clrscr(); ogretmen(); 
		break;
		case 2 :clrscr();
		ogrsil(); clrscr(); ogretmen(); 
		break;
		case 3 :clrscr();
		notgiris(); clrscr(); ogretmen();
		break;
		case 4 :clrscr();
		ogrgor(); printf("devam etmek icin herhangi bir tusa basiniz\n"); getch();  clrscr(); ogretmen();  break;
		case 5:clrscr(); menu(); break;
		
		case 6:exit(1);
		default:clrscr();  printf("Lütfen birini seçin! \n"); clrscr(); ogretmen();
	}
}
