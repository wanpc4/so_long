/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:27:05 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/29 09:28:37 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count_dst;
	size_t	count_src;
	size_t	length_dest;
	size_t	count;

	count_src = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (count_src);
	count_dst = ft_strlen(dst);
	length_dest = count_dst;
	if (dstsize <= length_dest)
		return (dstsize + count_src);
	count = 0;
	while (src[count] && count_dst + 1 < dstsize)
	{
		dst[count_dst] = src[count];
		count++;
		count_dst++;
	}
	dst[count_dst] = '\0';
	return (length_dest + count_src);
}
