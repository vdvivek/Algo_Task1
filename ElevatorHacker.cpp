#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void schedule(int n, int enter[0], int exit[0],int total, int c, int b[0])
{
	int i,j=0;
	int enter2[n], exit2[n], d[n];
	for(i = 0; i < n; i++)
	{
		if((total + enter[i] - exit[i]) > c)
		{
			d[j] = b[i];
			enter2[j] = enter[i];
			exit2[j] = exit[i];
			j++;
			continue;
		}
	
		total = total + enter[i] - exit[i];
	
		if (total < 0)
		total =0;
		
		printf("Floor Number: %d   No. of lift occupants: %d\n",b[i],total);
	}
	if (j !=0 )
	{
		for(i = 0;i < j; i++)
		{
			total = total + enter2[i] - exit2[i];
			printf("Floor Number: %d   No. of lift occupants: %d\n",d[i],total);
		}
	}
}

void capacity (int b[0], int n)
{
	int c, i, j = 0,total = 0;
	int enter[n], exit[n];
	int enter2[n], exit2[n], d[n];
	printf("\nEnter the capacity\n");
	scanf("%d",&c);
	for(i = 0; i < n; i++)
	{
		printf("Enter the no. of ppl enetering and leaving floor %d\n",b[i]);
		scanf("%d	%d",&enter[i], &exit[i]);
	}
	schedule(n, &enter[0], &exit[0], total, c, &b[0]);
}

void sort(int n,int m, int a[0])
{
   int x, y, z, w;
   int b[n];
   for ( x = 0 ; x < ( n - 1 ) ; x++ )
   {
      z = x;
 
      for ( y = x + 1 ; y < n ; y++ )
      {
         if ( a[z] > a[y] )
            z = y;
      }
      if ( z != x )
      {
         w = a[x];
         a[x] = a[z];
         a[z] = w;
      }
	}
  	z = 0;
   for ( x = 0 ; x < n ; x++ )
	{
		if(a[x] == m)
		{
			for(y = x; y < n; y++)
			{
				printf("%d ",a[y]);										/*Initial floor and above*/
				b[z] = a[y];
				z++;
			}
		}
	}
	for(x = n-1; x >= 0; x--)
	{
		if (a[x] < m)
		{
		printf("%d ", a[x]);											/*Floors below initial floor*/
		b[z] = a[x];
		z++;
		}
	}
	m = (a[n-1] - m) + (a[n-1] - a[0]);									/*Distance*/
	printf("\n%d\n",m);
	for(x = 0; x < n; x++)
	{
		printf("%d ",b[x]);
	}
	capacity(&b[0],n);
}

main()
{
	int i, n, d;
	int f[d];
	printf("Enter initial floor number\n");
	scanf("%d",&n);
	printf("Enter final floor numbers\n");
	for (i = 0; i < 100; i ++)
	{
		scanf("%d",&f[i]);
		if ( f[i] == 0)													/* Ending the loop*/
		{
			f[i] = n;
			break;
		}
	
	}
	d= i +1;															/*Size of the array*/
	/*for(i = 0; i < d; i++)
	{
		printf("%d ",f[i]);
	}
	printf("\n");*/
	sort(d, n, &f[0]);
}
