#include <stdio.h>
#include <stdlib.h>


int store(char *s)
{
	scanf("%s", s);

	return 1;
}


int convert(int p, int k, char *s)
{
	int base[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
			100000000, 1000000000};
	
	int opn = 0, e = 0;

	while (k >= p)
		{
			opn += (int)(s[k] - 48) * base[e];
			k--;
			e++;
		}
	
	return opn;	
}


int compute(int *res, int opn2, char op)
{
	if (op == '+')
		*res += opn2;

	else
		*res -= opn2;

	return 1;
}


int main(int argc, char *argv[])
{
	char *s = (char*)malloc(sizeof(char) * 102);

	store(s);

	char op;
	int *res = (int*)malloc(sizeof(int)), i, p, k, opn1, opn2;

	if (s[0] == '-')
		{
			i = 1;
			p = 1;
		}
	
	else
		{
			i = 0;
			p = 0;
		}
		

	while (s[i] != '=' && s[i] != '+' && s[i] != '-')
		++i;

	k = --i;

	opn1 = convert(p, k, s);

	if (s[k + 1] == '=')
		{
			printf("%d\n", opn1);
			return 0;
		}
	
	if (s[0] == '-')
		*res = 0 - opn1;
	else
		*res = opn1;

	++i;
	op = s[i];
	++i;

	while (s[i] != '=')
		{
			p = i;
			while (s[i] != '=' && s[i] != '+' && s[i] != '-')
				++i;
			k = --i;

			opn2 = convert(p, k, s);

			compute(res, opn2, op);

			++i;
			if (s[i] != '=')
				{
					op = s[i];
					++i;
				}
		}

	printf("%d\n", *res);
	return 0;
}
