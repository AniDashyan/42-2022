#include <unistd.h>

int isUpper(char c)
{
	return  (c >= 'A' && c <= 'Z');
}

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if ((argv[1][i] >= 'a' && argv[1][i] < 'n') || (argv[1][i] >= 'A' && argv[1][i] < 'N'))
				argv[1][i] += (25 - 2*((argv[1][i] - (isUpper(argv[1][i]) ? 'A' : 'a') + 1) - 1));
			else if ((argv[1][i] >= 'n' && argv[1][i] <= 'z') || (argv[1][i] >= 'N' && argv[1][i] <= 'Z'))
				argv[1][i] += (-25 + 2*(((isUpper(argv[1][i]) ? 'Z' : 'z') - argv[1][i] + 1) - 1));
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
