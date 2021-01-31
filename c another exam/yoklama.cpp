#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define BOS 0
  
          
  int parola();
  
  int anamenu();
  
  int notgiris();
  
  int listele();
  
  int ogrkyt();
  
  int ogrsil();
  
  int devamsizlik();
  
  int arama();
  
  int detay();
  
  int duzelt();
  
  int s_listesi();
  
  int esas();
  
  int s_bul();
  
  int ara_isim();
  
  int ara_no();
  
  
  long double f_no(char array[]);
  
  char sinif[20],izin,fab_adi[20];
  
  int q=0;
  
  struct kimlik
  {
        char ad[80];char s_ad[80];char no [13];
  };
  
  struct ogrenci
        {
            struct kimlik bilgi;
            int devamsizlik,not1[10];
            int kontrol[10];
        };
        
  struct as
         {
            struct ogrenci ogr[50];/*Ogrenci deki bilgiler ogr daki 50 adet ogrenci için kullanýlýr ve bu bilgiler as'a atanýr. */
            char sinif_adi[20];int __mevcut;
         }dos[10];
         
  FILE *f;
                           
  int main()
  {                          
       int n,durum=0;
       
       char izin;
       
       int i;
       
	   parola();
       
	   printf("Fabrik adini giriniz");
       
	   gets(fab_adi);
       
	   if ((f=fopen("ders1.txt","r+"))==BOS)
       { 
            printf("_%s_ DOSYA BULUNAMADI!!!\n Yeni Dosya Olusturmak Icin 'n' \n Cikis Icin Herhangi Bir Tus\n",fab_adi);
            izin=getch();
            if(izin=='n')
            {
                if ((f=fopen("ders1.txt","w+"))==BOS)
                {                    
                    printf("HATA!!!\n");
                    exit(0);
                }
            }
            else
            return 0; 
       }
       
       fseek(f,0,SEEK_SET);
       
       for(i=0;i<10;i++)
       if(fread(&dos[i],sizeof(struct as),1,f)<1)
       {
                     printf("\n\t-----*%d***-----\n",i);
                     printf("Dosya Okunamiyor\n");
                     s_listesi();
       }
       fseek(f,0,SEEK_SET);
       printf("Sinif Ýsmi Giriniz...\n");
       gets(sinif);
       for(i=0;i<10;i++)
       {
              if ((f=fopen("ders1.txt","r+"))==BOS)
                     {
                                   printf("HATA!!!");
                                   exit (0);
                     }
              if(strcmp(dos[i].sinif_adi,sinif)==BOS)
                     {
                       q=i;
                       s_listesi();
                       break;
                     }
       }
       
       fclose(f);
      
	   char islem;
      
	   while(1) 
       {
                islem=anamenu();
                switch (islem)
                {
                    case '1' : notgiris(); break;
                    case '2' : listele(); break;
                    case '3' : ogrkyt(); break;
                    case '4' : ogrsil(); break;
                    case '5' : devamsizlik(); break;
                    case '6' : arama(); break;
                    case '7' : detay(); break;
                    case '8' : duzelt();break;
                    default : printf("GECERSÝZ SECENEK!..\n");
                }
       }
  return 0;
  }
  
  int listele()
  {
        struct ogrenci is;
        
		float toplam[10];
        
		char n;
        
		int i,j,k;
        
		int durum=0;
        
		printf("Alfabetik siralama icin ?? tusuna bas\n ");
        
		n= getch();
        
		if(n=='n')
       
	    for (i = 0; i < dos[q].__mevcut-1 ; i++)
            for (k = 0; k < dos[q].__mevcut-1 ; k++)
                if (f_no(dos[q].ogr[k].bilgi.ad) > f_no(dos[q].ogr[k+1].bilgi.ad))
                {
                    is = dos[q].ogr[k];
                    dos[q].ogr[k] = dos[q].ogr[k+1];
                    dos[q].ogr[k+1] =is;
                }
                
        printf("AD \tSOYAD \tNO \t\t");
        
        for(j=0;j<dos[q].ogr[durum+2].kontrol[1];j++)
        printf("not%d ",j+1);
        
        printf("\n****************************\n");
        
        fseek(f, 0, SEEK_SET);
        
        while(durum<50)
        {
            if(dos[q].ogr[durum].kontrol[0]!=1)
            {
                durum++;
                continue;
            }
            printf("%s %s %s ",dos[q].ogr[durum].bilgi.ad,dos[q].ogr[durum].bilgi.s_ad,dos[q].ogr[durum].bilgi.no);
            for(i=0;i<dos[q].ogr[durum].kontrol[1];i++)
            {
                toplam[i]+=dos[q].ogr[durum].not1[i];
                printf("--(%.3d)-",dos[q].ogr[durum].not1[i]);
            }
            if(dos[q].ogr[durum].kontrol[1]==0)
                printf("BU KISIYE AIT SINAV SONUCU BULUNMAMAKTADIR.\n ");
                
				printf("\n");
                
				printf("/t ***\n");
                
				durum++;
        }
  
        printf("Sinav Ortalamalari=");
        
		for(i=0;i<dos[q].ogr[0].kontrol[1];i++)
        {
            printf("--(%2.1f)",toplam[i]/dos[q].__mevcut);
            if(toplam[i]==0)
            printf("!!Ortalama Yok!! ");
        }
  }      
                     
  int ogrkyt()
  {
        int s_farki=0;
         
		char sec;
         
		int k;
         
		int ek=dos[q].__mevcut;
         
		while(1)
        {
            printf("AD: ");
            gets(dos[q].ogr[ek].bilgi.ad);
            if(dos[q].ogr[ek].bilgi.ad[0]==BOS)
            break;
            printf("SOYAD: ");
            gets(dos[q].ogr[ek].bilgi.s_ad);
            printf("NO: ");
            gets(dos[q].ogr[ek].bilgi.no);
            dos[q].ogr[ek].kontrol[0]=1;
            dos[q].ogr[ek].kontrol[1]=0;
            if(dos[q].ogr[ek].kontrol[1]!=dos[q].ogr[ek-1].kontrol[1])
            {
                printf("Bu Sinif %d Sinava Girmis \n",dos[q].ogr[ek-1].kontrol[1]-dos[q].ogr[ek].kontrol[1]);
                s_farki=dos[q].ogr[ek-1].kontrol[1]-dos[q].ogr[ek].kontrol[1];
                for(k=0;k<s_farki;k++)
                {                
                    scanf("%d",&dos[q].ogr[ek].not1[k]);
                    
					dos[q].ogr[ek].kontrol[1]++;
                    
					dos[q].ogr[ek].kontrol[k+4]=dos[q].ogr[ek-1].kontrol[k+4];
                }     
            }
            ek++;
  
         }
         
         dos[q].__mevcut=ek;
  }
                  
  int ogrsil()
  {
        char cg;
        
		char delname[20];
        
		int x=0;
        
		printf("Silinecek Ogrenci Adini Giriniz\n");
        
		gets(delname);
        
		for( x=0;x<dos[q].__mevcut;x++)
        {
             if(strcmp(delname,dos[q].ogr[x].bilgi.ad)==0)
             {
                break;
             }
             
             if(x==dos[q].__mevcut-1)
             {
                printf("SISTEME KAYITLI DEGIL!\n");
                anamenu();
             }
        }
        
		printf("*SILINMEK ISTENEN KAYIT*\n");
        
		printf("%s %s %s ",dos[q].ogr[x].bilgi.ad,dos[q].ogr[x].bilgi.s_ad,dos[q].ogr[x].bilgi.no);
        
		printf("\n");
        
		printf("*devam etmek icin (s)*\n");
        
		scanf("%c",&cg);
        
		if(cg=='s')
        {
            printf("Kayit Silindi");
            dos[q].ogr[x].kontrol[0]=0;
            dos[q].__mevcut-=1;
        }
        
        else
        {
            printf("Yanlis Giris Ana Menuye Yonlendiriliyorsunuz\n"); 
            anamenu();
        }
  }

  int devamsizlik()
  {
        int sayac=0,n=1;
        char konum;
        printf("Ogrenci Isimlerinin Karsisini (+)::(-) Olarak Isaretleyin\n");
        while(sayac<dos[q].__mevcut)
        {
            printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
            
			printf("DEVAMSIZLIK=%d\n",dos[q].ogr[sayac].devamsizlik);
                                      do
                                      {
                                                 konum=getch(); 
                                                 
                                                 if(konum=='+')
                                                 {
                                                               break;
                                                 }
                                                 
                                                 if(konum=='-')
                                                 {
                                                               dos[q].ogr[sayac].devamsizlik+=1;
                                                               break;
                                                 }
                                                 
												 if(konum!='+'||konum!='-')
                                                 {
                                                               printf("HATA!!!!!");
                                                 }
                                      }
                                      
									  while(konum=='+'||konum=='-');
                                      if(konum=='-')
                                      {
                                                    printf("+1=");
                                      }
                                      
									  printf("DEVAMSIZLIK=%d\n",dos[q].ogr[sayac].devamsizlik);
                                      
									  sayac++;
          }
  }           
  
  int arama()
  {
       char l;
       printf("Aranacak Ogrenci \n\tIsmine Gore[1]\n\n\tNo ya Gore [2]\n");
       scanf("%s",&l);
      
	   switch(l)
       {
            case'1':ara_isim();break;
            case'2':ara_no();break;
            default:printf("HATA!!!Lutfen 1 veya 2 ye Basin");
       }
       anamenu();
  }
                    
  int ara_isim()
  {
        char ara_name[20];
        int index=0;
        int i;
        
		printf("ISMI GIRIN...\n");
        
		scanf("%s",&ara_name);
        
		while(index<dos[q].__mevcut)
        {
                   if(strcmp(ara_name,dos[q].ogr[index].bilgi.ad)==0)
                   {
                             printf("KAYÝT BULUNDU\n");
                           
						     printf("%s %s %s ",dos[q].ogr[index].bilgi.ad,dos[q].ogr[index].bilgi.s_ad,dos[q].ogr[index].bilgi.no);
                           
						     for(i=0;i<dos[q].ogr[index].kontrol[1];i++)
                             {
                                     printf("--(%.3d)-",dos[q].ogr[index].not1[i]);
                             }
                           
						     if(dos[q].ogr[index].kontrol[1]==0)
                             printf("Sinav Sonucu Bulunmamaktadir \n");
        
		                     printf("DEVAMSIZLIK=%d Ders Saati\n",dos[q].ogr[index].devamsizlik);
        
		           }
				   
				   if(strcmp(ara_name,dos[q].ogr[index].bilgi.ad)==1)
                   printf("Bu Kiþi Sisteme Kayitli Degildir.");
                   
				   index++;
        }
  
  }
                     
  int ara_no()
  {
           char arayici_no[15];
           int i;
           int index=0;printf("Ogrenci Nosunu Girin\n");
           
		   scanf("%s",&arayici_no);
           
		   while(index<dos[q].__mevcut)
           {
                        if(strcmp(arayici_no,dos[q].ogr[index].bilgi.no)==0)
                        {
                                        printf("KAYIT BULUNMUSTUR\n");
                                        
										printf("%s %s %s ",dos[q].ogr[index].bilgi.ad,dos[q].ogr[index].bilgi.s_ad,dos[q].ogr[index].bilgi.no);
                                        for(i=0;i<dos[q].ogr[index].kontrol[1];i++)
                                        {
                                                printf("--(%.3d)-",dos[q].ogr[index].not1[i]);
                                        }
           
		                                if(dos[q].ogr[index].kontrol[1]==0)
                                        printf("--sinav sonucu yok ");
           
		                                puts("\n");
           
		                                printf("DEVAMSIZLIK=%d Ders Saati\n",dos[q].ogr[index].devamsizlik);
                        }
           
		                 if(strcmp(arayici_no,dos[q].ogr[index].bilgi.no)==1)
                        {
                                        printf("Bu Kiþi Sisteme Kayitli Degildir.");
                        }
           
		                index++;
  
           }
  
  }
                           
  int detay()
  {
          int not1=0;
          int sayac=0;
          int i;
          int sinir;
          
		  printf("SECILEN DERS ICIN MAKSIMUM DEVAMSIZLIK BILGISINI GIRIN:\n");
          
		  scanf("%d",&sinir);
          
		  while(sayac<50) 
          {
                          if(dos[q].ogr[sayac].kontrol[0]!=1)
                          {
                                                             sayac++;
                                                             continue;
                          }
                          printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
                          for(i=0;i<dos[q].ogr[sayac].kontrol[1];i++)
                          {
                               not1+=dos[q].ogr[sayac].not1[i]*dos[q].ogr[sayac].kontrol[i+4]/100;
                          }
                          if(not1>=90)
                          {
                               printf("Notunuz %.3d___A1_GECTI",not1);
                          }
                          else if(90>not1>=85)
                          {
                               printf("Notunuz %.3d___A2_GECTI",not1);
                          }
                          else if(85>not1>=80)
                          {
                               printf("Notunuz %.3d___B1_GECTI",not1);
                          }
                          else if(80>not1>=75)
                          {
                               printf("Notunuz %.3d___B2_GECTI",not1);
                          }
                          else if(75>not1>=70)
                          {
                               printf("Notunuz %.3d___CC_GECTI",not1);
                          }
                          else if(70>not1>=50)
                          {
                               printf("Notunuz %.3d___CD_KALDI",not1);
                          }
                          else if(50>not1>=30)
                          {
                               printf("Notunuz %.3d___DD_KALDI",not1);
                          }
                          else
                          printf("Notunuz %.3d___FF_ KALDI",not1);
                          if(dos[q].ogr[sayac].devamsizlik>sinir)
                          printf("DZ__ DEVAMSIZLIKTAN KALDI");
                          printf("\n");
                          printf("\t----------------------------------------\n");
                          sayac++;
                          not1=0;
          }
  }

  int duzelt()
  {
          char konum;
          int j;
          int sayac=0,i,n=1;
          printf("\tDegisiklik Yapilacak Kaydi Secin\n\n");
          printf("\tIlerlemek Icin [+] Geri Gitmek icin[-]ye Basin\n\n");
          printf("\tSecmek Icin[enter]\n");
          while(n)
          {
                  printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
                  for( i=0;i<dos[q].ogr[sayac].kontrol[1];i++)
                  printf("--(%.3d)",dos[q].ogr[sayac].not1[i]);
                  if(dos[q].ogr[sayac].kontrol[1]==0)
                  printf("*Sinav Sonucu Yok*\n ");
                  printf("\t\\\\\\\\\\\\\\\\//////////////\n");
                  do
                  { 
                           konum=getch(); 
                           if(konum=='+')
                           {
                                         if(sayac==dos[q].__mevcut-1)
                                         sayac=-1;
                                         sayac++;
                                         break;
                           }
                           if(konum=='-')
                           {
                                         if(sayac==0)
                                         sayac=dos[q].__mevcut;
                                         sayac--;
                                         break;
                           }
                           if(konum!='\n')
                           {
                                          printf("Secildi\n");
                                          n=0;
                                          break; 
                           }
                  }
                  while(1);
          }
          printf("\t*Ad Degisikligi Icin*[1]\n");
          printf("\t*Soyad Degisikligi Icin*[2]\n");
          printf("\t*No Degisikligi Icin*[3]\n");
          printf("\t*Not Degisikligi Icin*[4]\n");
          printf("\t*Devamsizlik Degisikligi Icin*[5]\n");
          konum=getch();
          switch(konum)
          {
                       case '1' :
                       {
                            printf("%s Degerini Degistir\n",dos[q].ogr[sayac].bilgi.ad);
                            gets(dos[q].ogr[sayac].bilgi.ad);
                            break;
                       }
                       case'2':
                       {
                            printf("%s Degerini Degistir",dos[q].ogr[sayac].bilgi.s_ad);
                            gets(dos[q].ogr[sayac].bilgi.s_ad);
                            break;
                       }
                       case'3':
                       {
                            printf("%d Degerini Degistir\n",dos[q].ogr[sayac].bilgi.no);
                            gets(dos[q].ogr[sayac].bilgi.no);
                            break;
                       }
                       case'4':
                       {
                            printf("Bu Ogrenci Icin %d Sinav Notu Bulunmaktadir\n",dos[q].ogr[sayac].kontrol[1]);
                            if(dos[q].ogr[sayac].kontrol[1]==0)
                            printf("Degistirilecek Birsey Bulunamadi!!!\n");
                            
							else
                            {
                                                   for(j=0;j<dos[q].ogr[sayac+2].kontrol[1];j++)
                                                   printf("not%d ",j+1);
                                                   for( i=0;i<dos[q].ogr[sayac].kontrol[1];i++)
                                                   printf("--(%.3d)",dos[q].ogr[sayac].not1[i]);
                                                   printf("Sinav Nosunu Girin:");
                                                   scanf("%d",&i);
                                                   printf("%3d Degerini Degistirin:");
                                                   scanf("%d",&dos[q].ogr[sayac].not1[i]);
                                                   break;
                            }
                       }
                       case'5':
                       {
                            printf("Ogrencinin Devamsizligi_(%d)_ ders");
                            printf("Yeni Deger=");
                            scanf("%d",&dos[q].ogr[sayac].devamsizlik);
                       }
                       default:
                       printf("HATA!!!\n");
          }
  }
  int s_listesi()
  {
  	      int i;
          for(i=0;i<10;i++)
          {
                  if(dos[i].__mevcut==0)
                  {
                                        break;
                  }
                  int mevcut=0;
                  for(mevcut=0;mevcut<=3;mevcut++)
                  {
                                                  printf("AD: ");
                                                  gets(dos[i].ogr[mevcut].bilgi.ad);
                                                  if(dos[i].ogr[mevcut].bilgi.ad[0]==BOS)
                                                  break;
                                                  puts("SOYAD: ");
                                                  gets(dos[i].ogr[mevcut].bilgi.s_ad);
                                                  puts("NO: ");
                                                  gets(dos[i].ogr[mevcut].bilgi.no);
                                                  dos[i].ogr[mevcut].kontrol[0]=1;
                                                  dos[i].ogr[mevcut].kontrol[1]=0;
                                                  mevcut++;
                                                  dos[i].__mevcut=mevcut;
                                                  esas();
                  }
          }
  }
  
  int esas()
  {
         struct ogrenci is;
        
		 int sayac=0;
        
		 int i,k;
        
		 for (i = 0; i < dos[q].__mevcut-1 ; i++)
        
		 for (k = 0; k < dos[q].__mevcut-1 ; k++)
        
		 if (f_no(dos[q].ogr[k].bilgi.no) > f_no(dos[q].ogr[k+1].bilgi.no))
         {
                     is = dos[q].ogr[k];
                     dos[q].ogr[k] = dos[q].ogr[k+1];
                     dos[q].ogr[k+1] =is;
         }
        
		 for(i=0;i<dos[q].__mevcut+1;i++)
         {
                     if(dos[q].ogr[i].kontrol[0]!=1)
                     {
                               for(k=i;k<dos[q].__mevcut+1;k++)
                               {
                                       dos[q].ogr[k]=dos[q].ogr[k+1];
                               }
                     }
         }
        
		 if((f=fopen("ders1.txt","r+"))==BOS)
         {
                     printf("HATA!!!\n");
                     exit(1);
         }
        
		 for(i=0;i<10;i++)
         {
                     if(fwrite(&dos[i], sizeof(sayac), 1, f)<1)
                     printf("HATA!!!\n");
         }
        
		 fclose(f);
        
		 printf("**Guncelleme Gerceklesti**..");
  }
  
  long double f_no(char array[])
  {
         long double g_no=0,carpan;
         int t,k;
         int n=strlen(array);
         if(!isdigit(array[1]))
         n=3;
         int m;
         for(t=0;t<n;t++)
         {
                 carpan=1;
                 for(k=1;k<n-t;k++)
                 {
                         carpan*=10;
                 }
                 m=array[t]-48;
                 g_no+=m*carpan;
         }
         return g_no;
  }                  
  
  int anamenu()
  {
          printf("****************************\n");
          esas(); 
          printf("Sinif Adi=%s\n",sinif);
          printf("MEVCUT= %d\n",dos[q].__mevcut);
          char ch;
          printf("*******OGRENCI BILGI SISTEMINE HOS GELDINIZ!********\n");
          printf("\t\t **YENI NOT GIRISI **(1)\n\n");
          printf("\t\t **SIRALAMA**(2)\n\n");
          printf("\t\t **OGRENCI EKLE**(3)\n\n");
          printf("\t\t **OGRENCÝ SIL**(4)\n\n");
          printf("\t\t **YOKLAMA**(5)\n\n");
          printf("\t\t **OGRENCI ARAMA**(6)\n\n");
          printf("\t\t **GENEL SONUCLAR**(7)\n\n");
          printf("\t\t **BILGI DUZELTME**(8)\n\n");
          ch=getch();
          printf("\n\n\n");
          return ch;
  }                             
  
  int parola()
  {
          char str[] = "1";
          char s[20];
          int i=0;
          printf("Parolayi Giriniz :\n ");
          printf("Parolayi dikkatli giriniz.Aksi taktirde sistem kilitlenecektir=");
          gets(s);
          if (!strcmp(str, s))
  
          {
                           printf("Onaylandi...\n");
                           return 1;
          }
          else
          {
                           printf("HATA!!!.Lutfen programi tekrar baslatip sifreyi girmeyi tekrar deneyin\n");
                           for(;;);
                           return 0;
          }
  }
                 
  int notgiris()
  {
        int sayi=0,yuzde,kalan=0,pay_t=0;
      
	    int a;
      
	    for(a=4;a<9;a++)
           {
                pay_t+=dos[q].ogr[0].kontrol[a];
           }
      
	       printf("KALAN YUZDE=%d\n",100-pay_t);
      
	       do
           {
                printf("GIRILECEK SINAVIN ETKIYECEGI YUZDEYI GIRIN=");
                scanf("%d",&yuzde);
           }
           while(yuzde>100-pay_t);
      
	       printf("GIRILECEK SINAV ICIN YUZDE %d ETKIYECEK\n",yuzde);
      
	       printf("LUTFEN 0-100 ARASI NOT GIRIN\n");
      
	       int sinav_no= dos[q].ogr[0].kontrol[1];
      
	       while(sayi<dos[q].__mevcut)
           {                                     
                    printf("%s\t%s SINAV NOTU",dos[q].ogr[sayi].bilgi.ad,dos[q].ogr[sayi].bilgi.s_ad);
                    
					do
                    {              scanf("%d",&dos[q].ogr[sayi].not1[sinav_no]);
                                   
								    if(dos[q].ogr[sayi].not1[sinav_no]<0||dos[q].ogr[sayi].not1[sinav_no]>100)             
                                   
								    printf("_**LUTFEN 0-100 ARASINDA NOT GIRIN**_ \n");
                    }while(dos[q].ogr[sayi].not1[sinav_no]<0||dos[q].ogr[sayi].not1[sinav_no]>100);
      
	                 dos[q].ogr[sayi].kontrol[1]++;
      
	                 dos[q].ogr[sayi].kontrol[sinav_no+4]=yuzde;
      
	                 sayi++;
                     
					 continue;
           }
  }
