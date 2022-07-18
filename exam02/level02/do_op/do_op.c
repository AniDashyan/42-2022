#include "do_op.h"

int main(int argc, char **argv)
{
	int first;
	int second;
	int third;

	if (argc == 4)
	{
		first = atoi(argv[1]);
		second = argv[2][0];
		third = atoi(argv[3]);

		if (second == '+')
			printf("%d", first + third);
		else if (second == '-')
			printf("%d", first - third);
		else if (second == '*')
			printf("%d", first * third);
		else if (second == '/')
			printf("%d", first / third);
		else if (second == '%')
			printf("%d", first % third);
	}
	write(1, "\n", 1);
	return (0);
}
