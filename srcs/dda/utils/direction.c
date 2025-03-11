/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:11:56 by lpennisi          #+#    #+#             */
/*   Updated: 2024/12/07 18:12:05 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	angle_normalization(double *angle)
{
	while (*angle < 0)
		*angle = *angle + 2 * M_PI;
	while (*angle >= 2 * M_PI)
		*angle = *angle - 2 * M_PI;
}

int	get_cardinal_direction(double angle)
{
	int	cardinal_direction;

	angle_normalization(&angle);
	cardinal_direction = BLACK;
	if (fabs(angle - 0) < EPSILON || fabs(angle - 2 * M_PI) < EPSILON)
		cardinal_direction = E;
	else if (fabs(angle - M_PI) < EPSILON)
		cardinal_direction = W;
	else if (fabs(angle - M_PI / 2) < EPSILON)
		cardinal_direction = S;
	else if (fabs(angle - (3 * M_PI) / 2) < EPSILON)
		cardinal_direction = N;
	else if (angle > 0 && angle < M_PI / 2)
		cardinal_direction = SE;
	else if (angle > M_PI / 2 && angle < M_PI)
		cardinal_direction = SW;
	else if (angle > M_PI && angle < (3 * M_PI) / 2)
		cardinal_direction = NW;
	else if (angle > (3 * M_PI) / 2 && angle < 2 * M_PI)
		cardinal_direction = NE;
	return (cardinal_direction);
}
