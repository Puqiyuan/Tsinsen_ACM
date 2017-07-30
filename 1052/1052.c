#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int create_map(char **map)
{
	map[0] = "ling"; map[1] = "yi"; map[2] = "er";
	map[3] = "san"; map[4] = "si"; map[5] = "wu";
	map[6] = "liu"; map[7] = "qi"; map[8] = "ba";
	map[9] = "jiu"; 
	
	return 0;
}


int seek(char *s)
{
	int k = strlen(s) - 1;

	for (; k >= 0; k--)
		{
			if (s[k] != '0')
				return k;
		}

	return -1;
}


int output1(char *s, char **map)
{
	int i = strlen(s) - 1;

	if (s[i] != '0' || s[i - 1] != '0' ||
	    s[i - 2] != '0' || s[i - 3] != '0')
		{
			if (s[i - 3] > '0' && s[i - 3] <= '9' && (i - 3 >= 0))
				printf("%s qian ",
				       map[(int)s[i - 3] - 48]);

			if (s[i - 2] > '0' && s[i - 2] <= '9' && (i - 2 >= 0))
				printf("%s bai ",
				       map[(int)s[i - 2] - 48]);

			if (s[i - 2] == '0' && s[i - 1] != '0')
				printf("ling ");

			if (s[i - 1] > '0' && s[i - 1] <= '9' && (i - 1 >= 0))
				printf("%s shi ",
				       map[(int)s[i - 1] - 48]);
			if (s[i - 1] == '0' && s[i] != '0')
				printf("ling ");

			if (s[i] > '0' && s[i - 1] <= '9')
				printf("%s ",
				       map[(int)s[i] - 48]);
		}

	printf("\n");
	
	return 1;
}


int output2(char *s, char **map)
{
	int i = strlen(s) - 5;

	if (((s[i] != '0' || s[i - 1] != '0' ||
	     s[i - 2] != '0' || s[i - 3] != '0' )) && i >= 0)
		{
			if (s[i - 3] > '0' && s[i - 3] <= '9' && (i - 3 >= 0))
				printf("%s qian ",
				       map[(int)s[i - 3] - 48]);

			if (s[i - 2] > '0' && s[i - 2] <= '9' && (i - 2 >= 0))
				printf("%s bai ",
				       map[(int)s[i - 2] - 48]);

			if (s[i - 2] == '0' && s[i - 1] != '0')
				printf("ling ");

			if (s[i - 1] > '0' && s[i - 1] <= '9' && (i - 1 >= 0))
				printf("%s shi ",
				       map[(int)s[i - 1] - 48]);
			
			if (s[i - 1] == '0' && s[i] != '0')
				printf("ling ");

			if (s[i] > '0' && s[i - 1] <= '9')
				printf("%s ",
				       map[(int)s[i] - 48]);

			printf("wan ");
		}

	return 1;
}


int output3(char *s, char **map)
{
	int i = strlen(s) - 9;


	if ((s[i] != '0' || s[i - 1] != '0') && i >= 0)
		{
			if (s[i - 1] > '0' && s[i - 1] <= '9' && (i - 1 >= 0))
				printf("%s shi ",
				       map[(int)s[i - 1] - 48]);

			if (s[i - 1] == '0' && s[i] != '0')
				printf("ling ");

			if (s[i] > '0' && s[i - 1] <= '9')
				printf("%s ",
				       map[(int)s[i] - 48]);

			printf("yi ");
		}

	return 1;
}


int main(int argc, char *argv[])
{
	char s[12];
	scanf("%s", s);
	int len = strlen(s);

	int i;

	char **map = (char**)malloc(10 * sizeof(char*));
	for (i = 0; i <= 9; i++)
		map[i] = (char*)malloc(6 * sizeof(char));

	create_map(map);

	int nz = seek(s);

	if (nz != 0 || (len != 6 && len != 10) || s[0] != '1')
		{
			output3(s, map);
			output2(s, map);
			output1(s, map);
		}
	
	else
		{
			if (len == 6)
				printf("shi wan\n");

			else if (len == 10)
				printf("shi yi\n");
		}
	
	return 0;
}
