/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:12:13 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/09/26 09:49:53 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	on_destroy(t_map *game)
{
	int	line;

	line = 0;
	if (game->window_ptr)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	while (line < game->map_height)
	{
		free(game->map[line]);
		line++;
	}
	free(game->map);
	free(game->mlx_ptr);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_map	game;

	if (argc != 2)
	{
		wrong_input(1);
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_map));
	read_map(&game, argv);
	check_errors(&game);
	game.mlx_ptr = mlx_init();
	game.window_ptr = mlx_new_window(game.mlx_ptr, (game.map_width * 32),
			(game.map_height * 32), "so_long");
	if (!game.mlx_ptr)
	{
		free(game.mlx_ptr);
		return (1);
	}
	load_images(&game);
	render_frame(&game);
	mlx_hook(game.window_ptr, KeyPress, KeyPressMask, input_keyboard, &game);
	mlx_hook(game.window_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_ptr);
	return (0);
}
