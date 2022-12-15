/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:16:54 by adashyan          #+#    #+#             */
/*   Updated: 2022/08/07 18:00:15 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000000
# endif

char	*get_next_line(int fd);
size_t	ft_strlen1(const char *c);
char	*ft_strchr1(char *s, int c);
char	*ft_strjoin1(char	*str1, char	*str2);

#endif
