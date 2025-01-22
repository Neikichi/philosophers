/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrrange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:39:22 by vlow              #+#    #+#             */
/*   Updated: 2024/12/28 21:40:11 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstrrange(t_list *lst, int target)
{
	int		dist;
	t_list	*temp;

	dist = 0;
	temp = NULL;
	while (lst)
	{
		if (lst->idx == target)
			temp = lst;
		if (temp)
			dist++;
		lst = lst->next;
	}
	if (!temp)
		return (-1);
	return (dist);
}
