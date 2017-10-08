#include <stdio.h>
#include <stdlib.h>

int sum(int **map, int n)
{
	int i, j, total;

	for (i = 0; i <= n - 1; i++)
		{
			total = 0;
			for (j = 0; j <= n - 1; j++)
				total += map[j][i];
			
			if (total > n / 2)
				printf("%d ", i + 1);
		}

	printf("\n");

	return 0;
}


int main(int argc, char *argv[])
{
	int n, i, j;
	scanf("%d", &n);
	
	int **map = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i <= n - 1; i++)
		map[i] = (int*)malloc(sizeof(int) * n);

	for (i = 0; i <= n - 1; i++)
		{
			for (j = 0; j <= n - 1; j++)
				scanf("%d", &map[i][j]);
		}
	
	sum(map, n);

	return 0;
}
