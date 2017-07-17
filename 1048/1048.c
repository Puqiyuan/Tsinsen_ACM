#include <stdio.h>
#include <stdlib.h>


int get_map(int **map, int n)
{
	int loop = n, i = -1, j = 0, count, num = 1;

	while (loop >= 1)
		{
			count = loop;
			while (count >= 1)
				{
					i++;
					map[i][j] = num;
					num++;
					count--;
				}
			
			loop--;
			count = loop;
			while (count >= 1)
				{
					j++;
					map[i][j] = num;
					num++;
					count--;
				}

			loop--;
			count = loop;
			while (count >= 1)
				{
					i--; j--;
					map[i][j] = num;
					num++;
					count--;
				}

			loop--;
		}

	return 1;
}


int display(int **map, int n)
{
	int i, j;

	for (i = 0; i <= n - 1; i++)
		{
			for (j = 0; j <= i; j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}

	return 1;
}


int main(int argc, char *argv[])
{
	int i, n, **map;

	scanf("%d", &n);

	map = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i <= n - 1; i++)
		map[i] = (int*)malloc(sizeof(int) * n);

	get_map(map, n);

	display(map, n);
	
	return 0;
}
