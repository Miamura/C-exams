

struct isci {

char isim[15];

char soyadi[15];

 char tc[11];

 char tel[10];

int gelmedigigunsayisi;

} kisi[200],kisiokuma[200],kisisil[200];

int listele();

int main()
{
	int sayi
	printf("bir sayi giriniz : ");
	scanf("%d",&sayi)
	if(sayi==1)
	kayitekle();
    else
	listele();
	
	getch();
}

int kayit_ekle()
{
    
        char kayit_eklesayialgilama;
        
        FILE *dosya;
        
        dosya=fopen("ödev.txt","a");
 
    do{
    	
	printf(" %d.kisi adi giriniz\n",mevcut+1);
    
    scanf("%s",kisi[sayac].isim);
    
    fflush(stdin);
    
    printf("%d.kisinin soyadi giriniz\n",mevcut+1);
    
    scanf("%s",kisi[sayac].soyadi);
    
    fflush(stdin);
    
    printf("%d.kisi tc sini giriniz\n",mevcut+1);
    
    scanf("%s",&kisi[sayac].tc);
    
    fflush(stdin);
    
    printf("%d.kisi telefon numarasini giriniz\n",mevcut+1);
    
    scanf("%s",&kisi[sayac].tel);
    
    fflush(stdin);
    
    mevcut++;
    
    printf("yeni kayit icin e'ye basin ve menuye donmek icin herhangi bir tusa basin");
    
	kayit_eklesayialgilama=getch();
 
    fprintf(dosya,"%s\t%s\t%s\t%s\t\n",kisi[sayac].isim,kisi[sayac].soyadi,kisi[sayac].tc,kisi[sayac].tel);
    
    sayac++;
    
    }while(kayit_eklesayialgilama=='e' || kayit_eklesayialgilama=='E');
    
    fclose(dosya);

}

int listele()
{
	
   FILE *dosya;
   
   dosya=fopen("ödev.txt","r");
   
   int sayac2=0,i;
   
   while(!feof(dosya)){
   
        fscanf(dosya,"%s%s%s%s",kisiokuma[sayac2].isim,kisiokuma[sayac2].soyadi,&kisiokuma[sayac2].tc,&kisiokuma[sayac2].tel);
    
        sayac2++;
    }
   
    for(i=0;i<(sayac2-1);i++)
       printf("\t%s\t%s\t%s\t%s\n",kisiokuma[i].isim,kisiokuma[i].soyadi,kisiokuma[i].tc,kisiokuma[i].tel);
       
    fclose(dosya);
    
}
