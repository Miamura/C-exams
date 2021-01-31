#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define BOS 0
  
  int anamenu();
  
  int ogrkyt();
  
  int devamsizlik();
  
  int detay();
  
  int esas();
  
  long double f_no(char array[]);
  
  int q=0;
  
  struct kimlik
  {
        char ad[80];
		
		char s_ad[80];
		
		char no [13];
  };
  
  struct ogrenci
        {
            struct kimlik bilgi;
            int devamsizlik;
            int kontrol[10];
        };
        
  struct as
         {
            struct ogrenci ogr[50];/*Ogrenci deki bilgiler ogr daki 50 adet ogrenci için kullanýlýr ve bu bilgiler as'a atanýr. */
            char sinif_adi[20];
			int __mevcut;
         }dos[10];
         
  FILE *f;
                           
  int main()
  {                          
       int n,durum=0;
              
       int i;
            
	   char islem;
      
	   while(1) 
       {
                islem=anamenu();
                
                switch (islem)
                {
                    case '1' : ogrkyt(); break;
                    case '2' : devamsizlik(); break;
                    case '3' : detay(); break;
                    default : printf("GECERSÝZ SECENEK!..\n");
                }
       }
  return 0;
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
            
		
            
			ek++;
  
         }
         
         dos[q].__mevcut=ek;
  }
            
  int devamsizlik()
  {
        int sayac=0,n=1;
        char konum;
        
        printf("Isci Isimlerinin Karsisini (+)veya(-) Olarak Isaretleyin\n");
        while(sayac<dos[q].__mevcut)
        {
            printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
            
			printf("Iscinin gelemdigi gunler = %d \n",dos[q].ogr[sayac].devamsizlik);
                                    do
                                    {
                                        konum=getch(); 
                                        if(konum=='+'){break;}      
                                        if(konum=='-')
                                        {dos[q].ogr[sayac].devamsizlik+=1;break;}
                                        if(konum!='+'||konum!='-'){printf("HATA!!!!!");
										continue;
                                       }}
                                       while(konum=='+'||konum=='-');
                                      if(konum=='-')
                                      {
                                                    printf("+1=");
                                      }
                                      printf("\nToplam gelmedigi gun sayisi=%d\n",dos[q].ogr[sayac].devamsizlik);
                                      sayac++;
          }
  }           
              
  int detay()
  {
		  int sayac=0;
          
          int i;
          
		  int sinir;
          
		  printf("Isci icin maksimum gelmeme gununu belirleyin : \n");
          
		  scanf("%d",&sinir);
          
		  while(sayac<50) 
          {
                          if(dos[q].ogr[sayac].kontrol[0]!=1)
                          {
                                                             sayac++;
                                                             
                                                             continue;
                          }
                          
                          printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
                          
                          
						  if(dos[q].ogr[sayac].devamsizlik>sinir)
                          
						  printf("");
                          
						  printf("\n");
                          
						  sayac++;
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
          
		  printf("MEVCUT= %d\n",dos[q].__mevcut);
          char ch;
          printf("*******Isci yoklama sistemine hoþgeldiniz********\n");
          printf("\t\t **isci EKLE**(1)\n\n");
          printf("\t\t **YOKLAMA**(2)\n\n");
          printf("\t\t **GENEL SONUCLAR**(3)\n\n");
          ch=getch();
          
          printf("\n\n\n");
          
          return ch;
  }
