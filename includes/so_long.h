/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:12:27 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/09/30 17:49:54 by wwan-ab-         ###   ########.fr       */
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

typedef struct s_map
{
    int         fd;
    int         y;
    int         x;
    int         map_height;
    int         map_width;
    int         exit;
    int         moves;
    int         countPlayer;
    int         countColumn;
    int         countExit;
    char        *line;
    char        *file;
    char        **map;
    char        **copy;
    char        *filename;
    void        *mlx_ptr;
    void        *window_ptr;
    void        *wall;
    void        *character;
    void        *empty_space;
}   t_map;

void    parse_map(t_map *map);
void    load_images(t_map *map);
int     render_frame(t_map *map);
int     on_destroy(t_map *data);
int     on_keypress(int keysym, t_map *data);
int     read_map(t_map *game, char *argv[]);
int     map_size(char *size);
int     add_line(t_map *game, char *line);

/*
    Functions for error handling
*/
void    wrong_input(int sign);
void    check_errors(t_map *game);

#endif