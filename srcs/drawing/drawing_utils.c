/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:30 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:12:50 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

/*questa funzione va a posizionare il puntatore all'inizio di un colore.
lo casta poi ad int.
in questo modo veranno letto i 4 byte consecutivi come un singolo valore intero
che rappresenterà il colore.
siccome parliamo di byte e codice bianrio avrai un'area di emroia
10010111000110100101010100 tutta sta roe è il colore.
ricordati che ogni elemento del charone è una componente
del colore: 8 bits = 1 byte. quindi tu qui avanzi di 4 byte in 4 byte
(0vvero 8 bits * 4 in 8bits * 4)
*/
int	get_pixel(t_img *img, int x, int y)
{
	int	*pixel;

	if (x < 0 || x > img->img_dimension.w || y < 0 || y > img->img_dimension.h)
		return (RED);
	pixel = (int *)(img->data_addr + \
	(y * img->size_line + x * (img->bits_per_pixel / 8)));
	return (*pixel);
}

/*put_pixel() parte dalla constatazione che dispongo di un
char * (un array di char, che rappresenta il mio data_Addr della
immagine, in cui sono custoditi i colori).
Sappiamo che i colori sono tuttavia degli int.
Pertanto put_pixel() casta il charone ad array di int (int *).
poi dereferenzia lo stesso per l'assrgnazione del colore, di volta in volta*/
void	put_pixel(t_img *img, int x, int y, int color)
{
	int	*pixel;

	if (y < 0 || x < 0)
		return ;
	pixel = (int *)(img->data_addr + \
	(y * img->size_line + x * (img->bits_per_pixel / 8)));
	*pixel = color;
}

void	set_step(t_bras_params *params, int x1, int y1)
{
	if (params->xy0.x < x1)
		params->sx.x = 1;
	else
		params->sx.x = -1;
	if (params->xy0.y < y1)
		params->sx.y = 1;
	else
		params->sx.y = -1;
}

void	draw_bras_line(t_c3d *c3d, t_bras_params *p, int x1, int y1)
{
	int	err;
	int	e2;

	err = p->dx.x - p->dx.y;
	while (1)
	{
		mlx_pixel_put(c3d->mlx_connection, c3d->win_2d.mlx_win, \
		p->xy0.x, p->xy0.y, p->color);
		if (p->xy0.x == x1 && p->xy0.y == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -(p->dx.y))
		{
			err -= p->dx.y;
			p->xy0.x += p->sx.x;
		}
		if (e2 < p->dx.x)
		{
			err += p->dx.x;
			p->xy0.y += p->sx.y;
		}
	}
}

void	bresenham(t_c3d *c3d, int x1, int y1, int color)
{
	t_bras_params	params;

	params.xy0.x = c3d->player.position.x;
	params.xy0.y = c3d->player.position.y;
	params.dx.x = fabs(x1 - params.xy0.x);
	params.dx.y = fabs(y1 - params.xy0.y);
	params.color = color;
	set_step(&params, x1, y1);
	draw_bras_line(c3d, &params, x1, y1);
}
