/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:55 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/04 17:14:21 by mgayout          ###   ########.fr       */
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

struct 				s_data;

typedef struct 		s_philo
{
	int				id;
	int				meal;
	bool			alive;
	struct s_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	long long		lasteat;
}					t_philo;

typedef struct 		s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal;
	bool			iterating;
	long long		start_time;
	//pthread_mutex_t	mut_eat_t;
	//pthread_mutex_t	mut_die_t;
	//pthread_mutex_t	mut_sleep_t;
	//pthread_mutex_t	mut_print;
	//pthread_mutex_t	mut_nb_philos;
	//pthread_mutex_t	mut_keep_iter;
	//pthread_mutex_t	mut_start_time;
	pthread_mutex_t	get_value;
	pthread_mutex_t	update_value;
	pthread_mutex_t	writting;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*fork;
	t_philo			*philo;
}					t_data;

//MAIN

//INIT

void		init_data(t_data *data, int argc, char **argv);
int			init_malloc(t_data *data);
void		init_philo(t_data *data);
void		init_fork(t_data *data);
int			init_thread(t_data *data);

//PHILO

int			philo(int argc, char **argv);
void		*philo_routine(void *philo);
void		*all_alive_routine(void *void_data);
int			join_threads(t_data *data);
void		free_data(t_data *data);

//EATING

int			eat_routine(t_philo *philo);
int			take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);

//LIBFT

int			ft_atoi(char *str);
int			digit_args(int argc, char **argv);

//UTILS

long long	gettime(void);
void		ft_usleep(size_t time);
void		philo_writting(t_philo *philo, char *str);
bool		philo_died(t_philo *philo);
bool		nb_meals_option(t_data *data);

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

//UPDATE_VALUE

void		update_lasteat(t_philo *philo);
void		update_nbmeal(t_philo *philo);
void		update_iter(t_data *data, bool update);

#endif