/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:32:42 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/27 19:00:33 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	return (0);
}

unsigned long hex_to_decimal(char *hex, int length)
{
    int i;
    unsigned long decimal = 0;
    unsigned long weight = 1;
    hex += length - 1;
	i = length - 1;
	while (i >= 0)
	{
		decimal += weight * valueOf(*hex);
        weight *= 16;
		i--;
		hex--;
	}
    return decimal;
}