/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:07:59 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/06 14:54:25 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	check;
	int	count;
	int	i;

	check = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			check += 1;
			if (check == 1)
				count += 1;
		}
		else
			check = 0;
		i++;
	}
	return (count);
}

static char	**fill(char **ptr, char const *s, char c)
{
	int	len;
	int	i;
	int	first_occ;

	len = 0;
	i = 0;
	while (s[len])
	{
		if (s[len] == c)
		{
			len++;
			continue ;
		}
		first_occ = len;
		while (s[len] != c && s[len])
			len++;
		ptr[i] = malloc(sizeof(char) * (len - first_occ + 1));
		if (!ptr[i])
			return (NULL);
		ft_strlcpy(ptr[i], (s + first_occ), (len - first_occ + 1));
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		n_words;
	int		i;
	char	**ptr;

	i = 0;
	if (!s)
		return (NULL);
	n_words = count(s, c);
	ptr = malloc(sizeof(char *) * (n_words + 1));
	if (!ptr)
		return (NULL);
	if (!fill(ptr, s, c))
	{
		while (ptr[i])
		{
			free (ptr[i]);
			i++;
		}
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
