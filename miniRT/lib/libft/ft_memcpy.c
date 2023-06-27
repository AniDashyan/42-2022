/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:24:09 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/22 17:18:14 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dsts;
	char	*srcs;
	size_t	i;

	srcs = (char *)src;
	dsts = (char *)dst;
	i = 0;
	if (ft_abs((int)dst, (int)src) >= (int)n)
	{
		while (i < n)
		{
			dsts[i] = srcs[i];
			i++;
		}
	}
	return (dst);
}
