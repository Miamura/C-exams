     /*DEVAMSIZLIK ��LEMLER*/
  **** devamsizlik()
  {
          int sayac=0,n=1;
          char konum;
          printf("Ogrenci Isimlerinin Karsisini (+)::(-) Olarak Isaretleyin\n");
          while(sayac<dos[q].__mevcut)/*Mevcut say�s� kadar d�ner*/
          {
                                      printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
                                      printf("DEVAMSIZLIK=%d\n",dos[q].ogr[sayac].devamsizlik);/*��rencinin devams�zl�k say�s�*/
                                      do
                                      {
                                                 konum=getch(); 
                                                 if(konum=='+')/*Di�er ��renciye ge�er*/
                                                 {
                                                               break;
                                                 }
                                                 if(konum=='-')/*��rencinin devams�zl���na 1 ekler*/
                                                 {
                                                               dos[q].ogr[sayac].devamsizlik+=1;
                                                               break;
                                                 }
                                                 if(konum!='+'||konum!='-')/*Yanl�� se�enek durumu*/
                                                 {
                                                               printf("HATA!!!!!");
                                                 }
                                      }
                                      while(konum=='+'||konum=='-');
                                      if(konum=='-')
                                      {
                                                    printf("+1=");/*1 eklendi�i belirtilir*/
                                      }
                                      printf("DEVAMSIZLIK=%d\n",dos[q].ogr[sayac].devamsizlik);
                                      sayac++;
