/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:34 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:13 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 0 && n < 10)
	{
		n += 48;
		count += ft_c(n, fd);
	}
	else
	{
		count += ft_u(n / 10, fd);
		n = n % 10 + 48;
		count += ft_c(n, fd);
	}
	return (count);
}
