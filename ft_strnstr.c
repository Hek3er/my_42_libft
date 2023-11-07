/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:52:37 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/06 17:59:25 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (n == 0)
		return ((char *) str);
	if (find[i] == 0)
		return ((char *) str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] && str[i + j] == find[j])
		{
			j++;
			if (find[j] == 0)
				return ((char *)&str[i]);
			if ((i + j) >= n)
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
