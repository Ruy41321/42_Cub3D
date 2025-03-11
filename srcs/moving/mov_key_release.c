/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_key_release.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:20:39 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:20:40 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

/*this function manages the release of movement's player keycode
it is called by key_release which is the call-back function managed by mlx_hook
*/
static void	mov_key_release_position(int keycode, t_c3d *c3d)
{
	if (keycode == KEY_W)
		c3d->player.move.w = 0;
	if (keycode == KEY_S)
		c3d->player.move.s = 0;
	if (keycode == KEY_A)
		c3d->player.move.a = 0;
	if (keycode == KEY_D)
		c3d->player.move.d = 0;
}

/*this function manages the release of rotaionn of player's alpha direction
which is where the player is looking at in a particular moment.
it is called by key_release which is the call-back function managed by mlx_hook
*/
static void	mov_key_release_rotation(int keycode, t_c3d *c3d)
{
	if (keycode == ARROW_RIGHT)
		c3d->player.rotate_alpha_right = 0;
	if (keycode == ARROW_LEFT)
		c3d->player.rotate_alpha_left = 0;
}

/*this function has to be this sign becouse it is called in mlx_hook*/
int	mov_key_release(int keycode, void *param)
{
	t_c3d	*c3d;

	c3d = (t_c3d *)param;
	mov_key_release_position(keycode, c3d);
	mov_key_release_rotation(keycode, c3d);
	return (0);
}
