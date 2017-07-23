#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float computing(char *s, int len)
{
	int i;
	float count = 0;

	for (i = 0; i <= len - 1; i++)
		{
			if (s[i] == 'G' || s[i] == 'C')
				count++;
		}

	return count / len;
}


int main(int argc, char *argv[])
{
	char s[1001];

	scanf("%s", s);

	printf("%.f\n", computing(s, strlen(s)) * 100);
	
	return 0;
}

