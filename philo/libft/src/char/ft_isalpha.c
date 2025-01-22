/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:36:19 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 14:56:21 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Check if character is an alphabetic letter
/// 
/// This function checks whether the given 
/// character `c` is either an uppercase
/// or lowercase alphabetic character.
/// 
/// @param c The character to be checked
/// @return 1 if `c` is an alphabetic letter, 0 otherwise
int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}
