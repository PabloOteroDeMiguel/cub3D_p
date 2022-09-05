/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:36:49 by potero            #+#    #+#             */
/*   Updated: 2022/09/05 10:40:41 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	advance(int key_code, t_game *game)
{
	if (key_code == 1 || key_code == 2 || key_code == 3 || key_code == 13)
		game->player.advance = 1;
	else if (key_code == 123 || key_code == 124)
		game->player.turn = 1;
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
	return (0);
}
