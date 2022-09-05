/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:52:30 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/05 10:32:46 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pixel(t_game *game)
{
	int	i;
	int	j;

	i = 5;
	while (i < 10)
	{
		j = 6;
		while (j < 11)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				(game->player.y * 15) + j, (game->player.x * 15) + i, 0x0000FF);
			j++;
		}
		i++;
	}
}	

void	wall_floor_pixel(t_game *game, int pos_x, int pos_y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				(pos_y * 15) + j, (pos_x * 15) + i, color);
			j++;
		}
		i++;
	}
}


void	image_aux(t_game *game, int pos_x, int pos_y)
{
	//if (game->matrix[pos_x][pos_y].value == '0')
	wall_floor_pixel(game, pos_x, pos_y, 0x8C8C8C);
		//mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		//	game->mlx.img_f, (pos_y * 15), (pos_x * 15));
	if (game->matrix[pos_x][pos_y].value == 'N')
	{
		//mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		//	game->mlx.img_n, (pos_y * 15), (pos_x * 15));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
		player_pixel(game);
	}
	else if (game->matrix[pos_x][pos_y].value == 'S')
	{
		//mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		//	game->mlx.img_s, (pos_y * 15), (pos_x * 15));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
		player_pixel(game);
	}
	else if (game->matrix[pos_x][pos_y].value == 'O')
	{
		//mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		//	game->mlx.img_o, (pos_y * 15), (pos_x * 15));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
		player_pixel(game);
	}
	else if (game->matrix[pos_x][pos_y].value == 'E')
	{
		//mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
		//	game->mlx.img_e, (pos_y * 15), (pos_x * 15));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
		player_pixel(game);
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
				wall_floor_pixel(game, pos_x, pos_y, 0x4B0082);
				//mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
				//	game->mlx.img_w, (pos_y * 15), (pos_x * 15));
			else if (game->matrix[pos_x][pos_y].value != '1')
			{
				image_aux(game, pos_x, pos_y);
			}
			pos_y++;
		}
		pos_x++;
	}
}
