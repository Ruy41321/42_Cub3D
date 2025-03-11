/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_main_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:58:33 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:17:04 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	move_face_north(t_move move, t_point *position, int step_decr)
{
	if (move.w)
		position->y -= (FOOT_STEP - step_decr);
	if (move.s)
		position->y += (FOOT_STEP - step_decr);
	if (move.a)
		position->x -= (FOOT_STEP - step_decr);
	if (move.d)
		position->x += (FOOT_STEP - step_decr);
}

void	move_face_south(t_move move, t_point *position, int step_decr)
{
	if (move.w)
		position->y += (FOOT_STEP - step_decr);
	if (move.s)
		position->y -= (FOOT_STEP - step_decr);
	if (move.a)
		position->x += (FOOT_STEP - step_decr);
	if (move.d)
		position->x -= (FOOT_STEP - step_decr);
}

void	move_face_east(t_move move, t_point *position, int step_decr)
{
	if (move.w)
		position->x += (FOOT_STEP - step_decr);
	if (move.s)
		position->x -= (FOOT_STEP - step_decr);
	if (move.a)
		position->y -= (FOOT_STEP - step_decr);
	if (move.d)
		position->y += (FOOT_STEP - step_decr);
}

void	move_face_west(t_move move, t_point *position, int step_decr)
{
	if (move.w)
		position->x -= (FOOT_STEP - step_decr);
	if (move.s)
		position->x += (FOOT_STEP - step_decr);
	if (move.a)
		position->y += (FOOT_STEP - step_decr);
	if (move.d)
		position->y -= (FOOT_STEP - step_decr);
}

void	move_player_mains(int direction, t_move move, \
t_point *position, int step_decr)
{
	if (direction == N)
		move_face_north(move, position, step_decr);
	else if (direction == S)
		move_face_south(move, position, step_decr);
	else if (direction == W)
		move_face_west(move, position, step_decr);
	else if (direction == E)
		move_face_east(move, position, step_decr);
	else
		move_player_oblq(direction, move, position, step_decr);
}
