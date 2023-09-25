#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int iter(char *s1, char c, int i)
{
	int n = 0;

	while (s1[n] && (n < i || i == -1))
		if (s1[n++] == c)
			return (1);
	return (0);		
	
}


int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!iter(argv[1], argv[1][i], i) && iter(argv[2], argv[1][i], -1))
				write(1,&argv[1][i], 1);
			i++;
		}
	}
	
	// ft_split("ddf6vewg64fz", "gtwthgdwthdwfteewhrtag6h4ffdhsd");
    return 0;
}