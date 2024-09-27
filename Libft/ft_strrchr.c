/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:29:51 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/25 17:40:58 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	chr;

	count = ft_strlen(s);
	chr = (char)c;
	while (count >= 0)
	{
		if (s[count] == chr)
			return ((char *)(s + count));
		count--;
	}
	return (0);
}
