/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:40:24 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 23:01:33 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/// @brief Calculate the length of a string
/// 
/// This function counts the number of characters in the string `str`
/// until the null terminator is encountered.
/// 
/// @param str The input string whose length is to be calculated
/// @return The length of the input string (excluding the null terminator)
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}
