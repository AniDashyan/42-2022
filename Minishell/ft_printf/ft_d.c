/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:39:57 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:13 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_c('-', fd);
		count += ft_c('2', fd);
		n = 147483648;
	}
	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		count += ft_c('-', fd);
	}
	if ((n / 10) > 0)
	{
		count += ft_d(n / 10, fd);
		count += ft_d(n % 10, fd);
		return (count);
	}
	else
		count += ft_c(n + 48, fd);
	return (count);
}
