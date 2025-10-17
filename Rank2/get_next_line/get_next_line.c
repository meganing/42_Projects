/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:47:34 by tthwe             #+#    #+#             */
/*   Updated: 2025/10/17 02:26:01 by tthwe            ###   ########.fr       */
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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				bytes_read;
	static char*	temp_store;
	char*			line;
	char			buffer[BUFF_SIZE + 1];
	char*			new_line_pos;
	int				len;

	len = 0;
	new_line_pos == NULL;
	temp_store = ft_strdup("");
	while (new_line_pos == NULL)
	{
		bytes_read = read(fd, buffer, BUFF_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		if (!temp_store)
			temp_store = ft_strdup("");
		buffer[bytes_read] = '\0';
		temp_store = ft_strjoin(temp_store, buffer); (If ft_strjoin allocates new memory, the old temp_store isn’t freed.
			You can fix this by using a helper that joins and frees the old one (like join_and_free).)
		new_line_pos = ft_strchr(temp_store, '\n');
	}
	len = new_line_pos - temp_store;
	line = ft_substr(temp_store, 0, len);
}