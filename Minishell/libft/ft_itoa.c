/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:35:09 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	absolut(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_strcpy(char	*dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = count(n);
	res = ft_calloc(sizeof(char), (len + 2));
	if (n < 0)
		res [0] = '-';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (n != 0)
	{
		res[len - 1] = absolut(n % 10) + '0';
		len--;
		n = n / 10;
	}
	return (res);
}
