/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:22:33 by vlow              #+#    #+#             */
/*   Updated: 2024/11/28 13:23:21 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// For unsigned Version.
/// Does not count sign symbols.
int	ft_countdigits_u(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
