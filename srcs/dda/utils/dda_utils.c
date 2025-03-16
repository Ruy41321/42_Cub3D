/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:18:24 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/15 17:15:32 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

double	pitagora_theorem(t_point first_point, t_point second_point)
{
	double	result;
	double	dx;
	double	dy;

	dx = first_point.x - second_point.x;
	dy = first_point.y - second_point.y;
	result = sqrt(pow(dx, 2) + pow(dy, 2));
	return (result);
}

t_point	find_intersection(t_point p1, double p1_ang, t_point p2, double p2_ang)
{
	t_point	intersection;
	double	c1;
	double	c2;
	double	m1;
	double	m2;

	point_init(&intersection);
	if (cos(p1_ang) <= PI_FIX && cos(p1_ang) >= -PI_FIX)
		p1_ang += PI_FIX;
	if (cos(p2_ang) <= PI_FIX && cos(p2_ang) >= -PI_FIX)
		p2_ang += PI_FIX;
	m1 = tan(p1_ang);
	m2 = tan(p2_ang);
	c1 = p1.y - (m1 * p1.x);
	c2 = p2.y - (m2 * p2.x);
	intersection.x = (c2 - c1) / (m1 - m2);
	intersection.y = (m1 * intersection.x) + c1;
	return (intersection);
}

int	is_it_a_wall(t_point point_to_verify, char **map_grid)
{
	int	map_height;
	int	map_width;

	map_width = ft_strlen(map_grid[0]);
	map_height = ft_arrlen(map_grid);
	if (point_to_verify.x / TILE_SIZE >= map_width || \
	point_to_verify.y / TILE_SIZE >= map_height)
		return (FALSE);
	if (map_grid[(int)point_to_verify.y / TILE_SIZE][\
	(int)point_to_verify.x / TILE_SIZE] == '1')
		return (TRUE);
	return (FALSE);
}

int	is_it_inside_map_perimeter(t_point point, t_dimension map_dimension)
{
	if (point.x >= TILE_SIZE && \
	point.x < (map_dimension.w * TILE_SIZE - TILE_SIZE) && \
	point.y >= TILE_SIZE && \
	point.y < (map_dimension.h * TILE_SIZE) - TILE_SIZE)
		return (TRUE);
	return (FALSE);
}
