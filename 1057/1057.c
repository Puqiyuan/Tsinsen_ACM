#include <stdio.h>

int display(int N)
{
	if (N > 1)
		{
			display(N - 1);
			printf("%c", N + 64);
			display(N - 1);
		}
	
	if (N == 1)
		printf("%c", 65);

	return 0;
}


int main(int argc, char *argv[])
{
	int N;
	scanf("%d", &N);

	display(N);
	printf("\n");
	
	return 0;
}

