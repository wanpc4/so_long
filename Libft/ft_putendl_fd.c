/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:17:23 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/29 10:07:53 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	if (s == NULL)
		return ;
	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	write(fd, s, count);
	write(fd, "\n", 1);
}
