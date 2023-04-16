/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_for_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:30:15 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_sub_str(char const	*str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	if (count == 0 || str[0] != c)
		count++;
	return (count);
}

static char	*word_dup(char const	*str, int start, int finish)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	i = 0;
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_for_export(char const *s, char c)
{
	int				i;
	int				j;
	int				index;
	char			**split;

	split = (char **)ft_calloc(sizeof(char *), (count_sub_str(s, c) + 2));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			if (s[i] == c)
				split[j] = ft_strdup(s + i + 1);
			return (split);
		}
		i++;
	}
	return (split);
}
