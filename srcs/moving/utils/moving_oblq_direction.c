/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_oblq_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:00:44 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:17:20 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	move_face_north_east(t_move move, t_point *position, int step_decr)
{
	if (move.w)
	{
		position->y -= (FOOT_STEP - step_decr);
		position->x += (FOOT_STEP - step_decr);
	}
	if (move.s)
	{
		position->y += (FOOT_STEP - step_decr);
		position->x -= (FOOT_STEP - step_decr);
	}
	if (move.a)
	{
		position->x -= (FOOT_STEP - step_decr);
		position->y -= (FOOT_STEP - step_decr);
	}
	if (move.d)
	{
		position->x += (FOOT_STEP - step_decr);
		position->y += (FOOT_STEP - step_decr);
	}
}

void	move_face_north_west(t_move move, t_point *position, int step_decr)
{
	if (move.w)
	{
		position->y -= (FOOT_STEP - step_decr);
		position->x -= (FOOT_STEP - step_decr);
	}
	if (move.s)
	{
		position->y += (FOOT_STEP - step_decr);
		position->x += (FOOT_STEP - step_decr);
	}
	if (move.a)
	{
		position->x -= (FOOT_STEP - step_decr);
		position->y += (FOOT_STEP - step_decr);
	}
	if (move.d)
	{
		position->x += (FOOT_STEP - step_decr);
		position->y -= (FOOT_STEP - step_decr);
	}
}

void	move_face_south_east(t_move move, t_point *position, int step_decr)
{
	if (move.w)
	{
		position->y += (FOOT_STEP - step_decr);
		position->x += (FOOT_STEP - step_decr);
	}
	if (move.s)
	{
		position->y -= (FOOT_STEP - step_decr);
		position->x -= (FOOT_STEP - step_decr);
	}
	if (move.a)
	{
		position->x += (FOOT_STEP - step_decr);
		position->y -= (FOOT_STEP - step_decr);
	}
	if (move.d)
	{
		position->x -= (FOOT_STEP - step_decr);
		position->y += (FOOT_STEP - step_decr);
	}
}

void	move_face_south_west(t_move move, t_point *position, int step_decr)
{
	if (move.w)
	{
		position->y += (FOOT_STEP - step_decr);
		position->x -= (FOOT_STEP - step_decr);
	}
	if (move.s)
	{
		position->y -= (FOOT_STEP - step_decr);
		position->x += (FOOT_STEP - step_decr);
	}
	if (move.a)
	{
		position->x += (FOOT_STEP - step_decr);
		position->y += (FOOT_STEP - step_decr);
	}
	if (move.d)
	{
		position->x -= (FOOT_STEP - step_decr);
		position->y -= (FOOT_STEP - step_decr);
	}
}

void	move_player_oblq(int direction, t_move move, \
t_point *position, int step_decr)
{
	if (direction == NE)
		move_face_north_east(move, position, step_decr);
	else if (direction == NW)
		move_face_north_west(move, position, step_decr);
	else if (direction == SE)
		move_face_south_east(move, position, step_decr);
	else if (direction == SW)
		move_face_south_west(move, position, step_decr);
}
