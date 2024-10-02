/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:12:13 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/09/26 09:49:53 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int on_destroy(t_map *game)
{
    mlx_destroy_window(game->mlx_ptr, game->window_ptr); // Closes the MLX window
    mlx_destroy_display(game->mlx_ptr); //Destroys the MLX display
    free(game->mlx_ptr); //Frees memory allocated for MLX
    exit(0); //Exits the program
    return (0);
}

int on_keypress(int keysym, t_map *data)
{
    (void)data; // Unused parameter
    char *direction;
    
    if (keysym == 65362)
        direction = "Up";
    else if (keysym == 65364)
        direction = "Down";
    else if (keysym == 65361)
        direction = "Left";
    else if (keysym == 65363)
        direction = "Right";
    printf("Pressed key: %s\n", direction); // Prints the key that was pressed
    return (0);
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
    if (video_game_2d.mlx_ptr == NULL)
    {
        perror("Error: MLX initialization failed\n");
        return (1);
    }
    video_game_2d.window_ptr = mlx_new_window(video_game_2d.mlx_ptr, (video_game_2d.map_width * 32), (video_game_2d.map_height * 32), "so_long");
    if (video_game_2d.window_ptr == NULL)
    {
        perror("Error: Window creation failed\n");
        return (1);
    }
    load_images(&video_game_2d);
    render_frame(&video_game_2d);
    //mlx_key_hook(video_game_2d.window, controls_working, &video_game_2d);
    mlx_hook(video_game_2d.window_ptr, 17, 0, on_destroy, &video_game_2d);
    mlx_loop(video_game_2d.mlx_ptr);
    return (0);
}
