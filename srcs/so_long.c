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

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1); //If fails
    win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "Hello :)");
    if (!data.win_ptr) //If window can't open
        return (free(data.mlx_ptr), 1); //Deallocate memory
    
    //Register key release hook
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

    //Register destroy hook
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

    //Loop over the MLX pointer
    mlx_loop(data.mlx_ptr);
    return (0);
}
