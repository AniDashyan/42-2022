/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:09:50 by adashyan          #+#    #+#             */
/*   Updated: 2022/05/08 17:24:16 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if ((char *)s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char));
		*sub = '\0';
		return (sub);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
