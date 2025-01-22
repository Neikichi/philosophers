/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:20:37 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:08:33 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Convert unsigned long integer to HEX string representation
/// 
/// This function converts the given integer `n` to a string representation.
/// Of base 16, hexadecimal in lower case.
/// Special cases such as '0' are handled separately.
/// 
/// @param n The integer to be converted
/// @return A pointer to a null-terminated string representing the integer
char	*ft_itoa_hex(unsigned long int n)
{
	unsigned long int		size;
	char					*buffer;
	char					*base;

	base = "0123456789abcdef";
	if (n == 0)
		return (ft_strdup("0"));
	size = ft_countdigits_hex(n);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	buffer[size] = '\0';
	while (size)
	{
		buffer[size - 1] = base[(n % 16)];
		size--;
		n /= 16;
	}
	return (buffer);
}
