/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:03:46 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/22 18:07:04 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_intlen(int n);

char	*ft_itoa(int n1)
{
	char	*itoa;
	size_t	c;
	long	n;

	n = (long)n1;
	c = ft_intlen(n);
	if (n < 0)
	{
		itoa = (char *)malloc(sizeof(char) * c + 1);
		if (!itoa)
			return (0);
		itoa[0] = '-';
		n = -n;
	}
	else
		itoa = (char *)malloc(sizeof(char) * c + 1);
	itoa[c] = '\0';
	if (n == 0)
		itoa[0] = '0';
	while (n)
	{
		itoa[--c] = (n % 10) + '0';
		n = n / 10;
	}
	return (itoa);
}

static	size_t	ft_intlen(int n)
{
	if (n >= 0 && n <= 9)
		return (1);
	return (1 + ft_intlen(n / 10));
}
