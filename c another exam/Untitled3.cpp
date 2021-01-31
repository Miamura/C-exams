#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

FILE *dosya;
char ad[15];
char soyad[15];
char no[15];
char sec;

void giris(void)
{ dosya=fopen ("D:\\iscikayit.txt","a");
  if (dosya==NULL)
    dosya=fopen ("D:\\iscikayit.txt","w");

  printf("ad .....");   scanf("%s",ad);
  printf("soyad...");   scanf("%s",soyad);
  printf("numara..");   scanf("%s",no);
  fprintf(dosya,"%s\n",ad);
  fprintf(dosya,"%s\n",soyad);
  fprintf(dosya,"%s\n",no);
  fclose(dosya);
}

void oku(void)
{ dosya=fopen("D:\\iscikayit.txt","r");
  if (dosya==NULL)
  { printf("dosya yok..");
    getch();
    exit(1);
  }
  
  while (feof(dosya)==0)
  { fscanf(dosya,"%s\n", ad);
    fscanf(dosya,"%s\n",soyad);
    fscanf(dosya,"%s\n",no);
    printf("%s %s %s\n",ad,soyad,no);
  }
  fclose(dosya);
  getch();
}

int main()
{ do
  { 
    printf("1- kayit girisi \n");
    printf("2- kayit listeleme \n");
    printf("3- cikis  \n");
    printf("seciminiz (1,2,3) ");
    sec=getch();
    if (sec=='1')
      giris();
    if (sec=='2')
      oku();
  }while (sec!='3');
}
