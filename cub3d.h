/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:17:49 by potero-d          #+#    #+#             */
/*   Updated: 2022/08/30 14:50:37 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include "gnl/get_next_line.h"
# include "structs.h"
# include "libft.h"
# include <mlx.h>

/*Main*/
int		main(int argc, char **argv);
void	init(t_game *game, int x, int y, char *argv);
int		hook_loop(t_game *game);

/*Marix Size*/
void	matrix_size(char *file, int *x, int *y);
void	matrix_size_y(char *file, int x, int *y);

/*Matrix*/
void	create_matrix(char *file, int x, int y, t_matrix **matrix);

/*Assets*/
void	assets(t_mlx *mlx);

/*Map*/
void	image(t_game *game, int x, int y);

/*Key Event*/
int		key_event(int key_code, t_game *game);
int		movement(t_game *game, int x, int y);
void	key_a(t_game *game);
void	key_s(t_game *game);
void	key_d(t_game *game);
void	key_w(t_game *game);

/*Lookin*/
void	looking_at(t_game *game);
void	look_left(t_game *game);
void	look_right(t_game *game);
int		dir(char value);
#endif
