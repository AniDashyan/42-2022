// #include <stdio.h>

unsigned int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

unsigned int hcf(unsigned int a, unsigned int b)
{
	int i = 1;
	int max = 1;
	while (i <= a && i <= b)
	{
		if (a % i == 0 && b % i == 0)
			max = i;
		i++;
	}
	return (max);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	if (!a || !b)
		return (0);
	unsigned int HCF = hcf(a, b);
	unsigned int ABS = ft_abs(a * b);
	unsigned int LCM = ABS / HCF;
	return (LCM);
}

/*
int main()
{
	unsigned int a = 20;
	unsigned int b = 40;
	printf("%u\n", lcm(a, b));
	return (0);
}
*/
