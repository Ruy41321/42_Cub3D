/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:43:52 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:43:53 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

#define MAP_PATH 1
#define WIDTH 2
#define HEIGHT 3
#define FACTOR 50

#include <stdlib.h>

void	parse_parameters(int argc, char **argv)
{
	if (argc != 2)
		error_exit(NULL, INVALID_PARAMS);
}

/*mlx_hook ha come secondo parametro il codice evento.
	il codice evento è un numero. Questo numero indica che tipologia
	di evento mlx:hook deve ascolatre.
	Ad esempio il numero 2 indica che ora mlx_hook è in ascolto su eventi
	di pressione della tastiera
	Inece ad esempio il codice 3 indica che mlx_hook è in ascolto su event
	di rilascio dei tasti della tastiera
	*/
void	set_hook_and_loop(t_c3d *c3d)
{
	mlx_hook(c3d->win_3d.mlx_win, KeyPress, \
	KeyPressMask, &mov_key_press, c3d);
	mlx_hook(c3d->win_3d.mlx_win, KeyRelease, \
	KeyReleaseMask, &mov_key_release, c3d);
	mlx_hook(c3d->win_3d.mlx_win, DestroyNotify, \
	StructureNotifyMask, &on_destroy, c3d);
	mlx_hook(c3d->win_3d.mlx_win, ResizeRequest, \
	ResizeRedirectMask, &on_3d_resize, c3d);
	if (SHOW_2D)
	{
		mlx_hook(c3d->win_2d.mlx_win, KeyPress, \
		KeyPressMask, &mov_key_press, c3d);
		mlx_hook(c3d->win_2d.mlx_win, KeyRelease, \
		KeyReleaseMask, &mov_key_release, c3d);
		mlx_hook(c3d->win_2d.mlx_win, DestroyNotify, \
		StructureNotifyMask, &on_destroy, c3d);
		mlx_hook(c3d->win_2d.mlx_win, ResizeRequest, \
		ResizeRedirectMask, &on_2d_resize, c3d);
	}
	mlx_loop_hook(c3d->mlx_connection, update_movement, c3d);
	mlx_loop(c3d->mlx_connection);
}

int	main(int argc, char **argv)
{
	t_c3d	c3d;

	parse_parameters(argc, argv);
	initialization(&c3d);
	build_map(argv[MAP_PATH], &c3d);
	set_connection_and_windows(&c3d);
	set_texture(&c3d);
	if (SHOW_2D)
		create_visualize_2d_map_img(&c3d);
	draw_3d_scene(&c3d);
	set_hook_and_loop(&c3d);
	return (0);
}
