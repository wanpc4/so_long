

#include "../includes/so_long.h"

void parse_map(t_map *map)
{
    char buffer[4096];
    int bytes_read;
    int fd;

    // Open the map file
    //map->filename = "maps/map1.ber"; // Make sure this is correct
    fd = open(map->filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Error opening map file\n", 2);
        exit(1);
    }

    // Read the entire file into the buffer
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0)
    {
        perror("Error reading map file");
        close(fd);
        exit(1);
    }

    // Null-terminate the buffer to make it a valid string
    buffer[bytes_read] = '\0';

    // Close the file after reading
    close(fd);

    // Split the buffer into an array of strings (each line in the map)
    map->array = ft_split(buffer, '\n'); // Assume you have a function to split by '\n'
    if (!map->array)
    {
        perror("Error splitting map");
        exit(1);
    }

    // Debug: Print the loaded map
    int i;

    i = 0;
    while (map->array[i])
    {
        printf("Line %d: %s\n", i, map->array[i]);
        i++;
    }

    // Calculate dimensions
    map->y = 0;
    while (map->array[map->y]) // Count lines
        map->y++;

    if (map->y > 0)
        map->x = strlen(map->array[0]); // Set width based on first line
    else
        map->x = 0;

    printf("Parsed map dimensions: %d x %d\n", map->x, map->y);
}


void load_images(t_map *map)
{
    map->img.empty = mlx_xpm_file_to_image(map->mlx, "textures/empty_space.xpm", &map->x, &map->y);
    map->img.wall = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &map->x, &map->y);
    //map->img.player_left1 = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &map->x, &map->y);
}

int render_frame(t_map *map)
{
    int x;
    int y;

    y = 0;
    mlx_clear_window(map->mlx, map->window);
    while (map->array[y])
    {
        x = 0;
        while (map->array[y][x])
        {
            if (map->array[y][x] == '1')
                mlx_put_image_to_window(map->mlx, map->window, map->img.wall, x * 32, y * 32);
            else if (map->array[y][x] == '0')
                mlx_put_image_to_window(map->mlx, map->window, map->img.empty, x * 32, y * 32);
            // else if (map->array[y][x] == 'P')
            //     mlx_put_image_to_window(map->mlx, map->window, map->img.wall, x * 100, y * 100);
            // else if (map->array[y][x] == 'C')
            //     mlx_put_image_to_window(map->mlx, map->window, map->img.wall, x * 100, y * 100);
            // else if (map->array[y][x] == 'E')
            //     mlx_put_image_to_window(map->mlx, map->window, map->img.wall, x * 100, y * 100);
            x++;
        }
        y++;
    }
    return (0);
}