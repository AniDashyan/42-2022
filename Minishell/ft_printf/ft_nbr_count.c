/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:40:13 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:48:51 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_count(long long int n, const char *base, int fd)
{
	int	count;

	count = 0;
	if (n >= ft_strlen_ft(base))
		count += ft_nbr_count((n / ft_strlen_ft(base)), base, fd);
	count += write(fd, &base[n % ft_strlen_ft(base)], 1);
	return (count);
}
