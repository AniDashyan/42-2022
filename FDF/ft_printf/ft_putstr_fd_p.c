/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:05:15 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/01 17:29:29 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_p(char *s, int fd)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}
