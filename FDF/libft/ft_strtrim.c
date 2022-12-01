/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:49:30 by adashyan          #+#    #+#             */
/*   Updated: 2022/11/24 20:49:31 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	i = 0;
	if (s == NULL || set == NULL)
		return (NULL);
	j = ft_strlen(s);
	while (s[i] != '\0' && ft_strchr(set, s[i]))
			i++;
	while (s[j - 1] && ft_strchr(set, s[j - 1]) && j > i)
		j--;
	trim = ft_substr(s, i, j - i);
	if (!trim)
		return (NULL);
	return (trim);
}
