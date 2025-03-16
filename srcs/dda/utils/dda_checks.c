/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:18:50 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/15 17:23:14 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static int	check_ne(char **map_grid, double card_dir, t_point p)
{
	int		h;
	int		w;

	h = ft_strlen(map_grid[0]);
	w = ft_arrlen(map_grid);
	if (card_dir == NE)
	{
		if ((int)p.y / TILE_SIZE >= w || ((int)p.x - 1) / TILE_SIZE >= h \
		|| ((int)p.y + 1) / TILE_SIZE >= w || (int)p.x / TILE_SIZE >= h)
			return (FALSE);
		if (map_grid[(int)p.y / TILE_SIZE][((int)p.x - 1) / TILE_SIZE] == '1' \
		&& map_grid[((int)p.y + 1) / TILE_SIZE][(int)p.x / TILE_SIZE] == '1')
		{
			p.x = p.x - 1;
			p.y = p.y + 1;
			return (TRUE);
		}
	}
	return (FALSE);
}

static int	check_nw(char **map_grid, double card_dir, t_point p)
{
	int		h;
	int		w;

	h = ft_strlen(map_grid[0]);
	w = ft_arrlen(map_grid);
	if (card_dir == NW)
	{
		if ((int)p.y / TILE_SIZE >= w || ((int)p.x + 1) / TILE_SIZE >= h \
		|| ((int)p.y + 1) / TILE_SIZE >= w || (int)p.x / TILE_SIZE >= h)
			return (FALSE);
		if (map_grid[(int)p.y / TILE_SIZE][((int)p.x + 1) / TILE_SIZE] == '1' \
		&& map_grid[((int)p.y + 1) / TILE_SIZE][(int)p.x / TILE_SIZE] == '1')
		{
			p.x = p.x - 1;
			p.y = p.y + 1;
			return (TRUE);
		}
	}
	return (FALSE);
}

static int	check_se(char **map_grid, double card_dir, t_point p)
{
	int		h;
	int		w;

	h = ft_strlen(map_grid[0]);
	w = ft_arrlen(map_grid);
	if (card_dir == SE)
	{
		if ((int)p.y / TILE_SIZE >= w || ((int)p.x - 1) / TILE_SIZE >= h \
		|| ((int)p.y - 1) / TILE_SIZE >= w || (int)p.x / TILE_SIZE >= h)
			return (FALSE);
		if (map_grid[(int)p.y / TILE_SIZE][((int)p.x - 1) / TILE_SIZE] == '1' \
		&& map_grid[((int)p.y - 1) / TILE_SIZE][(int)p.x / TILE_SIZE] == '1')
		{
			p.x = p.x - 1;
			p.y = p.y + 1;
			return (TRUE);
		}
	}
	return (FALSE);
}

static int	check_sw(char **map_grid, double card_dir, t_point p)
{
	int		h;
	int		w;

	h = ft_strlen(map_grid[0]);
	w = ft_arrlen(map_grid);
	if (card_dir == SW)
	{
		if ((int)p.y / TILE_SIZE >= w || ((int)p.x + 1) / TILE_SIZE >= h \
		|| ((int)p.y - 1) / TILE_SIZE >= w || (int)p.x / TILE_SIZE >= h)
			return (FALSE);
		if (map_grid[(int)p.y / TILE_SIZE][((int)p.x + 1) / TILE_SIZE] == '1' \
		&& map_grid[((int)p.y - 1) / TILE_SIZE][(int)p.x / TILE_SIZE] == '1')
		{
			p.x = p.x - 1;
			p.y = p.y + 1;
			return (TRUE);
		}
	}
	return (FALSE);
}

int	is_it_passing_between_two_walls(t_ray *ray, char **map_grid, t_point p)
{
	double	direction;

	direction = ray->cardinal_direction;
	if (check_ne(map_grid, direction, p))
		return (TRUE);
	else if (check_se(map_grid, direction, p))
		return (TRUE);
	else if (check_nw(map_grid, direction, p))
		return (TRUE);
	else if (check_sw(map_grid, direction, p))
		return (TRUE);
	return (FALSE);
}
