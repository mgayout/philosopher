/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:21:20 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/04 17:09:12 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo(int argc, char **argv)
{
	t_data	data;
	
	init_data(&data, argc, argv);
	if (init_malloc(&data))
		return (2);
	init_philo(&data);
	init_fork(&data);
	init_thread(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}

void	*philo_routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	update_lasteat(philo);
	if (philo->id % 2 == 0)
		ft_usleep(get_data_timeeat(philo->data) - 10);
	while (get_data_iter(philo->data) != false)
	{
		//printf("routine\n");
		if (eat_routine(philo) != 0)
			break ;
		//if (get_philo_state(philo) == DEAD)
			//break ;
		//if (ft_sleep(philo) != 0)
			//break ;
		//if (get_philo_state(philo) == DEAD)
			//break ;
		//if (think(philo) != 0)
			//break ;
	}
	return (NULL);
}

void	*all_alive_routine(void *void_data)
{
	int		i;
	int		nb_philo;
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)void_data;
	philo = data->philo;
	nb_philo = get_data_nbphilo(data);
	i = -1;
	while (++i < nb_philo && get_data_iter(data))
	{
		if (philo_died(&philo[i]) && get_data_iter(data))
		{
			philo_writting(&philo[i], "died");
			update_iter(data, false);
			//notify_all_philos(data);
			break ;
		}
		if (i == nb_philo - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_data_nbphilo(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	/*if (nb_meals_option(data) == true
		&& pthread_join(data->monit_all_full, NULL))
		return (1);*/
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_data_nbphilo(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->fork[i]);
		//pthread_mutex_destroy(&data->philo[i].mut_state);
		//pthread_mutex_destroy(&data->philo[i].mut_nb_meals_had);
		//pthread_mutex_destroy(&data->philo[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data->get_value);
	pthread_mutex_destroy(&data->update_value);
	pthread_mutex_destroy(&data->writting);
	//pthread_mutex_destroy(&data->mut_die_t);
	//pthread_mutex_destroy(&data->mut_eat_t);
	//pthread_mutex_destroy(&data->mut_sleep_t);
	//pthread_mutex_destroy(&data->mut_nb_philos);
	//pthread_mutex_destroy(&data->mut_print);
	//pthread_mutex_destroy(&data->mut_keep_iter);
	//pthread_mutex_destroy(&data->mut_start_time);
	free(data->philo_ths);
	free(data->philo);
	free(data->fork);
}
