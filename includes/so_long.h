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
#include <X11/X.h>
#include <X11/keysym.h>

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

void    parse_map(t_map *map);
void    load_images(t_map *map);
int     render_frame(t_map *map);
int     on_destroy(t_data *data);
int     on_keypress(int keysym, t_data *data);

#endif