/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:21:37 by potero-d          #+#    #+#             */
/*   Updated: 2022/08/30 14:11:20 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_event(int key_code, t_game *game)
{
	printf("key->%d\n", key_code);
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
/*	if (key_code == 53)
		close_esc(&game->mlx);
		*/
	return (0);
}

int	movement(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + x;
	new_y = game->player.y + y;
	if (game->matrix[new_x][new_y].value == '1')
	{
		printf("Impossible movement\n");
		return (1);
	}
	else
	{
		game->player.x = new_x;
		game->player.y = new_y;
		return (0);
	}
}

void	looking_at(t_game *game)
{
	if (game->direction == 'N')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_n,
			(game->player.y * 50), (game->player.x * 50));
	else if (game->direction == 'S')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
			(game->player.y * 50), (game->player.x * 50));
	else if (game->direction== 'O')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_o,
			(game->player.y * 50), (game->player.x * 50));
	else if (game->direction== 'E')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_e,
			(game->player.y * 50), (game->player.x * 50));
}

void	key_a(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_f,
		((game->player.y + 1) * 50), ((game->player.x) * 50));
	looking_at(game);
}

void	key_s(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_f,
		((game->player.y) * 50), ((game->player.x - 1) * 50));
	looking_at(game);
}

void	key_d(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_f,
		((game->player.y - 1) * 50), ((game->player.x) * 50));
	looking_at(game);
}

void	key_w(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_f,
		((game->player.y) * 50), ((game->player.x + 1) * 50));
	looking_at(game);
}
