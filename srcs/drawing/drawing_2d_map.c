/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_2d_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:47:53 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 15:27:09 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	draw_tile_with_marg(t_img *img, t_point xy, int color)
{
	int	x_value;
	int	y_value;

	x_value = xy.x;
	y_value = xy.y;
	while (xy.y < y_value + TILE_SIZE)
	{
		xy.x = x_value;
		while (xy.x < x_value + TILE_SIZE)
		{
			if (xy.y == y_value + TILE_SIZE - 1)
				put_pixel(img, xy.x, xy.y, BLACK);
			else if (xy.x == x_value + TILE_SIZE - 1)
				put_pixel(img, xy.x, xy.y, BLACK);
			else
				put_pixel(img, xy.x, xy.y, color);
			xy.x++;
		}
		xy.y++;
	}
}

/*questa funzione stampa il confie destro e sinistro del FOV! Punto!*/
void	draw_2d_fov_boundaries(t_c3d *c3d)
{
	t_point	end_point;
	t_ray	ray;

	point_init(&end_point);
	ray = dda(c3d->player.position, c3d->player.fov.half_left, c3d);
	end_point = ray.end_point;
	bresenham(c3d, end_point.x, end_point.y, RED);
	ray = dda(c3d->player.position, c3d->player.fov.half_right, c3d);
	end_point = ray.end_point;
	bresenham(c3d, end_point.x, end_point.y, RED);
}

/*
commentata per lavorare su un'altra cosi 
da non modificare questa che funziona
*/
void	draw_2d_map(t_img *img, t_c3d *c3d)
{
	int		x;
	int		y;
	t_point	xy;

	y = -1;
	while (++y < 0 + c3d->raw_map.dimension.h)
	{
		x = -1;
		while (++x < 0 + c3d->raw_map.dimension.w)
		{
			xy.x = x * TILE_SIZE;
			xy.y = y * TILE_SIZE;
			if (x >= ft_strlen(c3d->raw_map.grid[y]))
				draw_tile_with_marg(img, xy, BLACK);
			else if (c3d->raw_map.grid[y][x] == '1')
				draw_tile_with_marg(img, xy, GRAY);
			else if (c3d->raw_map.grid[y][x] == '0')
				draw_tile_with_marg(img, xy, WHITE);
			else if (c3d->raw_map.grid[y][x] == ' ')
				draw_tile_with_marg(img, xy, BLACK);
			else
				draw_tile_with_marg(img, xy, RED);
		}
	}
}

void	create_visualize_2d_map_img(t_c3d *c3d)
{
	c3d->map.img = mlx_new_image(c3d->mlx_connection, \
	c3d->raw_map.dimension.w * TILE_SIZE, \
	c3d->raw_map.dimension.h * TILE_SIZE);
	c3d->map.data_addr = mlx_get_data_addr(c3d->map.img, \
	&c3d->map.bits_per_pixel, &c3d->map.size_line, &c3d->map.endian);
	draw_2d_map(&c3d->map, c3d);
	draw_player_in_img(c3d);
	mlx_put_image_to_window(c3d->mlx_connection, c3d->win_2d.mlx_win, \
	c3d->map.img, 0, 0);
	draw_2d_fov_boundaries(c3d);
}

void	drawing_routine(t_c3d *c3d)
{
	if (SHOW_2D)
	{
		mlx_destroy_image(c3d->mlx_connection, c3d->map.img);
		create_visualize_2d_map_img(c3d);
	}
	mlx_destroy_image(c3d->mlx_connection, c3d->scene_3d.img);
	draw_3d_scene(c3d);
}
