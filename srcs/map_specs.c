
#include "../includes/so_long.h"

/*
    map_specs.c (Map Specifications): What makes the map look good.
*/

void    place_character(t_map *game, int height, int width)
{
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->character, width * 32, height * 32);
    game->y = height;
    game->x = width;
}

void    place_collectable(t_map *game, int height, int width)
{
    mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->collectable, width * 32, height * 32);
    game->collectable++;
}

void    load_images(t_map *game)
{
    int x;
    int y;

    game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &x, &y);
    game->empty_space = mlx_xpm_file_to_image(game->mlx_ptr, "textures/empty_space.xpm", &x, &y);
    game->character = mlx_xpm_file_to_image(game->mlx_ptr, "textures/character.xpm", &x, &y);
}

int render_frame(t_map *game)
{
    int height;
    int width;

    game->collectable = 0;
    height = 0;
    while (height < game->map_height)
    {
        width = 0;
        while (game->map[height][width])
        {
            if (game->map[height][width] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->wall, width * 32, height * 32);
            else if (game->map[height][width] == '0')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->empty_space, width * 32, height * 32);
            else if (game->map[height][width] == 'P')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->character, width * 32, height * 32);
            // else if (game->array[height][width] == 'C')
            //     mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->img.wall, width * 32, height * 32);
            // else if (game->array[height][width] == 'E')
            //     mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->img.wall, width * 32, height * 32);
            width++;
        }
        height++;
    }
    return (0);
}