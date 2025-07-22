#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL) // ek olarak bu kontrol eklendi
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	i;
	char	*s1_addr;

	s1_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	joined = (char *)malloc(s1_len + ft_strlen(s2) + 1);
	if (!joined)
		return ((char *) NULL);
	i = 0;
	s1_addr = s1;
	while (s1_len && *s1)
	{
		joined[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = '\0';
	if (s1_addr != NULL)
		free(s1_addr);
	return (joined);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	new_len = ft_strlen(s) - start;
	if (new_len > len)
		new_len = len;
	sub = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (s + start), (new_len + 1));
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	unsigned char	*ptr_addr;
	size_t			n;

	n = nmemb * size;
	ptr = (unsigned char *)malloc(n);
	if (ptr == NULL)
		return (NULL);
	ptr_addr = ptr;
	while (n--)
		*ptr++ = '\0';
	return ((void *)ptr_addr);
}
