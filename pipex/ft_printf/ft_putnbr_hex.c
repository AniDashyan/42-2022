/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:07:54 by adashyan          #+#    #+#             */
/*   Updated: 2022/05/28 18:13:38 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long int nbr, int cX)
{	
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_hex(nbr / 16, cX);
		count += ft_putnbr_hex(nbr % 16, cX);
	}
	else
	{
		if (!cX)
			count += ft_putchar_fd("0123456789abcdef"[nbr], 1);
		else
			count += ft_putchar_fd("0123456789ABCDEF"[nbr], 1);
	}
	return (count);
}
