/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:26:44 by potero-d          #+#    #+#             */
/*   Updated: 2022/08/30 13:03:23 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_matrix(char *file, int x, int y, t_matrix **matrix)
{
	char	*str;
	int		map;
	int		ij[2];

	map = open(file, O_RDONLY);
	if (map == -1)
		exit(0);
		//error_map_no(0);
	ij[0] = 0;
	while (ij[0] < x)
	{
		str = get_next_line(map);
		ij[1] = 0;
		matrix[ij[0]] = malloc(sizeof(t_matrix) * y);
		if (!matrix[ij[0]])
			exit (0); /**/
		while (ij[1] < y)
		{
			matrix[ij[0]][ij[1]].pos_x = ij[0];
			matrix[ij[0]][ij[1]].pos_y = ij[1];
			matrix[ij[0]][ij[1]].value = str[ij[1]];
			ij[1]++;
		}
		free(str);
		ij[0]++;
	}
}
