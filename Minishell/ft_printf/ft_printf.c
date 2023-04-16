/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:40:29 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:13 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(int fd)
{
	write(fd, "%", 1);
	return (1);
}

int	ft_convert(va_list arg, const char form, int fd)
{
	int	length;

	length = 0;
	if (form == 'c')
		length += ft_c(va_arg(arg, int), fd);
	else if (form == 's')
		length += ft_s(va_arg(arg, char *), fd);
	else if (form == 'p')
		length += ft_p(va_arg(arg, unsigned long long), fd);
	else if (form == 'd' || form == 'i')
		length += ft_d(va_arg(arg, int), fd);
	else if (form == 'u')
		length += ft_u(va_arg(arg, unsigned int), fd);
	else if (form == 'x')
		length += ft_xu(va_arg(arg, unsigned int), fd);
	else if (form == 'X')
		length += ft_xl(va_arg(arg, unsigned int), fd);
	else if (form == '%')
		length += ft_print_percent(fd);
	return (length);
}

int	ft_printf(int fd, const char *s, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_convert(arg, s[i + 1], fd);
			i++;
		}
		else
			len += ft_c(s[i], fd);
		i++;
	}
	va_end(arg);
	return (len);
}
