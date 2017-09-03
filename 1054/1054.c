#include <stdio.h>


int check(int n)
{
	int i;

	for (i = 2; i * i <= n; i += 1)
		{
			if (n % i == 0)
				return 0;
			
			continue;
		}

	return 1;
}


int main(int argc, char *argv[])
{
	int n;

	scanf("%d", &n);

	for (n = n + 1; n <= 99999999; n++)
		{
			if (check(n))
				{
					printf("%d\n", n);
					break;
				}
		}
	
	return 0;
}
