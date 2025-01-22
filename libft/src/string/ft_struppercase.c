/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struppercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:37:08 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:21:51 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_struppercase(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (ft_islower(*str))
			*str = ft_toupper((unsigned char)*str);
		str++;
	}
}
