/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:52:30 by potero-d          #+#    #+#             */
/*   Updated: 2022/08/30 14:45:41 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	image_aux(t_game *game, int pos_x, int pos_y)
{
	if (game->matrix[pos_x][pos_y].value == '0')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_f, (pos_y * 50), (pos_x * 50));
	else if (game->matrix[pos_x][pos_y].value == 'N')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_n, (pos_y * 50), (pos_x * 50));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
	}
	else if (game->matrix[pos_x][pos_y].value == 'S')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_s, (pos_y * 50), (pos_x * 50));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
	}
	else if (game->matrix[pos_x][pos_y].value == 'O')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_o, (pos_y * 50), (pos_x * 50));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
	}
	else if (game->matrix[pos_x][pos_y].value == 'E')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_e, (pos_y * 50), (pos_x * 50));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
	}
}

void	image(t_game *game, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	while (pos_x < x)
	{
		pos_y = 0;
		while (pos_y < y)
		{
			if (game->matrix[pos_x][pos_y].value == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
					game->mlx.img_w, (pos_y * 50), (pos_x * 50));
			else if (game->matrix[pos_x][pos_y].value != '1')
			{
				image_aux(game, pos_x, pos_y);
			}
			pos_y++;
		}
		pos_x++;
	}
}
