/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:20:10 by potero-d          #+#    #+#             */
/*   Updated: 2022/08/30 14:01:31 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	t_game	game;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(0);
	}
	x = 0;
	matrix_size(argv[1], &x, &y);
	//printf("Map size->(%d, %d)\n", x, y);
	game.matrix = malloc(sizeof(t_matrix *) * x + 1);
	game.matrix[x] = 0;
	if (!game.matrix)
		return (0);
	init(&game, x, y, argv[1]);
	image(&game, x, y);
	hook_loop(&game);
}

void	init(t_game *game, int x, int y, char *argv)
{
	create_matrix(argv, x, y, game->matrix);
//	create_border(x, y, game->matrix);
//	border(game->matrix, x, y);
//	read_map(game, x, y);
//	read_matrix(game, x, y);
	game->mlx.mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx,
			(y * 50), (x * 50), "Cub3D");
	assets(&game->mlx);
}

int	hook_loop(t_game *game)
{
	mlx_key_hook(game->mlx.window, key_event, game);
//	mlx_hook(game->mlx.window, 17, (1L << 17), close_esc, &game->mlx);
	mlx_loop(game->mlx.mlx);
	return (0);
}
