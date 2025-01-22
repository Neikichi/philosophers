/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:40:37 by vlow              #+#    #+#             */
/*   Updated: 2024/11/10 17:04:31 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/// @brief Locate a substring in a string, up to a maximum length
/// 
/// This function locates the first occurrence of the null-terminated
/// substring `little` in the string `big`, where no more than `len`
/// characters are searched.
/// 
/// @param big The larger string to be searched
/// @param little The substring to be located in `big`
/// @param len The maximum number of characters to search
/// @return A pointer to the beginning of the located substring,
///			or `NULL` if not found
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!big || !little) && len == 0)
		return (NULL);
	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (little[j] == big[i])
		{
			while (little[j] && big[i + j] && (i + j) < len)
			{
				if (big[i + j] != little[j])
					break ;
				j++;
			}
			if (!little[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*	const char *big1 = "Hello, world!";*/
/*	const char *little1 = "world";*/
/*	size_t len1 = 13;*/
/*	char *result1 = ft_strnstr(big1, little1, len1);*/
/*	printf("ft_strnstr result: %s\n", result1 ? result1 : "NULL");*/
/**/
/*	const char *big5 = "Hello, world!";*/
/*	const char *little5 = "world";*/
/*	size_t len5 = 13;*/
/*	char *std_result = strnstr(big5, little5, len5);*/
/*	printf("Standard strnstr result: %s\n", std_result ? std_result : "NULL");*/
/**/
/*	return 0;*/
/*}*/
