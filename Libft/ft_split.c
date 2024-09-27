/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-ab- <wwan-ab-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:25:00 by wwan-ab-          #+#    #+#             */
/*   Updated: 2024/06/29 08:54:48 by wwan-ab-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freearr(char **ptr, int count)
{
	while (count > 0)
	{
		count--;
		free(ptr[count]);
	}
	free(ptr);
	return (NULL);
}

static int	count_word(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != c && str[i] != '\0')
			{
				i++;
			}
		}
	}
	return (count);
}

static char	*putword(char *word, char const *s, int start, int len)
{
	int	x;

	x = 0;
	while (len > 0)
	{
		word[x] = s[start + x];
		x++;
		len--;
	}
	word[x] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s1, char c, char **s2, int wordnum)
{
	int	a;
	int	word;
	int	len;

	a = 0;
	word = 0;
	len = 0;
	while (word < wordnum)
	{
		while (s1[a] == c && s1[a] != '\0')
			a++;
		while (s1[a] != c && s1[a] != '\0')
		{
			a++;
			len++;
		}
		s2[word] = (char *) malloc((len + 1) * sizeof(char));
		if (s2[word] == NULL)
			return (freearr(s2, word));
		putword(s2[word], s1, a - len, len);
		len = 0;
		word++;
	}
	s2[word] = NULL;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	int		numword;

	if (s == NULL)
		return (NULL);
	numword = count_word(s, c);
	s2 = (char **) malloc(sizeof(char *) * (numword + 1));
	if (s2 == NULL)
		return (NULL);
	s2 = ft_split_words(s, c, s2, numword);
	return (s2);
}
