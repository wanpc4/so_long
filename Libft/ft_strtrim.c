/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:27:43 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/29 10:08:27 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);
int		is_char_there(char w, char const *word);

int	is_char_there(char w, char const *word)
{
	size_t	count;

	count = 0;
	while (word[count] != '\0')
	{
		if (word[count] == w)
		{
			return (1);
		}
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count1;
	size_t	count2;
	size_t	i;
	char	*str;

	count1 = 0;
	count2 = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[count1] != '\0' && is_char_there(s1[count1], set))
		count1++;
	count2 = ft_strlen(s1);
	while ((count1 < count2) && is_char_there(s1[count2 - 1], set))
		count2--;
	str = (char *) malloc((count2 - count1 + 1) * sizeof(*s1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (count1 < count2)
		str[i++] = s1[count1++];
	str[i] = '\0';
	return (str);
}
