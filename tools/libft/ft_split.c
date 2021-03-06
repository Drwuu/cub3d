/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwourms <lwourms@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:41:28 by lwourms           #+#    #+#             */
/*   Updated: 2021/03/06 15:40:31 by lwourms          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_sep(const char *str, const char *sep, int i)
{
	int j;

	j = 0;
	while (sep[j])
	{
		if (str[i] == sep[j])
			return (1);
		j++;
	}
	return (0);
}

static int		count_str(const char *str, const char *sep)
{
	int i;
	int words;
	int new_word;

	i = 0;
	words = 0;
	new_word = 0;
	while (str[i])
	{
		if (!is_sep(str, sep, i))
		{
			if (!new_word)
			{
				new_word = 1;
				words++;
			}
		}
		else
			new_word = 0;
		i++;
	}
	return (words);
}

static int		char_nbr(const char *str, const char *sep, int i)
{
	int char_nbr;

	char_nbr = 0;
	while (str[i])
	{
		if (!is_sep(str, sep, i))
			char_nbr++;
		else
			return (char_nbr);
		i++;
	}
	return (char_nbr);
}

static char	*build_str(const char *str, const char *sep, int i)
{
	char	*build_str;
	int		j;
	int		k;
	int		size;

	size = char_nbr(str, sep, i);
	j = 0;
	k = 0;
	if (!(build_str = malloc(sizeof(*build_str) * (size + 1))))
		return (NULL);
	while (j < size)
	{
		build_str[k] = str[i++];
		k++;
		j++;
	}
	build_str[k] = '\0';
	return (build_str);
}

char	**ft_split(const char *s, const char *sep)
{
	char	**split;
	int		new_word;
	int		i;
	int		j;

	if (!s || !(split = malloc(sizeof(*split) * (count_str(s, sep) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	new_word = 0;
	while (s[i])
	{
		if (!is_sep(s, sep, i))
		{
			if (!new_word)
			{
				if (!(split[j++] = build_str(s, sep, i)))
					return (ft_free_dbl_array(split));
				new_word = 1;
			}
		}
		else
			new_word = 0;
		i++;
	}
	split[j] = 0;
	return (split);
}
