/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:25:23 by vlow              #+#    #+#             */
/*   Updated: 2024/12/31 00:44:01 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstpop_back(t_list **lst)
{
	t_list	*temp;
	t_list	*prev;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	ft_lstdelone(temp, free);
}
