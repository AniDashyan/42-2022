/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:37:49 by sokhacha          #+#    #+#             */
/*   Updated: 2023/01/24 11:55:47 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s1)
{
	char	*new;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	new = (char *)malloc((i + 1) * sizeof(*s1));
	if (new == NULL)
		return (0);
	else
	{
		if (!s1)
			return (NULL);
		i = 0;
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
}
