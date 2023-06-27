/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:54:49 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/26 13:08:23 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	val;
	int		i;
	int		k;

	val = 0;
	i = 0;
	k = 1;
	while (s[i] == '\t' || s[i] == '\r' || s[i] == ' ' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\n' || s[i] == '-' || s[i] == '+')
		if ((s[i++] == '+' || s[i - 1] == '-') && !ft_isdigit(s[i]))
			return (0);
	if (!ft_isdigit(s[i]))
		return (0);
	if (i != 0 && s[i - 1] == '-')
		k = -1;
	while (ft_isdigit(s[i]))
	{
		val = (val * 10) + s[i++] - '0';
		if (val > INT_MAX && k == 1)
			return (-1);
		if (INT_MIN > -val)
			return (0);
	}
	return (val * k);
}
