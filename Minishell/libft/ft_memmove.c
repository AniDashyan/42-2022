/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:35:42 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:12 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t len)
{
	unsigned char		*dst1;
	const unsigned char	*src1;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		dst1 = (unsigned char *)dst;
		src1 = (unsigned char *)src;
		while (len--)
			*dst1++ = *src1++;
	}
	else
	{
		dst1 = (unsigned char *)dst + (len - 1);
		src1 = (unsigned char *)src + (len - 1);
		while (len--)
			*dst1-- = *src1--;
	}
	return (dst);
}
