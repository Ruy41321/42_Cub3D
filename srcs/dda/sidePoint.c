/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidePoint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:01:28 by lpennisi          #+#    #+#             */
/*   Updated: 2024/12/07 18:11:22 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static t_point	get_side_point_ne_e(t_point tile_ref)
{
	t_point	side_point;

	side_point.x = ((int)tile_ref.x + 1) * TILE_SIZE;
	side_point.y = (int)tile_ref.y * TILE_SIZE;
	return (side_point);
}

static t_point	get_side_point_nw_w_n(t_point tile_ref)
{
	t_point	side_point;

	side_point.x = (int)tile_ref.x * TILE_SIZE;
	side_point.y = (int)tile_ref.y * TILE_SIZE;
	return (side_point);
}

static t_point	get_side_point_se(t_point tile_ref)
{
	t_point	side_point;

	side_point.x = ((int)tile_ref.x + 1) * TILE_SIZE;
	side_point.y = ((int)tile_ref.y + 1) * TILE_SIZE;
	return (side_point);
}

static t_point	get_side_point_sw_s(t_point tile_ref)
{
	t_point	side_point;

	side_point.x = (int)tile_ref.x * TILE_SIZE;
	side_point.y = ((int)tile_ref.y + 1) * TILE_SIZE;
	return (side_point);
}

t_point	chose_side_point(t_point first_point, int cardinal_direction)
{
	t_point	tile_ref;

	tile_ref = tile_reference(first_point);
	if (cardinal_direction == NE || cardinal_direction == E \
	|| cardinal_direction == 0)
		return (get_side_point_ne_e(tile_ref));
	else if (cardinal_direction == NW || cardinal_direction == W \
	|| cardinal_direction == N)
		return (get_side_point_nw_w_n(tile_ref));
	else if (cardinal_direction == SE)
		return (get_side_point_se(tile_ref));
	else if (cardinal_direction == SW || cardinal_direction == S)
		return (get_side_point_sw_s(tile_ref));
	return ((t_point){0, 0});
}
