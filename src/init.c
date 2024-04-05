/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:26:24 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/05 18:08:20 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_meal = ft_atoi(argv[5]);
	else
		data->nb_meal = -1;
	data->iterating = true;
	data->start_time = 0;
	pthread_mutex_init(&data->get_value, NULL);
	pthread_mutex_init(&data->update_value, NULL);
	pthread_mutex_init(&data->writting, NULL);
}

int	init_malloc(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (2);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
	{
		free(data->philo);
		return (2);
	}
	data->philo_ths = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->philo_ths)
	{
		free(data->philo);
		free(data->fork);
		return (2);
	}
	return (0);
}

void	init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = data->philo;
	while (++i < data->nb_philo)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].meal = 0;
		update_lasteat(&philo[i]);
	}
}

void	init_fork(t_data *data)
{
	int		i;
	t_philo	*philo;

	philo = data->philo;
	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_init(&data->fork[i], NULL);
	i = 0;
	philo[i].left_fork = &data->fork[i];
	philo[i].right_fork = &data->fork[data->nb_philo - 1];
	while (++i < data->nb_philo)
	{
		philo[i].left_fork = &data->fork[i];
		philo[i].right_fork = &data->fork[i - 1];
	}
}
