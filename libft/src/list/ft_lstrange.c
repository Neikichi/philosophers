/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:37:43 by vlow              #+#    #+#             */
/*   Updated: 2024/12/28 21:40:31 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstrange(t_list *lst, int target)
{
	int	dist;

	dist = 0;
	while (lst)
	{
		if (lst->idx == target)
			break ;
		lst = lst->next;
		dist++;
	}
	if (!lst)
		return (-1);
	return (dist);
}
