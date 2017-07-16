#include <stdio.h>


int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;

	else
		return fib(n - 1) + fib(n - 2);

	return -1;
}


int sum(int n)
{
	int sum = 0, tmp, i;

	for(i = 1; i <= n; ++i)
		{
			tmp = fib(i);
			sum += tmp;
		}

	return sum;
}


int main(int argc, char *argv[])
{
	int in;
	scanf("%d", &in);

	while (in != 0)
		{
			printf("%d\n", sum(in));
			scanf("%d", &in);
		}
	
	return 0;
}
