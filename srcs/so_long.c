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
    t_map map;

    // Check for the correct number of arguments (at least one map file)
    if (argc != 2)
    {
        perror("Usage: ./so_long path_to_map/\n");
        return (1);
    }

    // Initialize the map structure
    map.filename = argv[1]; //To the map folder. Acessing map with .ber extension
    map.mlx = mlx_init();
    if (!map.mlx)
    {
        perror("Failed to initialize MLX");
        return (1);
    }

    // Parse the map from the provided file
    parse_map(&map); // Implement this in generate_map.c
    printf("Map loaded. Dimensions: %d x %d\n", map.x, map.y);

    if (map.x <= 0 || map.y <= 0)
    {
        fprintf(stderr, "Invalid map dimensions: x=%d, y=%d\n", map.x, map.y);
        return (1);
    }

    // Create a window based on the map size
    map.window = mlx_new_window(map.mlx, map.x * 32, map.y * 32, "so_long");
    if (!map.window)
    {
        perror("Unable to create window");
        free(map.mlx);
        return (1);
    }

    // Load textures and images (XPM files)
    load_images(&map);  // Implement this function to load XPM files

    // Register key press and destroy hooks
    mlx_hook(map.window, KeyRelease, KeyReleaseMask, &on_keypress, &map);
    mlx_hook(map.window, DestroyNotify, StructureNotifyMask, &on_destroy, &map);

    // Render the initial frame (map, player, etc.)
    render_frame(&map);

    // Start the MLX event loop
    mlx_loop(map.mlx);

    return (0);
}
