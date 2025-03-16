/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:38:08 by lpennisi          #+#    #+#             */
/*   Updated: 2025/03/03 10:43:32 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	get_oriented_texture_color(int orientation)
{
	if (orientation == N)
		return (RED);
	else if (orientation == S)
		return (GREEN);
	else if (orientation == W)
		return (PINK);
	else
		return (YELLOW);
}

int	get_orientation_id(int orientation)
{
	if (orientation == N)
		return (0);
	else if (orientation == S)
		return (1);
	else if (orientation == W)
		return (2);
	else
		return (3);
}

/*la seguente funzione:ha l'obiettivo di intercettare 
i colori della striscie di pixl della texture...
e riportarli sulla striscia della rappresentazione 3D.
In particolare va a prendere la corrispettiva striscia verticale su una texture.
quando hai questa strisica verticale in pratica hai i colori appuntodi 
quella stricia verticale.
Ebbene questi colori puoi ora usarli uno ad uno man mano che sali lungo 
la striscia vericale da 
disegnare nella finestra 3d.*/
static void	set_pixels(int x_texture, t_c3d *c3d, t_ray ray)
{
	int		y_texture;
	int		color;
	double	max_iteration;
	double	y;
	double	y_min;

	y = c3d->win_2d.dimension.h / 2 - \
	(c3d->player.ray.view3d.height_wall_line / 2);
	y_min = y;
	max_iteration = y + c3d->player.ray.view3d.height_wall_line;
	if (y < 0)
		y = 0;
	while (y < max_iteration && y < c3d->win_2d.dimension.h)
	{
		y_texture = (c3d->texture[get_orientation_id(ray.orientation)].\
		img_dimension.h * (y - y_min)) / \
		c3d->player.ray.view3d.height_wall_line;
		if (SHOW_WITH_COLORS)
			color = get_oriented_texture_color(ray.orientation);
		else
			color = get_pixel(&c3d->texture[\
				get_orientation_id(ray.orientation)], x_texture, y_texture);
		put_pixel(&c3d->scene_3d, c3d->player.ray.view3d.x_wall_line, y, color);
		y++;
	}
}

/*objective: visualiza all you can see in 3D Window.
This functions wrap-up different functions IOT 
print ne vertical line in the 3D win.*/
void	draw_3d_vertical_line(t_c3d *c3d, t_ray ray, double saved_left_half_fov)
{
	int		x_text;
	t_point	end_point;

	end_point = ray.end_point;
	c3d->player.ray.projection.point = find_intersection(c3d->player.position, \
	c3d->player.perpendicular_direction, end_point, c3d->player.direction);
	c3d->player.ray.view3d.x_wall_line = find_x_3d(c3d->player.fov.half_left, \
	saved_left_half_fov, c3d->win_3d.dimension.w);
	x_text = find_x_texture(end_point, c3d->player.ray);
	c3d->player.ray.projection.length = pitagora_theorem(end_point, \
	c3d->player.ray.projection.point);
	c3d->player.ray.view3d.height_wall_line = \
	calculate_3d_wall_height(c3d->player);
	set_pixels(x_text, c3d, ray);
}

/*itero dal confine sinistro del fov al confine destro.
cosi facendo vado a prendere di vola in volta, in ogni iterazione, 
il punto di ipatto calcolato con il dda.
questo punto di impatto lo passo (sempre nell'ambito di quella iterazione)
alla funzione visualize_3d*/
void	draw_3d_fov(t_c3d *c3d)
{
	double	angle_variation;
	t_ray	ray;
	double	saved_left_half_fov;

	saved_left_half_fov = c3d->player.fov.half_left;
	angle_variation = FOV_ANGLE / NUM_OF_RAYS;
	while (c3d->player.fov.half_left < c3d->player.fov.half_right)
	{
		ray = dda(c3d->player.position, c3d->player.fov.half_left, c3d);
		if (SHOW_2D)
			bresenham(c3d, ray.end_point.x, ray.end_point.y, PINK);
		draw_3d_vertical_line(c3d, ray, saved_left_half_fov);
		c3d->player.fov.half_left += angle_variation;
	}
}
