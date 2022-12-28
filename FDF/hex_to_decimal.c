/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:41:34 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/28 21:14:15 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_decimal(char	*hex)
{
	long long	decimal;
	int			i;
	int			val;
	int			len;

	decimal = 0;
	len = ft_strlen(hex);
	len--;
	i = 0;
	while (hex[i] != '\0')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			val = hex[i] - 48;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			val = hex[i] - 97 + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			val = hex[i] - 65 + 10;
		decimal += val * pow(16, len);
		len--;
		i++;
	}
	return (decimal);
}
