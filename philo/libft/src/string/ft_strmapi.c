/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:40:27 by vlow              #+#    #+#             */
/*   Updated: 2024/11/10 16:36:14 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Apply a function to each character of a string to
///			create a new string
/// 
/// This function iterates over each character of the string `s`, applies the
/// function `f` to it (along with the index), and creates a new string with
/// the resulting characters.
/// 
/// @param s The input string
/// @param f The function to apply to each character, taking the index and
///			 character as arguments
/// @return A pointer to the newly created string, or
///			`NULL` if allocation fails
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buffer;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	buffer = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!buffer)
		return (NULL);
	while (s[i])
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/*#include <stdio.h>*/
/*char f(unsigned int i, char c)*/
/*{*/
/*		if (i % 2 == 0 && c >= 'a' && c <= 'z')*/
/*		{*/
/*				return (c - 32);*/
/*		}*/
/*		return (c);*/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*		const char *str = "abc";*/
/*		char *result = ft_strmapi(str, f);*/
/*		if (result)*/
/*		{*/
/*				printf("ft_strmapi result: %s\n", result);*/
/*				free(result);*/
/*		}*/
/*		else*/
/*		{*/
/*				printf("ft_strmapi failed to allocate memory.\n");*/
/*		}*/
/**/
/*		return 0;*/
/*}*/
