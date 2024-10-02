
#include "../includes/so_long.h"

void    wrong_input(int sign)
{
    if (sign == 1)
        printf("./so_long maps/filename.ber");
    else if (sign == 2)
    {
        printf("Something does not seems right.");
        printf("It can be a character, collectable, or exit.");
    }
}

int     horizontal_wall(t_map *game)
{
    int x;

    x = 0;
    while (x < game->map_width)
    {
        if (game->map[0][x] == '1' && game->map[game->map_height - 1][x] == '1')
            return (0);
        x++;
    }
    return (1);
}

int     vertical_wall(t_map *game)
{
    int height;
    int width;

    height = 0;
    width = game->map_width;
    while (height < game->map_height)
    {
        if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'))
            return (0);
        height++;
    }
    return (1);
}

void    if_walls(t_map *game)
{
    int vertical;
    int horizontal;

    vertical = vertical_wall(game);
    horizontal = horizontal_wall(game);
    if (!vertical || !horizontal)
    {
        printf("\nMissing walls");
        on_destroy(game);
    }
}

void    count_checker(t_map *game, int height, int width)
{
    if (game->map[height][width] != '1' && game->map[height][width] != '0' && game->map[height][width] != 'P' && game->map[height][width] != 'E' && game->map[height][width] != 'C' && game->map[height][width] != '\n')
    {
        printf("\nError at %c\n", game->map[height][width]);
        on_destroy(game);
    }
    if (game->map[height][width] == 'C')
        game->countColumn++;
    if (game->map[height][width] == 'P')
        game->countPlayer++;
    if (game->map[height][width] == 'E')
        game->countExit++;
}

void    character_valid(t_map *game)
{
    int height;
    int width;

    height = 0;
    while (height < game->map_height - 1)
    {
        width = 0;
        while (width < game->map_width)
        {
            count_checker(game, height, width);
            width++;
        }
        height++;
    }
    while (!(game->countPlayer == 1 && game->countColumn > 1 && game->countExit == 1))
    {
        wrong_input(2);
        on_destroy(game);
    }
}

void    check_errors(t_map *game)
{
    if_walls(game);
    character_valid(game);
}