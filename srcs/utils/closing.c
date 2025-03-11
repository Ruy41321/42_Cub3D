/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:31:51 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/03 17:36:56 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	free_raw_map(t_c3d *c3d)
{
	if (c3d->raw_map.texture_data)
		free(c3d->raw_map.texture_data);
	if (c3d->raw_map.map_data)
		free(c3d->raw_map.map_data);
	if (c3d->raw_map.grid)
		ft_free_matrix(c3d->raw_map.grid, -1);
	if (c3d->raw_map.no_texture)
		free(c3d->raw_map.no_texture);
	if (c3d->raw_map.so_texture)
		free(c3d->raw_map.so_texture);
	if (c3d->raw_map.we_texture)
		free(c3d->raw_map.we_texture);
	if (c3d->raw_map.ea_texture)
		free(c3d->raw_map.ea_texture);
	if (c3d->raw_map.f_color)
		free(c3d->raw_map.f_color);
	if (c3d->raw_map.c_color)
		free(c3d->raw_map.c_color);
	if (c3d->map_lines)
		ft_free_matrix(c3d->map_lines, -1);
}

int	on_destroy(t_c3d *c3d)
{
	free_raw_map(c3d);
	if (c3d->win_3d.mlx_win)
		mlx_destroy_window(c3d->mlx_connection, c3d->win_3d.mlx_win);
	if (c3d->win_2d.mlx_win)
		mlx_destroy_window(c3d->mlx_connection, c3d->win_2d.mlx_win);
	if (c3d->mlx_connection)
	{
		if (c3d->map.img)
			mlx_destroy_image(c3d->mlx_connection, c3d->map.img);
		if (c3d->scene_3d.img)
			mlx_destroy_image(c3d->mlx_connection, c3d->scene_3d.img);
		if (c3d->texture[0].img)
			mlx_destroy_image(c3d->mlx_connection, c3d->texture[0].img);
		if (c3d->texture[1].img)
			mlx_destroy_image(c3d->mlx_connection, c3d->texture[1].img);
		if (c3d->texture[2].img)
			mlx_destroy_image(c3d->mlx_connection, c3d->texture[2].img);
		if (c3d->texture[3].img)
			mlx_destroy_image(c3d->mlx_connection, c3d->texture[3].img);
		mlx_destroy_display(c3d->mlx_connection);
		free(c3d->mlx_connection);
	}
	return (exit(0), 0);
}

void	error_exit(t_c3d *c3d, char *message)
{
	printf("%s\n", message);
	on_destroy(c3d);
}
