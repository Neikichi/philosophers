/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:37:53 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:08:09 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_itoa_ex(int n);

/// @brief Convert integer to string representation
/// 
/// This function converts the given integer `n` to a string representation.
/// Special cases such as INT_MAX and INT_MIN are handled separately.
/// 
/// @param n The integer to be converted
/// @return A pointer to a null-terminated string representing the integer
char	*ft_itoa(int n)
{
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_itoa_ex(n));
}

static char	*ft_itoa_ex(int n)
{
	int		neg;
	int		size;
	char	*buffer;

	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	size = ft_countdigits(n) + neg;
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	if (neg)
		buffer[0] = '-';
	buffer[size] = '\0';
	while (size != neg)
	{
		buffer[size - 1] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	return (buffer);
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*	int test_values[] = {0, -2147483648, 2147483647, -12345, 12345};*/
/*	char *result;*/
/**/
/*	for (int i = 0; i < 5; i++)*/
/*	{*/
/*	result = ft_itoa(test_values[i]);*/
/*	if (result)*/
/*	{*/
/*		printf("ft_itoa(%d) = %s\n", test_values[i], result);*/
/*		free(result);*/
/*	}*/
/*	else*/
/*	{*/
/*		printf("ft_itoa(%d) = NULL (Memory failed)\n", test_values[i]);*/
/*	}*/
/*	}*/
/**/
/*	return 0;*/
/*}*/
