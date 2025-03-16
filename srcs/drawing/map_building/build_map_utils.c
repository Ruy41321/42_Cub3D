/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:55:11 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/03 17:59:29 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	check_texture_path(t_map *raw_map, char *line)
{
	char	*path;
	char	*ptr;

	ptr = ft_strchr(line, ' ');
	if (!ptr)
		return (2);
	path = ft_strdup(ptr + 1);
	if (ft_strncmp(line, "NO ", 3) == 0)
		raw_map->no_texture = path;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		raw_map->so_texture = path;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		raw_map->we_texture = path;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		raw_map->ea_texture = path;
	else
		return (free(path), 2);
	if (access(path, F_OK) == -1)
		return (1);
	return (0);
}

int	are_information_set(t_map raw_map)
{
	if (!raw_map.no_texture || !raw_map.so_texture || !raw_map.we_texture \
	|| !raw_map.ea_texture || !raw_map.f_color || !raw_map.c_color)
		return (0);
	return (1);
}

void	check_texture_data(t_c3d *c3d)
{
	t_map	*raw_map;
	char	**lines;
	int		status;
	int		status2;
	int		i;

	raw_map = &c3d->raw_map;
	lines = ft_split(raw_map->texture_data, '\n');
	c3d->map_lines = lines;
	i = -1;
	remove_extra_space(lines);
	while (lines[++i])
	{
		status = check_texture_path(raw_map, lines[i]);
		if (status == 1)
			error_exit(c3d, INVALID_TEXTURE_PATH);
		status2 = check_color_format(raw_map, lines[i]);
		if (status2 == 1)
			error_exit(c3d, INVALID_COLOR_FORMAT);
		if (status2 == 2 && status == 2)
			error_exit(c3d, INVALID_MAP);
	}
	if (!are_information_set(*raw_map))
		error_exit(c3d, MISSING_INFORMATION);
}

void	parse_and_check(t_c3d *c3d)
{
	t_map	*raw_map;
	char	**map_lines;

	check_texture_data(c3d);
	raw_map = &c3d->raw_map;
	map_lines = ft_split(raw_map->map_data, '\n');
	c3d->raw_map.grid = map_lines;
	if (check_map_characters(raw_map, map_lines))
		error_exit(c3d, INVALID_CHARACTER);
	c3d->player.position = raw_map->player_position;
	c3d->player.tile = tile_reference(c3d->player.position);
	set_player_orientation(c3d);
	check_map_closed(c3d, map_lines);
}
