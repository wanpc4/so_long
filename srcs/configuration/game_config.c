/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 06:36:22 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/10/04 06:36:45 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_status(int sign)
{
	if (sign == 1)
		printf("You won the game, congratulations!\n");
	else if (sign == 2)
	{
		printf("Try again.\n");
	}
	else if (sign == 3)
	{
		printf("You must collect all diamonds ");
		printf("before entering exit point.\n");
	}
	else if (sign == 4)
	{
		printf("Quitting the game.\nThanks for playing!\n");
	}
}

void	count_steps(t_map *game)
{
	printf("Current step count: %d\n", game->countMove);
}

void	update_character_position(t_map *game, int height_y, int width_x)
{
	game->map[game->y][game->x] = EMPTY_SPACE;
	game->y = height_y;
	game->x = width_x;
	game->map[game->y][game->x] = START_POINT;
	game->countMove++;
	count_steps(game);
}

void	character_move(t_map *game, int height_y, int width_x)
{
	if (height_y < 0 || height_y >= game->map_height
		|| width_x < 0 || width_x >= game->map_width)
		return ;
	if (game->map[height_y][width_x] == EXIT_MAP)
	{
		if (game->countColumn > 0)
		{
			game_status(3);
			return ;
		}
		game_status(1);
		on_destroy(game);
	}
	else if (game->map[height_y][width_x] == EMPTY_SPACE
		|| game->map[height_y][width_x] == COLLECTABLE)
	{
		if (game->map[height_y][width_x] == COLLECTABLE)
			game->countColumn--;
		update_character_position(game, height_y, width_x);
		render_frame(game);
	}
}

int	input_keyboard(int keysym, t_map *game)
{
	int	move_left_right;
	int	move_up_down;

	move_left_right = game->x;
	move_up_down = game->y;
	if (keysym == KEY_W || keysym == ARROW_UP)
		move_up_down--;
	else if (keysym == KEY_S || keysym == ARROW_DOWN)
		move_up_down++;
	else if (keysym == KEY_A || keysym == ARROW_LEFT)
		move_left_right--;
	else if (keysym == KEY_D || keysym == ARROW_RIGHT)
		move_left_right++;
	else if (keysym == KEY_Q || keysym == KEY_ESC)
	{
		game_status(4);
		on_destroy(game);
	}
	if (game->map[move_up_down][move_left_right] != WALL)
		character_move(game, move_up_down, move_left_right);
	return (0);
}
