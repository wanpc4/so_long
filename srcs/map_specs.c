
#include "../includes/so_long.h"

/*
    map_specs.c (Map Specifications): What makes the map look good.
*/

void    load_images(t_map *game)
{
    game->empty_space = mlx_xpm_file_to_image(game->mlx_ptr, "textures/empty_space.xpm", &game->x, &game->y);
    game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &game->x, &game->y);
    game->character = mlx_xpm_file_to_image(game->mlx_ptr, "textures/character.xpm", &game->x, &game->y);
    if (!game->empty_space || !game->wall || !game->character)
    {
        perror("Error: failed to load one or more images\n");
        on_destroy(game);
    }
}

int render_frame(t_map *game)
{
    int x;
    int y;

    y = 0;
    mlx_clear_window(game->mlx_ptr, game->window_ptr);
    while (y < game->map_height)
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->wall, x * 32, y * 32);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->empty_space, x * 32, y * 32);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->character, x * 32, y * 32);
            // else if (game->array[y][x] == 'C')
            //     mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->img.wall, x * 100, y * 100);
            // else if (game->array[y][x] == 'E')
            //     mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->img.wall, x * 100, y * 100);
            x++;
        }
        y++;
    }
    return (0);
}