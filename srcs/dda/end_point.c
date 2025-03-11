/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:45:09 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/03 11:06:55 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

t_point	adjust_end_point_x(t_point end_point, \
	t_ray *ray, double alpha, t_c3d *c3d)
{
	int		start;
	double	remind;

	start = ((int)(end_point.x / TILE_SIZE)) * TILE_SIZE;
	remind = fabs(start - end_point.x);
	if (remind == 63 || remind == 0)
	{
		c3d->player.ray.last_increment = INCREMENT_Y;
		end_point = trigonometric_point_calc(ray->first_point, \
			ray->path.y, alpha);
	}
	return (end_point);
}

t_point	adjust_end_point_y(t_point end_point, \
	t_ray *ray, double alpha, t_c3d *c3d)
{
	int		start;
	double	remind;

	start = ((int)(end_point.y / TILE_SIZE)) * TILE_SIZE;
	remind = fabs(start - end_point.y);
	if (remind == 0 || remind == 63)
	{
		c3d->player.ray.last_increment = INCREMENT_X;
		end_point = trigonometric_point_calc(ray->first_point, \
			ray->path.x, alpha);
	}
	return (end_point);
}

t_point	calculate_end_point_x(t_ray *ray, double alpha, t_c3d *c3d)
{
	t_point	end_point;
	t_point	n_normalized_ep;
	int		y;
	int		x;

	end_point = trigonometric_point_calc(ray->first_point, ray->path.x, alpha);
	n_normalized_ep.x = end_point.x - 35;
	n_normalized_ep.y = end_point.y - 35;
	y = (int)n_normalized_ep.y / TILE_SIZE;
	x = (int)n_normalized_ep.x / TILE_SIZE;
	if (is_it_a_wall(end_point, c3d->raw_map.grid))
	{
		if (north(x, y, c3d) && !north(x, y + 1, c3d) && !n_corner(x, y, c3d) \
		&& !north(x + 1, y + 1, c3d))
		{
			end_point = adjust_end_point_x(end_point, ray, alpha, c3d);
		}
	}
	return (end_point);
}

t_point	calculate_end_point_y(t_ray *ray, double alpha, t_c3d *c3d)
{
	t_point	end_point;
	t_point	n_normalized_ep;
	t_point	xy;

	end_point = trigonometric_point_calc(ray->first_point, ray->path.y, alpha);
	n_normalized_ep.x = end_point.x - 35;
	n_normalized_ep.y = end_point.y - 35;
	xy.y = (int)n_normalized_ep.y / TILE_SIZE;
	xy.x = (int)n_normalized_ep.x / TILE_SIZE;
	if (is_it_a_wall(end_point, c3d->raw_map.grid))
	{
		if (west(xy.x, xy.y, c3d) && !west(xy.x + 1, xy.y, c3d) \
		&& !n_corner(xy.x, xy.y, c3d) && !west(xy.x + 1, xy.y + 1, c3d))
			end_point = adjust_end_point_y(end_point, ray, alpha, c3d);
	}
	return (end_point);
}

t_point	calculate_end_point(t_ray *ray, double alpha, t_c3d *c3d)
{
	if (fabs(ray->path.x) < fabs(ray->path.y))
	{
		c3d->player.ray.last_increment = INCREMENT_X;
		return (calculate_end_point_x(ray, alpha, c3d));
	}
	else
	{
		c3d->player.ray.last_increment = INCREMENT_Y;
		return (calculate_end_point_y(ray, alpha, c3d));
	}
}
