/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:09:25 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/30 12:49:33 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stddef.h>
#include <stdarg.h>
#include <limits.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr_hex(unsigned long int nbr, int cX);
int		ft_putptr(void *p);
int		ft_putchar_fd_p(char c, int fd);
int		ft_putnbr_fd_unsigned(unsigned int nbr, int fd);
int		ft_putnbr_fd_p(int nbr, int fd);
int		ft_putstr_fd_p(char *s, int fd);

#endif
