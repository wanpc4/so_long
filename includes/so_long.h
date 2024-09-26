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

struct color_grade{
    unsigned long color; //Example: 0x00FF0000 (red)
};

typedef struct s_data
{
    void    *mlx_ptr; //MLX pointer
    void    *win_ptr; //MLX window pointer
    void    *textures[5]; //MLX image pointers (on the stack)
    t_map   *map; //Map pointer (contains map details - preferably kept on the stack)
}   t_data;

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
    printf("Pressed key: %d\\n");
    return (0);
}

void    *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

#endif