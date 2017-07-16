#include <stdio.h>
#include <stdlib.h>


int store(int **price, int r, int c)
{
	int i, j;

	for (i = 0; i <= r - 1; i++)
		{
			for (j = 0; j <= c - 1; j++)
				scanf("%d", &price[i][j]);
		}

	return 1;
}


int adjust(int **price, int r, int c)
{
	int i, j;

	for (i = 0; i <= r - 1; ++i)
		{
			for (j = 0; j <= c - 1; ++j)
				{
					if (price[i][j] == 0)
						price[i][j] = 101;
				}
		}

	return 1;
}


int determine(int **price, int r, int c, int *res)
{
	int i, j, min, index;

	for (j = 0; j <= c - 1; j++)
		{
			index = 0, min = price[0][j];

			for (i = 0; i <= r - 1; i++)
				{
					if (price[i][j] <= min)
						{
							min = price[i][j];
							index = i;
						}
				}

			if (min == 101)
				res[j] = 0;
			else
				res[j] = index + 1;
		}

	return 1;
}


int display(int *res, int c)
{
	int i;

	for (i = 0; i <= c - 1; ++i)
		printf("%d ", res[i]);

	printf("\n");

	return 1;
}


int main(int argc, char *argv[])
{
	int r, c, i, **price, *res;

	scanf("%d %d", &r, &c);

	price = (int**)malloc(r * sizeof(int*));
	for (i = 0; i <= r - 1; i++)
		price[i] = (int*)malloc(c * sizeof(int));

	res = (int*)malloc(c * sizeof(int));

	store(price, r, c);

	adjust(price, r, c);

	determine(price, r, c, res);

	display(res, c);
	
	return 0;
}
