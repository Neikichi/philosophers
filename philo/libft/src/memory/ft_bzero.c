/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:32:42 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 23:05:00 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/// @brief Set memory area to zero
/// 
/// This function writes zeroes to a byte string. If `n` is zero, `ft_bzero()`
/// does nothing.
/// 
/// @param s Pointer to the memory area to be zeroed
/// @param n Number of bytes to set to zero
/// @return This function does not return a value
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/*int main(void)*/
/*{*/
/*	char buffer[] = "123456789";*/
/**/
/*	ft_bzero(buffer, 0);*/
/*	printf("ft_bzero with n=0: \"%s\"\n", buffer);*/
/**/
/*	memset(buffer, 'X', 5);*/
/*	buffer[5] = '\0';*/
/*	ft_bzero(buffer, 0);*/
/*	printf("Comparison after memset and ft_bzero: \"%s\"\n", buffer);*/
/**/
/*	return 0;*/
/*}*/
