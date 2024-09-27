/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 06:59:39 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/26 01:46:23 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_char(char *str, unsigned int num, long int len)
{
	while (num > 0)
	{
		str[len] = '0' + (num % 10);
		num = num / 10;
		len--;
	}
	return (str);
}

static long int	ft_nbrlen(int n)
{
	int			len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		len;
	unsigned int	num;
	int				sign;

	sign = 1;
	len = ft_nbrlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		num = n * -1;
		str[0] = '-';
	}
	else
		num = n;
	str = ft_char(str, num, len);
	return (str);
}
