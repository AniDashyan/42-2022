/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:10 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/13 18:01:31 by adashyan         ###   ########.fr       */
=======
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:10 by adashyan          #+#    #+#             */
/*   Updated: 2022/05/28 18:13:01 by adashyan         ###   ########.fr       */
>>>>>>> 34a63c3f525fa4a5a01f8f36534fb641cfb78f24
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int	ft_formats(va_list ap, const char *s, int *i)
{
	int	count;

	count = 0;
	if (s[*i + 1] && s[*i + 1] == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (s[*i + 1] && (s[*i + 1] == 'd' || s[*i + 1] == 'i'))
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (s[*i + 1] && s[*i + 1] == 'u')
		count += ft_putnbr_fd_unsigned(va_arg(ap, unsigned int), 1);
	else if (s[*i + 1] && (s[*i + 1] == 'x' || s[*i + 1] == 'X'))
		count += ft_putnbr_hex(va_arg(ap, unsigned int),
				s[*i + 1] == 'X');
	else if (s[*i + 1] && s[*i + 1] == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (s[*i + 1] && s[*i + 1] == '%')
		count += ft_putchar_fd('%', 1);
	else if (s[*i + 1] && s[*i + 1] == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	return (count);
}

int	ft_printf(const char *s, ...)
<<<<<<< HEAD
{
=======
{	
>>>>>>> 34a63c3f525fa4a5a01f8f36534fb641cfb78f24
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i])
<<<<<<< HEAD
	{
		if (s[i] == '%')
		{
=======
	{	
		if (s[i] == '%')
		{	
>>>>>>> 34a63c3f525fa4a5a01f8f36534fb641cfb78f24
			count += ft_formats(ap, s, &i);
			i++;
		}
		else
			count += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
<<<<<<< HEAD
=======


int main()
{	
	int a = ft_printf("zxcvb%");
	printf("\n%d", a);
	return 0;
}
>>>>>>> 34a63c3f525fa4a5a01f8f36534fb641cfb78f24
