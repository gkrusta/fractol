/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:48:25 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 17:39:10 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr_tofree;

	if (lst && del)
	{
		while (*lst)
		{
			del((*lst)->content);
			ptr_tofree = *lst;
			*lst = ptr_tofree->next;
			free (ptr_tofree);
		}
		*lst = 0;
	}
}
