#include <stdio.h>


int main(int argc, char *argv[])
{
	int n, i, count = 0;
	scanf("%d", &n);

	if (n >= 2)
		{
			for (i = 2; i <= n / 2; i++)
				{
					if (n % i == 0)
						count++;
				}
		}

	if (n == 1)
		printf("%d\n", 1);

	else
		printf("%d\n", count + 2);
	
	return 0;
}
