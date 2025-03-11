/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_path_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:48:58 by lpennisi          #+#    #+#             */
/*   Updated: 2024/12/07 18:13:21 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

double	calc_x(t_point first_point, t_point second_point, int direction)
{
	double	delta_x;

	delta_x = 0;
	if (direction == E || direction == 0 \
	|| direction == NE || direction == SE)
		delta_x = fabs(second_point.x - first_point.x);
	else
		delta_x = fabs(second_point.x - first_point.x - 1);
	return (delta_x);
}

double	calc_y(t_point first_point, t_point second_point, int direction)
{
	double	delta_y;

	if (direction == N || direction == NE || direction == NW)
		delta_y = fabs(first_point.y - second_point.y + 1);
	else
		delta_y = fabs(first_point.y - second_point.y);
	return (delta_y);
}

t_point	calc_delta(t_point first_point, t_point second_point, int direction)
{
	t_point	delta;

	delta.x = 0;
	delta.y = 0;
	delta.x = calc_x(first_point, second_point, direction);
	delta.y = calc_y(first_point, second_point, direction);
	return (delta);
}

t_point	calculate_path(t_point delta, double alpha)
{
	t_point	path;

	path.x = 0;
	path.y = 0;
	if (fabs(alpha - M_PI / 2) < EPSILON || \
	fabs(alpha - 3 * M_PI / 2) < EPSILON)
		path.x = fabs(delta.y / sin(alpha));
	else
		path.x = fabs(delta.x / cos(alpha));
	if (fabs(alpha - M_PI) < EPSILON || \
	fabs(alpha - 2 * M_PI) < EPSILON || fabs(alpha) < EPSILON)
		path.y = fabs(delta.x / cos(alpha));
	else
		path.y = fabs(delta.y / sin(alpha));
	return (path);
}

t_point	trigonometric_point_calc(t_point point, double path, double alpha)
{
	t_point	point_to_return;

	point_to_return.x = 0;
	point_to_return.y = 0;
	point_to_return.x = point.x + (fabs(path) * cos(alpha));
	point_to_return.y = point.y + (fabs(path) * sin(alpha));
	return (point_to_return);
}
