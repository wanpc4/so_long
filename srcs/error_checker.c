
#include "../includes/so_long.h"

void wrong_input(int sign)
{
    if (sign == 1)
        printf("./so_long maps/filename.ber\n");
    else if (sign == 2)
    {
        printf("Something does not seems right.\n");
        printf("It can be a character, collectable, or exit.\n");
    }
}

static int horizontal_wall(t_map *game)
{
    int x;
    int y;

    x = game->map_width;
    y = 0;
    while (y < x)
    {
        if (game->map[0][x] == '1' && game->map[game->map_height - 1][y] == '1')
            return (0);
        y++;
    }
    return (1);
}

static int vertical_wall(t_map *game)
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

static void if_walls(t_map *game)
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

static void count_checker(t_map *game, int height, int width)
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
        while (width <= game->map_width)
        {
            count_checker(game, height, width);
            width++;
        }
        height++;
    }
    if (!(game->countPlayer == 1))
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