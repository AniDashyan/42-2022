#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int count = 0;
	int i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int ft_putnbr(int n)
{
	int count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else 
		count += ft_putchar(n + '0');
	return (count);
}

int ft_puthex(unsigned int n)
{
	int count = 0;
	if (n >= 16)
	{
		count += ft_puthex(n / 16);
		count += ft_puthex(n % 16);
	}
	else
		count += write(1, &"0123456789abcdef"[n % 16], 1);
	return (count);
}

int ft_printf(const char *s, ... )
{
	va_list ap;
	int i = 0;
	int count = 0;

	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] && s[i + 1] == 's')
				count += ft_putstr(va_arg(ap, char *));
			if (s[i + 1] && s[i + 1] == 'd')
				count += ft_putnbr(va_arg(ap, int));
			if (s[i + 1] && s[i + 1] == 'x')
				count += ft_puthex(va_arg(ap, unsigned int));
			i++;
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

// int ft_putchar(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// int ft_putstr(char *str)
// {
// 	int i;

// 	i = 0;
// 	if (!str)
// 		str =  "(null)";
// 	while (str[i])
// 	{
// 		ft_putchar(str[i]);
// 		i++;
// 	}
// 	return (i);
// }

// int ft_printxd(unsigned int nb, int base)
// {
// 	char *hex = "0123456789abcdef";
// 	char *dec = "0123456789";
// 	int n;
// 	int count;

// 	count = 0;
// 	if (nb / base != 0)
// 		count += ft_printxd(nb/base,base);
// 	n = nb % base;
// 	if (base == 16)
// 			count += write(1, &hex[n], 1);
// 	if (base == 10)
// 			count += write(1, &dec[n], 1);
// 	return (count);
// }
// int printd(int nb)
// {
// 	int count;

// 	count = 0;
// 	if (nb < 0)
// 	{
// 		nb *= -1;
// 		count += ft_putchar('-');
// 	}
// 	count += ft_printxd(nb, 10);
// 	return (count);
// }

// int ft_printf(const char *fmt, ...)
// {
// 	int i;
// 	int count;
// 	va_list ap;

// 	i = 0;
// 	count = 0;

// 	va_start(ap, fmt);
// 	while (fmt[i])
// 	{
// 		if (fmt[i] == '%')
// 		{
// 			i++;
// 			if (fmt[i] == 's')
// 				count += ft_putstr(va_arg(ap, char *));
// 			if (fmt[i] == 'd')
// 				count += printd(va_arg(ap, int));
// 			if (fmt[i] == 'x')
// 				count +=ft_printxd(va_arg(ap, unsigned int), 16);
// 		}
// 		else 
// 		  count += ft_putchar(fmt[i]);
//         i++;
//     }
//     va_end(ap);
//     return (count);
// }

// int main()
// {
// 	// ft_printf("Simple test\n");
// 	ft_printf("");
// 	ft_printf("--ft_printformat---");
// 	ft_printf("\n");
// 	ft_printf("%d\n", 0);
// 	ft_printf("%d\n", 42);
// 	ft_printf("%d\n", 1);
// 	ft_printf("%d\n", 5454);
// 	ft_printf("%d\n", (int)2147483647);
// 	ft_printf("%d\n", (int)2147483648);
// 	ft_printf("%d\n", (int)-2147483648);
// 	ft_printf("%d\n", (int)-2147483649);
// 	ft_printf("\n");
// 	ft_printf("%x\n", 0);
// 	ft_printf("%x\n", 42);
// 	ft_printf("%x\n", 1);
// 	ft_printf("%x\n", 5454);
// 	ft_printf("%x\n", (int)2147483647);
// 	ft_printf("%x\n", (int)2147483648);
// 	ft_printf("%x\n", (int)-2147483648);
// 	ft_printf("%x\n", (int)-2147483649);
// 	ft_printf("%x\n", (int)0xFFFFFFFF);
// 	ft_printf("\n");
// 	ft_printf("%s\n", "");
// 	ft_printf("%s\n", "toto");
// 	ft_printf("%s\n", "wiurwuyrhwrywuier");
// 	ft_printf("%s\n", NULL);
// 	ft_printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	ft_printf("\n--Mixed---\n");
// 	ft_printf("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
// 	ft_printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
// 	ft_printf("\n");
// 	ft_printf("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	ft_printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
// 	return (0);
// }