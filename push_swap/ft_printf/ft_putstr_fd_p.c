/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:05:15 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/30 12:51:09 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return  (i);
}

int	ft_putstr_fd_p(char *s, int fd)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(fd, s, str_len(s)));
}
