/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:20:01 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/03 10:47:03 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	enstabilish_orient(t_ray *ray, int last_increment)
{
	int	ray_direction;

	ray_direction = ray->cardinal_direction;
	if (last_increment == INCREMENT_X)
	{
		if (ray_direction == NW || ray_direction == SW || ray_direction == W)
			ray->orientation = E;
		else
			ray->orientation = W;
	}
	else
	{
		if (ray_direction == NW || ray_direction == NE || ray_direction == N)
			ray->orientation = S;
		else
			ray->orientation = N;
	}
}

static int	check_wall_collision(t_ray *ray, t_c3d *c3d)
{
	if (is_it_passing_between_two_walls(ray, c3d->raw_map.grid, ray->end_point))
		return (TRUE);
	if (is_it_a_wall(ray->end_point, c3d->raw_map.grid))
		return (TRUE);
	return (FALSE);
}

t_ray	dda(t_point start_point, double alpha, t_c3d *c3d)
{
	t_ray	ray;

	initialize_ray(&ray);
	ray.cardinal_direction = get_cardinal_direction(alpha);
	ray.first_point = start_point;
	while (is_it_inside_map_perimeter(ray.first_point, c3d->raw_map.dimension))
	{
		ray.first_side_point = chose_side_point(ray.first_point, \
		ray.cardinal_direction);
		ray.delta = calc_delta(ray.first_point, \
		ray.first_side_point, ray.cardinal_direction);
		ray.path = calculate_path(ray.delta, alpha);
		ray.end_point = calculate_end_point(&ray, alpha, c3d);
		if (check_wall_collision(&ray, c3d))
			break ;
		ray.first_point = ray.end_point;
	}
	enstabilish_orient(&ray, c3d->player.ray.last_increment);
	return (ray);
}
