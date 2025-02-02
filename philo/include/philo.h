/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:17 by vlow              #+#    #+#             */
/*   Updated: 2025/02/03 03:18:55 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# define MAX_PHILO 200
# define ERROR_SYNTAX "Error! Syntax: ./philo <number_of_philosopher> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[OPTIONAL: number_of_times_each_philosophers_must_eat]\n"
# define ERROR_PHILO_COUNT "Error! <number_of_philosopher> [Input: 1 - 200]\n"

// COLOUR
# define CYAN "\033[1;36m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define COLOUR "\033[0m"

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
	int				t_num;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				to_eat;
	int				end;
	time_t			start_time;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_end;
	pthread_mutex_t	lock_eat;
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
	int			times_eaten;
	time_t		last_meal;
	t_table		*table;
}	t_philo;

typedef struct s_data
{
	t_table			table;
	t_philo			philo[MAX_PHILO];
}	t_data;

// init
int		init_data(t_data *data, int ac, char **av);
int		init_mutex(t_data *data);
int		init_philo(t_data *data);
int		init_join_philo(t_data *data);
void	init_destroy(t_data *data);

// routine
void	*table_routine(void *arg);
void	philo_status(t_data *data);

// Input Check
int		input_check(int ac, char **av);
int		exit_check(t_philo *philo);
int		dead_check(t_philo *philo);

// Utils
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_issign(char c);
void	print_status(t_philo *philo, t_status status);
time_t	timer_ms(void);
void	delay_ms(t_philo *philo, time_t delay_time);
int		exit_error(char *err, int ret);

#endif
