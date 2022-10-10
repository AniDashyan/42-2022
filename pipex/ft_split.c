/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:15:24 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/08 18:52:40 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else if (flag)
		{
			count++;
			if (s[i] != '\0' && s[i] != c)
				flag = 0;
		}
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	*ft_strdup2(const char *s, char c, int len, int *i)
{
	char	*ptr;
	int		j;

	j = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s[*i] && s[*i] != c)
	{
		ptr[j] = s[*i];
		j++;
		*i += 1;
	}
	ptr[j] = '\0';
	return (ptr);
}

static void	*ft_free(char **splitted, int j)
{
	while (splitted[j])
	{
		free(splitted[j]);
		j++;
	}
	free(splitted);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	splitted = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!splitted)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			splitted[j] = ft_strdup2(s, c, ft_wordlen(s, c, i) + 1, &i);
			if (!splitted[j++])
				return (ft_free(splitted, j - 1));
		}
		if (!s[i])
			break ;
		i++;
	}
	splitted[j] = NULL;
	return (splitted);
}
