/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:32:59 by vlow              #+#    #+#             */
/*   Updated: 2025/01/19 01:33:22 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	free_split(char **str)
{
	char	**temp;

	if (!str)
		return (0);
	temp = str;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(str);
	return (1);
}

void	split_print(char **str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printf("Split returned NULL.\n");
		return ;
	}
	ft_printf("Split result:\n");
	while (str[i])
	{
		ft_printf("[%d]: %s\n", i, str[i]);
		i++;
	}
	ft_printf("[%d]: %s\n", i, str[i]);
}
