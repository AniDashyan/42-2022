/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:11:39 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 17:11:43 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	ft_is_from_charset(const char *str, const char *charset)
{
	int	i;
	int	j;
	int	ok;

	i = 0;
	while (str[i])
	{
		ok = 0;
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j++])
				ok = 1;
		}
		if (!ok)
			return (0);
		i++;
	}
	return (1);
}

int	ft_in_charset(char const c, char const *charset)
{
	int	i_charset;

	i_charset = 0;
	while (charset[i_charset])
	{
		if (c == charset[i_charset++])
			return (1);
	}
	return (0);
}

int	ft_atoi_strict(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			sign *= -1;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += *nptr++ - '0';
	}
	if (*nptr == '\0')
		return (res * sign);
	return (-1);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			sign *= -1;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += *nptr++ - '0';
	}
	return (res * sign);
}

float	ft_atof(const char *str)
{
	int		decimal_size;
	float	nb;
	int		sign;

	while (ft_in_charset(*str, "\t "))
		str++;
	sign = 1;
	if ((*str == '+' || *str == '-') && *str++ == '-')
		sign *= -1;
	nb = 0;
	nb += ft_atol(str);
	while (*str && ft_in_charset(*str, "0123456789"))
		str++;
	if (*str == '.')
		str++;
	else
		return (nb * sign);
	decimal_size = 0;
	while (ft_in_charset(str[decimal_size], "0123456789"))
		decimal_size++;
	if (decimal_size)
		nb += ft_atol(str) / (pow(10, decimal_size));
	else
		return (nb * sign);
	return (nb * sign);
}
