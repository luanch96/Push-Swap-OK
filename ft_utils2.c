/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luna <luna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:25:16 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/17 01:30:00 by luna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_words(char *str, char c)
{
	int		count;
	int		stop;

	count = 0;
	while (*str)
	{
		stop = 0;
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			if (stop == 0)
			{
				count++;
				stop = 1;
			}
			str++;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == c)
		cursor++;
	while ((str[cursor + len] != c) && str[cursor + len])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != c) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char c)
{
	int		words_number;
	char	**splitted_array;
	int		i;

	i = 0;
	words_number = num_words(str, c);
	if (!words_number)
		exit(1);
	splitted_array = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (splitted_array == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			splitted_array[i] = malloc(sizeof(char));
			if (splitted_array[i] == NULL)
				return (NULL);
			splitted_array[i++][0] = '\0';
			continue ;
		}
		splitted_array[i++] = get_next_word(str, c);
	}
	splitted_array[i] = NULL;
	return (splitted_array);
}

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}
