/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:40:32 by vlow              #+#    #+#             */
/*   Updated: 2024/11/10 11:33:27 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/// @brief Compare two strings up to a given number of characters
/// 
/// This function compares up to `n` characters of the strings `s1` and `s2`.
/// It returns an integer less than, equal to, or greater than zero if `s1`
/// is found, respectively, to be less than, to match,
/// or to be greater than `s2`.
/// Characters are compared as unsigned values to avoid issues
/// with negative character values.
/// 
/// @param s1 The first string to be compared
/// @param s2 The second string to be compared
/// @param n The maximum number of characters to compare
/// @return The difference between the first differing characters,
///			or `0` if no difference is found within `n` characters
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*	const char *str1 = "Hello"; // \xE1*/
/*	const char *str2 = "Hello"; // \x61*/
/*	size_t n = 5;*/
/*	int result = ft_strncmp(str1, str2, n);*/
/*	printf("ft_strncmp result: %d\n", result);*/
/**/
/*	result = strncmp(str1, str2, n);*/
/*	printf("Strncmp result: %d\n", result);*/
/**/
/*	return 0;*/
/*}*/
