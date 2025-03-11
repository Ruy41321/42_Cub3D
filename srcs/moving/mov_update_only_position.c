/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_update_only_position.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:27:16 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:27:16 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	get_direction(double perpendicular_direction)
{
	if (perpendicular_direction >= -0.3925 && perpendicular_direction < 0.3925)
		return (S);
	if (perpendicular_direction >= 0.3925 && perpendicular_direction < 1.1775)
		return (SW);
	if (perpendicular_direction >= 1.1775 && perpendicular_direction < 1.9625)
		return (W);
	if (perpendicular_direction >= 1.9625 && perpendicular_direction < 2.7475)
		return (NW);
	if (perpendicular_direction >= 2.7475 && perpendicular_direction < 3.5325)
		return (N);
	if (perpendicular_direction >= 3.5325 && perpendicular_direction < 4.3175)
		return (NE);
	if ((perpendicular_direction >= 4.3175 && \
	perpendicular_direction <= 4.713) || \
	(perpendicular_direction >= -1.571 && \
	perpendicular_direction < -1.1775))
		return (E);
	if (perpendicular_direction >= -1.1775 && perpendicular_direction < -0.3925)
		return (SE);
	printf("error in get_direction with angle: %f\n", perpendicular_direction);
	return (0);
}

int	step_management(t_player *player, int foot_step_decrement)
{
	t_move	move;
	t_point	*position;
	int		direction;

	move = player->move;
	if ((move.w || move.s || move.a || move.d))
	{
		position = &player->position;
		direction = get_direction(player->perpendicular_direction);
		move_player_mains(direction, move, position, foot_step_decrement);
		return (TRUE);
	}
	return (FALSE);
}

/*this functions save the position of the player in a tmp variable.
Then works on this last variable.
It first update the coordinate of this point depending on step_management
function. Then it checks if the new point is a collision or not.
if everything was ok, the player position is update with the new valuse.
This function is also the occasion to update the tile where the player is in.
*/
int	moving(t_c3d *c3d)
{
	t_point	tmp;
	int		foot_step_decrement;

	foot_step_decrement = 0;
	tmp.x = c3d->player.position.x;
	tmp.y = c3d->player.position.y;
	while (foot_step_decrement <= FOOT_STEP - 3)
	{
		if (step_management(&c3d->player, foot_step_decrement))
		{
			if (!is_collision(c3d->player.position.x, \
			c3d->player.position.y, c3d))
			{
				c3d->player.tile = tile_reference(c3d->player.position);
				return (TRUE);
			}
		}
		c3d->player.position.x = tmp.x;
		c3d->player.position.y = tmp.y;
		foot_step_decrement++;
	}
	return (FALSE);
}

/*
metto il check perchè altrimenti stampa in loop ogni volta con destory
e ristamp mappa
invece cosi lo fa solo se c'eè stato un cambiamento
This function colled from "update_player_movement" which in turn
is colled from mlx_loop_hook.
Well, it checks if one of the properties of player-position has been set to 1.
Remember that these are set to 1 from the  function key_press_player_position.
Remeber also that this  last (key_press_player_alpha_rotation) is called from
key_press which is called from
mlx_hook(c3d.win.mlx_win, 2, 1L << 0, key_press, &c3d), with second argument
2 which indicates the management of press.
If there is a collision simpli don't do anything. so don't update coordinates
of player.
*/
int	update_position(void *param)
{
	t_c3d	*c3d;

	c3d = (t_c3d *)param;
	return (moving(c3d));
}
