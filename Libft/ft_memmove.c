/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:25:54 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/26 02:34:10 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src)
	{
		while (len--)
			*dest++ = *source++;
	}
	else if (dst > src)
	{
		dest += len - 1;
		source += len - 1;
		while (len--)
			*dest-- = *source--;
	}
	return (dst);
}
