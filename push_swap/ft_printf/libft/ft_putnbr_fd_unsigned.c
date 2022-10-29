/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:07:14 by adashyan          #+#    #+#             */
/*   Updated: 2022/05/10 20:29:01 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
		count += ft_putchar_fd(nbr + '0', fd);
	return (count);
}
