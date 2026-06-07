/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 00:12:05 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/06 07:15:06 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*append_chunk(char *result, char *buffer)
{
	char	*temp;

	temp = result;
	result = ft_strjoin(result, buffer);
	free(temp);
	return (result);
}

static char	*read_file_to_string(char *filepath)
{
	int		fd;
	char	buffer[4097];
	ssize_t	got;
	char	*result;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
	result = ft_strdup("");
	got = read(fd, buffer, 4096);
	while (result && got > 0)
	{
		buffer[got] = '\0';
		result = append_chunk(result, buffer);
		got = read(fd, buffer, 4096);
	}
	close(fd);
	if (got < 0 || !result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

void	check_extension(char *filepath, char *extension)
{
	int	path_len;
	int	ext_len;

	path_len = ft_strlen(filepath);
	ext_len = ft_strlen(extension);
	if (path_len <= ext_len
		|| ft_strncmp(filepath + path_len - ext_len, extension, ext_len) != 0)
		error_exit("Error\nInvalid file extension\n");
}

char	**read_map(char *filepath, int *rows)
{
	char	*contents;
	char	**map;

	contents = read_file_to_string(filepath);
	if (!contents)
		return (NULL);
	map = ft_split(contents, '\n');
	free(contents);
	if (!map)
		return (NULL);
	*rows = 0;
	while (map[*rows])
		(*rows)++;
	return (map);
}
