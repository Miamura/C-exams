     /*DEVAMSIZLIK ÝÞLEMLER*/
  **** devamsizlik()
  {
          int sayac=0,n=1;
          char konum;
          printf("Ogrenci Isimlerinin Karsisini (+)::(-) Olarak Isaretleyin\n");
          while(sayac<dos[q].__mevcut)/*Mevcut sayýsý kadar döner*/
          {
                                      printf("%s %s %s ",dos[q].ogr[sayac].bilgi.ad,dos[q].ogr[sayac].bilgi.s_ad,dos[q].ogr[sayac].bilgi.no);
                                      printf("DEVAMSIZLIK=%d\n",dos[q].ogr[sayac].devamsizlik);/*Öðrencinin devamsýzlýk sayýsý*/
                                      do
                                      {
                                                 konum=getch(); 
                                                 if(konum=='+')/*Diðer öðrenciye geçer*/
                                                 {
                                                               break;
                                                 }
                                                 if(konum=='-')/*Öðrencinin devamsýzlýðýna 1 ekler*/
                                                 {
                                                               dos[q].ogr[sayac].devamsizlik+=1;
                                                               break;
                                                 }
                                                 if(konum!='+'||konum!='-')/*Yanlýþ seçenek durumu*/
                                                 {
                                                               printf("HATA!!!!!");
                                                 }
                                      }
                                      while(konum=='+'||konum=='-');
                                      if(konum=='-')
                                      {
                                                    printf("+1=");/*1 eklendiði belirtilir*/
                                      }
                                      printf("DEVAMSIZLIK=%d\n",dos[q].ogr[sayac].devamsizlik);
                                      sayac++;
