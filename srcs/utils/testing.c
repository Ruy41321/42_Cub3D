/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:35:54 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:36:24 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

/*questa funzione è inutilizzata...serve per scopi di testing.
se vuoi usarla la inserisc al posto di draw_3d_wall_height_with_textute_colors.
quindi va inserita nell'ambito di visualize_3d.
In ogni caso questa funione ha lo scopo di disegnare
le linee verticali nella mappa 3d.
ma adifferenza dell'altra funzione, non va a prendere
i colori dalla texture, bensi
più semplicemente colora ogni cosa di un solo colore, ad esempio
il colore rosso. Tutte le altezze disegnate nella mappa 3d quindi avrebbero
un solo colore.*/
void	draw_3d_wall_height_with_one_color(double x_3d, double h, t_c3d *c3d)
{
	double	y;
	double	tmp;

	y = 0;
	tmp = y + h;
	y = c3d->win_2d.dimension.w / 2 - (h / 2);
	while (y < tmp)
	{
		mlx_pixel_put(c3d->mlx_connection, c3d->win_3d.mlx_win, x_3d, y, RED);
		y++;
	}
}

/*if you know a point and an angle, you can determin
the line passing for that point
along that direction. You can use the linear equation of a line.
Indeed the angula coefficient
in the equation (m) is the tan(angle).
The linear equation is: y = mx + c
where c is the impact point on y axis.
*/
void	draw_line(t_point point, double angle, int color, t_c3d *c3d)
{
	double	m;
	double	c;

	m = tan(angle);
	c = point.y - (m * point.x);
	while (point.x < 10 * TILE_SIZE)
	{
		point.y = m * point.x + c;
		mlx_pixel_put(c3d->mlx_connection, c3d->win_2d.mlx_win, \
		point.x, point.y, color);
		point.x++;
	}
}
