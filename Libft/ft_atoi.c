/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:24:41 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/25 16:42:07 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str);

int	ft_atoi(const char *str)
{
	int	count;
	int	sign;
	int	converter;

	count = 0;
	sign = 1;
	converter = 0;
	while ((str[count] == ' ') || (str[count] >= '\t' && str[count] <= '\r'))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while ((str[count] >= '0') && (str[count] <= '9'))
	{
		converter = (converter * 10) + (str[count] - '0');
		count++;
	}
	return (converter * sign);
}
