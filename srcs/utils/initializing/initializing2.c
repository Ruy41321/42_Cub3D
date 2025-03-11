/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:17:10 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:28:26 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	initialize_win(t_win *win)
{
	win->dimension.h = 0;
	win->dimension.w = 0;
	win->mlx_win = NULL;
}

void	point_init(t_point *point_to_initialize)
{
	point_to_initialize->x = 0;
	point_to_initialize->y = 0;
}
