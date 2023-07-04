/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:11:10 by adashyan          #+#    #+#             */
/*   Updated: 2023/07/03 21:02:43 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

char	*line_ret(char *line, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	long	i;
	char	*tmp;

	while (1)
	{
		i = read(fd, buff, 1);
		buff[i] = '\0';
		if (i == -1)
			return (0);
		if (!line)
			line = ft_strdup(buff);
		else
		{
			tmp = line;
			line = ft_strjoin(line, buff);
			free(tmp);
		}
		if (ft_strchr(buff, '\n') || i == 0)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*line;
	char		*tmp;
	long		len;

	len = 0;
	read_line = line_ret(read_line, fd);
	if (!read_line)
		return (0);
	len = ft_strlen(read_line) - ft_strlen(ft_strchr(read_line, '\n')) + 1;
	line = ft_substr(read_line, 0, len);
	tmp = read_line;
	read_line = ft_substr(read_line, len, ft_strlen(read_line));
	free(tmp);
	return (line);
}
