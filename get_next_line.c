/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sertan <sertan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:58:27 by sertan            #+#    #+#             */
/*   Updated: 2025/07/24 17:55:07 by sertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	s1_len;

	s1_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	joined = (char *)ft_calloc((s1_len + ft_strlen(s2) + 1), sizeof(char));
	if (!joined)
		return ((char *) NULL);
	i = 0;
	while (s1 && s1[i] && s1_len)
	{
		joined[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		joined[i] = *s2++;
		i++;
	}
	joined[i] = '\0';
	return (free(s1), joined);
}

char	*ft_add_read_ones(int fd, char *read_ones)
{
	char	*temp;
	ssize_t	read_res;

	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (ft_strchr(read_ones, '\n') == NULL)
	{
		read_res = read(fd, temp, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(temp);
			free(read_ones);
			return (NULL);
		}	
		if (read_res == 0)
			break ;
		temp[read_res] = '\0';
		read_ones = ft_strjoin(read_ones, temp);
		if (read_ones == NULL)
			break ;
	}
	free (temp);
	return (read_ones);
}

char	*ft_line(char *read_ones)
{
	char	*line;
	char	*n_addr;

	n_addr = ft_strchr(read_ones, '\n');
	if (n_addr == NULL)
		line = ft_substr(read_ones, 0, ft_strlen(read_ones));
	else
		line = ft_substr(read_ones, 0, (n_addr - read_ones + 1));
	return (line);
}

char	*ft_remained_ones(char *read_ones)
{
	char	*original;
	char	*new;

	original = read_ones;
	read_ones = ft_strchr(read_ones, '\n');
	if (read_ones == NULL)
	{
		free(original);
		return (NULL);
	}
	read_ones++;
	new = ft_calloc(ft_strlen(read_ones) + 1, sizeof(char));
	if (!new)
	{
		free(original);
		return (NULL);
	}
	ft_strlcpy(new, read_ones, ft_strlen(read_ones) + 1);
	free (original);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*read_ones;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_ones = ft_add_read_ones(fd, read_ones);
	if (read_ones == NULL)
		return (NULL);
	if (ft_strlen(read_ones) == 0)
	{
		free(read_ones);
		read_ones = NULL;
		return (NULL);
	}
	line = ft_line(read_ones);
	read_ones = ft_remained_ones(read_ones);
	return (line);
}
