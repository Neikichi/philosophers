/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:08:35 by vlow              #+#    #+#             */
/*   Updated: 2025/02/03 02:50:13 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (exit_error(ERROR_SYNTAX, 1));
	if (!input_check(ac, av))
		return (exit_error("Error! Invalid Input\n", 1));
	if (!init_data(&data, ac, av))
		return (exit_error(ERROR_PHILO_COUNT, 1));
	if (!init_sem(&data))
		return (exit_error("Error! Init Semaphores\n", 1));
	return (init_philo(&data));
}
