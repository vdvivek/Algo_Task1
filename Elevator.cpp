#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void sort(int n,int m, int a[0])
{
   int x, y, z, w;
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
   for ( x = 0 ; x < n ; x++ )
	{
		if(a[x] == m)
		{
			for(y = x; y < n; y++)
			{
				printf("%d ",a[y]);
			}
		}
	}
	for(x = n-1; x >= 0; x--)
	{
		if (a[x] < m)
		printf("%d ", a[x]);
	}
	n = (a[n-1] - m) + (a[n-1] - a[0]);
	printf("\n%d",n);
}
main()
{
	int i, n, d;
	int f[d];
	printf("Enter initial floor number\n");
	scanf("%d",&n);
	printf("Enter final floor numbers\nEnter 0 to confirm\n");
	for (i = 0; i < 100; i ++)
	{
		scanf("%d",&f[i]);
		if ( f[i] == 0)
		{
			f[i] = n;
			break;
		}
	
	}
	d= i +1;
	sort(d, n, &f[0]);
}
