/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:41:08 by jemonthi          #+#    #+#             */
/*   Updated: 2025/10/27 18:32:29 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!*lst || !del)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		ptr = (*lst)->next;
		del((*lst)->content);
		free (*lst);
		*lst = ptr;
	}
}
