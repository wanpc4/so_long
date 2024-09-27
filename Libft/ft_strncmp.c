/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:22:57 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/29 09:31:45 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	length;

	length = 0;
	while ((length < n) && (s1[length] != '\0') && (s2[length] != '\0'))
	{
		if ((unsigned char)s1[length] != (unsigned char)s2[length])
		{
			return ((unsigned char)s1[length] - (unsigned char)s2[length]);
		}
		length++;
	}
	if (length == n)
		return (0);
	if (s1[length] == '\0' && s2[length] != '\0')
		return (-1);
	else
	{
		return ((unsigned char)s1[length]);
	}
	return (s1[length] - s2[length]);
}
