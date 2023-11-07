/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:53:30 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/06 18:15:05 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cpy(unsigned int start, size_t len, char const *s, char *ptr)
{
	size_t	i;

	i = 0;
	while (i < len && s[start])
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	max_len;

	i = 0;
	if (!s)
		return (NULL);
	max_len = ft_strlen(s) - start;
	if (len > max_len)
		len = max_len;
	if (start >= ft_strlen(s))
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[i] = '\0';
		return (ptr);
	}
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	cpy(start, len, s, ptr);
	return (ptr);
}
