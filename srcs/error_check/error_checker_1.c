/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 06:36:04 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/10/04 06:36:08 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    print_Error()
{
    printf("Error\n");
}

void    wrong_input(int sign)
{
    if (sign == 1)
    {
        print_Error();
        printf("Your execution file should be like this:\n");
        printf("./so_long maps/filename.ber\n");
    }
    else if (sign == 2)
    {
        print_Error();
        printf("It can be a character, collectable, or exit.\nPlease check your map.");
    }
    else if (sign == 3)
    {
        print_Error();
        printf("Missing Walls. \nPlease check your map.");
    }
}

void count_checker(t_map *game, int height, int width)
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
    if (!(game->countPlayer == 1 && game->countColumn > 1 && game->countExit == 1))
    {
        wrong_input(2);
        on_destroy(game);
    }
}

void    check_errors(t_map *game)
{
    check_walls(game);
    character_valid(game);
}
