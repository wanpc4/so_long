
#include "../includes/so_long.h"

/*
    map_specs.c (Map Specifications): What makes the map look good.
*/

void    load_images(t_map *game)
{
    game->img.empty = mlx_xpm_file_to_image(game->mlx, "textures/empty_space.xpm", &game->x, &game->y);
    game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->x, &game->y);
    game->img.character = mlx_xpm_file_to_image(game->mlx, "textures/character.xpm", &game->x, &game->y);
}

int render_frame(t_map *game)
{
    int x;
    int y;

    y = 0;
    mlx_clear_window(game->mlx, game->window);
    while (y < game->map_height)
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->img.wall, x * 32, y * 32);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->window, game->img.empty, x * 32, y * 32);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->window, game->img.wall, x * 32, y * 32);
            // else if (game->array[y][x] == 'C')
            //     mlx_put_image_to_window(game->mlx, game->window, game->img.wall, x * 100, y * 100);
            // else if (game->array[y][x] == 'E')
            //     mlx_put_image_to_window(game->mlx, game->window, game->img.wall, x * 100, y * 100);
            x++;
        }
        y++;
    }
    return (0);
}