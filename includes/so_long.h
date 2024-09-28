/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:12:27 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/09/26 09:45:55 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h> //perror()
#include <unistd.h> //close(), read(), write()
#include <stdlib.h> //malloc(), free(), exit()
#include <string.h> //strerror()
#include <fcntl.h> //open()
#include "../minilibx-lib/mlx.h"
#include "../Libft/libft.h" //Include Libft
#include "../get_next_line/get_next_line.h" //Include get_next_line
#include <X11/X.h>
#include <X11/keysym.h>

struct color_grade{
    unsigned long color; //Example: 0x00FF0000 (red)
};

typedef struct s_data
{
    void    *mlx_ptr; //MLX pointer
    void    *win_ptr; //MLX window pointer

}   t_data;

typedef struct s_player
{
    int x;
    int y;
}   t_player;

typedef struct s_img
{
    void    *empty;
    void    *collectible;
    void    *wall;
    void    *exit;
    void    *player_left1;
    void    *player_right1;
    void    *player_up1;
    void    *player_down1;
    void    *player_left2;
    void    *player_right2;
    void    *player_up2;
    void    *player_down2;
    void    *enemy;
    
}   t_img;

typedef struct s_map
{
    int         fd;
    char        *line;
    char        *file;
    char        **array;
    char        **copy;
    char        *filename;
    int         y;
    int         x;
    int         e;
    int         c;
    int         c_check;
    int         e_check;
    int         p;
    int         exit;
    int         moves;
    void        *mlx;
    void        *window;
    t_img       img;
    t_player    player;
}   t_map;

int on_destroy(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
    return (0);
}

int on_keypress(int keysym, t_data *data)
{
    (void)data;
    printf("Pressed key: %d\\n", keysym);
    return (0);
}

int render_frame(t_data *data)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr); //Clear the window

    int x;
    int y;
    for (y = 0; y < 400; y++)
    {
        for (x = 0; x < 600; x++)
        {
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x8000FF);
        }
    }
    return (0);
}

void    *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

#endif