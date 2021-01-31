# include <stdio.h>
# include <conio.h>
main ()
{
int num[20]={0},j,k,n,p,t,s;
printf ("\n Enter number of elements: ");
scanf ("%d",&n);

printf ("\n Enter elements: ");
for (j=0;j<n;j++)
scanf ("%d",&num[j]);

printf ("\n Elements are: ");

for (j=0;j<n;j++)
printf ("\n num[j]: %d",num[j]);

printf ("\n Enter element and position to insert at: ");
scanf ("%d %d",&s,&p);
p--;

for (j=n;j!=p;j--)
num[j]=num[j-1];

num[j]=s;

for (j=0;j<=n;j++)
printf ("\n num[j] = %d",num[j]);

}

