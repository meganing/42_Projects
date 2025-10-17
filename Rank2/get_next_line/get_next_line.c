/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:47:34 by tthwe             #+#    #+#             */
/*   Updated: 2025/10/17 19:08:23 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char* bytes_read; //store the return result of the read function --- number of bytes read
    static char* temp_store; //store the content that is read from the read function calls
    char* line; //store the complete line that is read 
    char buffer[BUFF_SIZE + 1]; //store the content read from the file in each function call
    char* new_line_pos; //store the position of the new line
    int len; //store the length of the line
    int i;

    i = 0;
    len = 0; 
    while (buffer[i] != '\n')
    {
        bytes_read = read(fd, buffer, BUFF_SIZE);
        if (bytes_read == -1)
            return NULL;
        if (bytes_read == 0)
            break;
        temp_store = ft_strdup("");
        while(buffer[i])
        {
            temp_store = ft_strjoin(temp_store, buffer);
        }
        new_line_pos = ft_strchr(buffer, '\n');
        if (new_line_pos != NULL)
        {
            len = new_line_pos - temp_store;
            line = malloc((len + 1) * sizeof(char));
            ft_strlcpy(line, temp_store, len);
        }
    }
    bytes_read = read(fd, buffer, BUFF_SIZE);
}




////

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:47:34 by tthwe             #+#    #+#             */
/*   Updated: 2025/10/18 01:37:27 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_temp_store(char *temp, char *buff)
{
	char	*update;

	update = ft_strjoin(temp, buff);
	free(temp);
	return (update);
}

static char	*remove_old_line(char *temp, char *new_line_pos)
{
	char	*remain;

	if (new_line_pos == NULL)
	{
		free(temp);
		return (NULL);
	}
	else
	{
		remain = ft_strdup(new_line_pos + 1);
		free(temp);
		return (remain);
	}
}

static char	*store_line_content(char *temp, char *new_line_pos)
{
	char	*content;
	int		len;

	len = 0;
	if (new_line_pos == NULL)
		len = ft_strlen(temp);
	else
		len = new_line_pos - temp + 1;
	content = ft_substr(temp, 0, len);
	return (content);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*temp_store;
	char		*line;
	char		buffer[BUFF_SIZE + 1];
	char		*new_line_pos;

	new_line_pos = NULL;
	if (!temp_store)
		temp_store = ft_strdup("");
	while (new_line_pos == NULL)
	{
		bytes_read = read(fd, buffer, BUFF_SIZE);
		if (bytes_read == -1)
		{
			free(temp_store);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp_store = update_temp_store(temp_store, buffer);
		new_line_pos = ft_strchr(temp_store, '\n');
	}
	line = store_line_content(temp_store, new_line_pos);
	temp_store = remove_old_line(temp_store, new_line_pos);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*read;

	fd = open("thoughts.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((read = get_next_line(fd)) != NULL)
	{
		printf("%s", read);
		free(read);
	}
	close(fd);
	return (0);
}