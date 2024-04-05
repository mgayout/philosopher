/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:55 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/05 18:06:35 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdbool.h>
//# include <stdint.h>

struct				s_data;

typedef struct s_philo
{
	int				id;
	int				meal;
	struct s_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		lasteat;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal;
	bool			iterating;
	long long		start_time;
	pthread_mutex_t	get_value;
	pthread_mutex_t	update_value;
	pthread_mutex_t	writting;
	pthread_t		monit_all_alive;
	pthread_t		*philo_ths;
	pthread_mutex_t	*fork;
	t_philo			*philo;
}					t_data;

//MAIN

int			check_args(int argc, char **argv);
int			philo(int argc, char **argv);
int			join_threads(t_data *data);
void		free_data(t_data *data);

//INIT

void		init_data(t_data *data, int argc, char **argv);
int			init_malloc(t_data *data);
void		init_philo(t_data *data);
void		init_fork(t_data *data);

//ROUTINE

int			thread_routine(t_data *data);
void		*philo_routine(void *philo);
void		*dead_routine(void *void_data);

//EAT

int			eat_routine(t_philo *philo);
int			take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);

//SLEEP_THINK

int			sleep_routine(t_philo *philo);
int			think_routine(t_philo *philo);

//LIBFT

int			ft_atoi(char *str);
int			digit_args(int argc, char **argv);

//UTILS

long long	gettime(void);
void		ft_usleep(size_t time);
void		philo_writting(t_philo *philo, char *str);

//UTILS2

bool		philo_died(t_philo *philo);
void		stop_philo(t_data *data);

//GET_DATA

int			get_data_nbphilo(t_data *data);
int			get_data_timedie(t_data *data);
int			get_data_timeeat(t_data *data);
int			get_data_timesleep(t_data *data);
int			get_data_nbmeal(t_data *data);

//GET_DATA2

bool		get_data_iter(t_data *data);

//GET_PHILO

long long	get_philo_lasteat(t_philo *philo);
bool		get_philo_alive(t_philo *philo);

//UPDATE_VALUE

void		update_lasteat(t_philo *philo);
void		update_nbmeal(t_philo *philo);
void		update_iter(t_data *data, bool update);
void		update_alive(t_philo *philo, bool update);

#endif