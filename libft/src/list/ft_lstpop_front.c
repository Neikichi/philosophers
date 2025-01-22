/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:12:37 by vlow              #+#    #+#             */
/*   Updated: 2024/12/31 00:44:14 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstpop_front(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	*lst = temp->next;
	ft_lstdelone(temp, free);
}
