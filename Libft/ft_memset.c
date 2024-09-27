/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:26:03 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/29 08:37:48 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	replace;
	size_t			count;

	a = s;
	replace = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		a[count] = replace;
		count++;
	}
	return (s);
}
