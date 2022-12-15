/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:14:13 by adashyan          #+#    #+#             */
/*   Updated: 2022/06/07 20:14:14 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_stat(int fd, char *stat)
{
	char	*buff;
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr1(stat, '\n'))
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		stat = ft_strjoin1(stat, buff);
		free(buff);
	}
	return (stat);
}

char	*ret_line(char *stat)
{	
	char	*line;
	int		i;
	int		c;
	int		j;

	i = 0;
	j = -1;
	c = 1;
	if (!stat[i])
		return (NULL);
	while (stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\n')
		c++;
	line = (char *)malloc((i + c) * sizeof(char));
	if (!line)
		return (NULL);
	while (++j < i)
		line[j] = stat[j];
	if (stat[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*new_static(char *stat)
{	
	char	*new_stat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stat[i] && stat[i] != '\n')
		i++;
	if (!stat[i])
	{
		free(stat);
		return (NULL);
	}
	new_stat = (char *)malloc((ft_strlen1(stat) - i + 1) * sizeof(char));
	if (!new_stat)
		return (NULL);
	while (stat[i++] != '\0')
	{	
		new_stat[j++] = stat[i];
	}
	new_stat[j] = '\0';
	free(stat);
	return (new_stat);
}

char	*get_next_line(int fd)
{	
	char		*line;
	static char	*stat;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = read_to_stat(fd, stat);
	if (!stat)
		return (NULL);
	line = ret_line(stat);
	stat = new_static(stat);
	return (line);
}