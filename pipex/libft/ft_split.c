/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cyuzbas <cyuzbas@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 10:25:47 by cyuzbas       #+#    #+#                 */
/*   Updated: 2021/10/27 11:27:21 by cyuzbas       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**split_free(char **s1, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(s1[i]);
		i++;
	}
	free(s1);
	return (NULL);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static int	each_start(char const *s, char c)
{
	int	start;

	start = 0;
	while (s[start] == c && s[start])
		start++;
	return (start);
}

static int	word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		index;
	int		start;
	int		len;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	index = 0;
	while (words > index)
	{
		start = each_start(s, c);
		len = word_len(s, c, start);
		split[index] = ft_substr(s, start, len);
		if (!split[index])
			return (split_free(split, index));
		index++;
		s = s + (start + len);
	}
	split[index] = 0;
	return (split);
}
