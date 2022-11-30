/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:47:27 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:47:28 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n == 0)
		return (NULL);
	while (--n && *(unsigned char *)s != (unsigned char)c)
		s++;
	if (*(unsigned char *)s != (unsigned char)c)
		return (NULL);
	return ((void *)s);
}
