/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:07:14 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/30 12:43:34 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_p(int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += ft_putchar_fd_p('-', fd);
		count += ft_putchar_fd_p('2', fd);
		nbr = 147483648;
	}
	else if (nbr < 0)
	{
		count += ft_putchar_fd_p('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		count += ft_putnbr_fd_p(nbr / 10, fd);
		count += ft_putnbr_fd_p(nbr % 10, fd);
	}
	else
		count += ft_putchar_fd_p(nbr + '0', fd);
	return (count);
}
