#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


char *get_next_line(int fd);

int main(void)
{
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	int fd3 = open("file3.txt", O_RDONLY);
	int fd4 = open("file4.txt", O_RDONLY);

	char *line;
	int line_num = 1;

	printf("------ Sıralı Okuma (fd1) ------\n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("fd1 - line %d: %s", line_num++, line);
		free(line);
	}

	line_num = 1;
	printf("\n------ Karışık Okuma (fd2 & fd3) ------\n");
	for (int i = 0; i < 5; i++)
	{
		line = get_next_line(fd2);
		if (line)
		{
			printf("fd2 - line %d: %s", i + 1, line);
			free(line);
		}

		line = get_next_line(fd3);
		if (line)
		{
			printf("fd3 - line %d: %s", i + 1, line);
			free(line);
		}
	}

	line_num = 1;
	printf("\n------ fd4 ilk 2 satır, sonra kapanıyor ------\n");
	for (int i = 0; i < 2; i++)
	{
		line = get_next_line(fd4);
		if (line)
		{
			printf("fd4 - line %d: %s", i + 1, line);
			free(line);
		}
	}
	close(fd4);
	printf("fd4 closed\n");

	line_num = 1;
	printf("\n------ fd2 ve fd3 okumaya devam ------\n");
	for (int i = 0; i < 5; i++)
	{
		line = get_next_line(fd2);
		if (line)
		{
			printf("fd2 - line %d: %s", line_num++, line);
			free(line);
		}

		line = get_next_line(fd3);
		if (line)
		{
			printf("fd3 - line %d: %s", line_num++, line);
			free(line);
		}
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
