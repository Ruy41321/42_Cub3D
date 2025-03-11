/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:00:50 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/03 19:01:42 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

char	**allocate_map(int width, int height);
void	fill_map(char **map, char *file_content, int width, int height);

char	**get_map_from_file(char *file_content, int width, int height)
{
	char	**map;

	map = allocate_map(width, height);
	fill_map(map, file_content, width, height);
	return (map);
}

char	**allocate_map(int width, int height)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc((height + 1) * sizeof(char *));
	i = 0;
	while (i < height)
	{
		map[i] = (char *)malloc((width + 1) * sizeof(char));
		j = 0;
		while (j < width)
		{
			map[i][j] = ' ';
			j++;
		}
		map[i][width] = '\0';
		i++;
	}
	map[height] = NULL;
	return (map);
}

void	fill_map(char **map, char *file_content, int width, int height)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (map[y][x])
		{
			if (file_content[i] != '\n')
				map[y][x] = file_content[i];
			else if (x != width)
				while (map[y][x])
					x++;
			i++;
			if (file_content[i] == '\n' && !map[y][x])
				i++;
			x++;
		}
		y++;
	}
}
