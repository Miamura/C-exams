#include <stdio.h>
int main(int argc, char *argv[]) {
	 
	 int dizi[2][3] = { 13, 6, 10, 7, 12, 15};
	 int i, j;
	
	int min = dizi[0][0]; 
	
	for (i=0; i<2; i++)
 	       for (j=0; j<3; j++) 
 		if (min > dizi[i][j]) 
	
		      min = dizi[i][j ]; 
  	printf("\n dizi minimumu : %d", min);
  	
}

