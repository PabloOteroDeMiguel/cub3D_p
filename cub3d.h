/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:17:49 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/05 13:06:21 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include<math.h>
# include "gnl/get_next_line.h"
# include "structs.h"
# include "libft.h"
# include <mlx.h>

/*Main*/
int		main(int argc, char **argv);
void	init(t_game *game, int x, int y, char *argv);
int		hook_loop(t_game *game);
int		close_esc(t_mlx *mlx);

/*Marix Size*/
void	matrix_size(char *file, int *x, int *y);
void	matrix_size_y(char *file, int x, int *y);

/*Matrix*/
void	create_matrix(char *file, int x, int y, t_matrix **matrix);

/*Assets*/
void	assets(t_mlx *mlx);

/*Map*/
void	image(t_game *game, int x, int y);
void	player_pixel(t_game *game, int color);
void	wall_floor_pixel(t_game *game, int pos_x, int pos_y, int color);

/*Key Event*/
int		key_event(int key_code, t_game *game);
int		movement(t_game *game, int x, int y);
void	key_a(t_game *game);
void	key_s(t_game *game);
void	key_d(t_game *game);
void	key_w(t_game *game);

/*Key event dir*/
int		key_event_n(int key_code, t_game *game);
int		key_event_s(int key_code, t_game *game);
int		key_event_e(int key_code, t_game *game);
int		key_event_o(int key_code, t_game *game);

/*Lookin*/
void	looking_at(t_game *game);
void	look_left(t_game *game);
void	look_right(t_game *game);
int		dir(char value);
void	dir_x_y(t_game *game);

/*Screen*/
void	screen_game(t_game *game, int x, int y);

/*Key hook*/
int		advance(int key_code, t_game *game);
int		stop(int key_code, t_game *game);
void	hook(t_game *game);

#endif
