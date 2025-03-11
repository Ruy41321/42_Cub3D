/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_point_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:01:30 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/03 11:03:20 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	n_corner(int x, int y, t_c3d *c3d)
{
	if (c3d->raw_map.grid[y][x + 1] == '0' \
		&& c3d->raw_map.grid[y + 1][x] == '0')
		return (1);
	return (0);
}

int	north(int x, int y, t_c3d *c3d)
{
	if (c3d->raw_map.grid[y][x] == '1')
		return (1);
	return (0);
}

int	west(int x, int y, t_c3d *c3d)
{
	if (c3d->raw_map.grid[y][x] == '1')
		return (1);
	return (0);
}
