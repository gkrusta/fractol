/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:01:21 by gkrusta           #+#    #+#             */
/*   Updated: 2023/05/01 17:39:05 by gkrusta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*ptr_tofree;

	if (lst && del)
	{
		del(lst->content);
		ptr_tofree = lst;
		lst = ptr_tofree->next;
		free (ptr_tofree);
		lst = 0;
	}
}
