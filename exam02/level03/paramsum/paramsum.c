#include <unistd.h>

void write_number(int n)
{
	if (n > 9)
		write_number(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int main(int argc, char **argv)
{
	argc--;
	if (argc > 0)
		write_number(argc);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
