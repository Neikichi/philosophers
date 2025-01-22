/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:45:40 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:21:22 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlowercase(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (ft_isupper(*str))
			*str = ft_tolower((unsigned char)*str);
		str++;
	}
}
