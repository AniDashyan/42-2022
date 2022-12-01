//#include <stdio.h>

int is_power_of_2(unsigned int n)
{
	if (n == 1)
		return (1);
	else if (n == 0 || n % 2 == 1)
		return (0);
	return (is_power_of_2(n / 2));
}

// int main()
// {
// 	int a = 14;
// 	int b = 8;
// 	printf("%d\n", is_power_of_2(a));
// 	printf("%d\n", is_power_of_2(b));
// 	return (0);
// }
