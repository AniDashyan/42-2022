/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:09:25 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/08 18:53:17 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr_hex(unsigned long int nbr, int cX);
int		ft_putptr(void *p);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd_unsigned(unsigned int nbr, int fd);
int		ft_putnbr_fd(int nbr, int fd);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
