/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 06:46:33 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/10/04 06:46:35 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static	int	vertical_wall(t_map *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->map_width;
	while (height < width)
	{
		if (game->map[0][width] == '1'
		&& game->map[game->map_height - 1][height] == '1')
			return (0);
		height++;
	}
	return (1);
}

static	int	horizontal_wall(t_map *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->map_width;
	while (height < game->map_height)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

void	check_walls(t_map *game)
{
	int	vertical;
	int	horizontal;

	vertical = vertical_wall(game);
	horizontal = horizontal_wall(game);
	if (!vertical || !horizontal)
	{
		wrong_input(3);
		on_destroy(game);
	}
}
