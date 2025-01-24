/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:17 by vlow              #+#    #+#             */
/*   Updated: 2025/01/24 15:17:55 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX_PHILO 200

# define CYAN "\033[1;36m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define COLOUR "\033[0m"

# include <pthread.h>

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	FORK_1 = 4,
	FORK_2 = 5
}	t_status;

typedef struct s_table
{
	int	t_num;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	opt_eat;
	time_t	start_time;
	pthread_mutex_t	print;
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
	t_table		*table;
}	t_philo;

typedef struct s_data
{
	// pthread_t		**philo;
	pthread_mutex_t	mutex;
	t_table			table;
	t_philo			philo[MAX_PHILO];
}	t_data;

#endif
