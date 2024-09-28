

#include "../includes/so_long.h"

void    parse_map(t_map *map)
{
    map->fd = open(map->filename, O_RDONLY);
    if (map->fd < 0)
    {
        perror("Error opening map file");
        exit(1);
    }
    // Read and store the map as a 2D array
    map->file = ft_strjoin(map->file, get_next_line(map->fd));
    while ((map->line = get_next_line(map->fd)) != NULL)
    {
        map->file = ft_strjoin(map->file, map->line);
        free(map->line);
    }
    close(map->fd);
    map->array = ft_split(map->file, '/n'); //Store map rows
}

void load_images(t_map *map)
{
    map->img.empty = mlx_xpm_file_to_image(map->mlx, "", &map->x, &map->y);
    map->img.wall = mlx_xpm_file_to_image(map->mlx, "", &map->x, &map->y);
    map->img.player_left1 = mlx_xpm_file_to_image(map->mlx, "", &map->x, &map->y);
}

int render_frame(t_map *map)
{
    int x;
    int y;

    mlx_clear_window(map->mlx, map->window);
    for (y = 0; map->array[y]; y++)
    {
        for (x = 0; map->array[y][x]; x++)
        {
            if (map->array[y][x] == '1')
                mlx_put_image_to_window(map->mlx, map->window, map->img.wall, x * 100, y * 100);
            else if (map->array[y][x] == '0')
                mlx_put_image_to_window(map->mlx, map->window, map->img.wall, x * 100, y * 100);
            else if (map->array[y][x] == 'P')
                mlx_put_image_to_window(map->mlx, map->window, map->img.wall, x * 100, y * 100);
            else if (map->array[y][x] == 'C')
                mlx_put_image_to_window(map->mlx, map->window, map->img.wall, x * 100, y * 100);
            else if (map->array[y][x] == 'E')
                mlx_put_image_to_window(map->mlx, map->window, map->img.wall, x * 100, y * 100);
        }
    }
    return (0);
}