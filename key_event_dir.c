/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:10:03 by potero-d          #+#    #+#             */
/*   Updated: 2022/08/30 16:37:20 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_event_n(int key_code, t_game *game)
{
	if (key_code == 0)
		if (movement(game, 0, -1) == 0)
			key_a(game);
	if (key_code == 1)
		if (movement(game, 1, 0) == 0)
			key_s(game);
	if (key_code == 2)
		if (movement(game, 0, 1) == 0)
			key_d(game);
	if (key_code == 13)
		if (movement(game, -1, 0) == 0)
			key_w(game);
	if (key_code == 123)
		look_left(game);
	if (key_code == 124)
	look_right(game);
/*
	if (key_code == 53)
		close_esc(&game->mlx);
*/
	return (0);
}

int key_event_s(int key_code, t_game *game)
{
	if (key_code == 0)
		if (movement(game, -1, 0) == 0)
			key_d(game);
	if (key_code == 1)
		if (movement(game, 0, 1) == 0)
			key_w(game);
	if (key_code == 2)
		if (movement(game, 1, 0) == 0)
			key_a(game);
	if (key_code == 13)
		if (movement(game, 0, -1) == 0)
			key_s(game);
	if (key_code == 123)
		look_left(game);
	if (key_code == 124)
	look_right(game);
/*
	if (key_code == 53)
		close_esc(&game->mlx);
*/
	return (0);
}

int key_event_e(int key_code, t_game *game)
{
	if (key_code == 0)
		if (movement(game, 0, -1) == 0)
			key_w(game);
	if (key_code == 1)
		if (movement(game, 1, 0) == 0)
			key_a(game);
	if (key_code == 2)
		if (movement(game, 0, 1) == 0)
			key_d(game);
	if (key_code == 13)
		if (movement(game, -1, 0) == 0)
			key_s(game);
	if (key_code == 123)
		look_left(game);
	if (key_code == 124)
	look_right(game);
/*
	if (key_code == 53)
		close_esc(&game->mlx);
*/
	return (0);
}

int key_event_o(int key_code, t_game *game)
{
	if (key_code == 0)
		if (movement(game, 0, -1) == 0)
			key_s(game);
	if (key_code == 1)
		if (movement(game, 1, 0) == 0)
			key_d(game);
	if (key_code == 2)
		if (movement(game, 0, 1) == 0)
			key_a(game);
	if (key_code == 13)
		if (movement(game, -1, 0) == 0)
			key_w(game);
	if (key_code == 123)
		look_left(game);
	if (key_code == 124)
	look_right(game);
/*
	if (key_code == 53)
		close_esc(&game->mlx);
*/
	return (0);
}