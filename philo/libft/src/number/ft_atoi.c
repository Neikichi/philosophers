/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:10:15 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:02:41 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief ASCII to INTEGER conversion
/// @param nptr takes in strings or char
/// @return 0 if fail or the digits in INT
int	ft_atoi(const char *nptr)
{
	int	neg;
	int	amt;

	amt = 0;
	neg = 1;
	while (ft_isspace(*nptr))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		amt = amt * 10 + (*nptr - '0');
		nptr++;
	}
	return (amt * neg);
}

/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/*int main(void)*/
/*{*/
/*	const char *test_case1 = "	 \t\n	-12345abc";*/
/*	printf("ft_atoi(\"%s\") = %d\n", test_case1, ft_atoi(test_case1));*/
/*	printf("atoi(\"%s\") = %d\n", test_case1, atoi(test_case1));*/
/**/
/*	return 0;*/
/*}*/
