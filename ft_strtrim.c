/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:40:52 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/05 14:02:39 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	return (i);
}

static int	last_index(char const *s1, char const *set)
{
	int	count;
	int	i;

	i = ft_strlen(s1) - 1;
	count = 0;
	while (i >= 0 && ft_strchr(set, s1[i]))
	{
		count += 1;
		i--;
	}
	return (count);
}

static void	copy_trimmed_chars(char *ptr, const char *s1, int start, int length)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	while (j < length)
	{
		ptr[j] = s1[i];
		i++;
		j++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		trimmed_lenght;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	trimmed_lenght = ft_strlen(s1) - first_index(s1, set) - last_index(s1, set);
	if (trimmed_lenght <= 0)
	{
		ptr = malloc (1);
		if (!ptr)
			return (NULL);
		ptr[i] = '\0';
		return (ptr);
	}
	i = first_index(s1, set);
	ptr = malloc(trimmed_lenght + 1);
	if (!ptr)
		return (NULL);
	copy_trimmed_chars(ptr, s1, i, trimmed_lenght);
	ptr[trimmed_lenght] = '\0';
	return (ptr);
}
