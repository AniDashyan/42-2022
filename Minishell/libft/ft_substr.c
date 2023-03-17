/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:17:03 by sokhacha          #+#    #+#             */
/*   Updated: 2023/01/24 11:55:47 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const	*s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	l;

	l = ft_strlen(s);
	if (l < start || len == 0)
		i = 0;
	else if (len <= l - start)
		i = len;
	else
		i = l - start;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	j = 0;
	while (s[start] && j < i)
	{
		ptr[j] = s[start];
		j++;
		start++;
	}	
	ptr[j] = '\0';
	return (ptr);
}
