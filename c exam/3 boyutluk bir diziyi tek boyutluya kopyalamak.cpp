#include <stdio.h>
#include <conio.h>
//Aþaðýda 3 boyutlu diziye  her elemanýna bulunduðu indis deðerlerinin toplamý atanmýþtýr

int main(int argc, char *argv[]) 
{
int dizi1[5][2][9] ;
int dizi2[90], i,j,k;
int s1=5, s2=2, s3=9;

for (i=0; i<s1; i++)
 for (j=0; j<s2; j++)
  for (k=0; k<s3; k++)
     dizi1[i][j][k]=i+j+k;


//3 boyutlu bir tamsayý dizisinin elemanlarýný tek boyutlu bir diziye kopyalamak????

for (i=0; i<s1; i++)
 for (j=0; j<s2; j++)
  for (k=0; k<s3; k++)
	    dizi2[(s2 * s3 * i) + (s3*j)+k]=dizi1[i][j][k];
	    
	for (i=0; i<s1*s2*s3; i++)
	    printf("\n  %d", dizi2[i]);
	    }

