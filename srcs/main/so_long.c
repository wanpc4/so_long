/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:12:13 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/09/26 09:49:53 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int on_destroy(t_map *game)
{
    int line;

    line = 0;
    if (game->window_ptr)
        mlx_destroy_window(game->mlx_ptr, game->window_ptr);
    while (line < game->map_height)
    {
        free(game->map[line]);
        line++;
    }
    free(game->map);
    free(game->mlx_ptr);
    exit(0);
}

int main(int argc, char *argv[])
{
    t_map   video_game_2d;

    if (argc != 2)
    {
        wrong_input(1);
        return (0);
    }
    ft_memset(&video_game_2d, 0, sizeof(t_map));
    read_map(&video_game_2d, argv);
    check_errors(&video_game_2d);
    video_game_2d.mlx_ptr = mlx_init();
    video_game_2d.window_ptr = mlx_new_window(video_game_2d.mlx_ptr, (video_game_2d.map_width * 32), (video_game_2d.map_height * 32), "so_long");
    load_images(&video_game_2d);
    render_frame(&video_game_2d);
    //mlx_key_hook(video_game_2d.window_ptr, input_keyboard, &video_game_2d);
    mlx_hook(video_game_2d.window_ptr, KeyPress, KeyPressMask, input_keyboard, &video_game_2d);
    mlx_hook(video_game_2d.window_ptr, 17, 0, (void *)exit, 0);
    mlx_loop(video_game_2d.mlx_ptr);
    return (0);
}