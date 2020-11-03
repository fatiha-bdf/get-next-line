/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboudyaf <fboudyaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:47:18 by fboudyaf          #+#    #+#             */
/*   Updated: 2018/12/18 15:23:20 by fboudyaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		word_lenght(const char *s, char c, size_t n)
{
	int		i;
	int		len;
	size_t	word_nb;

	i = 0;
	word_nb = 0;
	while (s[i])
	{
		len = 0;
		if (s[i] != c)
		{
			word_nb++;
			len++;
			while (s[i + 1] != '\0' && s[i + 1] != c)
			{
				len++;
				i++;
			}
			if (n == word_nb)
				return (len);
		}
		i++;
	}
	return (len);
}

static int		count_words(const char *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (words);
		if (s[i] != c && s[i] != '\0')
		{
			words++;
			while (s[i + 1] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dup;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(dup = (char **)malloc(sizeof(char*) * count_words(s, c) + 1)))
		return (NULL);
	while (j < count_words(s, c))
	{
		k = 0;
		dup[j] = (char *)malloc(sizeof(char) * word_lenght(s, c, (j + 1)) + 1);
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (dup);
		while ((s[i] != c && k < word_lenght(s, c, (j + 1))))
			dup[j][k++] = s[i++];
		dup[j++][k] = '\0';
	}
	dup[j] = 0;
	return (dup);
}
