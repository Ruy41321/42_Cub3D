/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:22:52 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/03 18:45:56 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	check_first_last_row(t_c3d *c3d, char **map_lines, int height)
{
	int	j;

	j = 0;
	while (map_lines[0][j])
	{
		if (map_lines[0][j] != '1' && map_lines[0][j] != ' ' \
		&& map_lines[0][j] != '\t')
			error_exit(c3d, "Error\nMap is not closed: first row");
		j++;
	}
	j = 0;
	while (map_lines[height - 1][j])
	{
		if (map_lines[height - 1][j] != '1' && map_lines[height - 1][j] \
		!= ' ' && map_lines[height - 1][j] != '\t')
			error_exit(c3d, "Error\nMap is not closed: last row");
		j++;
	}
}

void	check_space(t_c3d *c3d, char **map_lines, int i, int height)
{
	int	j;
	int	row_length;

	j = 1;
	row_length = ft_strlen(map_lines[i]);
	while (j < row_length - 1)
	{
		if (map_lines[i][j] == ' ')
		{
			if ((i > 0 && map_lines[i - 1][j] == '0') ||
				(i < height - 1 && map_lines[i + 1][j] == '0') ||
				(j > 0 && map_lines[i][j - 1] == '0') ||
				(j < row_length - 1 && map_lines[i][j + 1] == '0'))
				error_exit(c3d, \
				"Error\nMap is not closed: space inside \row adjacent to '0'");
		}
		j++;
	}
}

void	check_first_last_column(t_c3d *c3d, char **map_lines, int height)
{
	int	i;
	int	j;
	int	row_length;

	i = 0;
	while (i < height)
	{
		row_length = ft_strlen(map_lines[i]);
		if (c3d->raw_map.dimension.w < row_length)
			c3d->raw_map.dimension.w = row_length;
		if (map_lines[i][0] != '1' && map_lines[i][0] != ' ' \
		&& map_lines[i][0] != '\t')
			error_exit(c3d, "Error\nMap is not closed: first column");
		if (map_lines[i][row_length - 1] != '1' && map_lines[i] \
		[row_length - 1] != ' ' && map_lines[i][row_length - 1] != '\t')
			error_exit(c3d, "Error\nMap is not closed: last column");
		j = 1;
		check_space(c3d, map_lines, i, height);
		i++;
	}
}

void	check_map_closed(t_c3d *c3d, char **map_lines)
{
	int	height;

	height = ft_arrlen(map_lines);
	c3d->raw_map.dimension.h = height;
	check_first_last_row(c3d, map_lines, height);
	check_first_last_column(c3d, map_lines, height);
	check_shorter_rows(c3d, map_lines, height);
}
