/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:47:43 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:47:44 by adashyan         ###   ########.fr       */
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
