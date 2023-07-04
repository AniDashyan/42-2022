/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:22:46 by adashyan          #+#    #+#             */
/*   Updated: 2023/07/03 20:34:39 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_strncmp_rev(const char *s1, const char *s2, size_t n)
{
	unsigned int	i1;
	unsigned int	i2;

	if (!(s1 || s2))
		return (0);
	if (!(s1 && s2))
		return (-1);
	if (s1 == s2)
		return (0);
	i1 = ft_strlen(s1) - 1;
	i2 = ft_strlen(s2) - 1;
	while (i1 + 1 && i2 + 1 && s1[i1] == s2[i2] && n--)
	{
		i1--;
		i2--;
	}
	if (n)
		return ((unsigned char)s1[i1] - (unsigned char)s2[i1]);
	return (0);
}

static int	*count_lengths(int *words_len, const char *str, char *charset)
{
	int	i_length;
	int	i_str;

	i_length = 0;
	i_str = 0;
	while (str[i_str])
	{
		while (str[i_str])
		{
			if (!ft_in_charset(str[i_str], charset))
				break ;
			i_str++;
		}
		while (str[i_str])
		{
			if (ft_in_charset(str[i_str], charset))
				break ;
			i_str++;
			words_len[i_length]++;
		}
		i_length++;
	}
	return (words_len);
}

static int	count_words(const char *str, char *charset)
{
	int	count;
	int	i_str;

	count = 0;
	i_str = 0;
	while (str[i_str])
	{
		while (str[i_str])
		{
			if (!ft_in_charset(str[i_str], charset))
			{
				count++;
				break ;
			}
			i_str++;
		}
		while (str[i_str])
		{
			if (ft_in_charset(str[i_str++], charset))
				break ;
		}
	}
	return (count);
}

static int	fill_tab(char **tab, int *words_len, const char *str, char *charset)
{
	int		d1;
	int		d2;
	int		i_str;
	int		words_count;

	d1 = 0;
	i_str = 0;
	words_count = count_words(str, charset);
	while (d1 < words_count && str[i_str])
	{
		tab[d1] = malloc((words_len[d1] + 1) * sizeof(char));
		if (!tab[d1])
			return (0);
		while (ft_in_charset(str[i_str], charset))
			i_str++;
		d2 = 0;
		while (str[i_str] && !ft_in_charset(str[i_str], charset))
			tab[d1][d2++] = str[i_str++];
		tab[d1][d2++] = '\0';
		d1++;
	}
	tab[d1] = 0;
	free(words_len);
	return (1);
}

char	**ft_split_set(const char *str, char *charset)
{
	char	**tab;
	int		words_count;
	int		*words_len;
	int		i;

	if (!str)
		return (0);
	words_count = count_words(str, charset);
	words_len = malloc((words_count) * sizeof(int));
	if (!words_len)
		return (0);
	tab = malloc((words_count + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (i < words_count)
		words_len[i++] = 0;
	count_lengths(words_len, str, charset);
	if (fill_tab(tab, words_len, str, charset))
		return (tab);
	return (0);
}
