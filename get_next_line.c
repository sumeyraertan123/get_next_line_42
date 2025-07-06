#include "get_next_line.h"






char	*get_next_line(int fd)
{
	static char	*readed_ones; //stash
	char	*buffer;
	ssize_t	r_byte;
	char	*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!strchr())
	{
		r_byte = read(fd, buffer, BUFFER_SIZE);
		if (r_byte <= 0)
		{
			return (NULL);
			free (buffer);
		}
		buffer[r_byte] = '\0';
		readed_ones = str_join();
		free(buffer);
	}

}
