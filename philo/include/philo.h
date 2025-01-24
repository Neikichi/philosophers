/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:17 by vlow              #+#    #+#             */
/*   Updated: 2025/01/24 03:42:09 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_PHILO 200

#include <pthread.h>
typedef struct s_table
{
	int	t_num;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	opt_eat;
	pthread_mutex_t	forks[MAX_PHILO];
}	t_table;

typedef struct s_philo
{
	pthread_t	th;
	int			id;
	int			fork[2];
	int			eating;
	int			sleeping;
	int			thinking;
	int			dead;
	int			times_eaten;
}	t_philo;

typedef struct s_data
{
	// pthread_t		**philo;
	pthread_mutex_t	mutex;
	t_table			table;
	t_philo			philo[MAX_PHILO];
	int				test;
}	t_data;

#endif
