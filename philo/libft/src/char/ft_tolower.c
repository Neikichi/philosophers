/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:43:39 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 14:56:52 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Convert an uppercase character to lowercase
/// 
/// This function converts an uppercase character to its corresponding
/// lowercase character.
/// If the character is not an uppercase letter, it is returned unchanged.
/// 
/// @param c The character to be converted
/// @return The converted lowercase character, or the original character
///			if it is not uppercase
int	ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (c + 32);
	}
	return (c);
}
