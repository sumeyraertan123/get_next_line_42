#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j] != '\0')
		j++;
	if (size == 0)
		return (j);
	i = 0;
	while ((i < size -1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

static char	*ft_add_read_ones(int fd, char *read_ones)
{
	ssize_t	read_res;
	char	*temp;

	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (ft_strchr(read_ones, '\n') == NULL)
	{
		read_res = read(fd, temp, BUFFER_SIZE);
		if (read_res = -1)
		{
			free(read_ones);
			free(temp);
			return (NULL);
		}
		if (read_res == 0)
			break;
		temp[read_res] = '\0';
		read_ones = ft_strjoin(read_ones, temp);
		if (read_ones == NULL)
			break;
	}
	free(temp);
	return(read_ones);
}

static char	*ft_line(char *read_ones)
{
	char	*chr_addr;
	char	*line;

	chr_addr = ft_strchr(read_ones, '\n');
	if (chr_addr == NULL)
		return (ft_substr(read_ones, 0, ft_strlen(read_ones)));
	line = ft_substr(read_ones, 0, chr_addr - read_ones + 1);
	return (line);
}

static	*ft_remained_ones(char *read_ones)
{
	char	*orginal;
	char	*new;

	orginal = read_ones;
	read_ones = ft_strchr(read_ones, '\n');
	if (read_ones == NULL)
	{
		free(orginal);
		return (NULL);
	}
	read_ones++;
	if (!read_ones)
		return (NULL);
	new = (char *)ft_calloc(ft_strlen(read_ones) + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, read_ones, ft_strlen(read_ones) + 1);
	free(orginal);
	return (new);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*read_ones;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_ones = ft_add_read_ones(fd, read_ones);
	if (read_ones == NULL)
		return (NULL);
	if (ft_strlen(read_ones) == 0)
	{
		free(read_ones);
		read_ones = NULL ;
		return (NULL);
	}
	line = ft_line(read_ones);
	read_ones = ft_remained_ones(read_ones);
	return (line);
}
