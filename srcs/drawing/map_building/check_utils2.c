/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:58:58 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/03 18:55:06 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	is_map_character(char c)
{
	if (c == '0' || c == '1' || c == 'N' \
	|| c == 'S' || c == 'E' || c == 'W' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	is_player_character(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	get_orientation(char c)
{
	if (c == 'N')
		return (N);
	else if (c == 'S')
		return (S);
	else if (c == 'E')
		return (E);
	else if (c == 'W')
		return (W);
}

int	checks(char **lines, t_map *raw_map, int i, int j)
{
	if (!is_map_character(lines[i][j]))
		return (1);
	else if (is_player_character(lines[i][j]))
	{
		if (!raw_map->player_orientation)
		{
			raw_map->player_position = (t_point) \
			{j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2};
			raw_map->player_orientation = get_orientation(lines[i][j]);
		}
		else
			return (1);
	}
	return (0);
}

int	check_map_characters(t_map *raw_map, char **lines)
{
	int	i;
	int	j;

	i = -1;
	while (lines[++i])
	{
		j = -1;
		while (lines[i][++j])
		{
			if (checks(lines, raw_map, i, j))
				return (1);
		}
	}
	if (!raw_map->player_orientation)
		return (1);
	return (0);
}
