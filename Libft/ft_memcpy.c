/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:25:43 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/26 02:06:55 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;

	if (dst == NULL && src == NULL)
		return (NULL);
	count = 0;
	while (count < n)
	{
		*(char *)(dst + count) = *(char *)(src + count);
		count++;
	}
	return (dst);
}
