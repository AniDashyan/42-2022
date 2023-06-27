/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:54:45 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/04 17:43:33 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dsts;
	char	*srcs;
	size_t	i;

	dsts = (char *)dst;
	srcs = (char *)src;
	i = 0;
	if (dsts == srcs)
		return (0);
	if (dst < src)
	{
		while (i < len)
		{
			dsts[i] = srcs[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dsts[len] = srcs[len];
	}
	return (dst);
}
