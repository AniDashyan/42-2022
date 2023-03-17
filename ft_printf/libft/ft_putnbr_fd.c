/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:07:14 by adashyan          #+#    #+#             */
/*   Updated: 2023/03/09 15:46:54 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += ft_putchar_fd('-', fd);
		count += ft_putchar_fd('2', fd);
		nbr = 147483648;
	}
	else if (nbr < 0)
	{
		count += ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		count += ft_putnbr_fd(nbr / 10, fd);
		count += ft_putnbr_fd(nbr % 10, fd);
	}
	else
		count += ft_putchar_fd(nbr + '0', fd);
	return (count);
}
