/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:12:27 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/10/07 14:37:30 by wwan-ab-         ###   ########.fr       */
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
#include "get_next_line.h" //Include get_next_line
#include <X11/X.h>
#include <X11/keysym.h>

#define EMPTY_SPACE '0'
#define WALL        '1'
#define COLLECTABLE 'C'
#define EXIT_MAP    'E'
#define START_POINT 'P'

/*
    Keyboard configurations: For character movements
*/
#define KEY_W       119
#define KEY_A       97
#define KEY_S       115
#define KEY_D       100

#define ARROW_UP    65362
#define ARROW_LEFT  65361
#define ARROW_DOWN  65364
#define ARROW_RIGHT 65363

#define KEY_ESC     65307
#define KEY_Q       113

typedef struct s_map
{
    int         fd;
    int         x;
    int         y;
    int         map_height;
    int         map_width;
    int         countPlayer;
    int         countColumn;
    int         countExit;
    int         countMove;
    int         collectable_item;

    char        **map;

    void        *mlx_ptr;
    void        *window_ptr;
    void        *wall;
    void        *character;
    void        *empty_space;
    void        *collectable;
    void        *exit;
}   t_map;

int             render_frame(t_map *map);
void            free_map(t_map *game);
int             on_destroy(t_map *data);
int             read_map(t_map *game, char *argv[]);
int             controls_working(int cmd, t_map *game);
int             input_keyboard(int keysym, t_map *game);
void            load_images(t_map *map);
void            game_status(int sign);

/*
    Functions for error handling
*/
void            character_valid(t_map *game);
void            count_checker(t_map *game, int height, int width);
void            wrong_input(int sign);
void            check_errors(t_map *game);
void            check_walls(t_map *game);
void            print_Error();

#endif