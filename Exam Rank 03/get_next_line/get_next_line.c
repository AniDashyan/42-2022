#include "get_next_line.h"

char	*ft_strjoin(char	*str1, char	*str2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	i = 0;
	j = 0;
	joined = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (str1[i])
		joined[j++] = str1[i++];
	i = 0;
	while (str2[i])
		joined[j++] = str2[i++];
	joined[j] = '\0';
	free(str1);
	return (joined);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	while (c[count])
	{
		count++;
	}
	return (count);
}

char	*read_to_stat(int fd, char *stat)
{
	char	*buff;
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(stat, '\n'))
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
		stat = ft_strjoin(stat, buff);
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
	new_stat = (char *)malloc((ft_strlen(stat) - i + 1) * sizeof(char));
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
