#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int store(int n, char **name)
{
	int i;
	for (i = 0; i <= n - 1; i++)
		scanf("%s", name[i]);
	
	return 0;
}


int partition(char **name, int p, int r);

int quick_sort(char **name, int p, int r)
{
        int q;

        if (p < r)
                {
                        q = partition(name, p, r);
                        quick_sort(name, p, q - 1);
                        quick_sort(name, q + 1, r);
                }

        return 0;
}


int partition(char **name, int p, int r)
{
        int len = strlen(name[r]), i = p - 1, j;
        char *tmp1 = (char*)malloc(1000 * sizeof(char));
        char *tmp2 = (char*)malloc(1000 * sizeof(char));
        char *x = (char*)malloc(1000 * sizeof(char));

	x = name[r];

        for (j = p; j <= r - 1; j++)
                {
                        if (strcmp(name[j], x) < 0)
                                {
                                        i++;
                                        tmp1 = name[i];
                                        name[i] = name[j];
                                        name[j] = tmp1;
                                }
                }

        tmp2 = name[i + 1];
        name[i + 1] = name[r];
        name[r] = tmp2;

        return i + 1;   
}


int show(char **name, int len)
{
        int i;

        for (i = 0; i <= len - 1; i++)
                printf("%s\n", name[i]);

        return 0;
}


int bin_search(char **name, int n, char *key)
{
        int left = 0, right = n - 1;

        while (left <= right)
                {
                        int middle = (left + right) / 2;

                        if (strcmp(key, name[middle]) == 0)
                                return middle;

			if (strcmp(key, name[middle]) > 0)
                                left = middle + 1;

                        else
                                right = middle - 1;
                }
        
        return -1;
}


int t_store(int n, char** name)
{
	int i;
	for (i = 0; i <= n - 1; i++)
		printf("%s\n", name[i]);
	
	return 0;
}


int main(int argc, char *argv[])
{
	int n, i;
	char key[1000];
	
	scanf("%d", &n);

	scanf("%s", key);

	char **name = (char**)malloc(n * sizeof(char*));
	for (i = 0; i <= n - 1; i++)
		name[i] = (char*)malloc(1000 * sizeof(char));
	
	store(n, name);

	quick_sort(name, 0, n - 1);


	int loc = bin_search(name, n, key);

	if (loc < n - 1)
		printf("%s", name[loc + 1]);
	else
		printf("The End");
	

	return 0;
}
