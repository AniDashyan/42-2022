/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:27:38 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/13 17:38:29 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	j = 0;
	while (haystack[j] && j < len)
	{
		i = 0;
		if (haystack[j] == needle[i])
		{
			while (haystack[j + i]
				&& needle[i] && haystack[j + i] == needle[i]
				&& i + j < len)
				i++;
			if (i == ft_strlen(needle))
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (NULL);
}
