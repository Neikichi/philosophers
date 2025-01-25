/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:11:30 by vlow              #+#    #+#             */
/*   Updated: 2025/01/26 00:23:31 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

static int	isvalid_args(char *av);
static int	check_atoi(const char *nptr);

int	input_check(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!isvalid_args(av[i]) || !check_atoi(av[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	isvalid_args(char *av)
{
	char	*temp;
	int		flag;

	flag = 0;
	temp = av;
	while (*temp)
	{
		if (!ft_isdigit(*temp) && !(*temp == '+'))
			return (0);
		if (ft_issign((temp) && (*(temp + 1) && ft_issign(*(temp + 1)))))
			return (0);
		if (ft_isdigit(*temp))
			flag++;
		if (flag && ft_issign(*temp))
			return (0);
		temp++;
	}
	if (flag)
		return (1);
	return (0);
}

static int	check_atoi(const char *nptr)
{
	int			neg;
	long int	amt;

	amt = 0;
	neg = 0;
	while (ft_isspace(*nptr))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		amt = amt * 10 + (*nptr - '0');
		if ((!neg && (amt > INT_MAX)) || (neg && (-amt < INT_MIN)))
			return (0);
		nptr++;
	}
	return (1);
}
