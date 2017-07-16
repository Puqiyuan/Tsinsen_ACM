#include <stdio.h>
#include <stdlib.h>

int display(int *data, int num);


int store_data(int *data, int num)
{
	int i;

	for (i = 0; i <= num - 1; i++)
		scanf("%d", &data[i]);

	return 1;
}


int store_cou_data(int **cou_data, int n_cou)
{
	int i;

	for (i = 0; i <= n_cou - 1; ++i)
		scanf("%d %d", &cou_data[i][0], &cou_data[i][1]);

	return 1;
}


int swap(int *data, int **cou_data, int n_cou)
{
	int tmp, i;

	for (i = 0; i <= n_cou - 1; ++i)
		{
			tmp = data[cou_data[i][0] - 1];
			data[cou_data[i][0] - 1] = data[cou_data[i][1] - 1];
			data[cou_data[i][1] - 1] = tmp;
		}

	return 1;
}


int display(int *data, int num)
{
	int i;

	for (i = 0; i <= num - 1; ++i)
		printf("%d\n", data[i]);

	return 1;
}


int main(int argc, char *argv[])
{
	int t, num, n_cou, i;

	scanf("%d", &t);

	while (t >= 1)
		{
			scanf("%d %d", &num, &n_cou);
			
			int *data = (int*)malloc(num * sizeof(int));
			int **cou_data = (int**)malloc(n_cou * sizeof(int*));
			for (i = 0; i <= n_cou - 1; ++i)
				cou_data[i] = (int*)malloc(2 * sizeof(int));

			store_data(data, num);
			
			store_cou_data(cou_data, n_cou);

			swap(data, cou_data, n_cou);

			display(data, num);
			
			free(data);
			free(cou_data);
			t--;
		}

	return 0;
}
