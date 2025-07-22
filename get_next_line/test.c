#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	char *line = get_next_line(fd);
	printf("%s", line);
	char *line1 = get_next_line(fd);
	printf("%s\n", line1);
	char *line2 = get_next_line(fd);
	printf("%s\n", line2);
	char *line3 = get_next_line(fd);
	printf("%s\n", line3);
	char *line4 = get_next_line(fd);
	printf("%s\n", line4);
	close(fd);
}