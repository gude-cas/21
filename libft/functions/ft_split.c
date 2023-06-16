/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:17:36 by gude-cas          #+#    #+#             */
/*   Updated: 2023/06/16 15:51:15 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_word_counter(const char *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			word_count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (word_count);
}

static char	*ft_write_word(char *word_arr, const char *s, int i,
		int word_length)
{
	int	j;

	j = 0;
	while (word_length > 0)
	{
		word_arr[j] = s[i - word_length];
		j++;
		word_length--;
	}
	word_arr[j] = '\0';
	return (word_arr);
}

static void	ft_split_words(const char *s, char c, char **str, int word_count)
{
	int	i;
	int	word_number;
	int	word_length;

	i = 0;
	word_number = 0;
	word_length = 0;
	while (word_number < word_count)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			word_length++;
			i++;
		}
		str[word_number] = (char *)malloc(sizeof(char) * (word_length + 1));
		if (!str[word_number])
			return ;
		ft_write_word(str[word_number], s, i, word_length);
		word_length = '\0';
		word_number++;
	}
	str[word_number] = NULL;
	return ;
}

char	**ft_split(const char *s, char c)
{
	char			**str;
	unsigned int	word_count;

	if (!s)
		return (0);
	word_count = ft_word_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!str)
		return (0);
	ft_split_words(s, c, str, word_count);
	return (str);
}
