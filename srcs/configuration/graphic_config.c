/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:37:20 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/10/07 14:42:37 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    place_character(t_map *game, int height, int width)
{
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->character, width * 32, height * 32);
    game->y = height;
    game->x = width;
}

void    place_collectable(t_map *game, int height, int width)
{
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->collectable, width * 32, height * 32);
    game->collectable_item++;
}

void    load_images(t_map *game)
{
    int x;
    int y;

    game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/grass.xpm", &x, &y);
    game->empty_space = mlx_xpm_file_to_image(game->mlx_ptr, "textures/dirt.xpm", &x, &y);
    game->character = mlx_xpm_file_to_image(game->mlx_ptr, "textures/steve.xpm", &x, &y);
    game->collectable = mlx_xpm_file_to_image(game->mlx_ptr, "textures/diamond.xpm", &x, &y);
    game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/nether.xpm", &x, &y);
}

int render_frame(t_map *game)
{
    int height;
    int width;

    game->collectable_item = 0;
    height = 0;
    while (height < game->map_height)
    {
        width = 0;
        while (game->map[height][width])
        {
            if (game->map[height][width] == WALL)
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->wall, width * 32, height * 32);
            else if (game->map[height][width] == EMPTY_SPACE)
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->empty_space, width * 32, height * 32);
            else if (game->map[height][width] == START_POINT)
                place_character(game, height, width);
            else if (game->map[height][width] == COLLECTABLE)
                place_collectable(game, height, width);    
            else if (game->map[height][width] == EXIT_MAP)
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->exit, width * 32, height * 32);
            width++;
        }
        height++;
    }
    return (0);
}
