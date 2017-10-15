#include <stdio.h>
#include <stdlib.h>


int max(int a, int b, int m, int *res)
{
	res[0] = m / b;
	res[1] = m / a;

	return 0;
}


int display(int *res, int m, int a, int b)
{
	int i, j;

	for (i = 1; i <= res[0]; i++)
		{
			for (j = i; j <= res[1]; j++ )
				
				if (i * a + j * b <= m)
					printf("%d,%d\n", i, j);
		}

	return 0;
}


int main(int argc, char *argv[])
{
	int a, b, m;
	int *res = (int*)malloc(2 * sizeof(int));

	scanf("%d, %d, %d", &a, &b, &m);

	max(a, b, m, res);
	display(res, m, a, b);
		
	return 0;
}
