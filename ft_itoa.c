/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:03:54 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/03 22:20:47 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int			count;
	long long	nl;

	nl = n;
	count = 0;
	if (nl == 0)
		count = 1;
	if (nl < 0)
	{
		nl *= -1;
		count += 1;
	}
	while (nl)
	{
		nl /= 10;
		count += 1;
	}
	return (count);
}

static void	convert(char *ptr, int length, long long nl)
{
	while (nl)
	{
		ptr[length - 1] = (nl % 10) + '0';
		nl /= 10;
		length --;
	}
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long long	nl;
	int			length;

	nl = n;
	length = size(n);
	ptr = malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (NULL);
	if (nl < 0)
	{
		ptr[0] = '-';
		nl *= -1;
		convert(ptr, length, nl);
	}
	if (nl == 0)
		ptr[0] = '0';
	ptr[length] = '\0';
	if (nl >= 0)
	{
		convert(ptr, length, nl);
	}
	return (ptr);
}
