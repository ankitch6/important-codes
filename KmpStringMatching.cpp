#include <bits/stdc++.h>
using namespace std;

char text[1000005];

int main() {

	int m,n;
	while(scanf("%d", &m)!= EOF)
	{
		char pattern[m];
		scanf("%s", pattern);
		scanf("%s", text);
		int lps[m];
		lps[0] = 0;
		n = strlen(text);
		int i=1,j=0;
		while(i<m)
		{
			if(pattern[i] == pattern[j])
			{
				lps[i++] = j+1;
				j++;
			}
			else
			{
				if(j==0)
				{
					lps[i++] = 0;
				}
				else
				{
					j = lps[j-1];
				}
			}
		}
		//now we have the LPS array

		i=0;j=0;
		while(i<n)
		{
			if(text[i] == pattern[j])
			{
				if(j==m-1)
				{
					printf("%d\n", i+1-m);
					j = lps[j-1];
				}
				else
				{
					j++;
					i++;
				}
			}
			else
			{
				if(j==0)
				{
					i++;
				}
				else
				{
					j = lps[j-1];
				}
			}
		}
	printf("\n");
	}
	return 0;
}
