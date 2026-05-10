/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:39:46 by gopiment          #+#    #+#             */
/*   Updated: 2026/05/10 05:19:40 by gopiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temporary;

	if (!lst)
		return ;
	while (*lst)
	{
		temporary = (*lst)->next;
		free(*lst);
		*lst = temporary;
	}
	*lst = NULL;
}
