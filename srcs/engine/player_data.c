/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:52:30 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/13 08:05:46 by potero           ###   ########.fr       */
/*   Updated: 2022/10/11 15:08:04 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_data_aux(t_game *game, int pos_f, int pos_c, char value)
{
	double	aux;

	aux = 0.5;
	if (value == 'N' || value == 'S' || value == 'E' || value == 'W')
	{
		game->player.f = pos_f + aux;
		game->player.c = pos_c + aux;
		game->matrix[pos_f][pos_c].value = '0';
		if (value == 'N')
			game->player.angle = 3 * M_PI / 2;
		else if (value == 'S')
			game->player.angle = (M_PI / 2);
		else if (value == 'W')
			game->player.angle = (M_PI);
		else if (value == 'E')
			game->matrix[pos_f][pos_c].value = '0';
	}
}

void	player_data(t_game *game)
{
	int	pos_f;
	int	pos_c;

	pos_f = 0;
	while (pos_f < game->size_f)
	{
		pos_c = 0;
		while (pos_c < game->size_c)
		{
			if (game->matrix[pos_f][pos_c].value != '1')
				player_data_aux(game, pos_f, pos_c,
					game->matrix[pos_f][pos_c].value);
			pos_c++;
		}
		pos_f++;
	}
}
