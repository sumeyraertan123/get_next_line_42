/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sertan <sertan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:19:27 by sertan            #+#    #+#             */
/*   Updated: 2025/07/23 15:23:44 by sertan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	new_len = ft_strlen(s + start);
	if (new_len > len)
		new_len = len;
	sub = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (s + start), (new_len + 1));
	return (sub);
}

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
	while ((i < size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*src;
	size_t			i;
	size_t			space;

	space = nmemb * size;
	src = (unsigned char *)malloc(space);
	if (!src)
		return (NULL);
	i = 0;
	while (i < space)
	{
		src[i] = 0;
		i++;
	}
	return ((void *)src);
}
