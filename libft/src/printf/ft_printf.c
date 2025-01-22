/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:45:26 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:11:12 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int		sp_fl(va_list vlist, const char **fptr);
void	print_flags(t_flags *flags);

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		vlist;
	const char	*fptr;

	count = 0;
	fptr = format;
	va_start(vlist, format);
	while (*fptr)
	{
		if (*fptr == '%')
		{
			count += sp_fl(vlist, &fptr);
			fptr++;
		}
		else if (*fptr == '\\')
			count += bs_esc(fptr++);
		else if (*fptr)
		{
			ft_putchar_fd(*fptr++, 1);
			count++;
		}
	}
	va_end(vlist);
	return (count);
}

int	sp_fl(va_list vlist, const char **fptr)
{
	t_flags	flags;

	flags = fl_init();
	if (!fl_set(fptr, &flags))
		return (0);
	if (flags.specifier == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (fl_load(vlist, &flags));
}
