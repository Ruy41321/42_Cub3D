/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resizing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:31:03 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:14:03 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	on_2d_resize(t_c3d *c3d)
{
	mlx_destroy_image(c3d->mlx_connection, c3d->map.img);
	create_visualize_2d_map_img(c3d);
	return (0);
}

int	on_3d_resize(t_c3d *c3d)
{
	mlx_destroy_image(c3d->mlx_connection, c3d->scene_3d.img);
	draw_3d_scene(c3d);
	return (0);
}
