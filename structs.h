/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:15:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/08/30 14:50:33 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_matrix
{
	int		pos_x;
	int		pos_y;
	int		border;
	int		size;
	char	value;
}	t_matrix;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img_n;
	void	*img_s;
	void	*img_e;
	void	*img_o;
	void	*img_w;
	void	*img_f;
}	t_mlx;
/*
typedef struct s_sprite
{
	void	*l[8];
	void	*r[8];
	void	*u[8];
	void	*d[8];
}	t_sprite;
*/

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_game
{
	t_matrix	**matrix;
	t_mlx		mlx;
	t_player	player;
	int			direction;
	int			frames;
	int			steps;
}	t_game;

#endif
