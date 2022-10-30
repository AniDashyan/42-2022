/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:07:14 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/30 12:44:12 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_unsigned(unsigned int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_putnbr_fd_unsigned(nbr / 10, fd);
		count += ft_putnbr_fd_unsigned(nbr % 10, fd);
	}
	else
		count += ft_putchar_fd_p(nbr + '0', fd);
	return (count);
}
