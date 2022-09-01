/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:20:10 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/01 17:30:26 by potero           ###   ########.fr       */
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
	//screen_game(&game, x, y);
	hook_loop(&game);
}

void	init(t_game *game, int x, int y, char *argv)
{
	create_matrix(argv, x, y, game->matrix);
	dir_x_y(game);
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.speed_m = 3;	//pixels
	game->player.speed_t = 3 *(M_PI / 180);	//grados
	game->player.angle = 0;		//rad
	game->width = 1024;
	game->height = 1280;
	game->mlx.mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx, (y * 15), (x * 15), "minimap");
	//game->mlx.screen = mlx_new_window(game->mlx.mlx, game->height, game->width, "cub3D"); 
	assets(&game->mlx);
}

int advance(int key_code, t_game *game)
{
	if (key_code == 1 || key_code == 2 || key_code == 3 || key_code == 13)
		game->player.advance = 1;
	else if (key_code == 123 || key_code == 124)
		game->player.turn = 1;
	return (0);
}

int	hook_loop(t_game *game)
{
	mlx_key_hook(game->mlx.window, key_event, game);
//	mlx_hook(game->mlx.window, 2, (1L << 0), key_event, game);
//	mlx_hook(game->mlx.window, 3, (1L << 1), key_event, game);
	mlx_hook(game->mlx.window, 17, (1L << 17), close_esc, &game->mlx);
	mlx_loop(game->mlx.mlx);
	return (0);
}

int	close_esc(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->window);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
	return (0);
}
