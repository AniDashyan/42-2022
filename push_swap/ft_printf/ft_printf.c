/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:29:10 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/30 12:49:27 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list ap, const char *s, int *i)
{
	int	count;

	count = 0;
	if (s[*i + 1] && s[*i + 1] == 'c')
		count += ft_putchar_fd_p(va_arg(ap, int), 1);
	else if (s[*i + 1] && (s[*i + 1] == 'd' || s[*i + 1] == 'i'))
		count += ft_putnbr_fd_p(va_arg(ap, int), 1);
	else if (s[*i + 1] && s[*i + 1] == 'u')
		count += ft_putnbr_fd_unsigned(va_arg(ap, unsigned int), 1);
	else if (s[*i + 1] && (s[*i + 1] == 'x' || s[*i + 1] == 'X'))
		count += ft_putnbr_hex(va_arg(ap, unsigned int),
				s[*i + 1] == 'X');
	else if (s[*i + 1] && s[*i + 1] == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (s[*i + 1] && s[*i + 1] == '%')
		count += ft_putchar_fd_p('%', 1);
	else if (s[*i + 1] && s[*i + 1] == 's')
		count += ft_putstr_fd_p(va_arg(ap, char *), 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_formats(ap, s, &i);
			i++;
		}
		else
			count += ft_putchar_fd_p(s[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
