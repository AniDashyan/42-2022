/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:09:50 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/22 17:57:54 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	if (s == NULL)
		return (0);
	j = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * j + 1);
	if (!ptr)
		return (0);
	while (++i < j)
		ptr[i] = f(i, s[i]);
	ptr[j] = '\0';
	return (ptr);
}
