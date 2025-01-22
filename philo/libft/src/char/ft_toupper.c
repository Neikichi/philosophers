/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:43:51 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 14:57:03 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Convert a lowercase character to uppercase
/// 
/// This function converts a lowercase character to its 
/// corresponding uppercase character.
/// If the character is not a lowercase letter, 
/// it is returned unchanged.
/// 
/// @param c The character to be converted
/// @return The converted uppercase character, 
///			or the original character if it is not lowercase
int	ft_toupper(int c)
{
	if (ft_islower(c))
	{
		return (c - 32);
	}
	return (c);
}
