/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:16:06 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:16:34 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

t_point	get_circ_point(t_point player_next_position, double angle)
{
	t_point	circ_point;

	circ_point.x = 0;
	circ_point.y = 0;
	circ_point.x = player_next_position.x + RADIUS * cos(angle);
	circ_point.y = player_next_position.y + RADIUS * sin(angle);
	return (circ_point);
}

int	is_collision(double player_next_x, double player_next_y, t_c3d *c3d)
{
	t_point	player_next_position;
	t_point	circ_point;
	double	angle;
	int		loop;

	player_next_position.x = player_next_x;
	player_next_position.y = player_next_y;
	point_init(&circ_point);
	loop = 0;
	while (loop < CIRCUMFERENCE_CHECKS)
	{
		angle = 2 * M_PI * loop / CIRCUMFERENCE_CHECKS;
		circ_point = get_circ_point(player_next_position, angle);
		if (is_it_inside_map_perimeter(circ_point, c3d->raw_map.dimension))
		{
			if (is_it_a_wall(circ_point, c3d->raw_map.grid))
				return (TRUE);
		}
		else
			return (TRUE);
		loop++;
	}
	return (FALSE);
}
