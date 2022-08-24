/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:25:49 by adashyan          #+#    #+#             */
/*   Updated: 2022/05/08 18:46:35 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (!len)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (len--)
		cdst[len] = csrc[len];
	return (dst);
}
