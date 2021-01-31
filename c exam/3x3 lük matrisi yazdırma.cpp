# include <stdio.h>
# include <conio.h>
main ()
{
int a,b,c;
int mat[3][3][3] ={ 1,2,3,
4,5,6,
7,8,9,
1,4,7,
2,5,8,
3,6,9,
1,4,4,
2,4,7,
8,8,5 };

for (a=0;a<3;a++)
{
printf("\n");

for (b=0;b<3;b++)
{
    for (c=0;c<3;c++)
        printf ("%3d [%u] ",mat[a][b][c],&mat[a][b][c]);
        
		printf("\n");
//kodda haaaaaaaaaaaaaaaaaaaaaataaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
}
}
}
