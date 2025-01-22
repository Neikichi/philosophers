/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:30:12 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:08:45 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Convert unsigned long integer to string representation
/// 
/// This function converts the given integer `n` to a string representation.
/// Special cases such as '0' are handled separately.
/// 
/// @param n The integer to be converted
/// @return A pointer to a null-terminated string representing the integer
char	*ft_itoa_u(unsigned long int n)
{
	unsigned long int		size;
	char					*buffer;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_countdigits_u(n);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	buffer[size] = '\0';
	while (size)
	{
		buffer[size - 1] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	return (buffer);
}
