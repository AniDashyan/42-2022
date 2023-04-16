/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:38:20 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_first(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (set[++j] && s1[i])
	{
		if (s1[i] == set[j] && set[j] != '\0')
		{
			j = -1;
			i++;
		}
	}
	return (i);
}

int	find_last(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = ft_strlen(s1) - 1;
	j = -1;
	count = 0;
	while (set[++j] && s1[i])
	{
		if (s1[i] == set[j] && set[j] != '\0')
		{
			j = -1;
			i--;
			count++;
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		first;
	int		last;

	if (s1 && set)
	{
		first = find_first(s1, set);
		last = find_last(s1, set);
		ptr = ft_substr(s1, first, ft_strlen(s1) - first - last);
		return (ptr);
	}
	else
		return (ft_strdup(s1));
	return (0);
}
