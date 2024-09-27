/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:17:00 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/30 21:39:40 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*haystack;
	const char	*needle;
	size_t		count;

	haystack = (const char *)big;
	needle = (const char *)little;
	count = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (!len)
		return (0);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && count <= len - ft_strlen(needle))
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
		{
			return ((char *)haystack);
		}
		count++;
		haystack++;
	}
	return (NULL);
}
