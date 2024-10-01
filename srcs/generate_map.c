/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:56:18 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/09/30 18:56:21 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//To free from memory leak
void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int     map_size(char **size)
{
    int width;

    width = 0;
    while (size[width] != '\0')
        width++;
    if (size[width - 1] == '\n')
        width--;
    return (width);
}

int     add_line(t_map *game, char *line)
{
    char    **temp;
    int     i;

    if (!line)
        return (0);

    i = 0;
    game->map_height++;
    temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
    temp[game->map_height] = NULL;
    while (i < game->map_height - 1)
    {
        temp[i] = game->map[i];
        i++;
    }
    temp[i] = line;
    if (game->map)
        free(game->map);
    game->map = temp;
    return (1);
}

int read_map(t_map *game, char *argv[])
{
    char    *rMap;

    game->fd = open(argv[1], O_RDONLY);
    if (game->fd < 0)
        return (0);
    while (1)
    {
        rMap = get_net_line(game->fd);
        if (!add_line(game, rMap))
            break ;
    }
    close(game->fd);
    game->map_width = map_size(game->map[0]);
    return (1);
}