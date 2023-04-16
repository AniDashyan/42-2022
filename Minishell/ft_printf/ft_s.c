/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:20 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:13 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s(char *s, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		count += ft_s("(null)", fd);
	else
		while (s[i] != '\0')
			count += write(fd, &s[i++], 1);
	return (count);
}
