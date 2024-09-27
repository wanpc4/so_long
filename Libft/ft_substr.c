/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:02:13 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/25 21:07:11 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count1;
	size_t	count2;

	if (s == NULL)
		return (NULL);
	count1 = ft_strlen(s);
	count2 = 0;
	if (start < count1)
		count2 = count1 - start;
	if (count2 > len)
		count2 = len;
	str = malloc(sizeof(char) * (count2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, count2 + 1);
	return (str);
}
