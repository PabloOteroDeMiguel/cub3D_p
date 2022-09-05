/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:36:49 by potero            #+#    #+#             */
/*   Updated: 2022/09/05 13:27:44 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	advance(int key_code, t_game *game)
{
	if (key_code == 1 || key_code == 2 || key_code == 3 || key_code == 13)
		game->player.advance = 1;
	else if (key_code == 123)
		game->player.turn = -1;
	else if (key_code == 124)
		game->player.turn = 1;
	hook(game);
	return (0);
}

int	stop(int key_code, t_game *game)
{
	if (key_code == 1 || key_code == 2 || key_code == 3 || key_code == 13)
	{
		game->player.advance = 0;
		printf("stop advance\n");
	}
	else if (key_code == 123 || key_code == 124)
		game->player.turn = 0;
	hook(game);
	return (0);
}

void	hook(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = (game->player.advance * (cos(game->player.angle) * game->player.speed_m)) 
		+ game->player.x;
	new_y = (game->player.advance * (sin(game->player.angle) * game->player.speed_m)) 
		+ game->player.y;

	game->player.angle += game->player.turn * game->player.speed_t;
//	player_pixel(game, 0x8C8C8C);
	printf("old_x: %f\n", game->player.x);
	printf("old_y: %f\n", game->player.y);
	printf("new_x: %f\n", new_x);
	printf("new_y: %f\n", new_y);
	game->player.x = new_x;
	game->player.y = new_y;
	player_pixel(game, 0xFF0000);
}
