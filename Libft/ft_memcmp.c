/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:33:34 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/26 02:07:20 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*stmt_1;
	unsigned char	*stmt_2;

	if (n == 0)
		return (0);
	stmt_1 = (unsigned char *)s1;
	stmt_2 = (unsigned char *)s2;
	while ((*stmt_1 == *stmt_2) && (n - 1 > 0))
	{
		stmt_1++;
		stmt_2++;
		n--;
	}
	return ((int)(*stmt_1 - *stmt_2));
}
