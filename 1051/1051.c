#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int store(char **s, int n)
{
	int i;

	for (i = 0; i <= n - 1; i++)
		scanf("%s", s[i]);

	return 1;
}


int display(char **s, int n)
{
	int i;

	for (i = 0; i <= n - 1; i++)
		printf("%s\n", s[i]);

	return 1;
}


int counting(char **s, int n, int **info)
{
	int i, j, len = strlen(s[0]);

	for (i = 0; i <= len - 1; i++)
		{
			for (j = 0; j <= n - 1; j++)
				{
					if (s[j][i] == 'A')
						info[i][0]++;

					else if (s[j][i] == 'C')
						info[i][1]++;
					
					else if (s[j][i] == 'G')
						info[i][2]++;

					else if (s[j][i] == 'T')
						info[i][3]++;
				}
		}


	return 1;
}


int t_counting(int **info, int len)
{
	int i;

	for (i = 0; i <= len - 1; i++)
		printf("%d %d %d %d\n", info[i][0], info[i][1],
		       info[i][2], info[i][3]);


	return 1;
}


int output(int **info, int len)
{
	int max, i, j;

	for (j = 0; j <= len - 1; j++)
		{
			max = info[j][0];
			for (i = 0; i <= 3; i++)
				{
					if (max < info[j][i])
						max = info[j][i];
				}
			
			if (max == info[j][0])
				printf("%c", 'A');
			
			else if (max == info[j][1])
				printf("%c", 'C');

			else if (max == info[j][2])
				printf("%c", 'G');

			else if (max == info[j][3])
				printf("%c", 'T');
			
		}

	printf("\n");
	
	return 1;
}


int main(int argc, char *argv[])
{
	int n, i;

	scanf("%d", &n);

	char **s = (char**)malloc(n * sizeof(char*));
	for (i = 0; i <= n - 1; i++)
		s[i] = (char*)malloc(102 * sizeof(char));

	store(s, n);

	int len = strlen(s[0]);

	int **info = (int**)malloc(len * sizeof(int*));
	for (i = 0; i <= len - 1; i++)
		info[i] = (int*)malloc(4 * sizeof(int));

	counting(s, n, info);

	//t_counting(info, len);
	
	output(info, len);
	
	return 0;
}
