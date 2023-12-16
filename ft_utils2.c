/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luna <luna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:25:16 by luisanch          #+#    #+#             */
/*   Updated: 2023/12/16 22:38:39 by luna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}
size_t	ft_line_count(const char *s, char c)
{
	size_t	x;

	x = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		x++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (x);
}

char	*ft_linedata(const char *s, size_t start, size_t finish)
{
	char	*dest;
	size_t	x;

	x = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[x++] = s[start++];
	dest[x] = '\0';
	return (dest);
}

void	ft_fill_line(char **dest, const char *s, char c)
{
	size_t	x;
	size_t	pos1;
	size_t	start;

	x = 0;
	pos1 = 0;
	start = 0;
	while (s[x])
	{
		while (s[x] && s[x] != c)
		{
			x++;
			if (s[x] == c || x == ft_strlen(s))
				dest[pos1++] = ft_linedata(s, start, x);
		}	
		while (s[x] && s[x] == c)
		{
			x++;
			start = x;
		}
	}
	dest[pos1] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_line_count(s, c) + 1));
	if (!dest)
		return (NULL);
	ft_fill_line(dest, s, c);
	return (dest);
}