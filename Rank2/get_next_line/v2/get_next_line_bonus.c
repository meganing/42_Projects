/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 23:23:56 by tthwe             #+#    #+#             */
/*   Updated: 2025/11/15 17:52:45 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

static char	*extract_line(char *all_stored)
{
	char	*result;
	int		i;

	i = 0;
	if (!all_stored)
		return (NULL);
	while (all_stored[i] && all_stored[i] != '\n')
		i++;
	if (all_stored[i] == '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (all_stored[i] && all_stored[i] != '\n')
	{
		result[i] = all_stored[i];
		i++;
	}
	if (all_stored[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

static char	*store_leftover(char *all_stored)
{
	char	*leftover;
	size_t	i;
	size_t	len;

	if (!all_stored)
		return (NULL);
	len = ft_strlen(all_stored);
	i = 0;
	while (all_stored[i] && all_stored[i] != '\n')
		i++;
	if (!all_stored[i])
	{
		free(all_stored);
		all_stored = NULL;
		return (NULL);
	}
	if (len <= i + 1)
	{
		free(all_stored);
		return (NULL);
	}
	leftover = ft_substr(all_stored, i + 1, len - (i + 1));
	free(all_stored);
	return (leftover);
}

static char	*read_buffer(int fd, char *all_stored, char *read_buffer)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (all_stored);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		read_buffer[bytes_read] = '\0';
		temp = ft_strjoin(all_stored, read_buffer);
		free(all_stored);
		if (!temp)
			return (NULL);
		all_stored = temp;
		if (ft_strchr(all_stored, '\n') != NULL)
			break ;
	}
	return (all_stored);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*store[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!store[fd])
		store[fd] = NULL;
	store[fd] = read_buffer(fd, store[fd], buffer);
	free(buffer);
	if (!store[fd])
		return (NULL);
	line = extract_line(store[fd]);
	store[fd] = store_leftover(store[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*read;
// 	int		i;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	i = 1;
// 	while (i)
// 	{
// 		read = get_next_line(fd);
// 		if (!read)
// 			break ;
// 		printf("test %d: %s \n", i, read);
// 		free(read);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }