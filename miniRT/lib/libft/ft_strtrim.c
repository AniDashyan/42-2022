/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:28:56 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/28 19:09:25 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_rmmatch(char *ptr, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy_string;
	char	*return_string;
	size_t	k;
	size_t	j;

	if (!s1)
		return (0);
	j = 0;
	k = ft_strlen(s1);
	copy_string = (char *)malloc(k + 1);
	if (!copy_string)
		return (0);
	ft_strlcpy(copy_string, s1, k + 1);
	while (ft_rmmatch(copy_string, set))
		;
	if (ft_strlen(copy_string))
		while (ft_rmmatch(copy_string + ft_strlen(copy_string) - 1, set))
			;
	return_string = (char *)malloc(ft_strlen(copy_string) + 1);
	if (!return_string)
		return (0);
	ft_strlcpy(return_string, copy_string, ft_strlen(copy_string) + 1);
	free(copy_string);
	return (return_string);
}

static int	ft_rmmatch(char *ptr, const char *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (ptr[0] == set[j])
		{
			ft_memmove((void *)(ptr), (void *)(ptr + 1), ft_strlen(ptr));
			return (1);
		}
		j++;
	}
	return (0);
}
