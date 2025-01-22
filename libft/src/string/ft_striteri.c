/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:40:04 by vlow              #+#    #+#             */
/*   Updated: 2024/11/11 12:18:34 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Apply a function to each character of a string with its index
/// 
/// Applies the function ’f’ on each character of
/// the string passed as argument, passing its index
/// as first argument. Each character is passed by
/// address to ’f’ to be modified if necessary.
///  
/// @param s The string to be iterated over
/// @param f The function to apply to each character of the string
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>*/
/**/
/*void f(unsigned int i, char *c)*/
/*{*/
/*	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')*/
/*	{*/
/*		*c -= 32;*/
/*	}*/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*	char str1[] = "hello, world!";*/
/*	printf("Original string 1: %s\n", str1);*/
/*	ft_striteri(str1, f);*/
/*	printf("Modified string 1: %s\n", str1);*/
/**/
/**/
/*	return 0;*/
/*}*/
