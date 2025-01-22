/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:05:13 by vlow              #+#    #+#             */
/*   Updated: 2025/01/14 14:47:14 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	prefix_sum(const char *str, const char *base, int str_base);

int	ft_atoi_base(const char *str, int str_base)
{
	char	base[17];
	int		neg;

	if (!str || str_base < 2)
		return (0);
	ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	return (prefix_sum(str, base, str_base) * neg);
}

static int	prefix_sum(const char *str, const char *base, int str_base)
{
	int	i;
	int	amt;

	i = 0;
	amt = 0;
	if (str_base > 10 && *str == '0' && *(str + 1) \
		&& (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	while (*str && ft_strchr(base, ft_tolower(*str)))
	{
		i = ft_strchr(base, ft_tolower(*str)) - base;
		amt = amt * str_base + i;
		str++;
	}
	return (amt);
}
