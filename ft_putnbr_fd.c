/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:46:27 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/02 21:03:19 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		nb;
	long long	i;

	i = n;
	if (fd < 0)
		return ;
	if (i < 0)
	{
		write(fd, "-", 1);
		i *= -1; 
	}
	if (i <= 9)
	{
		nb = i + 48;
		write(fd, &nb, 1);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd); 
		ft_putnbr_fd(i % 10, fd); 
	}
}
