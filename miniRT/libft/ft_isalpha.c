/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:38:27 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/22 12:40:23 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int x)
{
	if (x >= 'A' && x <= 'Z')
		return (1);
	return (0);
}

static int	ft_islower(int x)
{
	if (x >= 'a' && x <= 'z')
		return (1);
	return (0);
}

int	ft_isalpha(int x)
{
	if (ft_islower(x) || ft_isupper(x))
		return (1);
	return (0);
}
