/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 08:45:21 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/29 10:08:06 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1);

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	count;
	size_t	i;

	count = 0;
	while (s1[count] != '\0')
	{
		count++;
	}
	str = (char *) malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
