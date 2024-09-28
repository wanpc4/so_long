/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:27:14 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/08/12 10:30:16 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		x;
	int		y;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) *((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (result == NULL)
		return (NULL);
	x = -1;
	y = 0;
	if (s1)
		while (s1[++x] != '\0')
			result[x] = s1[x];
	while (s2[y] != '\0')
		result[x++] = s2[y++];
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (result);
}

char	*ft_extract_line(char *left_str)
{
	int		count;
	char	*str;

	count = 0;
	if (!left_str[count])
		return (NULL);
	while ((left_str[count]) && (left_str[count] != '\n'))
		count++;
	str = (char *)malloc(sizeof(char) * (count + 2));
	if (!str)
		return (NULL);
	count = 0;
	while ((left_str[count]) && (left_str[count] != '\n'))
	{
		str[count] = left_str[count];
		count++;
	}
	if (left_str[count] == '\n')
	{
		str[count] = left_str[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

char	*ft_update_str(char *left_str)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	while ((left_str[x]) && (left_str[x] != '\n'))
		x++;
	if (!left_str[x])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - x + 1));
	if (!str)
		return (NULL);
	x++;
	y = 0;
	while (left_str[x])
		str[y++] = left_str[x++];
	str[y] = '\0';
	free(left_str);
	return (str);
}
