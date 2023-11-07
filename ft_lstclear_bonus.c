/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:36:29 by azainabi          #+#    #+#             */
/*   Updated: 2023/11/07 09:57:48 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	if (!lst)
		return ;
	curr = *lst;
	if (del)
	{
		while (curr != NULL)
		{
			(*del)(curr -> content);
			temp = curr;
			curr = curr -> next;
			free (temp);
		}
		*lst = NULL;
	}
}
