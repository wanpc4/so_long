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

int on_destroy(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr); // Closes the MLX window
    mlx_destroy_display(data->mlx_ptr); //Destroys the MLX display
    free(data->mlx_ptr); //Frees memory allocated for MLX
    exit(0); //Exits the program
    return (0);
}

int on_keypress(int keysym, t_data *data)
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

int main(int argc, char **argv)
{
    t_map   video_game_2d;

    if (argc != 2)
        wrong_input(1);
        return (0);
    
    return (0);
}
