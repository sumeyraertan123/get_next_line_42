#include "get_next_line.h"


char	*ft_strjoin(const char *read_ones, const char *buffer)
{
	int	i;
	char	*joined;

	if (!read_ones)
		read_ones = ft_strdup("");
	if (!read_ones || !buffer)
		return (NULL);
	i = 0;
	joined = malloc((ft_strlen(read_ones) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while ()
	read_ones;
}

//char	*ft_strdup();
char	*ft_substr(const char *str, int start, size_t len)
{
	int	i;
	char	*sub;

	i = 0;
	if (!str)
		return (NULL);
	if (len + start > ft_strlen(str))
		len = ft_strlen(str + start);
	sub = malloc(sizeof(char) * (len + 1));
	while (str[i + start] && i < len)
	{
		sub[i] = str[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
		i++;
	return (i);
}
//char	*ft_strchr();

