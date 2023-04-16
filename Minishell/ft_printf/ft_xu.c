/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:44 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:13 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xu(unsigned int n, int fd)
{
	int	count;

	count = 0;
	count += ft_nbr_count(n, "0123456789abcdef", fd);
	return (count);
}
