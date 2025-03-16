/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:02:59 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/03 17:42:50 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

/* this function receives a "file path",
opens it, reads it, saves its content in a malloced string
and finally returns this string.
First of all it opens the file using open() with READ_ONLY options.
This functions allow us to know the 
fd (file descriptor) to pass to read function.
We can then read the file using read(), which returns
 the number of bytes read! 
To remember: read requires as parameters: the fd, the buffer where 
to temporary memorize what has been read,and the dimension of the buffer.
when i call read I make it read for a total of (buffer_Size -1) so
 that the last byte of buffer can be reserved to null terminator \0.
After one reading, buffer could be full or it could be not completely 
full...i will know this info thanks to read_bytes returned by read();
So even if buffer is not completely full..I can know how manu bytes of 
buffer have been actually filled during the reading;
This means that I can put a null terminator exactly at the end of the
 reading. With buffer[read_bytes] = \0
 */
char	*read_texture_data(int fd)
{
	char	*line;
	char	*content_file;
	int		i;

	content_file = ft_safe_malloc(1);
	content_file[0] = '\0';
	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_blank_line(line))
		{
			free(line);
			continue ;
		}
		content_file = ft_strjoin_free(content_file, line, 3);
		i++;
	}
	return (content_file);
}

int	process_line(int fd, char **content_file, int *before_cont, int *blank_line)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	if (is_blank_line(line))
	{
		free(line);
		if (!*before_cont)
			*blank_line = 1;
		return (0);
	}
	if (*blank_line)
		return (free(line), 2);
	*before_cont = 0;
	*content_file = ft_strjoin_free(*content_file, line, 3);
	return (0);
}

char	*read_map_data(t_c3d *c3d, int fd)
{
	char	*content_file;
	int		before_cont;
	int		blank_line;
	int		status;

	content_file = ft_safe_malloc(1);
	content_file[0] = '\0';
	before_cont = 1;
	blank_line = 0;
	while (1)
	{
		status = process_line(fd, &content_file, &before_cont, &blank_line);
		if (status == 1)
			break ;
		else if (status == 2)
		{
			free(content_file);
			error_exit(c3d, INVALID_MAP);
		}
	}
	return (content_file);
}

void	build_map(char *path, t_c3d *c3d)
{
	int		fd;
	char	*ext;

	ext = ft_get_extention(path);
	if (ext)
	{
		if (ft_strcmp(ext, "cub"))
		{
			free(ext);
			error_exit(c3d, INVALID_MAP);
		}
		free(ext);
	}
	if (access(path, F_OK) == -1)
		error_exit(c3d, INVALID_PATH);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit(c3d, FILE_READ_ERROR);
	c3d->raw_map.texture_data = read_texture_data(fd);
	c3d->raw_map.map_data = read_map_data(c3d, fd);
	parse_and_check(c3d);
}
