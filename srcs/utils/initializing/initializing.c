/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:18:05 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/03 17:39:40 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	inizialize_map_fm_file(t_map *map)
{
	map->texture_data = NULL;
	map->map_data = NULL;
	map->dimension.h = 0;
	map->dimension.w = 0;
	map->grid = NULL;
	map->player_orientation = 0;
	map->player_position = (t_point){0, 0};
	map->no_texture = 0;
	map->so_texture = 0;
	map->we_texture = 0;
	map->ea_texture = 0;
	map->f_color = 0;
	map->c_color = 0;
}

void	initialize_player(t_player *player)
{
	player->direction = 0;
	player->perpendicular_direction = 0;
	player->position.x = 0;
	player->position.y = 0;
	player->move.w = 0;
	player->move.a = 0;
	player->move.s = 0;
	player->move.d = 0;
	player->rotate_alpha_right = 0;
	player->rotate_alpha_left = 0;
	player->ray.cardinal_direction = 0;
	player->ray.first_impact_point.x = 0;
	player->ray.first_impact_point.y = 0;
	player->ray.first_point.x = 0;
	player->ray.first_point.y = 0;
	player->ray.end_point.x = 0;
	player->ray.end_point.y = 0;
	player->fov.angle = FOV_ANGLE;
	player->fov.half_left = 0;
	player->fov.half_right = 0;
}

void	initialize_img(t_img *img)
{
	img->bits_per_pixel = 0;
	img->data_addr = NULL;
	img->endian = 0;
	img->img = NULL;
	img->img_dimension.w = 0;
	img->img_dimension.h = 0;
	img->size_line = 0;
}

void	initialize_ray(t_ray *ray)
{
	ray->cardinal_direction = 0;
	ray->first_side_point.x = 0;
	ray->first_side_point.y = 0;
	ray->first_impact_point.x = 0;
	ray->first_impact_point.y = 0;
	ray->delta.x = 0;
	ray->delta.y = 0;
	ray->path.x = 0;
	ray->path.y = 0;
	ray->first_point.x = 0;
	ray->first_point.y = 0;
	ray->end_point.x = 0;
	ray->end_point.y = 0;
	ray->projection.length = 0;
	ray->projection.point.x = 0;
	ray->projection.point.y = 0;
	ray->view3d.height_wall_line = 0;
	ray->view3d.x_wall_line = 0;
	ray->last_increment = 0;
}

void	initialization(t_c3d *c3d)
{
	initialize_img(&c3d->map);
	initialize_img(&c3d->texture[0]);
	initialize_img(&c3d->texture[1]);
	initialize_img(&c3d->texture[2]);
	initialize_img(&c3d->texture[3]);
	initialize_player(&c3d->player);
	initialize_win(&c3d->win_2d);
	initialize_win(&c3d->win_3d);
	inizialize_map_fm_file(&c3d->raw_map);
	c3d->mlx_connection = NULL;
	c3d->map_lines = NULL;
}
