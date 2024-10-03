#include "../includes/so_long.h" // Ensure this is included to declare `character_move`

void    game_status(int sign)
{
    if (sign == 1)
        printf("You won the game, parabéns!");
    else if (sign == 2)
        printf("Error");
}

void    character_move(t_map *game, int height_y, int width_x, int character)
{
    (void)character;  // Suppress unused parameter warning for now

    if (height_y < 0 || height_y >= game->map_height || width_x < 0 || width_x >= game->map_width)
        return; // Prevent moving out of bounds

    if (game->map[height_y][width_x] == EXIT_MAP)
        game_status(1);
    else if ((game->map[height_y][width_x] == EMPTY_SPACE) || (game->map[height_y][width_x] == COLLECTABLE))
    {
        game->map[game->y][game->x] = EMPTY_SPACE;
        game->map[height_y][width_x] = START_POINT;

        game->x = width_x;
        game->y = height_y;

        game->countMove++;
        render_frame(game);
    }
}

int input_keyboard(int keysym, t_map *game)
{
    if (keysym == ARROW_UP || keysym == KEY_W)
        character_move(game, game->y - 1, game->x, 4); // Move up
    else if (keysym == ARROW_LEFT || keysym == KEY_A)
        character_move(game, game->y, game->x - 1, 2); // Move left
    else if (keysym == ARROW_DOWN || keysym == KEY_S)
        character_move(game, game->y + 1, game->x, 3); // Move down
    else if (keysym == ARROW_RIGHT || keysym == KEY_D)
        character_move(game, game->y, game->x + 1, 1); // Move right
    else if (keysym == KEY_ESC || keysym == KEY_Q)
        on_destroy(game); // Quit the game
    return (0);
}
