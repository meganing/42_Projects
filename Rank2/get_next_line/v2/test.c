#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 10

int	main(void)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	fd = open("test.txt", O_RDONLY);
	if ( fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		printf("read result: %s\n", buffer);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	close(fd);
	return (0);
}



