/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:30:02 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:30:45 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

double	find_x_3d(double ray_angle, double fov_left_ray, double win_width)
{
	double	x_3d;
	double	angular_fov_percentage;
	double	win_width_angle_proportion;

	angular_fov_percentage = (ray_angle - fov_left_ray) / FOV_ANGLE;
	win_width_angle_proportion = angular_fov_percentage * win_width;
	x_3d = win_width_angle_proportion;
	return (x_3d);
}

double	calculate_3d_wall_height(t_player player)
{
	double	line_height;

	line_height = ((SCALE_FACTOR) / player.ray.projection.length);
	line_height *= (1 - line_height * 0.0001);
	return (line_height);
}

/*attenzione ora non sto guardando alla x_3d,
non sto calcolando quella x sul piano orizzontale dello schermo corrispondente
alla variazione angolare del ray.
qui sto calcolando la x all'interno della texture...ovvero quella x da cui
risalire lungo lìaltezza della texture da riportare nell'ambiente 3d.
quindi dato un certo punto di impatto...avrò una x...vedo in che cella ricade
vedo quindi a che distanza dall'inizio di quella cella la x si trova, e tento
di riprodurre quella distanza a apartire dall'inizio della texture.
una volta posizionatomi sulla giu
sta x nella textur avrò poi una funzione che mi sale lungo 
quella x...ovvero stessa x ma y diverse....*/
int	find_x_texture(t_point impact_point, t_ray ray)
{
	t_point	tile_point;
	int		x_texture;

	x_texture = 0;
	tile_point = tile_reference(impact_point);
	if (ray.last_increment == INCREMENT_Y)
		x_texture = (impact_point.x - (tile_point.x * TILE_SIZE));
	else
		x_texture = (impact_point.y - (tile_point.y * TILE_SIZE));
	return (x_texture);
}
