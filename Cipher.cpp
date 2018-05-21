#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(int k, char s[0], int p)
{
	int i;
	while(k > 26)
	k = k - 26;
	for(i = 0; i <= p; i ++)
	{
		if((s[i] >= 'A') && (s[i] <= 'Z'))
		{
			if (s[i] + k > 'Z')
			s[i] = s[i] -26;
		}
		else if ((s[i] >= 'a') && (s[i] <= 'z'))
		{
			if(s[i] + k > 'z')
			s[i]= s[i] - 26;
		}
		else
		s[i] = s[i] - k;
		s[i] = s[i] + k;
	}
	printf("ciphertext# %s",s);
}

main()
{
	int i,n,k,p=100;
	char c[p];
	printf("Enter key and no. of messages\n");
	scanf("%d	%d",&k,&n);
	printf("Enter the message\n");
	scanf("%s", &c);
	p = strlen(c);
	encrypt(k, &c[0],p);
}
