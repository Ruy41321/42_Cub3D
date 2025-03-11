/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:34:10 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:41:29 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

/*a differenza delle funzioni di mlx che agiscono sulle immagini,
    quelle che agiscono sulle texture impostano in automatico
    le dimensioni delle immagini (ovvero delle immagini
    che saranno associate alle texture. 
    Questo significa che non dovrai impostare tu le dimensioni.
*/
void	set_texture(t_c3d *c3d)
{
	c3d->texture[0].img = mlx_xpm_file_to_image(c3d->mlx_connection, \
	c3d->raw_map.no_texture, &c3d->texture[0].img_dimension.w, \
	&c3d->texture[0].img_dimension.h);
	c3d->texture[0].data_addr = mlx_get_data_addr(c3d->texture[0].img, \
	&c3d->texture[0].bits_per_pixel, &c3d->texture[0].size_line, \
	&c3d->texture[0].endian);
	c3d->texture[1].img = mlx_xpm_file_to_image(c3d->mlx_connection, \
	c3d->raw_map.so_texture, &c3d->texture[1].img_dimension.w, \
	&c3d->texture[1].img_dimension.h);
	c3d->texture[1].data_addr = mlx_get_data_addr(c3d->texture[1].img, \
	&c3d->texture[1].bits_per_pixel, &c3d->texture[1].size_line, \
	&c3d->texture[1].endian);
	c3d->texture[2].img = mlx_xpm_file_to_image(c3d->mlx_connection, \
	c3d->raw_map.we_texture, &c3d->texture[2].img_dimension.w, \
	&c3d->texture[2].img_dimension.h);
	c3d->texture[2].data_addr = mlx_get_data_addr(c3d->texture[2].img, \
	&c3d->texture[2].bits_per_pixel, &c3d->texture[2].size_line, \
	&c3d->texture[2].endian);
	c3d->texture[3].img = mlx_xpm_file_to_image(c3d->mlx_connection, \
	c3d->raw_map.ea_texture, &c3d->texture[3].img_dimension.w, \
	&c3d->texture[3].img_dimension.h);
	c3d->texture[3].data_addr = mlx_get_data_addr(c3d->texture[3].img, \
	&c3d->texture[3].bits_per_pixel, &c3d->texture[3].size_line, \
	&c3d->texture[3].endian);
}

static void	set_win_dimensions(t_win *win_2d, t_win *win_3d, t_dimension map_f)
{
	win_2d->dimension.w = TILE_SIZE * map_f.w;
	win_2d->dimension.h = TILE_SIZE * map_f.h;
	win_3d->dimension.w = TILE_SIZE * map_f.w;
	win_3d->dimension.h = TILE_SIZE * map_f.h;
	if (win_2d->dimension.w > 1000)
		win_2d->dimension.w = 1000;
	if (win_2d->dimension.h > 1000)
		win_2d->dimension.h = 1000;
	if (win_3d->dimension.w > 1000)
		win_3d->dimension.w = 1000;
	if (win_3d->dimension.h > 1000)
		win_3d->dimension.h = 1000;
}

void	set_connection_and_windows(t_c3d *c3d)
{
	set_win_dimensions(&c3d->win_2d, &c3d->win_3d, c3d->raw_map.dimension);
	c3d->mlx_connection = mlx_init();
	if (SHOW_2D)
		c3d->win_2d.mlx_win = mlx_new_window(c3d->mlx_connection, \
		c3d->win_2d.dimension.w, c3d->win_2d.dimension.h, "cub3d_2d");
	c3d->win_3d.mlx_win = mlx_new_window(c3d->mlx_connection, \
	c3d->win_3d.dimension.w, c3d->win_3d.dimension.h, "cub3d_3d");
}

void	set_player_orientation(t_c3d *c3d)
{
	if (c3d->raw_map.player_orientation == N)
		c3d->player.direction = 3 * M_PI / 2;
	else if (c3d->raw_map.player_orientation == E)
		c3d->player.direction = 0;
	else if (c3d->raw_map.player_orientation == S)
		c3d->player.direction = M_PI / 2;
	else if (c3d->raw_map.player_orientation == W)
		c3d->player.direction = M_PI;
	c3d->player.perpendicular_direction = c3d->player.direction - (M_PI / 2);
	c3d->player.fov.half_left = c3d->player.direction - (FOV_ANGLE / 2);
	c3d->player.fov.half_right = c3d->player.direction + (FOV_ANGLE / 2);
}
